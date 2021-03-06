// Sketch made by Apoorv Tomar
// Sketch for interfacing Bluetooth module HC-05, AirQuality sensor MQ 135, GSM Module SIM800 with Arduino UNO, MEGA.
// Uses pin 10,11 as Software Serial (RX, TX) to connect to HC-05 
// Uses Hardware Serial Pin RX1, TX1 to connect to SIM 800
// MQ 135 is connected with D0, A0 (which serve as input pins for Arduino).
// Data collected from Sensors and Bluetooth device is sent to SIM800 via Serial Communication.

#include<SoftwareSerial.h>
SoftwareSerial BTSerial(10, 11);

int sensorValue;
int digitalValue;
char ch;
int flag = 0;
String sendData = "at+httppara=\"URL\",\"52.76.4.177/?";

void setup() {

  //Being serial communication witj Arduino and SIM800
  Serial1.begin(9600);
  //Begin Serial Monitor 9600 bauds
  Serial.begin(9600);

  Serial.println("Arduino with HC-05 is ready");

  //Begin serial communication with HC-05
  BTSerial.begin(38400);
  Serial.println("BTserial started at 38400");
  Serial.println("");
 
}

void loop() {


  if (BTSerial.available()) {

    ch = BTSerial.read();
    Serial.write(ch);
  }
  else
  {
    if (Serial.available()) {

      delay(1000);
      sensorValue = analogRead(0);       // read analog input pin 0
      digitalValue = digitalRead(0);
      Serial.println(sensorValue, DEC);  // prints the value read
    }
  }
  
    Serial1.print(sendData + "v=" + sensorValue + "&session=" + sensorValue + "\"\r\n");
    // You can give your own commands to push data to remote server via GET OR POST HTTP requests.
    //if(Serial1.available())
    //Serial.print(Serial1.read());
    //Serial1.print("at+httpaction=0\r\n");
    //if(Serial1.available())
    //Serial.print(Serial1.read());
    Serial1.print("at+httpaction=0\r\n");
   // if(Serial1.available())
    //Serial.print(Serial1.read());
    //delay(100);
  
}
