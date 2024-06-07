/*******************************************************************************
 *  User-defined Parameters for Sensored Single Phase BLDCM Constants, Sequence 
 *  and Routine Header File
 * 
 *  File Name:
 *    userparams.h
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
#ifndef USERPARAMS_H
#define	USERPARAMS_H

// *****************************************************************************
// Section: Included Files
// *****************************************************************************
#include <stdint.h>
#include "mcc_generated_files/X2Cscope/X2Cscope.h"
#include "motor_control/motor_control_declarations.h"
#include "motor_control/motor_control_types.h"
#include "mcc_generated_files/pin_manager.h"
#include "mcc_generated_files/sccp3_tmr.h"
#include "mcc_generated_files/tmr1.h"
#include "mcc_generated_files/adc1.h"
#include "mcc_generated_files/cmp1.h"
#include "button_service.h"
/**
  Section: Function Declarations
**/

void InitializePWM(void);
void ADC_ISR(void);
void HALL_ISR(void);
void StateMachine(void);
void RotationSwitchingTable();
void CheckHalUpdatePWM(void);
void PWMDisableOutputs(void);
void PWMEnableOutputs(void);

void SpeedReference(void);
void OpenLoopSpeedController(void);
void PICloseLoopController(void);

void CalcMovingAvgSpeed(int32_t instSpeed);
void InitMovingAvgSpeed(void);
void Init_PIControlParameters(void);

void OverTemperature(void);
void StallDetection(void);
/**
  Section: User-defined parameters
**/

// *****************************************************************************
// Section: LOOP CONTROLLER
// *****************************************************************************  
/* Instruction:
 * Default Loop Controller is in Closed Loop mode.
 * Comment out the following line to run the motor in Open Loop mode. */
#define CLOSEDLOOP
//#define OPENLOOP

// *****************************************************************************
// Section: STALL DETECTION SET
// *****************************************************************************  
/* Instruction:
 * Stall detection is ENABLED by DEFAULT
 * Comment out STALL_DETECTION to DISABLE stall detection. */
#define STALL_DETECTION

// *****************************************************************************
// Section: OVERCURRENT DETECTION SET
// *****************************************************************************  
/* Instruction:
 * Overcurrent detection is ENABLED by default
 * Comment out the following line to DISABLE overcurrent detection. */
#define OVERCURRENT_DETECTION_ENABLE 1

// *****************************************************************************
// Section: Motor Ratings (from Name Plate Details or Datasheet)
// *****************************************************************************  
/* Instruction:
 * Use the parameters of the motor to be used */
#define POLEPAIRS		    2      // Number of pole pairs    
#define POLES               4      // Number of poles 

// *****************************************************************************
// Section: Open and Closed Loop Speed Limit
// *****************************************************************************  
/* Instruction:
 * Check Minimum and Nominal Speed of the Motor */
#define MAX_CL_MOTORSPEED   3000   // Specify the nominal speed of motor

#define MIN_OL_MOTORSPEED   500    // Recommendation: 500RPM or higher
#define MIN_CL_MOTORSPEED   500    // Recommendation: 500RPM or higher

// *****************************************************************************
// Section: Bus Voltage and Duty Cycle
// *****************************************************************************  
/* Instruction:
 * Change ONLY IF supply for board is greater than the required voltage for motor 
 * Please use appropriate board and supply */
#define BUS_VOLTAGE               (float)(300) //MCHV3 Board typical bus voltage
#define MAX_DUTYCYCLE             (MPER*0.9)      //Specify maximum duty cycle for PWM
#define MIN_DUTYCYCLE             (MPER*0.1)      //Specify minimum duty cycle for PWM

// (DO NOT EDIT BEYOND THIS LINE)
// *****************************************************************************
// Section: Parameters and Calculations
// *****************************************************************************
/* Potentiometer (Speed Reference - AN19) */
#define ADCBUF_POTENTIOMETER        ADCBUF19
/* Hall Sensor (HALL3 - RD1) */
#define HALLSENSOR                  HALL_A_GetValue()
// Instruction cycle frequency (Hz) - 100,000,000 Hz
#define FCY                         100000000UL
// PWM frequency (Hz) - 20kHz
#define PWM_FREQ_HZ                 20000
//Converting to 1.15 Numerical Format
#define Q15(Float_Value)	\
((Float_Value < 0.0) ? (int16_t)(32768 * (Float_Value) - 0.5) \
: (int16_t)(32767 * (Float_Value) + 0.5))
// SCCP Timer Period - 2^16
#define MAX_TMR_COUNT               65535
// SCCP Timer Prescaler - 1:64
#define TIMER_PRESCALER             64
// SCCP Period Calculation
// Period = (FCY / TIMER_PRESCALE) / (RPM * NO_POLEPAIRS )/10
#define MAXPERIOD                   (unsigned long)(((float)FCY / (float)TIMER_PRESCALER) / (float)((MIN_OL_MOTORSPEED * POLEPAIRS)/10))	
#define MINPERIOD                   (unsigned long)(((float)FCY / (float)TIMER_PRESCALER) / (float)((MAX_CL_MOTORSPEED * POLEPAIRS)/10))
//Maximum number of ticks in lowest speed for the counter used
#define PERIOD_CONSTANT             (unsigned long)((float)MAXPERIOD *(float)MIN_OL_MOTORSPEED) 
// Speed to be reduced in rpm before reversing the direction
#define REVERSE_DROP_SPEED          800   
/** Constants for Mathematical Computation */
#define TICKS                       FCY/(TIMER_PRESCALER)
/**  SPEED MULTIPLIER CALCULATION = ((FCY*60)/(TIMER_PRESCALER*POLEPAIRS))  */
#define SPEED_MULTI                 (unsigned long)(((float)FCY/(float)(TIMER_PRESCALER*POLES))*(float)60) //23437500
#define REV_SPEED_LIMIT             (unsigned long) ((float)(SPEED_MULTI)/(float)(REVERSE_DROP_SPEED*2))
/** Moving Average - No of Samples*/
#define SPEED_MOVING_AVG_FILTER_SCALE      4
#define SPEED_MOVING_AVG_FILTER_SIZE       (uint16_t)(1 << SPEED_MOVING_AVG_FILTER_SCALE) 
/* Start Up */
#define REPOSITION_STARTUP_STEP_VOLTAGE     (float)(20) //enough to reposition motor
#define DRAWBACK_STARTUP_STEP_VOLTAGE       (float)(16) //enough to draw back motor
#define PROPEL_STARTUP_STEP_VOLTAGE         (float)(23) //enough to propel motor to right direction
#define PWM_MASTER_PERIOD                   (float)(4999)
//#define REPOSITION_STARTUP_STEP             (unsigned long int)(((float)(REPOSITION_STARTUP_STEP_VOLTAGE/BUS_VOLTAGE ))*(PWM_MASTER_PERIOD)+0.5) // ( 20V /  300V ) * 4999 = 333
//#define DRAWBACK_STARTUP_STEP               (unsigned long int)(((float)(DRAWBACK_STARTUP_STEP_VOLTAGE/BUS_VOLTAGE ))*(PWM_MASTER_PERIOD)+0.5) // ( 16V /  300V ) * 4999 = 266
//#define PROPEL_STARTUP_STEP                 (unsigned long int)(((float)(PROPEL_STARTUP_STEP_VOLTAGE/BUS_VOLTAGE ))*(PWM_MASTER_PERIOD)+0.5) // ( 25V /  300V ) * 4999 = 416

#define REPOSITION_MULTIPLIER             (unsigned long int)(REPOSITION_STARTUP_STEP_VOLTAGE*PWM_MASTER_PERIOD) // ( 20V /  300V ) * 4999 = 333
#define DRAWBACK_MULTIPLIER               (unsigned long int)(DRAWBACK_STARTUP_STEP_VOLTAGE*PWM_MASTER_PERIOD) // ( 16V /  300V ) * 4999 = 266
#define PROPEL_MULTIPLIER                 (unsigned long int)(PROPEL_STARTUP_STEP_VOLTAGE*PWM_MASTER_PERIOD) // ( 25V /  300V ) * 4999 = 416

#define REPOSITION_STARTUP_STEP             REPOSITION_MULTIPLIER/BUS_VOLTAGE
#define DRAWBACK_STARTUP_STEP               DRAWBACK_MULTIPLIER/BUS_VOLTAGE
#define PROPEL_STARTUP_STEP                 PROPEL_MULTIPLIER/BUS_VOLTAGE
// *****************************************************************************
// Section: Fault Detection
// *****************************************************************************
/* Constants for Motor Stall Detection */
#define STALL_COUNT_LIMIT               30000 // within 2 seconds
/* Constants For Overcurrent Protection */
#define OVERCURRENT_COUNTER_DELAY       150
#define OVERCURRENT_DETECT_FLAG         DAC1CONLbits.CMPSTAT
#define OVERCURRENT_DETECTION_LIMIT     0xAB9 // 0x8BB = 1.5A for MCHV3 using external op amp config
#define OVERCURRENT_DETECTION_DEFINE    0

// *****************************************************************************
// Section: PI Velocity Control Loop Coefficients
// *****************************************************************************
#define SPEEDCNTR_PTERM        Q15(0.9999)
#define SPEEDCNTR_ITERM        Q15(0.0009)
#define SPEEDCNTR_CTERM        Q15(0.9999)
#define SPEEDCNTR_OUTMAX       Q15(0.9999)
#define SPEEDCNTR_OUTMIN       Q15(0.0)

// *****************************************************************************

// *****************************************************************************
// Section: Single Phase Sequence
// *****************************************************************************
const uint16_t PWM_STATE1_CLKW[4] = {0x3000, 0x0000, 0x3400, 0x3000};
const uint16_t PWM_STATE2_CLKW[4] = {0x3000, 0x3400, 0x0000, 0x3000};
uint16_t PWM_STATE1[4];
uint16_t PWM_STATE2[4];

// *****************************************************************************
// Section: Enums, Structures
// *****************************************************************************
typedef struct {
    uint32_t speedAcc;
    int32_t calculatedSpeed;
    uint32_t speedValue;
    uint16_t index;
    int16_t buffer[SPEED_MOVING_AVG_FILTER_SIZE];
    int32_t sum;
    int16_t avg;
} MOVING_AVG_SPEED_T;

typedef struct {
    MC_PIPARMIN_T piSpeedCalculation;
    MC_PIPARMOUT_T piOutputSpeed;
} PI_CONTROLLER_T;

typedef struct
{
    uint8_t overcurrent_detected;
    uint8_t stall_detected;
} FAULT_T;

typedef enum
{
    INIT             = 0,         /* Initialize Run time parameters */
    CMD_WAIT         = 1,         /* Wait for Run command */
    RUN              = 2,         /* Run the motor */
    CHANGE_DIRECTION = 3,         /* Change motor running direction */
    STOP             = 4,         /* Stop the motor */
} STATE_T;

bool runMotor = 0;
bool changeDirection = 0;
bool runDirection = 0;

uint16_t readyStartUp = 0;
uint16_t readyRun=0;
uint16_t startup=0;

uint16_t appState = 0;
uint16_t hallValue = 1;
int16_t inputReference = 0;
uint16_t desiredDC = 0;

uint32_t temp;
uint32_t timerValue,pastTimerValue,timerValueDelta;

uint16_t dutyCycle; 
uint16_t measuredSpeed;
uint16_t desiredSpeed;

uint32_t motorStallCounter = 0;

uint32_t overcurrentCounter = 0;
uint16_t cmp1, overcurrent_enable_flag;

MOVING_AVG_SPEED_T movingAvgSpeed;
PI_CONTROLLER_T PI_Input;

FAULT_T faultDetected;

#endif	/** USERPARAMS_H */

/*
 End of File
*/