/**
  SCCP4 Generated Driver File 

  @Company
    Microchip Technology Inc.

  @File Name
    sccp4.c

  @Summary
    This is the generated driver implementation file for the SCCP4 driver using PIC24 / dsPIC33 / PIC32MM MCUs

  @Description
    This header file provides implementations for driver APIs for SCCP4. 
    Generation Information : 
        Product Revision  :  PIC24 / dsPIC33 / PIC32MM MCUs - 1.171.4
        Device            :  dsPIC33CK256MP508
    The generated drivers are tested against the following:
        Compiler          :  XC16 v2.10
        MPLAB             :  MPLAB X v6.05
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

#include "sccp4_tmr.h"

/**
  Section: Data Type Definitions
*/

/**
  SCCP4 Driver Hardware Instance Object

  @Summary
    Defines the object required for the maintenance of the hardware instance.

  @Description
    This defines the object required for the maintenance of the hardware
    instance. This object exists once per hardware instance of the peripheral.

*/
typedef struct _SCCP4_TMR_OBJ_STRUCT
{

    /* Timer Elapsed */
    bool                                                    primaryTimer16Elapsed;
    bool                                                    secondaryTimer16Elapsed;
    bool                                                    Timer32Elapsed;
} SCCP4_TMR_OBJ;

static SCCP4_TMR_OBJ sccp4_timer_obj;
void SCCP4_TMR_Initialize(void)
{
    // CCPON enabled; MOD 16-Bit/32-Bit Timer; CCSEL disabled; CCPSIDL disabled; T32 32 Bit; CCPSLP disabled; TMRPS 1:64; CLKSEL FOSC/2; TMRSYNC disabled; 
    CCP4CON1L = (0x80E0 & 0x7FFF); //Disabling CCPON bit
    //RTRGEN disabled; ALTSYNC disabled; ONESHOT disabled; TRIGEN disabled; OPS Each Time Base Period Match; SYNC None; OPSSRC Timer Interrupt Event; 
    CCP4CON1H = 0x00;
    //ASDGM disabled; SSDG disabled; ASDG 0; PWMRSEN disabled; 
    CCP4CON2L = 0x00;
    //ICGSM Level-Sensitive mode; ICSEL IC4; AUXOUT Disabled; OCAEN disabled; OENSYNC disabled; 
    CCP4CON2H = 0x00;
    //OETRIG disabled; OSCNT None; POLACE disabled; PSSACE Tri-state; 
    CCP4CON3H = 0x00;
    //ICDIS disabled; SCEVT disabled; TRSET disabled; ICOV disabled; ASEVT disabled; ICGARM disabled; TRCLR disabled; 
    CCP4STATL = 0x00;
    //TMR 0; 
    CCP4TMRL = 0x00;
    //TMR 0; 
    CCP4TMRH = 0x00;
    //PR 0; 
    CCP4PRL = 0x00;
    //PR 0; 
    CCP4PRH = 0x00;
    //CMP 0; 
    CCP4RA = 0x00;
    //CMP 0; 
    CCP4RB = 0x00;
    //BUF 0; 
    CCP4BUFL = 0x00;
    //BUF 0; 
    CCP4BUFH = 0x00;

    CCP4CON1Lbits.CCPON = 0x1; //Enabling CCP

    IFS2bits.CCP4IF = 0;

    IFS2bits.CCT4IF = 0;
      

    // Enabling SCCP4 interrupt.
    IEC2bits.CCT4IE = 1;

}

void SCCP4_TMR_Start( void )
{
    /* Reset the status information */
    sccp4_timer_obj.primaryTimer16Elapsed = false;
    sccp4_timer_obj.secondaryTimer16Elapsed = false;
    sccp4_timer_obj.Timer32Elapsed = false;

    /* Start the Timer */
    CCP4CON1Lbits.CCPON = true;
}

void SCCP4_TMR_Stop( void )
{
    /* Stop the Timer */
    CCP4CON1Lbits.CCPON = false;
}

void __attribute__ ((weak)) SCCP4_TMR_Timer32CallBack(void)
{
    // Add your custom callback code here
}

void __attribute__ ( ( interrupt, no_auto_psv ) ) _CCT4Interrupt ( void )
{
    /* Check if the Timer Interrupt/Status is set */
    if(IFS2bits.CCT4IF)
    {         
        sccp4_timer_obj.Timer32Elapsed = true;
		// SCCP4 Timer 32 bit callback function 
		SCCP4_TMR_Timer32CallBack();
        IFS2bits.CCT4IF = 0;
    }
}



void SCCP4_TMR_Period32BitSet( uint32_t value )
{
    /* Update the period values */
    CCP4PRL = (value & 0x0000FFFF);
    CCP4PRH = ((value & 0xFFFF0000)>>16);

    /* Reset the status information */
    sccp4_timer_obj.Timer32Elapsed = false;
}

uint32_t SCCP4_TMR_Period32BitGet( void )
{
    uint32_t periodVal = 0xFFFFFFFF;
    
    /* get the timer period value and return it */
    periodVal = (((uint32_t)CCP4PRH <<16) | CCP4PRL);

    return(periodVal);
}

void SCCP4_TMR_Counter32BitSet ( uint32_t value )
{
    /* Update the counter values */
    CCP4TMRL = (value & 0x0000FFFF);
    CCP4TMRH = ((value & 0xFFFF0000)>>16);
    /* Reset the status information */
    sccp4_timer_obj.Timer32Elapsed = false;
}

uint32_t SCCP4_TMR_Counter32BitGet( void )
{
    uint32_t counterVal = 0xFFFFFFFF;

    /* get the timer period value and return it */
    counterVal = (((uint32_t)CCP4TMRH <<16) | (CCP4TMRL));

    return(counterVal);
}

bool SCCP4_TMR_Timer32ElapsedThenClear(void)
{
    bool status;
    
    status = sccp4_timer_obj.Timer32Elapsed ;
    
    if(status == true)
    {
        sccp4_timer_obj.Timer32Elapsed = false;
    }
    return status;
}
/**
 End of File
*/