# ESP32-Bluetooth-Home-Automation-with-IR-Remote-Control-Relay
ESP32 Bluetooth Home Automation system to control 8 home appliances with Bluetooth, IR remote, and manual switches. You don't need any internet connection for this project.

## Tutorial video link for this ESP32 Home Automation project
https://youtu.be/5c3rmfpAAsE

This ESP32 control smart relay has the following features:

1. Control home appliances with Bluetooth App from your smartphone.
2. Control home appliances with any IR remote.
3. Control home appliances with manual switches or Pushbutton.


If you don't want to use PCB, you can also make this IoT project using an 8-channel relay module, ESP32, and IR receiver sensor.

## Required Components:
1. ESP32 DEVKIT V1 board
2. 8-channel SPDT 5V Relay Module
3. TSOP1838 IR receiver (with metallic case)
4. Manual Switches or Pushbuttons

If you use the custom-designed PCB for this project, then please refer to the following required components list.

## Required Components for the PCB
1. ESP32 DEVKIT V1
2. TSOP1838 IR receiver (with metallic case)
3. Relays 5v (SPDT) (8 no)
4. BC547 Transistors (8 no)
5. PC817 Optocuplors (8 no)
6. 510-ohm 0.25-watt Resistor (8 no) (R1 - R8)
7. 1k 0.25-watt Resistors (10 no) (R9 - R18)
8. LED 5-mm (10 no)
9. 1N4007 Diodes (8 no) (D1 - D8)
10. Push Buttons (9 no) or Switches
11. Terminal Connectors
12. Jumper
13. 5V DC supply

## Required Software:
1. Arduino IDE
2. Bluetooth App

## Circuit Diagram of the ESP32 Projects
This is the complete circuit diagram for this home automation project. I have explained the circuit in the tutorial video.

The circuit is very simple, I have used the GPIO pins D23, D22, D21, D19, D18, D5, D25 & D26 to control the 8 relays.

And the GPIO pins D13, D12, D14, D27, D33, D32, D15 & D4 are connected with Switches to control the 8 relays manually.

And the output pin of the IR Receiver is connected with GPIO D35.

I have used the INPUT_PULLUP function in Arduino IDE instead of using the pull-up resistors.

I have used a 5V 5A DC power supply.

## Control Relays Using Bluetooth App
After pairing the ESP32 with mobile Bluetooth, you can easily control the relays from the Bluetooth App.

I have made this Bluetooth app in MIT app inventor. The app is simple and easy to use.

You can download the app from the following link.

https://github.com/techstudycell/ESP32-Bluetooth-Home-Automation-with-IR-Remote-Control-Relay/tree/main/Bluetooth_Switch_V1_App

## ESP32 Control Relay With IR Remote
You can always control the relays from the IR remote. For this project, you can use any IR remote.

I will explain how to get the IR codes (HEX codes) from any remote in the following steps.

## Control Relays Manually With Switches
For this project, you can use both switches or push buttons.

If you want to use switch (latched), then upload the source code for switches.

And for the push button upload the source code for the manual button.

Both source codes are shared in this article.

## Download the PCB Gerber File
To make the circuit compact and give a professional look, I have designed the PCB after testing all the features of the smart relay module on the breadboard.

You can download the PCB Gerber file of this home automation project from the following link:

https://github.com/techstudycell/ESP32-Bluetooth-Home-Automation-with-IR-Remote-Control-Relay/tree/main/PCB%20Gerber

## Order the PCB from JLCPCB
After downloading the Garber file you can easily order the PCB

1. Visit https://jlcpcb.com/RAB and Sign in / Sign up
2. Click on the QUOTE NOW button.
3. Click on the "Add gerber file" button. Then browse and select the Gerber file you have downloaded.
4. Set the required parameter like Quantity, PCB masking color, etc.
5. After selecting all the Parameters for PCB click on SAVE TO CART button.
6. Type the Shipping Address.
7. Select the Shipping Method suitable for you.
8. Submit the order and proceed with the payment.
9. You can also track your order from the JLCPCB.com

My PCBs took 2 days to get manufactured and arrived within a week using the DHL delivery option. PCBs were well packed and the quality was really good at this affordable price.

## Solder All the Components on PCB
After that, I have soldered all the components as per the circuit diagram.

Then connect the ESP32, 1838 IR receiver with the PCB.

## Codes for the ESP32 (Bluetooth + IR) Home Automation
If you use switch (Latched) then refer to the code for Switch, and for momentary switch please use the code for the pushbutton.

Download the Codes for this ESP32 project

https://github.com/techstudycell/ESP32-Bluetooth-Home-Automation-with-IR-Remote-Control-Relay/tree/main/Source%20Code

Download and install the following libraries in Arduino IDE

1. AceButton Library: https://github.com/bxparks/AceButton
2. IRremote Library: https://github.com/Arduino-IRremote/Arduino-IRremote

## Program the ESP32 With Arduino IDE
Here, I have given the ESP32 Bluetooth name as "ESP32_BT". To change the name update the following line in void setup().

SerialBT.begin("ESP32_BT"); //Bluetooth device name

Then update the HEX code in the ir_remote function as shown in the tutorial video.

After that, select the DOIT ESP32 DEVKIT V1 board and proper PORT.

Then upload the code to ESP32 Board.

While uploading the code to ESP32, if you see the Connecting....___ text, then press the BOOT button of the ESP32.

## Connect the Home Appliances
Connect the 8 home appliances as per the circuit diagram.

Please take proper safety precautions while working with high voltage.

Connect 5-volt DC supply with the PCB.

## Connect the Bluetooth App With ESP32
I have designed the Bluetooth Switch App in MIT App Inventor for this ESP32 Bluetooth project.

Please download and install the Bluetooth App (APK file attached), then you have to connect the Bluetooth App with ESP32.

Turn ON mobile Bluetooth and Pair the ESP32.
Open the Bluetooth Switch App and tap on "Tap to Connect".
Select the "ESP32_BT" from the list.
Now, you can control the relay from mobile with Bluetooth.
Download Bluetooth App for the ESP32 Bluetooth project

https://github.com/techstudycell/ESP32-Bluetooth-Home-Automation-with-IR-Remote-Control-Relay/tree/main/Bluetooth_Switch_V1_App

## Finally!! the ESP32 Home Automation System Is Ready
Now you can control your home appliances in a smart way.

I hope you have liked this ESP32 Bluetooth home automation project. I have shared all the required information for this project.

I will really appreciate it if you share your valuable feedback. Also if you have any query please write in the comment section. 

Thank you & Happy Learning.
