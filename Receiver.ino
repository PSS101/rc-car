
#include <RH_ASK.h>
#ifdef RH_HAVE_HARDWARE_SPI
#include <SPI.h> 
#endif

RH_ASK driver;

void setup()
{


  pinMode(7,OUTPUT);
  pinMode(6,OUTPUT);
  pinMode(5,OUTPUT);
  pinMode(4,OUTPUT);
  

driver.init();
Serial.begin(9600);
  digitalWrite(7,LOW);
    digitalWrite(6,LOW);
    digitalWrite(5,LOW);
    digitalWrite(4,LOW);
}

void loop()
{
 
    uint8_t buf[4];
    uint8_t buflen = sizeof(buf);
   
    if (driver.recv(buf, &buflen)) // Non-blocking
    {
	// Message with a good checksum received, dump it.
	driver.printBuffer("Got:", buf, buflen);
  Serial.println((char *)buf);
  if(strcmp((char*)buf, "F") == 0){
  

  digitalWrite(7,HIGH);
  digitalWrite(6,LOW);
  digitalWrite(5,LOW);
  digitalWrite(4,HIGH);
  
    }
  else  if(strcmp((char*)buf, "B") == 0){
      
  digitalWrite(7,LOW);
  digitalWrite(6,HIGH);
  digitalWrite(5,HIGH);
  digitalWrite(4,LOW);
 
    }
  else  if(strcmp((char*)buf, "L") == 0){


   digitalWrite(7,HIGH);
  digitalWrite(6,LOW);
  digitalWrite(5,HIGH);
  digitalWrite(4,LOW);
  
    }
   else if(strcmp((char*)buf, "R") == 0){

   digitalWrite(7,LOW);
  digitalWrite(6,HIGH);
  digitalWrite(5,LOW);
  digitalWrite(4,HIGH);
 
    }
  else{
   
    digitalWrite(7,LOW);
    digitalWrite(6,LOW);
    digitalWrite(5,LOW);
    digitalWrite(4,LOW);
   
  }
}
}
