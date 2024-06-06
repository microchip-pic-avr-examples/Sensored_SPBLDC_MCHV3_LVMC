/*******************************************************************************
 *  Drive Parameters for Sensored Single Phase BLDC Motor Control 
 *  
 *  File Name:
 *    drive.h
 *   
 *  Summary:
 *    This header file lists Single Phase BLDCM drive and motor fault 
 *    configuration related functions and definitions.
 *
 *  Description:
 *    Definitions in the file are for dsPIC33CK256MP508 microcontroller
 *    plugged onto the Low Voltage Motor Control (LVMC) Board from Microchip.
 */
/*******************************************************************************/
/*******************************************************************************
 * Copyright (c) 2019 released Microchip Technology Inc.  All rights reserved.
 *
 * SOFTWARE LICENSE AGREEMENT:
 * 
 * Microchip Technology Incorporated ("Microchip") retains all ownership and
 * intellectual property rights in the code accompanying this message and in all
 * derivatives hereto.  You may use this code, and any derivatives created by
 * any person or entity by or on your behalf, exclusively with Microchip's
 * proprietary products.  Your acceptance and/or use of this code constitutes
 * agreement to the terms and conditions of this notice.
 *
 * CODE ACCOMPANYING THIS MESSAGE IS SUPPLIED BY MICROCHIP "AS IS".  NO
 * WARRANTIES, WHETHER EXPRESS, IMPLIED OR STATUTORY, INCLUDING, BUT NOT LIMITED
 * TO, IMPLIED WARRANTIES OF NON-INFRINGEMENT, MERCHANTABILITY AND FITNESS FOR A
 * PARTICULAR PURPOSE APPLY TO THIS CODE, ITS INTERACTION WITH MICROCHIP'S
 * PRODUCTS, COMBINATION WITH ANY OTHER PRODUCTS, OR USE IN ANY APPLICATION.
 *
 * YOU ACKNOWLEDGE AND AGREE THAT, IN NO EVENT, SHALL MICROCHIP BE LIABLE,
 * WHETHER IN CONTRACT, WARRANTY, TORT (INCLUDING NEGLIGENCE OR BREACH OF
 * STATUTORY DUTY),STRICT LIABILITY, INDEMNITY, CONTRIBUTION, OR OTHERWISE,
 * FOR ANY INDIRECT, SPECIAL,PUNITIVE, EXEMPLARY, INCIDENTAL OR CONSEQUENTIAL
 * LOSS, DAMAGE, FOR COST OR EXPENSE OF ANY KIND WHATSOEVER RELATED TO THE CODE,
 * HOWSOEVER CAUSED, EVEN IF MICROCHIP HAS BEEN ADVISED OF THE POSSIBILITY OR
 * THE DAMAGES ARE FORESEEABLE.  TO THE FULLEST EXTENT ALLOWABLE BY LAW,
 * MICROCHIP'S TOTAL LIABILITY ON ALL CLAIMS IN ANY WAY RELATED TO THIS CODE,
 * SHALL NOT EXCEED THE PRICE YOU PAID DIRECTLY TO MICROCHIP SPECIFICALLY TO
 * HAVE THIS CODE DEVELOPED.
 *
 * You agree that you are solely responsible for testing the code and
 * determining its suitability.  Microchip has no obligation to modify, test,
 * certify, or support the code.
 *
 *******************************************************************************/
// *****************************************************************************
// Section: Included Files
// *****************************************************************************
#include "userparams.h"
/**
  Section: Function Declarations
**/

/* Function:
    HALL_ISR()
  Summary:
    This routine defines the Hall Sensor State and finds parameters for the
    calculation of moving average speed.
  Description:
    Designates high or low hall value,\ and calculates timer value for 
    moving average speed.
  Precondition:
    None.
  Parameters:
    None
  Returns:
    None.
  Remarks:
    None.
 */
void HALL_ISR(void)
{
    #ifdef STALL_DETECTION
    //Stall Timer Reset
    motorStallCounter = 0;
    #endif

    if (HALLSENSOR == 0) //Forward
    {
        hallValue = 1;
    }
    if (HALLSENSOR == 1) //Reverse
    {
        hallValue = 2;
    }
    
    SCCP3_TMR_Stop();
    timerValue = SCCP3_TMR_Counter32BitGet();
    SCCP3_TMR_Counter32BitSet(0);
    SCCP3_TMR_Start();
    
    if(timerValue > MAX_TMR_COUNT) //if speed is lower than approximately 400, do alernate speed calculation
    {
        timerValue = MAX_TMR_COUNT;
    }
    
    CalcMovingAvgSpeed(timerValue); //if max_tmr_count= 357rpm
    SCCP4_TMR_Stop();
    SCCP4_TMR_Period32BitSet(timerValue);
    SCCP4_TMR_Counter32BitSet(0);
    SCCP4_TMR_Start();
}

/* Function:
    ADC_ISR()
  Summary:
    This routine triggers the motor control subroutines and other functions.
  Description:
    Called by the ADC module to trigger state machine, 
    board service interrupt and X2CScope Updates.
  Precondition:
    None.
  Parameters:
    None
  Returns:
    None.
  Remarks:
    None.
 */
void ADC_ISR(void)
{
    StateMachine();
    BoardServiceStepIsr();
    X2Cscope_Update();
    IFS6bits.ADCAN11IF = 0;
}

/* Function:
    StateMachine()
  Summary:
    This routine handles the motor control routines.
  Description:
    Initializes the motor and parameters, conducts start up, operates the motor
    driving and direction change and triggers the stop to the motor.
  Precondition:
    None.
  Parameters:
    None
  Returns:
    None.
  Remarks:
    None.
 */
void StateMachine()
{ 
    switch(appState)
    {
        case INIT:
            PWMDisableOutputs();
            InitMovingAvgSpeed();
            Init_PIControlParameters();
            RotationSwitchingTable(runDirection);
            dutyCycle = MIN_DUTYCYCLE;
            //reset fault detection flag
            faultDetected.overtemperature_detected = 0;
            faultDetected.stall_detected = 0;
            faultDetected.overcurrent_detected = 0;
            //enable hall port
            CNCONEbits.ON = 1;
            //Reset parameters for start up
            readyStartUp = 0;
            startup = 0;
            readyRun = 0;
            if(runMotor)
            {
                readyStartUp = 1;
                appState = CMD_WAIT;
            }
        break;

        case CMD_WAIT:
            if(readyStartUp == 1)
            {
                startup = 1; //See timer1 interrupt for startup routine
            }
            if(readyRun == 1)
            {
                appState = RUN;
            }

        break;

        case RUN:     
            CheckHalUpdatePWM();
            SpeedReference();
        #ifdef CLOSEDLOOP
            PICloseLoopController();
        #else
            OpenLoopSpeedController();
        #endif           

        #ifdef  STALL_DETECTION
            StallDetection();
        #endif
    
        #ifdef  OVERTEMPERATURE_DETECTION
            OverTemperature();
        #endif
    
        #ifdef  OVERCURRENT_DETECTION
            overcurrent_enable_flag = 1;
        #endif
        
            if(changeDirection == 1)
            {
                dutyCycle = 0;
                PG1DC = PG2DC = dutyCycle;
                PWMDisableOutputs();
                appState = CHANGE_DIRECTION;
            }
            if(runMotor == 0)
            {
                appState = STOP;
            }
            
        break;
        
        case CHANGE_DIRECTION:
            
            if(changeDirection == 1)
            {
                if(runDirection == 0)
                {
                    runDirection = 1;
                }
                else
                {
                    runDirection = 0;
                }
                changeDirection = 0;
                RotationSwitchingTable(runDirection);
            }
            if(timerValue > REV_SPEED_LIMIT )  
            {
                appState = RUN;  
                PWMEnableOutputs();
            }
            
        break;
        
        case STOP:
            measuredSpeed = 0;
            desiredSpeed = 0;
            dutyCycle = 0;
            PG1DC = PG2DC = dutyCycle;
            PWMDisableOutputs();
            readyRun = 0;
            appState = INIT;
        break;
    }
}

/* Function:
    InitializePWM()
  Summary:
    This routine initializes the PWM Generators and duty cycle prior
    to enabling the PWM Generator
  Description:
    Overrides the PWM generators to disable PWM output. 
  Precondition:
    None.
  Parameters:
    None
  Returns:
    None.
  Remarks:
    None.
 */
void InitializePWM(void)
{
    PG1IOCONL = PG2IOCONL = 0x3000;
    PG1DC = PG2DC = 0x0000;
	PG1CONLbits.ON = PG2CONLbits.ON = 1;
}

/* Function:
    RotationSwitchingTable()
  Summary:
    This routine designates the drive sequences in Forward and Reverse mode.
  Description:
    Assigns drive sequence to Forward and Reverse via arrays.
  Precondition:
    None.
  Parameters:
    None
  Returns:
    None.
  Remarks:
    None.
 */
void RotationSwitchingTable()
{
	uint16_t arrayIndex = 0;
    
	if(runDirection == 0)
    {
	    for(arrayIndex = 0; arrayIndex < 4; arrayIndex++)
        {
            PWM_STATE1[arrayIndex] = PWM_STATE1_CLKW[arrayIndex];
            PWM_STATE2[arrayIndex] = PWM_STATE2_CLKW[arrayIndex];
        }
	}
    else
    {
		for(arrayIndex = 0;arrayIndex < 4; arrayIndex++)
        {
            PWM_STATE1[arrayIndex] = PWM_STATE1_CLKW[3-arrayIndex];
            PWM_STATE2[arrayIndex] = PWM_STATE2_CLKW[3-arrayIndex];
        }
    }
}

/* Function:
    CheckHalUpdatePWM()
  Summary:
    This routine updates the drive sequence for the current hall sensor state.
  Description:
    Assigns the drive sequence to override the PWM Generators depending on the 
    hall value.
  Precondition:
    None.
  Parameters:
    None
  Returns:
    None.
  Remarks:
    None.
 */
void CheckHalUpdatePWM(void)
{
    if((hallValue == 1) || (hallValue == 2))
    {
        PG1IOCONL = (PWM_STATE1[hallValue] & 0x7C00);
        PG2IOCONL = (PWM_STATE2[hallValue] & 0x7C00);
    }
}

/* Function:
    SpeedReference()
  Summary:
    This routine calculates the desired duty cycle and desired speed.
  Description:
    Reads the potentiometer value via ADC module for the calculation of 
    desired duty cycle and desired speed
  Precondition:
    None.
  Parameters:
    None
  Returns:
    None.
  Remarks:
    None.
 */
void SpeedReference(void)
{
    inputReference = ADCBUF_POTENTIOMETER;
    desiredDC =(uint16_t)((__builtin_mulss(inputReference,MAX_DUTYCYCLE)>>12));
    temp =  (int32_t)(__builtin_muluu(desiredDC,(MAX_CL_MOTORSPEED - MIN_CL_MOTORSPEED)));
    desiredSpeed = (int16_t)((__builtin_divud(temp,(MAX_DUTYCYCLE)))+ MIN_CL_MOTORSPEED);
    
    if(desiredSpeed < MIN_CL_MOTORSPEED)
    {
        desiredSpeed = MIN_CL_MOTORSPEED; //any speed lower than 400 will make timer overflow
    }
}

/* Function:
    OpenLoopSpeedController()
  Summary:
    This routine runs the motor in Open Loop mode.
  Description:
    Assigns the value of the desired duty cycle to the PWM Generators.
  Precondition:
    None.
  Parameters:
    None
  Returns:
    None.
  Remarks:
    None.
 */
void OpenLoopSpeedController(void)
{
    //SpeedReference();
    if (desiredDC > MAX_DUTYCYCLE) //MPER*0.9
    {
        dutyCycle = MAX_DUTYCYCLE;
    }
    else if (desiredDC <= MIN_DUTYCYCLE) //MPER*0.1
    {
        dutyCycle = MIN_DUTYCYCLE;
    }
    else
    {
        dutyCycle = desiredDC;
    }
    
    PG1DC = dutyCycle;
    PG2DC = dutyCycle;
    
}

/* Function:
    PICloseLoopController()
  Summary:
    This routine runs the motor in Closed Loop mode.
  Description:
    Uses the PI Controller to control the duty cycle to be assigned.
  Precondition:
    None.
  Parameters:
    None
  Returns:
    None.
  Remarks:
    None.
 */
void PICloseLoopController(void) 
{
    if (runMotor == 1)
    {
        measuredSpeed = movingAvgSpeed.avg;
    }
    else
    {
        measuredSpeed = 0;
    }
    
    PI_Input.piSpeedCalculation.inMeasure = measuredSpeed;
    PI_Input.piSpeedCalculation.inReference = desiredSpeed;
    MC_ControllerPIUpdate_Assembly(PI_Input.piSpeedCalculation.inReference,
                                PI_Input.piSpeedCalculation.inMeasure,
                                &PI_Input.piSpeedCalculation.piState,
                                &PI_Input.piOutputSpeed.out);
    dutyCycle = (uint16_t) (__builtin_mulss(PI_Input.piOutputSpeed.out, (MAX_DUTYCYCLE)) >> 15);
   
    PG1DC = dutyCycle;
    PG2DC = dutyCycle;
}

/* Function:
    Timer Interrupt for Start up
  Summary:
    This routine changes the starting position the motor.
  Description:
    Overrides the PWM Generators to reposition the motor prior to motor driving.
  Precondition:
    None.
  Parameters:
    None
  Returns:
    None.
  Remarks:
    None.
 */

void __attribute__((interrupt, no_auto_psv)) _T1Interrupt() 
{
    if(startup == 1)
    {
        readyStartUp = 0;
        PG1IOCONL = 0x3400;
        PG2IOCONL = 0x0000;
        PG2DC = MPER*0.75;
        startup++;
    }
    else if(startup == 2) 
    {
        PG1IOCONL = 0x3400;
        PG2IOCONL = 0x0000;
        PG1DC = MPER*0.75;
        startup++;
    }
    else if(startup == 3) 
    {
        PG1IOCONL = 0x3400;
        PG2IOCONL = 0x0000;
        PG2DC = MPER*0.75;
        startup++;
    }
    else if(startup == 4) 
    {
        PG1IOCONL = 0x3400;
        PG2IOCONL = 0x0000;
        PG1DC = MPER*0.75;
        startup++;
    }
    else if(startup == 5) 
    {
        PG1IOCONL = 0x0000;
        PG2IOCONL = 0x3400;
        PG2DC = MPER*0.4;
        startup++;
    }
    else if(startup == 6)
    {
        PG1IOCONL = 0x3400;
        PG2IOCONL = 0x0000;
        PG1DC = MPER*0.75;
        startup = 0;
        readyRun = 1;
    }
    IFS0bits.T1IF = false;
}

/* Function:
    PWMDisableOutputs()
  Summary:
    This routine disables the PWM Generators.
  Description:
    Overrides the PWM Generators to disable outputs.
  Precondition:
    None.
  Parameters:
    None
  Returns:
    None.
  Remarks:
    None.
 */
void PWMDisableOutputs(void)
{
    PG2DC = 0;      
    PG1DC = 0;

    PG2IOCONLbits.OVRDAT = 0;  // Low State for PWM2H,L, if Override is Enabled
    PG1IOCONLbits.OVRDAT = 0;  // Low State for PWM1H,L, if Override is Enabled

    PG2IOCONLbits.OVRENH = 1;  // OVRDAT<1> provides data for output on PWM2H
    PG1IOCONLbits.OVRENH = 1;  // OVRDAT<1> provides data for output on PWM1H

    PG2IOCONLbits.OVRENL = 1;  // OVRDAT<0> provides data for output on PWM2L
    PG1IOCONLbits.OVRENL = 1;  // OVRDAT<0> provides data for output on PWM1L
}

/* Function:
    PWMEnableOutputs()
  Summary:
    This routine enables the PWM Generators.
  Description:
    Overrides the PWM Generators to enable outputs to continue 
    motor driving operations.
  Precondition:
    None.
  Parameters:
    None
  Returns:
    None.
  Remarks:
    None.
 */
void PWMEnableOutputs(void)
{
    PG2DC = 0;      
    PG1DC = 0;

    PG2IOCONLbits.OVRENH = 0;  // PWM generator provides data for PWM2H pin
    PG1IOCONLbits.OVRENH = 0;  // PWM generator provides data for PWM1H pin

    PG2IOCONLbits.OVRENL = 0;  // PWM generator provides data for PWM2L pin
    PG1IOCONLbits.OVRENL = 0;  // PWM generator provides data for PWM1L pin
}

/* Function:
    InitMovingAvgSpeed()
  Summary:
    This routine initializes parameters for moving average speed calculation.
  Description:
    None.
  Precondition:
    None.
  Parameters:
    None
  Returns:
    None.
  Remarks:
    None.
 */
void InitMovingAvgSpeed(void)
{
    uint16_t i;

    for (i = 0; i < SPEED_MOVING_AVG_FILTER_SIZE; i++) {
        movingAvgSpeed.buffer[i] = 0;
    }

    movingAvgSpeed.index = 0;
    movingAvgSpeed.sum = 0;
    movingAvgSpeed.avg = 0;
}

/* Function:
    CalcMovingAvgSpeed()
  Summary:
    This routine calculates the moving average speed of the motor.
  Description:
    None.
  Precondition:
    None.
  Parameters:
    None
  Returns:
    None.
  Remarks:
    None.
 */
void CalcMovingAvgSpeed(int32_t instCount) 
{
    uint16_t i;
    
    movingAvgSpeed.speedValue =  instCount;
    movingAvgSpeed.calculatedSpeed = (int32_t) (__builtin_divud(SPEED_MULTI, movingAvgSpeed.speedValue));
    
    movingAvgSpeed.buffer[movingAvgSpeed.index] = movingAvgSpeed.calculatedSpeed;
    movingAvgSpeed.index++;
    if (movingAvgSpeed.index >= SPEED_MOVING_AVG_FILTER_SIZE)
    {
        movingAvgSpeed.index = 0;
    }
    movingAvgSpeed.sum = 0;
    for (i = 0; i < SPEED_MOVING_AVG_FILTER_SIZE; i++) 
    {
        movingAvgSpeed.sum = movingAvgSpeed.sum + movingAvgSpeed.buffer[i];
        movingAvgSpeed.avg = movingAvgSpeed.sum >> SPEED_MOVING_AVG_FILTER_SCALE;
    }
    measuredSpeed = movingAvgSpeed.avg;
}

/* Function:
    Init_PIControlParameters()
  Summary:
    This routine initializes parameters for PI Controller.
  Description:
    None.
  Precondition:
    None.
  Parameters:
    None
  Returns:
    None.
  Remarks:
    None.
 */
void Init_PIControlParameters(void) {
    PI_Input.piSpeedCalculation.piState.kp = SPEEDCNTR_PTERM;
    PI_Input.piSpeedCalculation.piState.ki = SPEEDCNTR_ITERM;
    PI_Input.piSpeedCalculation.piState.kc = SPEEDCNTR_CTERM;
    PI_Input.piSpeedCalculation.piState.outMax = SPEEDCNTR_OUTMAX;
    PI_Input.piSpeedCalculation.piState.outMin = SPEEDCNTR_OUTMIN;
    PI_Input.piSpeedCalculation.piState.integrator = 0;
    PI_Input.piOutputSpeed.out = 0;
}


/* Function:
    StallDetection()
  Summary:
    This routine handles the Stall Detection of the motor.
  Description:
    Shuts down the system when motor is stalled for a certain period of time.
  Precondition:
    None.
  Parameters:
    None
  Returns:
    None.
  Remarks:
    None.
 */
void StallDetection(void)
{
    motorStallCounter = motorStallCounter + 1;

    if (motorStallCounter >= STALL_COUNT_LIMIT)
    {
        PWMDisableOutputs();
        PG1CONLbits.ON = PG2CONLbits.ON = 0;
        LVMC_LED1_SetLow();
        LVMC_LED2_SetLow();
        motorStallCounter = 0;
        faultDetected.stall_detected = 1;
    }
}

/* Interrupt Service routine for CMP3 */
void __attribute__ ( ( interrupt, no_auto_psv ) ) _CMP3Interrupt(void)
{
	cmp3 = DAC1CONLbits.CMPSTAT; //IBUS comparator out data

    if (overcurrent_enable_flag) {
        if (OVERCURRENT_DETECT_FLAG) {
            overcurrentCounter++;
            if (overcurrentCounter > OVERCURRENT_COUNTER_DELAY)
            {
                PWMDisableOutputs();
                PG1CONLbits.ON = PG2CONLbits.ON = 0;
                LVMC_LED1_SetLow();
                LVMC_LED2_SetLow();
                faultDetected.overcurrent_detected = 1;
            }
        }
    }
    IFS4bits.CMP3IF = 0;
}

void OverTemperature(void)
{
    faultOverTemp.measure = ADCBUF_DSPICTEMP;
    if(faultOverTemp.measure < OVERTEMP_LIMITER)
    {
        faultOverTemp.counter++;
        if (faultOverTemp.counter > OVERTEMP_COUNTER)
        {
            PWMDisableOutputs();
            PG1CONLbits.ON = PG2CONLbits.ON = 0;
            LVMC_LED1_SetLow();
            LVMC_LED2_SetLow();
            faultOverTemp.counter = 0;
            faultDetected.overtemperature_detected = 1;
        }
    }
}