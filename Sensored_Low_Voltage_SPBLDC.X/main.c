/**
  Generated main.c file from MPLAB Code Configurator

  @Company
    Microchip Technology Inc.

  @File Name
    main.c

  @Summary
    This is the generated main.c using PIC24 / dsPIC33 / PIC32MM MCUs.

  @Description
    This source file provides main entry point for system initialization and application code development.
    Generation Information :
        Product Revision  :  PIC24 / dsPIC33 / PIC32MM MCUs - 1.171.0
        Device            :  dsPIC33CK256MP508
    The generated drivers are tested against the following:
        Compiler          :  XC16 v1.70
        MPLAB 	          :  MPLAB X v5.50
*/

/*
    (c) 2020 Microchip Technology Inc. and its subsidiaries. You may use this
    software and any derivatives exclusively with Microchip products.

    THIS SOFTWARE IS SUPPLIED BY MICROCHIP "AS IS". NO WARRANTIES, WHETHER
    EXPRESS, IMPLIED OR STATUTORY, APPLY TO THIS SOFTWARE, INCLUDING ANY IMPLIED
    WARRANTIES OF NON-INFRINGEMENT, MERCHANTABILITY, AND FITNESS FOR A
    PARTICULAR PURPOSE, OR ITS INTERACTION WITH MICROCHIP PRODUCTS, COMBINATION
    WITH ANY OTHER PRODUCTS, OR USE IN ANY APPLICATION.

    IN NO EVENT WILL MICROCHIP BE LIABLE FOR ANY INDIRECT, SPECIAL, PUNITIVE,
    INCIDENTAL OR CONSEQUENTIAL LOSS, DAMAGE, COST OR EXPENSE OF ANY KIND
    WHATSOEVER RELATED TO THE SOFTWARE, HOWEVER CAUSED, EVEN IF MICROCHIP HAS
    BEEN ADVISED OF THE POSSIBILITY OR THE DAMAGES ARE FORESEEABLE. TO THE
    FULLEST EXTENT ALLOWED BY LAW, MICROCHIP'S TOTAL LIABILITY ON ALL CLAIMS IN
    ANY WAY RELATED TO THIS SOFTWARE WILL NOT EXCEED THE AMOUNT OF FEES, IF ANY,
    THAT YOU HAVE PAID DIRECTLY TO MICROCHIP FOR THIS SOFTWARE.

    MICROCHIP PROVIDES THIS SOFTWARE CONDITIONALLY UPON YOUR ACCEPTANCE OF THESE
    TERMS.
*/

/**
  Section: Included Files
**/

#include <xc.h>
#include <stdbool.h>
#include "mcc_generated_files/system.h"
#include "mcc_generated_files/pin_manager.h"
#include "mcc_generated_files/X2Cscope/X2Cscope.h"
#include "mcc_generated_files/sccp3_tmr.h"
#include "mcc_generated_files/pwm.h"
#include "mcc_generated_files/adc1.h"
#include "mcc_generated_files/cmp1.h"
#include "mcc_generated_files/tmr1.h"
#include "userparams.h"
#include "button_service.h"

/**
  Section: Variables
**/

bool runMotor = 0;
bool changeDirection = 0;
bool runDirection = 0;

uint16_t appState = 0;
uint16_t hallValue = 1;
int16_t inputReference = 0;
uint16_t desiredDC = 0;
uint16_t arrayIndex = 0;

uint32_t temp;
uint32_t timerValue,pastTimerValue,timerValueDelta;

uint16_t readyRun = 0;
uint16_t startup = 0;
uint16_t dutyCycle; 
uint16_t measuredSpeed;
uint16_t desiredSpeed;

uint32_t motorStallCounter = 0;
uint32_t overcurrentCounter = 0;

OVERTEMP_T faultOverTemp;
MOVING_AVG_SPEED_T movingAvgSpeed;
PI_CONTROLLER_T PI_Input;

/**
  Section: Function Declarations
**/

void InitializePWM(void);
void ADC_ISR(void);
void HALL_ISR(void);
void StateMachine(void);
void RotationSwitchingTable();
void CheckHalUpdatePWM(void);
void SpeedReference(void);
void OpenLoopSpeedController(void);
void PICloseLoopController(void);
void CalcMovingAvgSpeed(int32_t instSpeed);
void InitMovingAvgSpeed(void);
void Init_PIControlParameters(void);
void StartUp(void);
void OverTemperature(void);
void StallDetection(void);
void OverCurrent(void);
void ShutDown(void);
void PWMDisableOutputs(void);
void PWMEnableOutputs(void);

/*
 *  MAIN APPLICATION
 */

/* Function:
    main()
  Summary:
    This routine controls the motor control operations via push buttons.
  Description:
    Initializes the system.
    Starts and stops and changes the drive direction of the motor.
    Indicates changes using LED1 and LED2.
  Precondition:
    None.
  Parameters:
    None
  Returns:
    1
  Remarks:
    None.
 */
int main(void)
{
    SYSTEM_Initialize();
    InitializePWM();
    HALL3_SetInterruptHandler(HALL_ISR);
    ADC1_SetPOT1InterruptHandler(ADC_ISR);
    SCCP3_TMR_Period32BitSet(PERIOD_CONSTANT);
    BoardServiceInit();
    appState = INIT;
    while (1)
    {
        X2CScope_Communicate();
        BoardService();
        
        if(StartStop())
        {
            if(runMotor == 0)
            {
                
                runMotor = 1;
                LED1_SetHigh(); //ON indicator
                LED2_SetHigh(); //Forward Indicator
            }
            else
            {
                runMotor = 0;
                LED1_SetLow(); //OFF indicator
                LED2_SetLow(); //Reverse Indicator
            }
        }
        
        if(ForwardReverse() && changeDirection == 0)
        {
            changeDirection = 1;
            LED2_Toggle(); //Direction Change Indicator
        }
    }
    return 1; 
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
    // Stall Timer Reset
    motorStallCounter = 0;
    
    // Hall State Assignment
    if (HALLSENSOR == 0) 
    {
        hallValue = 1;
    }
    if (HALLSENSOR == 1) 
    {
        hallValue = 2;
    }
    
    // For Measured Speed Calculation
    timerValue = SCCP3_TMR_Counter32BitGet();
    if (timerValue <= pastTimerValue)
    {
        timerValueDelta = PERIOD_CONSTANT - (pastTimerValue - timerValue);
    }
    else
    {
        timerValueDelta = timerValue - pastTimerValue;
    }
    pastTimerValue = timerValue;

    CalcMovingAvgSpeed(timerValueDelta);
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
    X2CScope_Update();
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
            InitMovingAvgSpeed();
            Init_PIControlParameters();
            dutyCycle = 0;
            readyRun = 0;
            appState = CMD_WAIT;
            
        break;

        case CMD_WAIT:  
            if(runMotor == 1)
            {
                RotationSwitchingTable(runDirection);
                CNCONEbits.ON = 1;
                StartUp();
                if(readyRun == 1)
                {
                appState = RUN;
                }
            }

        break;

        case RUN:     
            CheckHalUpdatePWM();
            SpeedReference();
        #ifdef CLOSEDLOOP
            PICloseLoopController();
        #endif

        #ifdef OPENLOOP
            OpenLoopSpeedController(); 
        #endif

        #ifdef  STALL_DETECTION
            StallDetection();
        #endif
    
        #ifdef  OVERTEMPERATURE_DETECTION
            OverTemperature();
        #endif
    
        #ifdef  OVERCURRENT_DETECTION
            OverCurrent();
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
                measuredSpeed = 0;
                desiredSpeed = 0;
                readyRun = 0;
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
            appState = INIT;
            
        break;
    }
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
    if (desiredDC > MAX_DUTYCYCLE)
    {
        dutyCycle = MAX_DUTYCYCLE;
    }
    else if (desiredDC <= MIN_DUTYCYCLE)
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
            if (measuredSpeed > desiredSpeed)
            {
                measuredSpeed = desiredSpeed;
            }
            else
            {
            measuredSpeed = movingAvgSpeed.avg;
            }
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
    StartUp()
  Summary:
    This routine propels the motor into motion with a start up sequence that lasts 200ms.
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
            
void StartUp(void)
{
    TMR1_Start();
    if(IFS0bits.T1IF == 1)
    {
        if(startup == 0)
        {
            PG1IOCONL = 0x3400;
            PG2IOCONL = 0x0000;
            PG2DC = MPER*0.2;
            startup++;
        }
        else if(startup == 1) 
        {
            PG1IOCONL = 0x3400;
            PG2IOCONL = 0x0000;
            PG2DC = MPER*0.4;
            startup++;
        }
        else if(startup == 2) 
        {
            PG1IOCONL = 0x3400;
            PG2IOCONL = 0x0000;
            PG2DC = MPER*0.6;
            startup++;
        }
        else if(startup == 3) 
        {
            PG1IOCONL = 0x3400;
            PG2IOCONL = 0x0000;
            PG2DC = MPER*0.8;
            startup++;
        }
        else if(startup == 4) 
        {
            PG1IOCONL = 0x3400;
            PG2IOCONL = 0x0000;
            PG2DC = MPER*0.8;
            startup++;
        }
        else if(startup == 5) 
        {
            PG1IOCONL = 0x3400;
            PG2IOCONL = 0x0000;
            PG2DC = MPER*0.8;
            startup++;
        }
        else if(startup == 6) 
        {
            PG1IOCONL = 0x3400;
            PG2IOCONL = 0x0000;
            PG2DC = MPER*0.8;
            startup++;
        }
        else if(startup == 7) 
        {
            PG1IOCONL = 0x3400;
            PG2IOCONL = 0x0000;
            PG2DC = MPER*0.8;
            startup++;
        }
        else if(startup == 8) 
        {
            PG1IOCONL = 0x3400;
            PG2IOCONL = 0x0000;
            PG2DC = MPER*0.8;
            startup++;
        }
        else if(startup == 9) 
        {
            PG1IOCONL = 0x3400;
            PG2IOCONL = 0x0000;
            PG2DC = MPER*0.8;
            startup++;
        }
        
        else if(startup == 10) 
        {
            CheckHalUpdatePWM();
            dutyCycle = MPER*0.8;
            PG2DC = dutyCycle;
            PG1DC = dutyCycle;
            startup++;
        }
        else if(startup == 11) 
        {
            CheckHalUpdatePWM();
            dutyCycle = MPER*0.8;
            PG2DC = dutyCycle;
            PG1DC = dutyCycle;
            startup++;
        }
        else if(startup == 12) 
        {
            CheckHalUpdatePWM();
            dutyCycle = MPER*0.8;
            PG2DC = dutyCycle;
            PG1DC = dutyCycle;
            startup++;
        }
        else if(startup == 13) 
        {
            CheckHalUpdatePWM();
            dutyCycle = MPER*0.8;
            PG2DC = dutyCycle;
            PG1DC = dutyCycle;
            startup++;
        }
        else if(startup == 14) 
        {
            CheckHalUpdatePWM();
            dutyCycle = MPER*0.7;
            PG2DC = dutyCycle;
            PG1DC = dutyCycle;
            startup++;
        }
        else if(startup == 15) 
        {
            CheckHalUpdatePWM();
            dutyCycle = MPER*0.6;
            PG2DC = dutyCycle;
            PG1DC = dutyCycle;
            startup++;
        }
        else if(startup == 16) 
        {
            CheckHalUpdatePWM();
            dutyCycle = MPER*0.5;
            PG2DC = dutyCycle;
            PG1DC = dutyCycle;
            startup++;
        }
        else if(startup == 17) 
        {
            CheckHalUpdatePWM();
            dutyCycle = MPER*0.4;
            PG2DC = dutyCycle;
            PG1DC = dutyCycle;
            startup++;
        }
        else if(startup == 18) 
        {
            CheckHalUpdatePWM();
            dutyCycle = MPER*0.3;
            PG2DC = dutyCycle;
            PG1DC = dutyCycle;
            startup++;
        }
        else if(startup == 19)
        {
            CheckHalUpdatePWM();
            dutyCycle = MPER*0.2;
            PG2DC = dutyCycle;
            PG1DC = dutyCycle;
            startup = 0;
            readyRun = 1;
        }
        
        IFS0bits.T1IF = 0;
    }
}

/* Function:
    OverTemperature()
  Summary:
    This routine handles the Overtemperature Detection of the motor.
  Description:
    Shuts down the system when motor runs in maximum operating temperature 
    conditions for a certain time period.
  Precondition:
    None.
  Parameters:
    None
  Returns:
    None.
  Remarks:
    None.
 */
void OverTemperature(void)
{
    faultOverTemp.measure = ADCBUF_DSPICTEMP;
    if(faultOverTemp.measure < OVERTEMP_LIMITER)
    {
        faultOverTemp.counter++;
        if (faultOverTemp.counter > OVERTEMP_COUNTER)
        {
            ShutDown();
            faultOverTemp.counter = 0;
        }
    }
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
       ShutDown();
       motorStallCounter = 0;
    }
}

/* Function:
    OverCurrent()
  Summary:
    This routine handles the Overcurrent Detection of the motor.
  Description:
    Shuts down the system once overcurrent is detected.
  Precondition:
    None.
  Parameters:
    None
  Returns:
    None.
  Remarks:
    None.
 */
void OverCurrent(void)
{
    if (OVERCURRENT_DETECT)
    {
        if (overcurrentCounter > OVERCURRENT_COUNTER)
        {
            ShutDown();
            overcurrentCounter = 0;
        }
        overcurrentCounter++;
    }
}
/* Function:
    ShutDown()
  Summary:
    This routine is the shut down function for motor fault detections.
  Description:
    Stops the motor driving and shuts down the system
  Precondition:
    None.
  Parameters:
    None
  Returns:
    None.
  Remarks:
    None.
 */
void ShutDown()
{
    runMotor = 0;
    appState = STOP;
    LED1_SetLow();
    LED2_SetLow();
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

/**
 End of File
*/