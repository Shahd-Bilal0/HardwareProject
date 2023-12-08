#include <SoftwareSerial.h>
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>

SoftwareSerial swSer(D5, D6);
#define BLYNK_PRINT Serial

char auth[] = "XTQRtL4LopgFPMXfd6R5p9Aig1bwifki";
char ssid[] = "shahd";
char pass[] = "shahd123";

WidgetLED PL(V0); //level v7
WidgetLED VL(V1); //level v9
WidgetLED SL(V2); //level v3
WidgetLED CL(V6); //level v8
  float pd;
const int se = D1; const int st = D2; float sr, sd; 
const int ve = D3; const int vt = D4; float vr, vd; 
const int ce = D7; const int ct = D8; float cr, cd; 

BLYNK_WRITE(V4)//switch on off
{
  if (param.asInt() == 0) swSer.write(1000);
  else if (param.asInt() == 1)  swSer.write(1001);
  Serial.println(param.asInt());
}

void setup() {
  Serial.begin(9600);
  swSer.begin(9600);
 


    WiFi.begin(ssid, pass);

   Serial.print("Connecting to WiFi");
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  Serial.println();
  Serial.print("Connected to WiFi. IP address: ");
  Serial.println(WiFi.localIP());
     Blynk.begin(auth, ssid, pass, "blynk.cloud", 80);

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
  Blynk.virtualWrite(V5, 0);
}

void loop() {
  Blynk.run();

  // Vegetables
  digitalWrite(vt, LOW);
  delayMicroseconds(2);
  digitalWrite(vt, HIGH);
  delayMicroseconds(10);
  digitalWrite(vt, LOW);
  vr = pulseIn(ve, HIGH);
  vd = (vr * 0.0343) / 2;

  // Sausage
  digitalWrite(st, LOW);
  delayMicroseconds(2);
  digitalWrite(st, HIGH);
  delayMicroseconds(10);
  digitalWrite(st, LOW);
  sr = pulseIn(se, HIGH);
  sd = (sr * 0.0343) / 2;

  // Cheese
  digitalWrite(ct, LOW);
  delayMicroseconds(2);
  digitalWrite(ct, HIGH);
  delayMicroseconds(10);
  digitalWrite(ct, LOW);
  cr = pulseIn(ce, HIGH);
  cd = (cr * 0.0343) / 2;

  // Pizza sauce
   pd = 100.00 - ((analogRead(A0) / 1023.00) * 100.00);

  Serial.print("Distance pizza sauce:");  Serial.println(pd); 
  // Serial.println(analogRead(A0)); 
  if (pd > 85) {swSer.write(10); PL.off();}
  else         {swSer.write(2);  PL.on(); }

       if (pd > 85.0)              Blynk.virtualWrite(V7, 0);
  else if (pd <= 85.0 && pd > 70.0)  Blynk.virtualWrite(V7, 30);
  else if (pd <= 70.0 && pd > 50.0) Blynk.virtualWrite(V7, 60);
  else if (pd <= 50.0)             Blynk.virtualWrite(V7, 100);


  Serial.print("Distance vegetables:"); Serial.println(vd);
  if (vd > 10) { swSer.write(3); VL.off();} 
  else         { swSer.write(4); VL.on(); }

       if (vd > 10)              Blynk.virtualWrite(V9, 0);
  else if (vd <= 10 && vd > 7.5)  Blynk.virtualWrite(V9, 30);
  else if (vd <= 7.5 && vd > 5.5) Blynk.virtualWrite(V9, 60);
  else if (vd <= 5.5)             Blynk.virtualWrite(V9, 100);


  Serial.print("Distance Sausage:"); Serial.println(sd);
  if (sd > 11) {swSer.write(5); SL.off();} //12o0
  else          {swSer.write(6); SL.on();}

       if (sd > 11)              Blynk.virtualWrite(V3, 0);
  else if (sd <= 11 && sd > 9)  Blynk.virtualWrite(V3, 30);
  else if (sd <= 9 && sd > 5.5) Blynk.virtualWrite(V3, 60);
  else if (sd <= 5.5)             Blynk.virtualWrite(V3, 100);

  Serial.print("Distance Cheese:"); Serial.println(cd);
  if (cd > 11) { swSer.write(7);  CL.off();} 
  else        { swSer.write(8);  CL.on(); }

       if (cd > 11)              Blynk.virtualWrite(V8, 0);
  else if (cd <= 11 && cd > 9)  Blynk.virtualWrite(V8, 30);
  else if (cd <= 9 && cd > 5.5)  Blynk.virtualWrite(V8, 60);
  else if (cd <= 5.5)              Blynk.virtualWrite(V8, 100);

  delay(500);

  if (swSer.available() > 0) {
    Serial.println(swSer.read());
   int v = swSer.read(); Blynk.virtualWrite(V5, v);
  }
}
