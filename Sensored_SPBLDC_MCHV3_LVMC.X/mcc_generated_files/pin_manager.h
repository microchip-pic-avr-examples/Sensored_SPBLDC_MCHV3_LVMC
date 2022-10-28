/**
  PIN MANAGER Generated Driver File

  @Company:
    Microchip Technology Inc.

  @File Name:
    pin_manager.h

  @Summary:
    This is the generated manager file for the PIC24 / dsPIC33 / PIC32MM MCUs device.  This manager
    configures the pins direction, initial state, analog setting.
    The peripheral pin select, PPS, configuration is also handled by this manager.

  @Description:
    This source file provides implementations for PIN MANAGER.
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

#ifndef _PIN_MANAGER_H
#define _PIN_MANAGER_H
/**
    Section: Includes
*/
#include <xc.h>

/**
    Section: Device Pin Macros
*/
/**
  @Summary
    Sets the GPIO pin, RB9, high using LATB9.

  @Description
    Sets the GPIO pin, RB9, high using LATB9.

  @Preconditions
    The RB9 must be set to an output.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Set RB9 high (1)
    channel_AN11_SetHigh();
    </code>

*/
#define channel_AN11_SetHigh()          (_LATB9 = 1)
/**
  @Summary
    Sets the GPIO pin, RB9, low using LATB9.

  @Description
    Sets the GPIO pin, RB9, low using LATB9.

  @Preconditions
    The RB9 must be set to an output.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Set RB9 low (0)
    channel_AN11_SetLow();
    </code>

*/
#define channel_AN11_SetLow()           (_LATB9 = 0)
/**
  @Summary
    Toggles the GPIO pin, RB9, using LATB9.

  @Description
    Toggles the GPIO pin, RB9, using LATB9.

  @Preconditions
    The RB9 must be set to an output.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Toggle RB9
    channel_AN11_Toggle();
    </code>

*/
#define channel_AN11_Toggle()           (_LATB9 ^= 1)
/**
  @Summary
    Reads the value of the GPIO pin, RB9.

  @Description
    Reads the value of the GPIO pin, RB9.

  @Preconditions
    None.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    uint16_t portValue;

    // Read RB9
    postValue = channel_AN11_GetValue();
    </code>

*/
#define channel_AN11_GetValue()         _RB9
/**
  @Summary
    Configures the GPIO pin, RB9, as an input.

  @Description
    Configures the GPIO pin, RB9, as an input.

  @Preconditions
    None.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Sets the RB9 as an input
    channel_AN11_SetDigitalInput();
    </code>

*/
#define channel_AN11_SetDigitalInput()  (_TRISB9 = 1)
/**
  @Summary
    Configures the GPIO pin, RB9, as an output.

  @Description
    Configures the GPIO pin, RB9, as an output.

  @Preconditions
    None.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Sets the RB9 as an output
    channel_AN11_SetDigitalOutput();
    </code>

*/
#define channel_AN11_SetDigitalOutput() (_TRISB9 = 0)
/**
  @Summary
    Sets the GPIO pin, RC0, high using LATC0.

  @Description
    Sets the GPIO pin, RC0, high using LATC0.

  @Preconditions
    The RC0 must be set to an output.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Set RC0 high (1)
    channel_AN12_SetHigh();
    </code>

*/
#define channel_AN12_SetHigh()          (_LATC0 = 1)
/**
  @Summary
    Sets the GPIO pin, RC0, low using LATC0.

  @Description
    Sets the GPIO pin, RC0, low using LATC0.

  @Preconditions
    The RC0 must be set to an output.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Set RC0 low (0)
    channel_AN12_SetLow();
    </code>

*/
#define channel_AN12_SetLow()           (_LATC0 = 0)
/**
  @Summary
    Toggles the GPIO pin, RC0, using LATC0.

  @Description
    Toggles the GPIO pin, RC0, using LATC0.

  @Preconditions
    The RC0 must be set to an output.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Toggle RC0
    channel_AN12_Toggle();
    </code>

*/
#define channel_AN12_Toggle()           (_LATC0 ^= 1)
/**
  @Summary
    Reads the value of the GPIO pin, RC0.

  @Description
    Reads the value of the GPIO pin, RC0.

  @Preconditions
    None.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    uint16_t portValue;

    // Read RC0
    postValue = channel_AN12_GetValue();
    </code>

*/
#define channel_AN12_GetValue()         _RC0
/**
  @Summary
    Configures the GPIO pin, RC0, as an input.

  @Description
    Configures the GPIO pin, RC0, as an input.

  @Preconditions
    None.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Sets the RC0 as an input
    channel_AN12_SetDigitalInput();
    </code>

*/
#define channel_AN12_SetDigitalInput()  (_TRISC0 = 1)
/**
  @Summary
    Configures the GPIO pin, RC0, as an output.

  @Description
    Configures the GPIO pin, RC0, as an output.

  @Preconditions
    None.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Sets the RC0 as an output
    channel_AN12_SetDigitalOutput();
    </code>

*/
#define channel_AN12_SetDigitalOutput() (_TRISC0 = 0)
/**
  @Summary
    Sets the GPIO pin, RC6, high using LATC6.

  @Description
    Sets the GPIO pin, RC6, high using LATC6.

  @Preconditions
    The RC6 must be set to an output.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Set RC6 high (1)
    channel_AN17_SetHigh();
    </code>

*/
#define channel_AN17_SetHigh()          (_LATC6 = 1)
/**
  @Summary
    Sets the GPIO pin, RC6, low using LATC6.

  @Description
    Sets the GPIO pin, RC6, low using LATC6.

  @Preconditions
    The RC6 must be set to an output.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Set RC6 low (0)
    channel_AN17_SetLow();
    </code>

*/
#define channel_AN17_SetLow()           (_LATC6 = 0)
/**
  @Summary
    Toggles the GPIO pin, RC6, using LATC6.

  @Description
    Toggles the GPIO pin, RC6, using LATC6.

  @Preconditions
    The RC6 must be set to an output.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Toggle RC6
    channel_AN17_Toggle();
    </code>

*/
#define channel_AN17_Toggle()           (_LATC6 ^= 1)
/**
  @Summary
    Reads the value of the GPIO pin, RC6.

  @Description
    Reads the value of the GPIO pin, RC6.

  @Preconditions
    None.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    uint16_t portValue;

    // Read RC6
    postValue = channel_AN17_GetValue();
    </code>

*/
#define channel_AN17_GetValue()         _RC6
/**
  @Summary
    Configures the GPIO pin, RC6, as an input.

  @Description
    Configures the GPIO pin, RC6, as an input.

  @Preconditions
    None.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Sets the RC6 as an input
    channel_AN17_SetDigitalInput();
    </code>

*/
#define channel_AN17_SetDigitalInput()  (_TRISC6 = 1)
/**
  @Summary
    Configures the GPIO pin, RC6, as an output.

  @Description
    Configures the GPIO pin, RC6, as an output.

  @Preconditions
    None.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Sets the RC6 as an output
    channel_AN17_SetDigitalOutput();
    </code>

*/
#define channel_AN17_SetDigitalOutput() (_TRISC6 = 0)
/**
  @Summary
    Sets the GPIO pin, RD1, high using LATD1.

  @Description
    Sets the GPIO pin, RD1, high using LATD1.

  @Preconditions
    The RD1 must be set to an output.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Set RD1 high (1)
    HALL1_SetHigh();
    </code>

*/
#define HALL1_SetHigh()          (_LATD1 = 1)
/**
  @Summary
    Sets the GPIO pin, RD1, low using LATD1.

  @Description
    Sets the GPIO pin, RD1, low using LATD1.

  @Preconditions
    The RD1 must be set to an output.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Set RD1 low (0)
    HALL1_SetLow();
    </code>

*/
#define HALL1_SetLow()           (_LATD1 = 0)
/**
  @Summary
    Toggles the GPIO pin, RD1, using LATD1.

  @Description
    Toggles the GPIO pin, RD1, using LATD1.

  @Preconditions
    The RD1 must be set to an output.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Toggle RD1
    HALL1_Toggle();
    </code>

*/
#define HALL1_Toggle()           (_LATD1 ^= 1)
/**
  @Summary
    Reads the value of the GPIO pin, RD1.

  @Description
    Reads the value of the GPIO pin, RD1.

  @Preconditions
    None.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    uint16_t portValue;

    // Read RD1
    postValue = HALL1_GetValue();
    </code>

*/
#define HALL1_GetValue()         _RD1
/**
  @Summary
    Configures the GPIO pin, RD1, as an input.

  @Description
    Configures the GPIO pin, RD1, as an input.

  @Preconditions
    None.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Sets the RD1 as an input
    HALL1_SetDigitalInput();
    </code>

*/
#define HALL1_SetDigitalInput()  (_TRISD1 = 1)
/**
  @Summary
    Configures the GPIO pin, RD1, as an output.

  @Description
    Configures the GPIO pin, RD1, as an output.

  @Preconditions
    None.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Sets the RD1 as an output
    HALL1_SetDigitalOutput();
    </code>

*/
#define HALL1_SetDigitalOutput() (_TRISD1 = 0)
/**
  @Summary
    Sets the GPIO pin, RD11, high using LATD11.

  @Description
    Sets the GPIO pin, RD11, high using LATD11.

  @Preconditions
    The RD11 must be set to an output.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Set RD11 high (1)
    channel_AN19_SetHigh();
    </code>

*/
#define channel_AN19_SetHigh()          (_LATD11 = 1)
/**
  @Summary
    Sets the GPIO pin, RD11, low using LATD11.

  @Description
    Sets the GPIO pin, RD11, low using LATD11.

  @Preconditions
    The RD11 must be set to an output.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Set RD11 low (0)
    channel_AN19_SetLow();
    </code>

*/
#define channel_AN19_SetLow()           (_LATD11 = 0)
/**
  @Summary
    Toggles the GPIO pin, RD11, using LATD11.

  @Description
    Toggles the GPIO pin, RD11, using LATD11.

  @Preconditions
    The RD11 must be set to an output.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Toggle RD11
    channel_AN19_Toggle();
    </code>

*/
#define channel_AN19_Toggle()           (_LATD11 ^= 1)
/**
  @Summary
    Reads the value of the GPIO pin, RD11.

  @Description
    Reads the value of the GPIO pin, RD11.

  @Preconditions
    None.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    uint16_t portValue;

    // Read RD11
    postValue = channel_AN19_GetValue();
    </code>

*/
#define channel_AN19_GetValue()         _RD11
/**
  @Summary
    Configures the GPIO pin, RD11, as an input.

  @Description
    Configures the GPIO pin, RD11, as an input.

  @Preconditions
    None.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Sets the RD11 as an input
    channel_AN19_SetDigitalInput();
    </code>

*/
#define channel_AN19_SetDigitalInput()  (_TRISD11 = 1)
/**
  @Summary
    Configures the GPIO pin, RD11, as an output.

  @Description
    Configures the GPIO pin, RD11, as an output.

  @Preconditions
    None.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Sets the RD11 as an output
    channel_AN19_SetDigitalOutput();
    </code>

*/
#define channel_AN19_SetDigitalOutput() (_TRISD11 = 0)
/**
  @Summary
    Sets the GPIO pin, RE10, high using LATE10.

  @Description
    Sets the GPIO pin, RE10, high using LATE10.

  @Preconditions
    The RE10 must be set to an output.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Set RE10 high (1)
    HALL3_SetHigh();
    </code>

*/
#define HALL3_SetHigh()          (_LATE10 = 1)
/**
  @Summary
    Sets the GPIO pin, RE10, low using LATE10.

  @Description
    Sets the GPIO pin, RE10, low using LATE10.

  @Preconditions
    The RE10 must be set to an output.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Set RE10 low (0)
    HALL3_SetLow();
    </code>

*/
#define HALL3_SetLow()           (_LATE10 = 0)
/**
  @Summary
    Toggles the GPIO pin, RE10, using LATE10.

  @Description
    Toggles the GPIO pin, RE10, using LATE10.

  @Preconditions
    The RE10 must be set to an output.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Toggle RE10
    HALL3_Toggle();
    </code>

*/
#define HALL3_Toggle()           (_LATE10 ^= 1)
/**
  @Summary
    Reads the value of the GPIO pin, RE10.

  @Description
    Reads the value of the GPIO pin, RE10.

  @Preconditions
    None.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    uint16_t portValue;

    // Read RE10
    postValue = HALL3_GetValue();
    </code>

*/
#define HALL3_GetValue()         _RE10
/**
  @Summary
    Configures the GPIO pin, RE10, as an input.

  @Description
    Configures the GPIO pin, RE10, as an input.

  @Preconditions
    None.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Sets the RE10 as an input
    HALL3_SetDigitalInput();
    </code>

*/
#define HALL3_SetDigitalInput()  (_TRISE10 = 1)
/**
  @Summary
    Configures the GPIO pin, RE10, as an output.

  @Description
    Configures the GPIO pin, RE10, as an output.

  @Preconditions
    None.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Sets the RE10 as an output
    HALL3_SetDigitalOutput();
    </code>

*/
#define HALL3_SetDigitalOutput() (_TRISE10 = 0)
/**
  @Summary
    Sets the GPIO pin, RE11, high using LATE11.

  @Description
    Sets the GPIO pin, RE11, high using LATE11.

  @Preconditions
    The RE11 must be set to an output.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Set RE11 high (1)
    SWITCH1_SetHigh();
    </code>

*/
#define SWITCH1_SetHigh()          (_LATE11 = 1)
/**
  @Summary
    Sets the GPIO pin, RE11, low using LATE11.

  @Description
    Sets the GPIO pin, RE11, low using LATE11.

  @Preconditions
    The RE11 must be set to an output.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Set RE11 low (0)
    SWITCH1_SetLow();
    </code>

*/
#define SWITCH1_SetLow()           (_LATE11 = 0)
/**
  @Summary
    Toggles the GPIO pin, RE11, using LATE11.

  @Description
    Toggles the GPIO pin, RE11, using LATE11.

  @Preconditions
    The RE11 must be set to an output.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Toggle RE11
    SWITCH1_Toggle();
    </code>

*/
#define SWITCH1_Toggle()           (_LATE11 ^= 1)
/**
  @Summary
    Reads the value of the GPIO pin, RE11.

  @Description
    Reads the value of the GPIO pin, RE11.

  @Preconditions
    None.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    uint16_t portValue;

    // Read RE11
    postValue = SWITCH1_GetValue();
    </code>

*/
#define SWITCH1_GetValue()         _RE11
/**
  @Summary
    Configures the GPIO pin, RE11, as an input.

  @Description
    Configures the GPIO pin, RE11, as an input.

  @Preconditions
    None.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Sets the RE11 as an input
    SWITCH1_SetDigitalInput();
    </code>

*/
#define SWITCH1_SetDigitalInput()  (_TRISE11 = 1)
/**
  @Summary
    Configures the GPIO pin, RE11, as an output.

  @Description
    Configures the GPIO pin, RE11, as an output.

  @Preconditions
    None.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Sets the RE11 as an output
    SWITCH1_SetDigitalOutput();
    </code>

*/
#define SWITCH1_SetDigitalOutput() (_TRISE11 = 0)
/**
  @Summary
    Sets the GPIO pin, RE12, high using LATE12.

  @Description
    Sets the GPIO pin, RE12, high using LATE12.

  @Preconditions
    The RE12 must be set to an output.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Set RE12 high (1)
    SWITCH2_SetHigh();
    </code>

*/
#define SWITCH2_SetHigh()          (_LATE12 = 1)
/**
  @Summary
    Sets the GPIO pin, RE12, low using LATE12.

  @Description
    Sets the GPIO pin, RE12, low using LATE12.

  @Preconditions
    The RE12 must be set to an output.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Set RE12 low (0)
    SWITCH2_SetLow();
    </code>

*/
#define SWITCH2_SetLow()           (_LATE12 = 0)
/**
  @Summary
    Toggles the GPIO pin, RE12, using LATE12.

  @Description
    Toggles the GPIO pin, RE12, using LATE12.

  @Preconditions
    The RE12 must be set to an output.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Toggle RE12
    SWITCH2_Toggle();
    </code>

*/
#define SWITCH2_Toggle()           (_LATE12 ^= 1)
/**
  @Summary
    Reads the value of the GPIO pin, RE12.

  @Description
    Reads the value of the GPIO pin, RE12.

  @Preconditions
    None.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    uint16_t portValue;

    // Read RE12
    postValue = SWITCH2_GetValue();
    </code>

*/
#define SWITCH2_GetValue()         _RE12
/**
  @Summary
    Configures the GPIO pin, RE12, as an input.

  @Description
    Configures the GPIO pin, RE12, as an input.

  @Preconditions
    None.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Sets the RE12 as an input
    SWITCH2_SetDigitalInput();
    </code>

*/
#define SWITCH2_SetDigitalInput()  (_TRISE12 = 1)
/**
  @Summary
    Configures the GPIO pin, RE12, as an output.

  @Description
    Configures the GPIO pin, RE12, as an output.

  @Preconditions
    None.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Sets the RE12 as an output
    SWITCH2_SetDigitalOutput();
    </code>

*/
#define SWITCH2_SetDigitalOutput() (_TRISE12 = 0)
/**
  @Summary
    Sets the GPIO pin, RE3, high using LATE3.

  @Description
    Sets the GPIO pin, RE3, high using LATE3.

  @Preconditions
    The RE3 must be set to an output.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Set RE3 high (1)
    channel_AN23_SetHigh();
    </code>

*/
#define channel_AN23_SetHigh()          (_LATE3 = 1)
/**
  @Summary
    Sets the GPIO pin, RE3, low using LATE3.

  @Description
    Sets the GPIO pin, RE3, low using LATE3.

  @Preconditions
    The RE3 must be set to an output.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Set RE3 low (0)
    channel_AN23_SetLow();
    </code>

*/
#define channel_AN23_SetLow()           (_LATE3 = 0)
/**
  @Summary
    Toggles the GPIO pin, RE3, using LATE3.

  @Description
    Toggles the GPIO pin, RE3, using LATE3.

  @Preconditions
    The RE3 must be set to an output.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Toggle RE3
    channel_AN23_Toggle();
    </code>

*/
#define channel_AN23_Toggle()           (_LATE3 ^= 1)
/**
  @Summary
    Reads the value of the GPIO pin, RE3.

  @Description
    Reads the value of the GPIO pin, RE3.

  @Preconditions
    None.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    uint16_t portValue;

    // Read RE3
    postValue = channel_AN23_GetValue();
    </code>

*/
#define channel_AN23_GetValue()         _RE3
/**
  @Summary
    Configures the GPIO pin, RE3, as an input.

  @Description
    Configures the GPIO pin, RE3, as an input.

  @Preconditions
    None.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Sets the RE3 as an input
    channel_AN23_SetDigitalInput();
    </code>

*/
#define channel_AN23_SetDigitalInput()  (_TRISE3 = 1)
/**
  @Summary
    Configures the GPIO pin, RE3, as an output.

  @Description
    Configures the GPIO pin, RE3, as an output.

  @Preconditions
    None.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Sets the RE3 as an output
    channel_AN23_SetDigitalOutput();
    </code>

*/
#define channel_AN23_SetDigitalOutput() (_TRISE3 = 0)
/**
  @Summary
    Sets the GPIO pin, RE5, high using LATE5.

  @Description
    Sets the GPIO pin, RE5, high using LATE5.

  @Preconditions
    The RE5 must be set to an output.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Set RE5 high (1)
    S1_SetHigh();
    </code>

*/
#define S1_SetHigh()          (_LATE5 = 1)
/**
  @Summary
    Sets the GPIO pin, RE5, low using LATE5.

  @Description
    Sets the GPIO pin, RE5, low using LATE5.

  @Preconditions
    The RE5 must be set to an output.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Set RE5 low (0)
    S1_SetLow();
    </code>

*/
#define S1_SetLow()           (_LATE5 = 0)
/**
  @Summary
    Toggles the GPIO pin, RE5, using LATE5.

  @Description
    Toggles the GPIO pin, RE5, using LATE5.

  @Preconditions
    The RE5 must be set to an output.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Toggle RE5
    S1_Toggle();
    </code>

*/
#define S1_Toggle()           (_LATE5 ^= 1)
/**
  @Summary
    Reads the value of the GPIO pin, RE5.

  @Description
    Reads the value of the GPIO pin, RE5.

  @Preconditions
    None.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    uint16_t portValue;

    // Read RE5
    postValue = S1_GetValue();
    </code>

*/
#define S1_GetValue()         _RE5
/**
  @Summary
    Configures the GPIO pin, RE5, as an input.

  @Description
    Configures the GPIO pin, RE5, as an input.

  @Preconditions
    None.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Sets the RE5 as an input
    S1_SetDigitalInput();
    </code>

*/
#define S1_SetDigitalInput()  (_TRISE5 = 1)
/**
  @Summary
    Configures the GPIO pin, RE5, as an output.

  @Description
    Configures the GPIO pin, RE5, as an output.

  @Preconditions
    None.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Sets the RE5 as an output
    S1_SetDigitalOutput();
    </code>

*/
#define S1_SetDigitalOutput() (_TRISE5 = 0)
/**
  @Summary
    Sets the GPIO pin, RE6, high using LATE6.

  @Description
    Sets the GPIO pin, RE6, high using LATE6.

  @Preconditions
    The RE6 must be set to an output.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Set RE6 high (1)
    LED1_SetHigh();
    </code>

*/
#define LED1_SetHigh()          (_LATE6 = 1)
/**
  @Summary
    Sets the GPIO pin, RE6, low using LATE6.

  @Description
    Sets the GPIO pin, RE6, low using LATE6.

  @Preconditions
    The RE6 must be set to an output.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Set RE6 low (0)
    LED1_SetLow();
    </code>

*/
#define LED1_SetLow()           (_LATE6 = 0)
/**
  @Summary
    Toggles the GPIO pin, RE6, using LATE6.

  @Description
    Toggles the GPIO pin, RE6, using LATE6.

  @Preconditions
    The RE6 must be set to an output.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Toggle RE6
    LED1_Toggle();
    </code>

*/
#define LED1_Toggle()           (_LATE6 ^= 1)
/**
  @Summary
    Reads the value of the GPIO pin, RE6.

  @Description
    Reads the value of the GPIO pin, RE6.

  @Preconditions
    None.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    uint16_t portValue;

    // Read RE6
    postValue = LED1_GetValue();
    </code>

*/
#define LED1_GetValue()         _RE6
/**
  @Summary
    Configures the GPIO pin, RE6, as an input.

  @Description
    Configures the GPIO pin, RE6, as an input.

  @Preconditions
    None.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Sets the RE6 as an input
    LED1_SetDigitalInput();
    </code>

*/
#define LED1_SetDigitalInput()  (_TRISE6 = 1)
/**
  @Summary
    Configures the GPIO pin, RE6, as an output.

  @Description
    Configures the GPIO pin, RE6, as an output.

  @Preconditions
    None.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Sets the RE6 as an output
    LED1_SetDigitalOutput();
    </code>

*/
#define LED1_SetDigitalOutput() (_TRISE6 = 0)
/**
  @Summary
    Sets the GPIO pin, RE7, high using LATE7.

  @Description
    Sets the GPIO pin, RE7, high using LATE7.

  @Preconditions
    The RE7 must be set to an output.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Set RE7 high (1)
    LED2_SetHigh();
    </code>

*/
#define LED2_SetHigh()          (_LATE7 = 1)
/**
  @Summary
    Sets the GPIO pin, RE7, low using LATE7.

  @Description
    Sets the GPIO pin, RE7, low using LATE7.

  @Preconditions
    The RE7 must be set to an output.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Set RE7 low (0)
    LED2_SetLow();
    </code>

*/
#define LED2_SetLow()           (_LATE7 = 0)
/**
  @Summary
    Toggles the GPIO pin, RE7, using LATE7.

  @Description
    Toggles the GPIO pin, RE7, using LATE7.

  @Preconditions
    The RE7 must be set to an output.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Toggle RE7
    LED2_Toggle();
    </code>

*/
#define LED2_Toggle()           (_LATE7 ^= 1)
/**
  @Summary
    Reads the value of the GPIO pin, RE7.

  @Description
    Reads the value of the GPIO pin, RE7.

  @Preconditions
    None.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    uint16_t portValue;

    // Read RE7
    postValue = LED2_GetValue();
    </code>

*/
#define LED2_GetValue()         _RE7
/**
  @Summary
    Configures the GPIO pin, RE7, as an input.

  @Description
    Configures the GPIO pin, RE7, as an input.

  @Preconditions
    None.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Sets the RE7 as an input
    LED2_SetDigitalInput();
    </code>

*/
#define LED2_SetDigitalInput()  (_TRISE7 = 1)
/**
  @Summary
    Configures the GPIO pin, RE7, as an output.

  @Description
    Configures the GPIO pin, RE7, as an output.

  @Preconditions
    None.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Sets the RE7 as an output
    LED2_SetDigitalOutput();
    </code>

*/
#define LED2_SetDigitalOutput() (_TRISE7 = 0)
/**
  @Summary
    Sets the GPIO pin, RE8, high using LATE8.

  @Description
    Sets the GPIO pin, RE8, high using LATE8.

  @Preconditions
    The RE8 must be set to an output.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Set RE8 high (1)
    DBG_LED1_SetHigh();
    </code>

*/
#define DBG_LED1_SetHigh()          (_LATE8 = 1)
/**
  @Summary
    Sets the GPIO pin, RE8, low using LATE8.

  @Description
    Sets the GPIO pin, RE8, low using LATE8.

  @Preconditions
    The RE8 must be set to an output.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Set RE8 low (0)
    DBG_LED1_SetLow();
    </code>

*/
#define DBG_LED1_SetLow()           (_LATE8 = 0)
/**
  @Summary
    Toggles the GPIO pin, RE8, using LATE8.

  @Description
    Toggles the GPIO pin, RE8, using LATE8.

  @Preconditions
    The RE8 must be set to an output.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Toggle RE8
    DBG_LED1_Toggle();
    </code>

*/
#define DBG_LED1_Toggle()           (_LATE8 ^= 1)
/**
  @Summary
    Reads the value of the GPIO pin, RE8.

  @Description
    Reads the value of the GPIO pin, RE8.

  @Preconditions
    None.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    uint16_t portValue;

    // Read RE8
    postValue = DBG_LED1_GetValue();
    </code>

*/
#define DBG_LED1_GetValue()         _RE8
/**
  @Summary
    Configures the GPIO pin, RE8, as an input.

  @Description
    Configures the GPIO pin, RE8, as an input.

  @Preconditions
    None.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Sets the RE8 as an input
    DBG_LED1_SetDigitalInput();
    </code>

*/
#define DBG_LED1_SetDigitalInput()  (_TRISE8 = 1)
/**
  @Summary
    Configures the GPIO pin, RE8, as an output.

  @Description
    Configures the GPIO pin, RE8, as an output.

  @Preconditions
    None.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Sets the RE8 as an output
    DBG_LED1_SetDigitalOutput();
    </code>

*/
#define DBG_LED1_SetDigitalOutput() (_TRISE8 = 0)
/**
  @Summary
    Sets the GPIO pin, RE9, high using LATE9.

  @Description
    Sets the GPIO pin, RE9, high using LATE9.

  @Preconditions
    The RE9 must be set to an output.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Set RE9 high (1)
    DBG_LED2_SetHigh();
    </code>

*/
#define DBG_LED2_SetHigh()          (_LATE9 = 1)
/**
  @Summary
    Sets the GPIO pin, RE9, low using LATE9.

  @Description
    Sets the GPIO pin, RE9, low using LATE9.

  @Preconditions
    The RE9 must be set to an output.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Set RE9 low (0)
    DBG_LED2_SetLow();
    </code>

*/
#define DBG_LED2_SetLow()           (_LATE9 = 0)
/**
  @Summary
    Toggles the GPIO pin, RE9, using LATE9.

  @Description
    Toggles the GPIO pin, RE9, using LATE9.

  @Preconditions
    The RE9 must be set to an output.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Toggle RE9
    DBG_LED2_Toggle();
    </code>

*/
#define DBG_LED2_Toggle()           (_LATE9 ^= 1)
/**
  @Summary
    Reads the value of the GPIO pin, RE9.

  @Description
    Reads the value of the GPIO pin, RE9.

  @Preconditions
    None.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    uint16_t portValue;

    // Read RE9
    postValue = DBG_LED2_GetValue();
    </code>

*/
#define DBG_LED2_GetValue()         _RE9
/**
  @Summary
    Configures the GPIO pin, RE9, as an input.

  @Description
    Configures the GPIO pin, RE9, as an input.

  @Preconditions
    None.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Sets the RE9 as an input
    DBG_LED2_SetDigitalInput();
    </code>

*/
#define DBG_LED2_SetDigitalInput()  (_TRISE9 = 1)
/**
  @Summary
    Configures the GPIO pin, RE9, as an output.

  @Description
    Configures the GPIO pin, RE9, as an output.

  @Preconditions
    None.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Sets the RE9 as an output
    DBG_LED2_SetDigitalOutput();
    </code>

*/
#define DBG_LED2_SetDigitalOutput() (_TRISE9 = 0)

/**
    Section: Function Prototypes
*/
/**
  @Summary
    Configures the pin settings of the dsPIC33CK256MP508
    The peripheral pin select, PPS, configuration is also handled by this manager.

  @Description
    This is the generated manager file for the PIC24 / dsPIC33 / PIC32MM MCUs device.  This manager
    configures the pins direction, initial state, analog setting.
    The peripheral pin select, PPS, configuration is also handled by this manager.

  @Preconditions
    None.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    void SYSTEM_Initialize(void)
    {
        // Other initializers are called from this function
        PIN_MANAGER_Initialize();
    }
    </code>

*/
void PIN_MANAGER_Initialize (void);

/**
  @Summary
    Callback for HALL1 Pin.

  @Description
    This routine is callback for HALL1 Pin

  @Param
    None.

  @Returns
    None
 
 
  @Example 
    <code>
        HALL1_SetInterruptHandler(&HALL1_CallBack);
    </code>
*/
void HALL1_CallBack(void);

/**
  @Summary
    Callback for HALL3 Pin.

  @Description
    This routine is callback for HALL3 Pin

  @Param
    None.

  @Returns
    None
 
 
  @Example 
    <code>
        HALL3_SetInterruptHandler(&HALL3_CallBack);
    </code>
*/
void HALL3_CallBack(void);


/**
  @Summary
    Assigns a function pointer with a callback address.

  @Description
    This routine assigns a function pointer with a callback address.

  @Param
    Address of the callback routine.

  @Returns
    None
 
  @Example 
    <code>
        HALL1_SetInterruptHandler(&HALL1_CallBack);
    </code>
*/
void HALL1_SetInterruptHandler(void (* InterruptHandler)(void));

/**
  @Summary
    Assigns a function pointer with a callback address.

  @Description
    This routine assigns a function pointer with a callback address.

  @Param
    Address of the callback routine.

  @Returns
    None
 
  @Example 
    <code>
        HALL1_SetIOCInterruptHandler(&HALL1_CallBack);
    </code>
*/
void __attribute__((deprecated("\nThis will be removed in future MCC releases. \nUse HALL1_SetInterruptHandler instead."))) HALL1_SetIOCInterruptHandler(void *handler);

/**
  @Summary
    Assigns a function pointer with a callback address.

  @Description
    This routine assigns a function pointer with a callback address.

  @Param
    Address of the callback routine.

  @Returns
    None
 
  @Example 
    <code>
        HALL3_SetInterruptHandler(&HALL3_CallBack);
    </code>
*/
void HALL3_SetInterruptHandler(void (* InterruptHandler)(void));

/**
  @Summary
    Assigns a function pointer with a callback address.

  @Description
    This routine assigns a function pointer with a callback address.

  @Param
    Address of the callback routine.

  @Returns
    None
 
  @Example 
    <code>
        HALL3_SetIOCInterruptHandler(&HALL3_CallBack);
    </code>
*/
void __attribute__((deprecated("\nThis will be removed in future MCC releases. \nUse HALL3_SetInterruptHandler instead."))) HALL3_SetIOCInterruptHandler(void *handler);


#endif
