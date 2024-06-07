/**
  PIN MANAGER Generated Driver File

  @Company:
    Microchip Technology Inc.

  @File Name:
    pin_manager.c

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


/**
    Section: Includes
*/

#include <xc.h>
#include <stdio.h>
#include "pin_manager.h"

/**
 Section: File specific functions
*/
void (*HALL_A_InterruptHandler)(void) = NULL;

/**
 Section: Driver Interface Function Definitions
*/
void PIN_MANAGER_Initialize (void)
{
    /****************************************************************************
     * Setting the Output Latch SFR(s)
     ***************************************************************************/
    LATA = 0x0000;
    LATB = 0x0000;
    LATC = 0x0000;
    LATD = 0x0000;
    LATE = 0x0000;

    /****************************************************************************
     * Setting the GPIO Direction SFR(s)
     ***************************************************************************/
    TRISA = 0x001F;
    TRISB = 0x0FFD;
    TRISC = 0xFFFF;
    TRISD = 0xFFBF;
    TRISE = 0xFCFF;

    /****************************************************************************
     * Setting the Weak Pull Up and Weak Pull Down SFR(s)
     ***************************************************************************/
    CNPDA = 0x0000;
    CNPDB = 0x0000;
    CNPDC = 0x0000;
    CNPDD = 0x0000;
    CNPDE = 0x0000;
    CNPUA = 0x0000;
    CNPUB = 0x0000;
    CNPUC = 0x0000;
    CNPUD = 0x0000;
    CNPUE = 0x0000;

    /****************************************************************************
     * Setting the Open Drain SFR(s)
     ***************************************************************************/
    ODCA = 0x0000;
    ODCB = 0x0000;
    ODCC = 0x0000;
    ODCD = 0x0000;
    ODCE = 0x0000;

    /****************************************************************************
     * Setting the Analog/Digital Configuration SFR(s)
     ***************************************************************************/
    ANSELA = 0x001F;
    ANSELB = 0x009D;
    ANSELC = 0x00CF;
    ANSELD = 0x2C00;
    ANSELE = 0x000F;
    
    /****************************************************************************
     * Set the PPS
     ***************************************************************************/
    __builtin_write_RPCON(0x0000); // unlock PPS

    RPOR19bits.RP70R = 0x0001;    //RD6->UART1:U1TX
    RPINR18bits.U1RXR = 0x0047;    //RD7->UART1:U1RX

    __builtin_write_RPCON(0x0800); // lock PPS
    
    /****************************************************************************
     * Interrupt On Change: any
     ***************************************************************************/
    CNEN0Dbits.CNEN0D1 = 1;    //Pin : RD1
    CNEN1Dbits.CNEN1D1 = 1;    //Pin : RD1
    /****************************************************************************
     * Interrupt On Change: flag
     ***************************************************************************/
    CNFDbits.CNFD1 = 0;    //Pin : RD1
    /****************************************************************************
     * Interrupt On Change: config
     ***************************************************************************/
    CNCONDbits.CNSTYLE = 1;    //Config for PORTD
    CNCONDbits.ON = 1;    //Config for PORTD
    
    /* Initialize IOC Interrupt Handler*/
    HALL_A_SetInterruptHandler(&HALL_A_CallBack);
    
    /****************************************************************************
     * Interrupt On Change: Interrupt Enable
     ***************************************************************************/
    IFS4bits.CNDIF = 0; //Clear CNDI interrupt flag
    IEC4bits.CNDIE = 1; //Enable CNDI interrupt
}

void __attribute__ ((weak)) HALL_A_CallBack(void)
{

}

void HALL_A_SetInterruptHandler(void (* InterruptHandler)(void))
{ 
    IEC4bits.CNDIE = 0; //Disable CNDI interrupt
    HALL_A_InterruptHandler = InterruptHandler; 
    IEC4bits.CNDIE = 1; //Enable CNDI interrupt
}

void HALL_A_SetIOCInterruptHandler(void *handler)
{ 
    HALL_A_SetInterruptHandler(handler);
}

/* Interrupt service routine for the CNDI interrupt. */
void __attribute__ (( interrupt, no_auto_psv )) _CNDInterrupt ( void )
{
    if(IFS4bits.CNDIF == 1)
    {
        if(CNFDbits.CNFD1 == 1)
        {
            if(HALL_A_InterruptHandler) 
            { 
                HALL_A_InterruptHandler(); 
            }
            
            CNFDbits.CNFD1 = 0;  //Clear flag for Pin - RD1

        }
        
        
        // Clear the flag
        IFS4bits.CNDIF = 0;
    }
}

