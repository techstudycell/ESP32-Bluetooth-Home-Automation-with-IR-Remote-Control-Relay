 /**********************************************************************************
 *  TITLE: Bluetooth + IR + Manual Switch (Latching) control 8 relays using ESP32.
 *  Click on the following links to learn more. 
 *  YouTube Video: https://youtu.be/5c3rmfpAAsE
 *  Related Blog : https://iotcircuithub.com/esp32-projects/
 *  by Subhajit (Tech StudyCell)
 *  Preferences--> Aditional boards Manager URLs : 
 *  https://dl.espressif.com/dl/package_esp32_index.json, http://arduino.esp8266.com/stable/package_esp8266com_index.json
 *  
 *  Download Board ESP32: https://github.com/espressif/arduino-esp32
 *  
 *  Download the libraries
 *  AceButton Library: https://github.com/bxparks/AceButton
 *  IRremote Library: https://github.com/Arduino-IRremote/Arduino-IRremote
 *  
 *  Install the libraries at Arduino IDE -> Sketch - Include Library -> Add Zip Library
 **********************************************************************************/


#include "BluetoothSerial.h" 
#include <IRremote.h>
#include <AceButton.h>
using namespace ace_button;

#if !defined(CONFIG_BT_ENABLED) || !defined(CONFIG_BLUEDROID_ENABLED)
#error Bluetooth is not enabled! Please run
`make menuconfig` to and enable it
#endif

BluetoothSerial SerialBT;


// define the GPIO connected with Relays and switches
#define RelayPin1 23  //D23
#define RelayPin2 22  //D22
#define RelayPin3 21  //D21
#define RelayPin4 19  //D19
#define RelayPin5 18  //D18
#define RelayPin6 5   //D5
#define RelayPin7 25  //D25
#define RelayPin8 26  //D26

#define SwitchPin1 13  //D13
#define SwitchPin2 12  //D12
#define SwitchPin3 14  //D14
#define SwitchPin4 27  //D27
#define SwitchPin5 33  //D33
#define SwitchPin6 32  //D32
#define SwitchPin7 15  //D15
#define SwitchPin8 4   //D4

#define IR_RECV_PIN 35  //D35

int toggleState_1 = 1; //Define integer to remember the toggle state for relay 1
int toggleState_2 = 1; //Define integer to remember the toggle state for relay 2
int toggleState_3 = 1; //Define integer to remember the toggle state for relay 3
int toggleState_4 = 1; //Define integer to remember the toggle state for relay 4
int toggleState_5 = 1; //Define integer to remember the toggle state for relay 5
int toggleState_6 = 1; //Define integer to remember the toggle state for relay 6
int toggleState_7 = 1; //Define integer to remember the toggle state for relay 7
int toggleState_8 = 1; //Define integer to remember the toggle state for relay 8

char bt_data; // variable for storing bluetooth data

IRrecv irrecv(IR_RECV_PIN);
decode_results results;

ButtonConfig config1;
AceButton button1(&config1);
ButtonConfig config2;
AceButton button2(&config2);
ButtonConfig config3;
AceButton button3(&config3);
ButtonConfig config4;
AceButton button4(&config4);
ButtonConfig config5;
AceButton button5(&config5);
ButtonConfig config6;
AceButton button6(&config6);
ButtonConfig config7;
AceButton button7(&config7);
ButtonConfig config8;
AceButton button8(&config8);

void handleEvent1(AceButton*, uint8_t, uint8_t);
void handleEvent2(AceButton*, uint8_t, uint8_t);
void handleEvent3(AceButton*, uint8_t, uint8_t);
void handleEvent4(AceButton*, uint8_t, uint8_t);
void handleEvent5(AceButton*, uint8_t, uint8_t);
void handleEvent6(AceButton*, uint8_t, uint8_t);
void handleEvent7(AceButton*, uint8_t, uint8_t);
void handleEvent8(AceButton*, uint8_t, uint8_t);

void relayOnOff(int relay){

    switch(relay){
      case 1: 
             if(toggleState_1 == 1){
              digitalWrite(RelayPin1, LOW); // turn on relay 1
              toggleState_1 = 0;
              Serial.println("Device1 ON");
              }
             else{
              digitalWrite(RelayPin1, HIGH); // turn off relay 1
              toggleState_1 = 1;
              Serial.println("Device1 OFF");
              }
             delay(100);
      break;
      case 2: 
             if(toggleState_2 == 1){
              digitalWrite(RelayPin2, LOW); // turn on relay 2
              toggleState_2 = 0;
              Serial.println("Device2 ON");
              }
             else{
              digitalWrite(RelayPin2, HIGH); // turn off relay 2
              toggleState_2 = 1;
              Serial.println("Device2 OFF");
              }
             delay(100);
      break;
      case 3: 
             if(toggleState_3 == 1){
              digitalWrite(RelayPin3, LOW); // turn on relay 3
              toggleState_3 = 0;
              Serial.println("Device3 ON");
              }
             else{
              digitalWrite(RelayPin3, HIGH); // turn off relay 3
              toggleState_3 = 1;
              Serial.println("Device3 OFF");
              }
             delay(100);
      break;
      case 4: 
             if(toggleState_4 == 1){
              digitalWrite(RelayPin4, LOW); // turn on relay 4
              toggleState_4 = 0;
              Serial.println("Device4 ON");
              }
             else{
              digitalWrite(RelayPin4, HIGH); // turn off relay 4
              toggleState_4 = 1;
              Serial.println("Device4 OFF");
              }
             delay(100);
      break;
      case 5: 
             if(toggleState_5 == 1){
              digitalWrite(RelayPin5, LOW); // turn on relay 5
              toggleState_5 = 0;
              Serial.println("Device5 ON");
              }
             else{
              digitalWrite(RelayPin5, HIGH); // turn off relay 5
              toggleState_5 = 1;
              Serial.println("Device5 OFF");
              }
             delay(100);
      break;
      case 6: 
             if(toggleState_6 == 1){
              digitalWrite(RelayPin6, LOW); // turn on relay 6
              toggleState_6 = 0;
              Serial.println("Device6 ON");
              }
             else{
              digitalWrite(RelayPin6, HIGH); // turn off relay 6
              toggleState_6 = 1;
              Serial.println("Device6 OFF");
              }
             delay(100);
      break;
      case 7: 
             if(toggleState_7 == 1){
              digitalWrite(RelayPin7, LOW); // turn on relay 7
              toggleState_7 = 0;
              Serial.println("Device7 ON");
              }
             else{
              digitalWrite(RelayPin7, HIGH); // turn off relay 7
              toggleState_7 = 1;
              Serial.println("Device7 OFF");
              }
             delay(100);
      break;
      case 8: 
             if(toggleState_8 == 1){
              digitalWrite(RelayPin8, LOW); // turn on relay 8
              toggleState_8 = 0;
              Serial.println("Device8 ON");
              }
             else{
              digitalWrite(RelayPin8, HIGH); // turn off relay 8
              toggleState_8 = 1;
              Serial.println("Device8 OFF");
              }
             delay(100);
      break;
      default : break;      
      }  
}


void all_Switch_ON(){
  digitalWrite(RelayPin1, LOW); toggleState_1 = 0; delay(100);
  digitalWrite(RelayPin2, LOW); toggleState_2 = 0; delay(100);
  digitalWrite(RelayPin3, LOW); toggleState_3 = 0; delay(100);
  digitalWrite(RelayPin4, LOW); toggleState_4 = 0; delay(100);
  digitalWrite(RelayPin5, LOW); toggleState_5 = 0; delay(100);
  digitalWrite(RelayPin6, LOW); toggleState_6 = 0; delay(100);
  digitalWrite(RelayPin7, LOW); toggleState_7 = 0; delay(100);
  digitalWrite(RelayPin8, LOW); toggleState_8 = 0; delay(100);
}

void all_Switch_OFF(){
  digitalWrite(RelayPin1, HIGH); toggleState_1 = 1; delay(100);
  digitalWrite(RelayPin2, HIGH); toggleState_2 = 1; delay(100);
  digitalWrite(RelayPin3, HIGH); toggleState_3 = 1; delay(100);
  digitalWrite(RelayPin4, HIGH); toggleState_4 = 1; delay(100);
  digitalWrite(RelayPin5, HIGH); toggleState_5 = 1; delay(100);
  digitalWrite(RelayPin6, HIGH); toggleState_6 = 1; delay(100);
  digitalWrite(RelayPin7, HIGH); toggleState_7 = 1; delay(100);
  digitalWrite(RelayPin8, HIGH); toggleState_8 = 1; delay(100);
}

void Bluetooth_handle()
{
  bt_data = SerialBT.read();
//  Serial.println(bt_data);
  delay(20);

  switch(bt_data)
      {
        case 'A': digitalWrite(RelayPin1, LOW);  toggleState_1 = 0; break; // if 'A' received Turn on Relay1
        case 'a': digitalWrite(RelayPin1, HIGH); toggleState_1 = 1; break; // if 'a' received Turn off Relay1
        case 'B': digitalWrite(RelayPin2, LOW);  toggleState_2 = 0; break; // if 'B' received Turn on Relay2
        case 'b': digitalWrite(RelayPin2, HIGH); toggleState_2 = 1; break; // if 'b' received Turn off Relay2
        case 'C': digitalWrite(RelayPin3, LOW);  toggleState_3 = 0; break; // if 'C' received Turn on Relay3
        case 'c': digitalWrite(RelayPin3, HIGH); toggleState_3 = 1; break; // if 'c' received Turn off Relay3
        case 'D': digitalWrite(RelayPin4, LOW);  toggleState_4 = 0; break; // if 'D' received Turn on Relay4
        case 'd': digitalWrite(RelayPin4, HIGH); toggleState_4 = 1; break; // if 'd' received Turn off Relay4
        case 'E': digitalWrite(RelayPin5, LOW);  toggleState_5 = 0; break; // if 'E' received Turn on Relay5
        case 'e': digitalWrite(RelayPin5, HIGH); toggleState_5 = 1; break; // if 'e' received Turn off Relay5
        case 'F': digitalWrite(RelayPin6, LOW);  toggleState_6 = 0; break; // if 'F' received Turn on Relay6
        case 'f': digitalWrite(RelayPin6, HIGH); toggleState_6 = 1; break; // if 'f' received Turn off Relay6
        case 'G': digitalWrite(RelayPin7, LOW);  toggleState_7 = 0; break; // if 'G' received Turn on Relay7
        case 'g': digitalWrite(RelayPin7, HIGH); toggleState_7 = 1; break; // if 'g' received Turn off Relay7
        case 'H': digitalWrite(RelayPin8, LOW);  toggleState_8 = 0; break; // if 'H' received Turn on Relay8
        case 'h': digitalWrite(RelayPin8, HIGH); toggleState_8 = 1; break; // if 'h' received Turn off Relay8
        case 'Z': all_Switch_ON(); break;  // if 'Z' received Turn on all Relays
        case 'z': all_Switch_OFF(); break; // if 'z' received Turn off all Relays
        default : break;
      }
}

void ir_remote(){
  if (irrecv.decode(&results)) {
    
      switch(results.value){
          case 0x80BF49B6:  relayOnOff(1);  break;
          case 0x80BFC936:  relayOnOff(2);  break;
          case 0x80BF33CC:  relayOnOff(3);  break;
          case 0x80BF718E:  relayOnOff(4);  break;
          case 0x80BFF10E:  relayOnOff(5);  break;
          case 0x80BF13EC:  relayOnOff(6);  break;
          case 0x80BF51AE:  relayOnOff(7);  break;
          case 0x80BFD12E:  relayOnOff(8);  break;
          case 0x80BF3BC4:  all_Switch_OFF();  break;
          case 0x80BF23DC:  all_Switch_ON();  break;
          default : break;         
        }   
        //Serial.println(results.value, HEX);    
        irrecv.resume();   
  } 
}

void setup()
{
  Serial.begin(9600);

  irrecv.enableIRIn(); // Start the receiver
  btStart();  //Serial.println("Bluetooth On");
  
  SerialBT.begin("ESP32_BT"); //Bluetooth device name
  Serial.println("The device started, now you can pair it with bluetooth!");
  delay(5000);

  pinMode(RelayPin1, OUTPUT);
  pinMode(RelayPin2, OUTPUT);
  pinMode(RelayPin3, OUTPUT);
  pinMode(RelayPin4, OUTPUT);
  pinMode(RelayPin5, OUTPUT);
  pinMode(RelayPin6, OUTPUT);
  pinMode(RelayPin7, OUTPUT);
  pinMode(RelayPin8, OUTPUT);


  pinMode(SwitchPin1, INPUT_PULLUP);
  pinMode(SwitchPin2, INPUT_PULLUP);
  pinMode(SwitchPin3, INPUT_PULLUP);
  pinMode(SwitchPin4, INPUT_PULLUP);
  pinMode(SwitchPin5, INPUT_PULLUP);
  pinMode(SwitchPin6, INPUT_PULLUP);
  pinMode(SwitchPin7, INPUT_PULLUP);
  pinMode(SwitchPin8, INPUT_PULLUP);

  //During Starting all Relays should TURN OFF
  digitalWrite(RelayPin1, toggleState_1);
  digitalWrite(RelayPin2, toggleState_2);
  digitalWrite(RelayPin3, toggleState_3);
  digitalWrite(RelayPin4, toggleState_4);
  digitalWrite(RelayPin5, toggleState_5);
  digitalWrite(RelayPin6, toggleState_6);
  digitalWrite(RelayPin7, toggleState_7);
  digitalWrite(RelayPin8, toggleState_8);

  config1.setEventHandler(button1Handler);
  config2.setEventHandler(button2Handler);
  config3.setEventHandler(button3Handler);
  config4.setEventHandler(button4Handler);
  config5.setEventHandler(button5Handler);
  config6.setEventHandler(button6Handler);
  config7.setEventHandler(button7Handler);
  config8.setEventHandler(button8Handler);

  button1.init(SwitchPin1);
  button2.init(SwitchPin2);
  button3.init(SwitchPin3);
  button4.init(SwitchPin4);
  button5.init(SwitchPin5);
  button6.init(SwitchPin6);
  button7.init(SwitchPin7);
  button8.init(SwitchPin8);

  delay(200);
}

void loop()
{  
   //IR Remote Control
    ir_remote();
    
   //Bluetooth Control
    if (SerialBT.available()){
     Bluetooth_handle();
   }

   //Manual Switch Control
    button1.check();
    button2.check();
    button3.check();
    button4.check();
    button5.check();
    button6.check();
    button7.check();
    button8.check();
}

void button1Handler(AceButton* button, uint8_t eventType, uint8_t buttonState) {
  Serial.println("EVENT1");
  relayOnOff(1);
}
void button2Handler(AceButton* button, uint8_t eventType, uint8_t buttonState) {
  Serial.println("EVENT2");
  relayOnOff(2);
}
void button3Handler(AceButton* button, uint8_t eventType, uint8_t buttonState) {
  Serial.println("EVENT3");
  relayOnOff(3);
}
void button4Handler(AceButton* button, uint8_t eventType, uint8_t buttonState) {
  Serial.println("EVENT4");
  relayOnOff(4);
}
void button5Handler(AceButton* button, uint8_t eventType, uint8_t buttonState) {
  Serial.println("EVENT5");
  relayOnOff(5);
}
void button6Handler(AceButton* button, uint8_t eventType, uint8_t buttonState) {
  Serial.println("EVENT6");
  relayOnOff(6);
}
void button7Handler(AceButton* button, uint8_t eventType, uint8_t buttonState) {
  Serial.println("EVENT7");
  relayOnOff(7);
}
void button8Handler(AceButton* button, uint8_t eventType, uint8_t buttonState) {
  Serial.println("EVENT8");
  relayOnOff(8);
}
