![image](images/microchip.jpg) 

# SENSORED SINGLE PHASE BRUSHLESS DC MOTOR DRIVER USING dsPIC33CK

## <b>INTRODUCTION</b>
<p style='text-align: justify;'>
This document describes the setup requirements for running the Sensored Single Phase BLDC Motor Driver, which is referenced in the "Sensored Single Phase BLDC Motor Driver using dsPIC33CK” application note. .</p>

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
    <th>Motor</th>
  </tr>
  <tr>
    <td>DSPICDEM™ MCHV-3 Development Board (DM330023-3)</td>
    <td>10A 250V Power Adapter</td>
    <td>High Voltage (310V, 65W) Single Phase BLDC Motor</td>
  </tr>
  <tr>
    <td>dsPIC33CK Low Voltage Motor Control (LVMC) Development Board (DM330031)</td>
    <td>12V Power Supply</td>
    <td>Low Voltage (12V) Single Phase BLDC Motor</td>
  </tr>
  
</table>
  <br />

## <b>HARDWARE SETUP</b>
<p style='text-align: justify;'>This section describes hardware setup required for the demonstration.</p>

> **_NOTE:_**
> Before making any connection on the MCHV-3 Board, verify that the system is not powered and it
is fully discharged. The system is completed discharged when the red
D13 LED is off.


1. <p style='text-align: justify;'> Connect the wires for Hall sensor and phase windings of the motor to the appropriate terminals of the development board, as mentioned in the table below.</p>

<table>
  <tr>
    <th>Motor Wire</th>
    <th>LVMC Terminal</th>
    <th>MCHV3 Terminal</th>
  </tr>
  <tr>
    <td>Motor Pin A</td>
    <td>Phase A (J14)</td>
    <td>MOTOR PHASE 1 M1 (J17)</td>
  </tr>
  <tr>
    <td>Motor Pin B</td>
    <td>Phase B (J14)</td>
    <td>MOTOR PHASE 2 M2 (J17)</td>
  </tr>
  <tr>
    <td>Hall Supply (RED)</td>
    <td>3.3V (J7)</td>
    <td>5V (J9)</td>
  </tr>
  <tr>
    <td>Hall Ground (BLACK)</td>
    <td>GND (J7)</td>
    <td>GROUND (J9)</td>
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
    <th>LVMC Terminal</th>
    <th>MCHV3 Terminal</th>
  </tr>
  <tr>
  <td>Motor Phases</td>
    <td><p align="left">
     <img  src="images/phaseconnectors.jpg" width ="400"></p></td>
    <td><p align="left" >
     <img  src="images/mchv3phases.jpg" width ="700"></p></td>
  </tr>
  <tr>
  <td>Hall Connectors</td>
    <td><p align="left" >
     <img  src="images/hallconnectors.jpg" width ="400"></p></td>
    <td><p align="left" >
     <img  src="images/mchv3hall.jpg" width ="700"></p></td>
  </tr>
  </tr>
</table>

2. <p style='text-align: justify;'> On the MCHV-3 Development Board, connect a 90V-265V power supply to the J1 Terminal. On the LVMC Development Board, plug in the 12V (up to 48V) power supply to connector J1. The table below is provided to summarize the supply and terminal as well. </p>

<table>
  <tr>
    <th></th>
    <th>MCHV-3 </th>
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
    <th>MCHV-3 </th>
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

For more details refer Microchip Application note ANXXXX 'Sensored Single Phase BLDC Motor driver' available at [Microchip web site](https://www.microchip.com/). </p>

> **_NOTE:_**
> The project may not build correctly in Windows OS if Maximum path length of any source file in the project is more than 260 characters. In case absolute path is exceeding or nearing maximum length, do any (or both) of the following:
> - Shorten the directory name containing the firmware used in this demonstration. If you renamed the directory, consider the new name while reading the instructions provided in the upcoming sections of the document.
> - Place firmware in a location, such that absolute path length of each file included in the projects does not exceed the Maximum Path length specified. 
Refer to MPLAB X IDE help topic <i>“Path, File, and Folder Name Restrictions”</i> for details.

### 5.2 Basic Demonstration
<p style='text-align: justify;'>
Follow below instructions step by step to setup and run the motor control demo application:</p>

1. <p style='text-align: leftjustify;'> Start MPLAB X IDE and open<span style="font-family:Courier New; font-size:;"> (File>Open Project)</span> the project <span style="font-family:Courier New; font-size:;">Sensored_SPBLDC_MCHV3_LVMC.X</span> with device selection dsPIC33CK256MP508.</p>
    <p align="left">
       <img  src="images/idedeviceselection.PNG"></p>
  

2. <p style='text-align: leftjustify;'> Set the project <span style="font-family:Courier New; font-size:;">Sensored_SPBLDC_MCHV3_LVMC.X </span>as main project by right clicking on the project name and selecting 'Set as Main Project' as shown. The project <b>'Sensored_SPBLDC_MCHV3_LVMC'</b> will then appear in bold.</p>
    <p align="left">
     <img  src="images/ideprojectsetup.PNG"></p>
 

	
3. <p style='text-align: leftjustify;'> Open <span style="font-family:Courier New; font-size:;">userparams.h </span>(under<span style="font-family:Courier New; font-size:;"> Sensored_SPBLDC_MCHV3_LVMC.X -> headerfiles)</span> in the project <span style="font-family:Courier New; font-size:;">Sensored_SPBLDC_MCHV3_LVMC.X</span> </p>
     <p style='text-align: leftjustify;'>
- Ensure either <span style="font-family:Courier New; font-size:;">CLOSEDLOOP  or OPENLOOP</span> are defined in the <span style="font-family:Courier New; font-size:;">LOOP CONTROLLER</span> section.
      <p align="left"><img  src="images/configLoop.PNG"></p><p style='text-align: leftjustify;'>
- Uncomment the defined <span style="font-family:Courier New; font-size:;">OVERTEMPERATURE_DETECTION</span>, <span style="font-family:Courier New; font-size:;">OVERCURRENT_DETECTION</span> and/or <span style="font-family:Courier New; font-size:;">STALL_DETECTION</span> in the <span style="font-family:Courier New; font-size:;">MOTOR FAULT DETECTION</span> section to enable the motor fault detections. 
      <p align="left"><img  src="images/configFault.PNG"></p>
      

4. Right click on the project <i>Sensored_SPBLDC_MCHV3_LVMC.X</i> and select “Properties”  to open its Project Properties Dialog. Click the “Conf: [LVMC]” category to reveal the general project configuration information. The development tools used for testing the firmware are listed in the section [2.2 Software Tools Used for Testing the firmware](#22-software-tools-used-for-testing-the-firmware).
   <p style='text-align: justify;'>
    In the <b><i>‘Conf: [LVMC]’</i></b> category window: 
    <p style='text-align: justify;'>

 - Select the specific Compiler Toolchain from the available list of compilers. Please ensure MPLAB® XC16 Compiler supports the device dsPIC33CK256MP508. In this case, “XC16(v1.70)” is selected.
      <p style='text-align: justify;'>
 - Select the Hardware Tool to be used for programming and debugging. 
       <p style='text-align: justify;'>     
 -   After selecting Hardware Tool and Compiler Toolchain, click button <b>Apply</b>
        <p align="left">
        <img  src="images/projectpropertiessettings.PNG"></p>

5. <p style='text-align: justify;'> Ensure that the checkbox <b>'Load symbols when programming or building for production (slows process)'</b> is checked, which is under the 'Loading' category of the Project Properties window.</p>        
        
      <p align="left">
      <img  src="images/loadvariables.PNG"></p>

6. <p style='text-align: justify;'>To build the project (in this case Sensored_SPBLDC_MCHV3_LVMC.X) and program the device dsPIC33CK256MP508, click <b>'Make and Program Device Main project'</b> on the toolbar.</p>
    <p align="left">
    <img  src="images/deviceprogramming.PNG"></p>

7. <p style='text-align: justify;'> When the device is programmed successfully, run or stop the motor by pressing the push button <b>SW1</b>. LD10 (LED1) should turn on and the motor should start spinning smoothly in one direction in the range indicated by the potentiometer. Ensure that the motor is spinning smoothly without any vibration.</p>
     <p align="left">
     <img  src="images/startButton.jpg" width ="200"></p>
 

8.  <p style='text-align: justify;'> The motor speed can be varied using the potentiometer (labeled <b>'POT1'</b>).</p>
    <p align="left">
    <img  src="images/potentiometer.jpg" width ="200"></p>

9.  <p style='text-align: justify;'> The direction of the motor rotation can be changed to reverse by pressing the push button <b>SW1</b>.</p>

10. <p style='text-align: justify;'>	Press the push button <b>SW1</b> to stop the motor.</p>


## 5.3  Data visualization through X2C-Scope Plug-in of MPLABX
<p style='text-align: justify;'>
 X2C-Scope is a third-party plug-in for MPLAB X, which helps in real-time diagnostics. The application firmware comes with the initialization needed to interface controller with the host PC to enable data visualization through X2C-Scope plug-in.</p>

1. Ensure X2C-Scope Plug-in is installed. For additional information on how to set up a plug-in refer [https://microchipdeveloper.com/mplabx:tools-plugins-available](https://microchipdeveloper.com/mplabx:tools-plugins-available)
 
2.	To establish serial communication with the host PC, connect a micro-USB cable between the host PC and the LVMC Board (connector J6).


3. Ensure application is configured and running as described under Section [Basic Demonstration](#5-basic-demonstration   ) by following steps 1 through 11.

 

4. Open the X2C-Scope window by selecting <span style="font-family:Courier New; font-size:;">Tools>Embedded>X2CScope.</span></p>
      <p align="left">
       <img  src="images/x2cselection.png"></p>
 

5. Open the X2C-Scope Configuration window and in <b>'Select project'</b> menu, select <b>Sensored_SPBLDC_MCHV3_LVMC</b> project as shown.
    <p align="left">
    <img  src="images/x2cprojectselection.PNG"></p>

6.	Serial communication needs to be set up, as shown in the following figure. Ensure the communication baud rate is set to 115200 as configured in the application firmware. The COM port used depends on the system settings. The <span style="font-family:Courier New; font-size:;">refresh button</span> lists the available COM Ports. Select the COM Port as per the connection.

    <p align="left">
     <img  src="images/x2cconnectionsetup.PNG"></p>
 


7. Once the COM port is detected, click on <b>'Disconnected'</b> and turn to <b>'Connected'</b>, to establish a serial communication between Host PC and the board.
     <p align="left">
    <img  src="images/x2cconnectionbutton.PNG"></p>


8. Set the <b>'Project Setup'</b> as shown below and click <b>'Set Value'</b>. Set Scope sample time as interval at which <span style="font-family:Courier New; font-size:1;">X2CScopeUpdate()</span> is called. In this application it is every 50µs.
      <p align="left">
      <img  src="images/x2cprojectsetup.png"></p>


9. When the setup is established, click on open scope View (under sub window <b>'Data Views'</b>), this opens 'Scope Window'.
     <p align="left">
      <img  src="images/x2cdataview.PNG"></p>
    	     

10. In this window, select the variables that needs to be monitored. To do this, click on the source against each channel, a window Select Variables opens upon the screen. From the available list, the required variable can be chosen. Ensure check boxes Enable & Visible are checked for the variables to be plotted.<br>
To view data plots continuously, uncheck<span style="font-family:Courier New; font-size:1;"> Single-shot</span>. When <span style="font-family:Courier New; font-size:1;">Single-shot</span> is checked it captures the data once and stops. The Sample time factor value multiplied with Sample time determines the time difference between any two consecutive data points on the plot.
    <p align="left">
    <img  src="images/x2cdatapointselection.PNG"></p>

11.	Click on <b>'SAMPLE'</b>, then X2C-Scope window shows variables in real time, which is updated automatically.
     <p align="left">
     <img  src="images/x2csample.PNG"></p>
 

12.	Click on <b>'ABORT'</b> to stop.
     <p align="left">
     <img  src="images/x2cabort.PNG"></p>
 
 ## 6. REFERENCES:
For additional information, refer following documents or links.
1. ANXXXX Application Note [Sensored Single Phase BLDC Motor Driver using dsPIC33CK] (soon)
2. [dsPIC33CK Low-Voltage Motor Control board User's Guide](https://ww1.microchip.com/downloads/aemDocuments/documents/MCU16/ProductDocuments/UserGuides/DS50002927a.pdf)
3. [dsPIC33CK256MP508 Family Datasheet (DS70005349)](https://ww1.microchip.com/downloads/en/DeviceDoc/dsPIC33CK256MP508-Family-Data-Sheet-DS70005349H.pdf)

6. MPLAB® X IDE User’s Guide (DS50002027) or MPLAB® X IDE help
7. [MPLAB® X IDE installation](http://microchipdeveloper.com/mplabx:installation)
8. [MPLAB® XC16 Compiler installation](http://microchipdeveloper.com/xc16:installation)










