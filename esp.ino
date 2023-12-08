#include <SoftwareSerial.h>
#define BLYNK_PRINT Serial
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>

#define BLYNK_AUTH_TOKEN "XTQRtL4LopgFPMXfd6R5p9Aig1bwifki"

char auth[] = BLYNK_AUTH_TOKEN;
char ssid[] = "F";//Enter your WIFI name
char pass[] = "945288";//Enter your WIFI password

WidgetLED PL(V0);WidgetLED VL(V1);WidgetLED SL(V2);WidgetLED CL(V3);
SoftwareSerial swSer(D5, D6);  // pins Rx (D5) and Tx  (D6)


void setup() {
  Serial.begin(9600);   
  swSer.begin(9600);    
  Blynk.begin(auth, ssid, pass, "blynk.cloud", 80);
}

void loop() {
  Blynk.run();
  while (swSer.available() > 0) 
  { 
    int v= swSer.read();
   if (v==1) 
 {   
   Serial.println("Pempty");
   PL.on();
 }
  if(v==2) {
   Serial.println("Pfull"); 
   PL.off();
 }
if (v==3) 
 {   
   Serial.println("Vempty");
   VL.on();
 }
  if(v==4) {
   Serial.println("Vfull"); 
   VL.off();
 }
 if (v==5) 
 {   
   Serial.println("Cempty");
   CL.on();
 }
  if(v==6) {
   Serial.println("Cfull");
   CL.off(); 
 }
  if (v==7) 
 {   
   Serial.println("Sempty");
   SL.on();
 }
  if(v==8) {
   Serial.println("Sfull"); 
   SL.off();
 }

  }
  while (Serial.available() > 0) { //wait for data at hardware serial
    swSer.write(Serial.read()); //send data from serial to mega
  }
 
}