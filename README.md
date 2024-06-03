![image](images/microchip.jpg) 

# AN5423 SENSORED SINGLE PHASE BRUSHLESS DC MOTOR DRIVER USING dsPIC33CK

## <b>INTRODUCTION</b>
<p style='text-align: justify;'>
This document describes the setup requirements for running the Sensored Single Phase BLDC Motor Driver, which is referenced in the "Sensored Single Phase BLDC Motor Driver using dsPIC33CK” application note.</p>

### <b>Motor Control Application Firmware Required for the Demonstration</b>
- Sensored_SPBLDC_MCHV3_LVMC.X

### <b>Software Tools Used for Testing the firmware</b>

- MPLAB® X IDE v5.45 
- MPLAB® XC16 Compiler v1.70
- MPLAB® X IDE Plugin: X2C-Scope v1.3.3 

### <b> Hardware Tools Required for the Demonstration</b>

<table>
  <tr>
    <th>Development Board</th>
    <th>Power Supply</th>
  </tr>
  <tr>
    <td>DSPICDEM™ MCHV3 Development Board (DM3300233)</td>
    <td>10A 250V Power Adapter</td>
  </tr>
  <tr>
    <td>dsPIC33CK Low Voltage Motor Control (LVMC) Development Board (DM330031)</td>
    <td>12V Power Supply</td>
  </tr>
  
</table>
  <br />

## <b>HARDWARE SETUP</b>
<p style='text-align: justify;'>This section describes hardware setup required for the demonstration.</p>

> **_NOTE:_**
> Before making any connection on the MCHV3 Board, verify that the system is not powered and it
is fully discharged. The system is completed discharged when the red
D13 LED is off.


1. <p style='text-align: justify;'> Connect the wires for Hall sensor and phase windings of the motor to the appropriate terminals of the development board, as mentioned in the table below.</p>

<table>
  <tr>
    <th>Motor Wire</th>
    <th>MCHV3 Board</th>
    <th>LVMC Board</th>
  </tr>
  <tr>
    <td>Motor Pin A</td>
    <td>M1 (J17)</td>
    <td>Phase A (J14)</td>
  </tr>
  <tr>
    <td>Motor Pin B</td>
    <td>M2 (J17)</td>
    <td>Phase B (J14)</td>
  </tr>
  <tr>
    <td>Hall Supply (RED)</td>
    <td>5V (J9)</td>
    <td>3.3V (J7)</td>
  </tr>
  <tr>
    <td>Hall Ground (BLACK)</td>
    <td>GROUND (J9)</td>
    <td>GND (J7)</td>
  </tr>
  <tr>
    <td>Hall Signal (BLUE)</td>
    <td>HALL C (J7)</td>
    <td>HALL A(J9)</td>
  </tr>
</table>
<table>
  <tr>
    <th></th>
    <th>MCHV3 Board</th>
    <th>LVMC Board</th>
  </tr>
  <tr>
  <td>Motor Phases</td>
    <td><p align="left">
     <img  src="images/mchv3phases.jpg" width ="700"></p></td>
    <td><p align="left" >
     <img  src="images/phaseconnectors.jpg" width ="400"></p></td>
  </tr>
  <tr>
  <td>Hall Connectors</td>
    <td><p align="left" >
     <img  src="images/mchv3hall.jpg" width ="700"></p></td>
    <td><p align="left" >
     <img  src="images/hallconnectors.jpg" width ="400"></p></td>
  </tr>
  </tr>
</table>

2. <p style='text-align: justify;'> On the MCHV3 Development Board, connect a 90V-265V power supply to the J1 Terminal. On the LVMC Development Board, plug in the 12V (up to 48V) power supply to connector J1. The table below is provided to summarize the supply and terminal as well. </p>

<table>
  <tr>
    <th></th>
    <th>MCHV3 </th>
    <th>LVMC </th>
  </tr>
  <tr>
    <td><b>Supply</b></td>
    <td>90V - 265V</td>
    <td>12V - 48V</td>
  </tr>
    <tr>
    <td><b>Terminal</b></td>
    <td>J1</td>
    <td>J1</td>
  </tr>
</table>
<p align="left">
<img  src="images/mchv3power.jpg" width ="400"></p>
<p align="left">
<img  src="images/lvmcpower.jpg" width ="400"></p>

 

3.	<p style='text-align: justify;'>The onboard programmer ‘PICkit™ On Board (PKoB4)’ , is used for programming or debugging the dsPIC33CK256MP508. To use an on-board programmer, connect a micro-USB cable between Host PC and the terminal provided on the LVMC Board as indicated on the PKoB4 row in the table below. To enable communication using X2CScope between the board and the host PC, refer to USB row in the table below.

<table>
  <tr>
    <th> </th>
    <th>MCHV3 </th>
    <th>LVMC </th>
  </tr>
  <tr>
    <td><b>PKoB4</b></td>
    <td>J19 (PROGRAM/DEBUG on the front panel)</td>
    <td>J13</td>
  </tr>
    <tr>
    <td><b>USB</b></td>
    <td>J6 (USB on the front panel)</td>
    <td>J6</td>
  </tr>
</table>



<p align="left"><img  src="images/mchv3front.jpg" width ="600"></p>

<p align="left"> <img  src="images/lvmcpkob4.png" width ="400"></p>
     <p align="left"><img  src="images/lvmcuart.jpg" width ="400"></p>

 
<br />

## <b>BASIC DEMONSTRATION</b>
### <b> Firmware Description</b>

<p style='text-align: justify;'>
This firmware is implemented to work on Microchip’s 16-bit Digital signal controller (dsPIC® DSC) dsPIC33CK256MP508. 
For more information, see the dsPIC33CK256MP508 Family datasheet (DS70005349).</p>
<p style='text-align: justify;'>
The Motor Control Demo application uses push button to start or stop the motor and potentiometer to vary speed of the motor. This Motor Control Demo Application configures and uses peripherals like PWM, ADC, SCCP, UART etc.</p>

<p style='text-align: justify;'>

For more details refer Microchip Application note 'Sensored Single Phase BLDC Motor driver' available at [Microchip web site](https://www.microchip.com/). </p>

### Basic Demonstration
<p style='text-align: justify;'>
Follow below instructions step by step to setup and run the motor control demo application:</p>

1. <p style='text-align: leftjustify;'> Start MPLAB X IDE and open<span style="font-family:Courier New; font-size:;"> (File>Open Project)</span> the project <span style="font-family:Courier New; font-size:;">Sensored_SPBLDC_MCHV3_LVMC.X</span></p>
    <p align="left">
       <img  src="images/idedeviceselection.PNG"></p>
  

2. <p style='text-align: leftjustify;'> Set the project <span style="font-family:Courier New; font-size:;">Sensored_SPBLDC_MCHV3_LVMC.X </span>as main project by right clicking on the project name and selecting 'Set as Main Project' as shown. The project <b>'Sensored_SPBLDC_MCHV3_LVMC'</b> will then appear in bold.</p>
    <p align="left">
     <img  src="images/ideprojectsetup.PNG"></p>
 

3. <p style='text-align: leftjustify;'> On the configuration panel drop down menu, select if the development board used for demonstration is MCHV3 or LVMC.</p>
    <p align="left">
     <img  src="images/configpanel.png"></p>

4. <p style='text-align: leftjustify;'> Open <span style="font-family:Courier New; font-size:;">userparams.h </span>(under<span style="font-family:Courier New; font-size:;"> Sensored_SPBLDC_MCHV3_LVMC.X -> headerfiles)</span> in the project <span style="font-family:Courier New; font-size:;">Sensored_SPBLDC_MCHV3_LVMC.X</span> </p>
     <p style='text-align: leftjustify;'>
- Ensure either <span style="font-family:Courier New; font-size:;">CLOSEDLOOP  or OPENLOOP</span> are defined in the <span style="font-family:Courier New; font-size:;">LOOP CONTROLLER</span> section.
- Select the default rotation of the motor based on the motor specification sheet by commenting either <span style="font-family:Courier New; font-size:;"> CW or CCW</span>.
- Uncomment the defined <span style="font-family:Courier New; font-size:;">OVERTEMPERATURE_DETECTION</span>, <span style="font-family:Courier New; font-size:;">OVERCURRENT_DETECTION</span> and/or <span style="font-family:Courier New; font-size:;">STALL_DETECTION</span> in the <span style="font-family:Courier New; font-size:;">MOTOR FAULT DETECTION</span> section to enable the motor fault detections. 
      <p align="left"><img  src="images/config.png"></p><p style='text-align: leftjustify;'>

5. Right click on the project <i>Sensored_SPBLDC_MCHV3_LVMC.X</i> and select “Properties”  to open its Project Properties Dialog. Click the selected category “Conf: [MCHV3]" or "Conf: [LVMC]” to display the general project configuration information. In the category window: 

 - Select the specific Compiler Toolchain from the available list of compilers. Please ensure MPLAB® XC16 Compiler supports the device dsPIC33CK256MP508. In this case, “XC16(v1.70)” is selected.
      <p style='text-align: justify;'>
 - Select the Hardware Tool to be used for programming and debugging. 
       <p style='text-align: justify;'>     
 -   After selecting Hardware Tool and Compiler Toolchain, click button <b>Apply</b>
        <p align="left">
        <img  src="images/projectpropertiessettings.PNG"></p>

6. <p style='text-align: justify;'> Ensure that the checkbox <b>'Load symbols when programming or building for production (slows process)'</b> is checked, which is under the 'Loading' category of the Project Properties window.</p>        
        
      <p align="left">
      <img  src="images/loadvariables.PNG"></p>

7. <p style='text-align: justify;'>To build the project (in this case Sensored_SPBLDC_MCHV3_LVMC.X) and program the device dsPIC33CK256MP508, click <b>'Make and Program Device Main project'</b> on the toolbar.</p>
    <p align="left">
    <img  src="images/deviceprogramming.PNG"></p>

8. <p style='text-align: justify;'> When the device is programmed successfully, run or stop the motor by pressing the push button. The appropriate LEDs should turn on and the motor should start spinning smoothly in one direction in the range indicated by the potentiometer. Ensure that the motor is spinning smoothly without any vibration.</p>

<table>
  <tr>
    <th></th>
    <th>MCHV3 Terminal</th>
    <th>LVMC Terminal</th>
  </tr>
  <tr>
  <td>Push Button</td>
    <td>PUSH BUTTON - ON/OFF<p align="left" >
     <img  src="images/mchv3start.png" width ="700"></p></td>
    <td>SW1 - ON/OFF<br> SW2 - REVERSE direction<p align="left">
     <img  src="images/startButton.jpg" width ="350"></p></td>
  </tr>
</table>

9.  <p style='text-align: justify;'> The motor speed can be varied using the potentiometer of the respective development board as indicated below.</p>
    <p align="left"><img  src="images/mchv3pot.png" width ="400"></p>
    <img  src="images/potentiometer.jpg" width ="200"></p>
     <p align="left">
    

10. <p style='text-align: justify;'>	Press the appropriate push button to stop the motor.</p>
 
 ## <b>REFERENCES:</b>
For additional information, refer following documents or links.
1. Sensored Single Phase BLDC Motor Driver using dsPIC33CK Application Note
2. [dsPICDEM™ MCHV3 Development Board User’s Guide](https://ww1.microchip.com/downloads/aemDocuments/documents/OTH/ProductDocuments/UserGuides/DS50002505a.pdf)
2. [dsPIC33CK Low-Voltage Motor Control board User's Guide](https://ww1.microchip.com/downloads/aemDocuments/documents/MCU16/ProductDocuments/UserGuides/DS50002927a.pdf)
3. [dsPIC33CK256MP508 Family Datasheet (DS70005349)](https://ww1.microchip.com/downloads/en/DeviceDoc/dsPIC33CK256MP508-Family-Data-Sheet-DS70005349H.pdf)

6. MPLAB® X IDE User’s Guide (DS50002027) or MPLAB® X IDE help
7. [MPLAB® X IDE installation](http://microchipdeveloper.com/mplabx:installation)
8. [MPLAB® XC16 Compiler installation](http://microchipdeveloper.com/xc16:installation)










