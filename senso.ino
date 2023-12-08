#define BLYNK_PRINT Serial
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>

#define BLYNK_AUTH_TOKEN "XTQRtL4LopgFPMXfd6R5p9Aig1bwifki"

char auth[] = BLYNK_AUTH_TOKEN;
// char ssid[] = "shahd";//Enter your WIFI name
// char pass[] = "shahd123";//Enter your WIFI password
char ssid[] = "abood2013";//Enter your WIFI name
char pass[] = "19701968";//Enter your WIFI password


WidgetLED PL(V0);WidgetLED VL(V1);WidgetLED SL(V2);WidgetLED CL(V3);

const int pe = D1; // Pin for sensor pp
const int pt = D2; // Pin for sensor pp
float pr,pd;
const int ve = D3; // Pin for sensor vv
const int vt = D4; // Pin for sensor vv
float vr,vd;
const int se = D5; // Pin for sensor ss
const int st = D6; // Pin for sensor ss
float sr,sd;
const int ce = D7; // Pin for sensor cc
const int ct = D8; // Pin for sensor cc
float cr,cd;

void setup() {
  Serial.begin(9600);      
  Blynk.begin(auth, ssid, pass, "blynk.cloud", 80);
  pinMode(pe, INPUT);
  pinMode(pt, OUTPUT);
  pinMode(ve, INPUT);
  pinMode(vt, OUTPUT);
  pinMode(se, INPUT);
  pinMode(st, OUTPUT);
  pinMode(ce, INPUT); 
  pinMode(ct, OUTPUT);
  PL.on();
  VL.on();
  SL.on();
  CL.on();
}

void loop() {
  Blynk.run();

// pizza sauce
  digitalWrite(pt, LOW);
  delayMicroseconds(2);
  digitalWrite(pt, HIGH);
  delayMicroseconds(10);
  digitalWrite(pt, LOW);

  pr= pulseIn(pe, HIGH);
  pd= (pr*.0343)/2;
  Serial.print("Distance pizza sauce:");
  Serial.println(pd);


  if(pd)
  {
    Serial.println("Pempty");
    PL.off();
  }
  else
  {
    Serial.println("Pfull");
    PL.on();
  }

//vegetables
  digitalWrite(vt, LOW);
  delayMicroseconds(2);
  digitalWrite(vt, HIGH);
  delayMicroseconds(10);
  digitalWrite(pt, LOW);

  vr= pulseIn(ve, HIGH);
  vd= (vr*.0343)/2;
  Serial.print("Distance vegetables:");
  Serial.println(vd);


  if(vd)
  {
    Serial.println("Vempty");
    VL.off();
  }
  else
  {
    Serial.println("Vfull");
    VL.on();
  }

//Sausage
  digitalWrite(st, LOW);
  delayMicroseconds(2);
  digitalWrite(st, HIGH);
  delayMicroseconds(10);
  digitalWrite(st, LOW);

  sr= pulseIn(se, HIGH);
  sd= (sr*.0343)/2;
  Serial.print("Distance Sausage:");
  Serial.println(sd);
 

  if(sd)
  {
    Serial.println("Sempty");
    SL.off();
  }
  else
  {
    Serial.println("Sfull");
    SL.on();
  }

//Cheese
  digitalWrite(ct, LOW);
  delayMicroseconds(2);
  digitalWrite(ct, HIGH);
  delayMicroseconds(10);
  digitalWrite(ct, LOW);

  cr= pulseIn(ce, HIGH);
  cd= (cr*.0343)/2;
  Serial.print("Distance Cheese:");
  Serial.println(cd);
  delay(100);

   if(cd)
  {
    Serial.println("Cempty");
    CL.off();
  }
  else
  {
   Serial.println("Cfull");
   CL.on();
  }

  delay(1000);

}
