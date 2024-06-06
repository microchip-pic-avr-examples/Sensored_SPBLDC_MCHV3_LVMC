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
        Product Revision  :  PIC24 / dsPIC33 / PIC32MM MCUs - 1.171.4
        Device            :  dsPIC33CK256MP508
    The generated drivers are tested against the following:
        Compiler          :  XC16 v2.10
        MPLAB 	          :  MPLAB X v6.05
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
*/
#include "mcc_generated_files/system.h"
#include "userparams.h"
/*
                         Main application
 */
int main(void)
{
    SYSTEM_Initialize(); //initializes peripherals
    InitializePWM(); //initializes PWM
    SCCP3_TMR_Period32BitSet(PERIOD_CONSTANT); //initializes timer for speed calculation
    HALL_A_SetInterruptHandler(HALL_ISR); //sets hall interrupt
    ADC1_SetMCHV3_MCLV2_POTENTIOMETERInterruptHandler(ADC_ISR); //sets adc interrupt for potentiometer
    MCHV3_MCLV2_LED2_SetHigh(); //power on led
    appState = INIT; //sets state machine at initialize
    while (1)
    {
        X2Cscope_Communicate();
        BoardService();
        
        if(StartStop()) //board switch state
        {
            if(runMotor == 0) 
            {
                runMotor = 1; //ON state
                MCHV3_MCLV2_LED1_SetHigh();
            }
            else
            {
                runMotor = 0; //OFF state
                MCHV3_MCLV2_LED1_SetLow();
            }
        }
    }
    return 1; 
}




/**
 End of File
*/

