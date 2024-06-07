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
    LVMC_POTENTIOMETER_SetHigh();
    </code>

*/
#define LVMC_POTENTIOMETER_SetHigh()          (_LATB9 = 1)
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
    LVMC_POTENTIOMETER_SetLow();
    </code>

*/
#define LVMC_POTENTIOMETER_SetLow()           (_LATB9 = 0)
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
    LVMC_POTENTIOMETER_Toggle();
    </code>

*/
#define LVMC_POTENTIOMETER_Toggle()           (_LATB9 ^= 1)
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
    postValue = LVMC_POTENTIOMETER_GetValue();
    </code>

*/
#define LVMC_POTENTIOMETER_GetValue()         _RB9
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
    LVMC_POTENTIOMETER_SetDigitalInput();
    </code>

*/
#define LVMC_POTENTIOMETER_SetDigitalInput()  (_TRISB9 = 1)
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
    LVMC_POTENTIOMETER_SetDigitalOutput();
    </code>

*/
#define LVMC_POTENTIOMETER_SetDigitalOutput() (_TRISB9 = 0)
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
    LVMC_TEMP_SetHigh();
    </code>

*/
#define LVMC_TEMP_SetHigh()          (_LATC0 = 1)
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
    LVMC_TEMP_SetLow();
    </code>

*/
#define LVMC_TEMP_SetLow()           (_LATC0 = 0)
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
    LVMC_TEMP_Toggle();
    </code>

*/
#define LVMC_TEMP_Toggle()           (_LATC0 ^= 1)
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
    postValue = LVMC_TEMP_GetValue();
    </code>

*/
#define LVMC_TEMP_GetValue()         _RC0
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
    LVMC_TEMP_SetDigitalInput();
    </code>

*/
#define LVMC_TEMP_SetDigitalInput()  (_TRISC0 = 1)
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
    LVMC_TEMP_SetDigitalOutput();
    </code>

*/
#define LVMC_TEMP_SetDigitalOutput() (_TRISC0 = 0)
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
    LVMC_VA_SetHigh();
    </code>

*/
#define LVMC_VA_SetHigh()          (_LATC6 = 1)
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
    LVMC_VA_SetLow();
    </code>

*/
#define LVMC_VA_SetLow()           (_LATC6 = 0)
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
    LVMC_VA_Toggle();
    </code>

*/
#define LVMC_VA_Toggle()           (_LATC6 ^= 1)
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
    postValue = LVMC_VA_GetValue();
    </code>

*/
#define LVMC_VA_GetValue()         _RC6
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
    LVMC_VA_SetDigitalInput();
    </code>

*/
#define LVMC_VA_SetDigitalInput()  (_TRISC6 = 1)
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
    LVMC_VA_SetDigitalOutput();
    </code>

*/
#define LVMC_VA_SetDigitalOutput() (_TRISC6 = 0)
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
    LVMC_S1_SetHigh();
    </code>

*/
#define LVMC_S1_SetHigh()          (_LATE11 = 1)
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
    LVMC_S1_SetLow();
    </code>

*/
#define LVMC_S1_SetLow()           (_LATE11 = 0)
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
    LVMC_S1_Toggle();
    </code>

*/
#define LVMC_S1_Toggle()           (_LATE11 ^= 1)
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
    postValue = LVMC_S1_GetValue();
    </code>

*/
#define LVMC_S1_GetValue()         _RE11
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
    LVMC_S1_SetDigitalInput();
    </code>

*/
#define LVMC_S1_SetDigitalInput()  (_TRISE11 = 1)
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
    LVMC_S1_SetDigitalOutput();
    </code>

*/
#define LVMC_S1_SetDigitalOutput() (_TRISE11 = 0)
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
    LVMC_S2_SetHigh();
    </code>

*/
#define LVMC_S2_SetHigh()          (_LATE12 = 1)
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
    LVMC_S2_SetLow();
    </code>

*/
#define LVMC_S2_SetLow()           (_LATE12 = 0)
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
    LVMC_S2_Toggle();
    </code>

*/
#define LVMC_S2_Toggle()           (_LATE12 ^= 1)
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
    postValue = LVMC_S2_GetValue();
    </code>

*/
#define LVMC_S2_GetValue()         _RE12
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
    LVMC_S2_SetDigitalInput();
    </code>

*/
#define LVMC_S2_SetDigitalInput()  (_TRISE12 = 1)
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
    LVMC_S2_SetDigitalOutput();
    </code>

*/
#define LVMC_S2_SetDigitalOutput() (_TRISE12 = 0)
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
    LVMC_VB_SetHigh();
    </code>

*/
#define LVMC_VB_SetHigh()          (_LATE3 = 1)
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
    LVMC_VB_SetLow();
    </code>

*/
#define LVMC_VB_SetLow()           (_LATE3 = 0)
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
    LVMC_VB_Toggle();
    </code>

*/
#define LVMC_VB_Toggle()           (_LATE3 ^= 1)
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
    postValue = LVMC_VB_GetValue();
    </code>

*/
#define LVMC_VB_GetValue()         _RE3
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
    LVMC_VB_SetDigitalInput();
    </code>

*/
#define LVMC_VB_SetDigitalInput()  (_TRISE3 = 1)
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
    LVMC_VB_SetDigitalOutput();
    </code>

*/
#define LVMC_VB_SetDigitalOutput() (_TRISE3 = 0)
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
    LVMC_LED1_SetHigh();
    </code>

*/
#define LVMC_LED1_SetHigh()          (_LATE6 = 1)
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
    LVMC_LED1_SetLow();
    </code>

*/
#define LVMC_LED1_SetLow()           (_LATE6 = 0)
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
    LVMC_LED1_Toggle();
    </code>

*/
#define LVMC_LED1_Toggle()           (_LATE6 ^= 1)
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
    postValue = LVMC_LED1_GetValue();
    </code>

*/
#define LVMC_LED1_GetValue()         _RE6
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
    LVMC_LED1_SetDigitalInput();
    </code>

*/
#define LVMC_LED1_SetDigitalInput()  (_TRISE6 = 1)
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
    LVMC_LED1_SetDigitalOutput();
    </code>

*/
#define LVMC_LED1_SetDigitalOutput() (_TRISE6 = 0)
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
    LVMC_LED2_SetHigh();
    </code>

*/
#define LVMC_LED2_SetHigh()          (_LATE7 = 1)
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
    LVMC_LED2_SetLow();
    </code>

*/
#define LVMC_LED2_SetLow()           (_LATE7 = 0)
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
    LVMC_LED2_Toggle();
    </code>

*/
#define LVMC_LED2_Toggle()           (_LATE7 ^= 1)
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
    postValue = LVMC_LED2_GetValue();
    </code>

*/
#define LVMC_LED2_GetValue()         _RE7
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
    LVMC_LED2_SetDigitalInput();
    </code>

*/
#define LVMC_LED2_SetDigitalInput()  (_TRISE7 = 1)
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
    LVMC_LED2_SetDigitalOutput();
    </code>

*/
#define LVMC_LED2_SetDigitalOutput() (_TRISE7 = 0)
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
    LVMC_HALL_SetHigh();
    </code>

*/
#define LVMC_HALL_SetHigh()          (_LATE8 = 1)
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
    LVMC_HALL_SetLow();
    </code>

*/
#define LVMC_HALL_SetLow()           (_LATE8 = 0)
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
    LVMC_HALL_Toggle();
    </code>

*/
#define LVMC_HALL_Toggle()           (_LATE8 ^= 1)
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
    postValue = LVMC_HALL_GetValue();
    </code>

*/
#define LVMC_HALL_GetValue()         _RE8
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
    LVMC_HALL_SetDigitalInput();
    </code>

*/
#define LVMC_HALL_SetDigitalInput()  (_TRISE8 = 1)
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
    LVMC_HALL_SetDigitalOutput();
    </code>

*/
#define LVMC_HALL_SetDigitalOutput() (_TRISE8 = 0)

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
    Callback for LVMC_HALL Pin.

  @Description
    This routine is callback for LVMC_HALL Pin

  @Param
    None.

  @Returns
    None
 
 
  @Example 
    <code>
        LVMC_HALL_SetInterruptHandler(&LVMC_HALL_CallBack);
    </code>
*/
void LVMC_HALL_CallBack(void);


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
        LVMC_HALL_SetInterruptHandler(&LVMC_HALL_CallBack);
    </code>
*/
void LVMC_HALL_SetInterruptHandler(void (* InterruptHandler)(void));

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
        LVMC_HALL_SetIOCInterruptHandler(&LVMC_HALL_CallBack);
    </code>
*/
void __attribute__((deprecated("\nThis will be removed in future MCC releases. \nUse LVMC_HALL_SetInterruptHandler instead."))) LVMC_HALL_SetIOCInterruptHandler(void *handler);


#endif
