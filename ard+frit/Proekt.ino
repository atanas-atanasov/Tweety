




//
//    FILE: dht_test.ino
//  AUTHOR: Rob Tillaart
// VERSION: 0.1.07
// PURPOSE: DHT Temperature & Humidity Sensor library for Arduino
//     URL: http://arduino.cc/playground/Main/DHTLib
//
// Released to the public domain
//

#include <dht.h>

dht DHT;

#define DHT11_PIN 3
int redPin =10;
int greenPin=12;
int bluePin=11;
int zoomer =13;

void setup()
{
  Serial.begin(115200);
  Serial.println("DHT TEST PROGRAM ");
  Serial.print("LIBRARY VERSION: ");
  Serial.println(DHT_LIB_VERSION);
  Serial.println();
  Serial.println("Type,\tstatus,\tHumidity (%),\tTemperature (C)");
  pinMode(bluePin, OUTPUT);
  pinMode(redPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(zoomer, OUTPUT);

}

void loop()
{

  


  for(;;)
  {
  Serial.print("DHT11 \t");
  int chk = DHT.read11(DHT11_PIN);
  switch (chk)
  {
    case DHTLIB_OK:  
		Serial.print("OK\t");                
		break;
    case DHTLIB_ERROR_CHECKSUM: 
		Serial.print("Checksum error,\t");                
		break;
    case DHTLIB_ERROR_TIMEOUT: 
		Serial.print("Time out error,\t");               
		break;
    default: 
		Serial.print("Unknown error,\t");             
		break;
  }
 // DISPLAY DATA
  Serial.print(DHT.humidity,1);
  Serial.print("      \t");
  Serial.println(DHT.temperature,1);

double t = DHT.temperature;
if(t<17){
  setColor(255,255,128);
}

if(t==17){
  setColor(255,255,50);
}

if(t==18){
  setColor(255,255,0);
}
if(t==19){
  setColor(155,106,18);
}
if(t==20){
  setColor(255,64,0);
}
if(t==21){
  setColor(120,49,5);
}
if(t==22){
  setColor(120,49,20);
}
if(t==23){
  setColor(79,31,16);
}
if(t==24){
  setColor(191,31,47);
}
if(t==25){
  setColor(255,49,46);
}
if(t==26){
  setColor(223,77,85);
}
if(t==27){
  setColor(153,80,85);
}
if(t==28){
  setColor(195,76,142);
}
if(t==29){
  setColor(205,50,205);
}
if(t==30){
    setColor(101,50,228);
}
if(t==31){
  setColor(131,3,255);
}
if(t==32){
  setColor(255,0,255);
}
if(t==33){
  setColor(210,0,255);
}
if(t==34){
  setColor(110,50,255);
}
if(t==35){
  setColor(0,55,255);
}
if(t==36){
  setColor(0,156,184);
}
if(t==37){
  setColor(0,156,184);
}
if(t==38){
  setColor(60,156,255);
}
if(t==39){
  setColor(60,156,255);
}
if(t==40){
  setColor(60,156,255);
}
if(t>40){
  setColor(0,255,255);
}

   for(int i=0;i<2000;i++){
     delay(1);
     if(DHT.temperature<16 || DHT.temperature>40){
       digitalWrite(zoomer,HIGH);
       digitalWrite(zoomer,LOW);
  }}
}
}
void setColor(int red, int green, int blue)
{
#ifdef COMMON_ANODE
red = 255 - red;
green = 255 - green;
blue = 255 - blue;
#endif
analogWrite(redPin, red);
analogWrite(greenPin, green);
analogWrite(bluePin, blue);
}


     
        
     

