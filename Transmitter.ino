#include <RH_ASK.h>

#include <SPI.h> 


RH_ASK driver;
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
