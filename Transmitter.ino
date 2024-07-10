// ask_transmitter.pde
// -*- mode: C++ -*-
// Simple example of how to use RadioHead to transmit messages
// with a simple ASK transmitter in a very simple way.
// Implements a simplex (one-way) transmitter with an TX-C1 module
// Tested on Arduino Mega, Duemilanova, Uno, Due, Teensy, ESP-12

#include <RH_ASK.h>

#include <SPI.h> // Not actually used but needed to compile


RH_ASK driver;
// RH_ASK driver(2000, 4, 5, 0); // ESP8266 or ESP32: do not use pin 11 or 2
// RH_ASK driver(2000, 3, 4, 0); // ATTiny, RX on D3 (pin 2 on attiny85) TX on D4 (pin 3 on attiny85), 
// RH_ASK driver(2000, PD14, PD13, 0); STM32F4 Discovery: see tx and rx on Orange and Red LEDS

void setup()
{

Serial.begin(9600);
driver.init();
pinMode(A0,INPUT);
pinMode(A1,INPUT);

}

void loop()
{

 int x = analogRead(A1);
 int y = analogRead(A2);
Serial.println(x);
Serial.println(y);
if(x >=550){
   const char *msg = "B";

    driver.send((uint8_t *)msg, strlen(msg));
    driver.waitPacketSent();
    
     Serial.println("B");
     Serial.print( strlen(msg));
}
else if(x <= 400){
      const char *msg = "F";

    driver.send((uint8_t *)msg, strlen(msg));
    driver.waitPacketSent();
    
     Serial.println("F");
     Serial.print( strlen(msg));
}
else if(y >= 550){
   const char *msg = "R";

    driver.send((uint8_t *)msg, strlen(msg));
    driver.waitPacketSent();
    
     Serial.println("R");
     Serial.print( strlen(msg));
}
else if(y <= 400){
      const char *msg = "L";

    driver.send((uint8_t *)msg, strlen(msg));
    driver.waitPacketSent();
    
     Serial.println("L");
     Serial.print( strlen(msg));
}
else{
      const char *msg = "0";

    driver.send((uint8_t *)msg, strlen(msg));
    driver.waitPacketSent();
    
     Serial.println("0");
     
}



}