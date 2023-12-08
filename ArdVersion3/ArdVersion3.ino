
#include <ezButton.h>
#include <max6675.h>
#include <Nextion.h>
#include <Servo.h>
#include <ezButton.h>
#include "max6675.h"

Servo servo;
ezButton toggleSwitch(2);  // create ezButton object that attaches to pin 7

const int Rpower = 3;   // Pin connected to the relay
const int Roven = 7;
const int Rketchup = 52;
int fd4=1;

const int thermoDO = 4; const int thermoCS = 5;  const int thermoCLK = 6;

const int stepPin3 = 22; 
const int dirPin3  = 11; 
const int enPin3   = 24;
const int in3      = 25;

const int stepPin4 = 26; 
const int dirPin4  = 10; 
const int enPin4   = 28;
const int in4      = 29;

const int stepPin2 = 34; 
const int dirPin2  = 35; 
const int enPin2   = 36;
const int in2      = 9;

const int stepPin1 = 30; 
const int dirPin1  = 31; 
const int enPin1   = 32;
const int in1      = 33;

bool pp=0; bool vv=0; bool ss=0; bool cc=0;
bool px=0; bool vx=0; bool sx=0; bool cx=0;
int vf=1; int pf=1; int sf=1; int cf=1;
int rate=0;
int angle = 10;
int sens;

MAX6675 thermocouple(thermoCLK, thermoCS, thermoDO);

NexButton b0 = NexButton(0, 1, "b0");
NexButton b1 = NexButton(0, 2, "b1");

NexCheckbox p  = NexCheckbox(1, 5, "p"); 
NexCheckbox v  = NexCheckbox(1, 6, "v");
NexCheckbox s  = NexCheckbox(1, 7, "s"); 
NexCheckbox c  = NexCheckbox(1, 8, "c");
NexButton back   = NexButton(1, 9, "b0"); 
NexButton confim = NexButton(1, 10, "b1");
NexButton     pe = NexButton(1, 11, "pe"); 
NexButton     ve = NexButton(1, 12, "ve");
NexButton     se = NexButton(1, 13, "se"); 
NexButton     ce = NexButton(1, 14, "ce");

NexButton beackcon = NexButton(2, 1, "b0");

NexButton neword2 = NexButton(3, 4, "b0");
NexButton next    = NexButton(3, 4, "b0");

NexButton r1      = NexButton(4, 1, "b0");
NexButton r2      = NexButton(4, 2, "b1");
NexButton r3      = NexButton(4, 3, "b2");
NexButton r4      = NexButton(4, 4, "b3");
NexButton r5      = NexButton(4, 5, "b4");
NexButton neword1 = NexButton(4, 6, "b5");

NexTouch *nex_listen_list[] ={
  &b0,&b1,&p,&v,&s,&c,&back,&confim,&next,&neword1,&neword2,&beackcon,&r1,&r2,&r3,&r4,&r5,&pe,&ve,&se,&ce, NULL
};

void init_sens() {
  int count = 0;
  Serial.print("inside");

  while (Serial1.available()) {
    sens = Serial1.read();
    Serial.println(sens);

         if (sens == 10) { count++; pf = 0;} 
    else if (sens == 2)  { count++; pf = 1;} 

         if (sens == 3)  { count++; vf = 0;} 
    else if (sens == 4)  { count++; vf = 1;} 

         if (sens == 5)  { count++; sf = 0;} 
    else if (sens == 6)  { count++; sf = 1;} 

         if (sens == 7) { count++; cf = 0;} 
    else if (sens == 8) { count++; cf = 1;} 
    
delay(1000);
    if (count == 4) {
      break; // Exit the loop when count reaches 4
    }
  }
  
}
//void init_sens(){
//   int count=0;
//   Serial.print("inside");
//
//      while (Serial1.available()) {       // read from Serial1 output to Serial
//     sens=Serial1.read();
//     Serial.println(sens);
//
//     if(sens==10){
//      count++;
//      pf=0;
//     
//     }
//      if(sens==2){
//        count++;
//        pf=1;
//     
//      }
//
//     if(sens==3){
//      count++;
//      vf=0;
//     
//     }
//     if(sens==4){
//      count++;
//      vf=1;
//    
//     }
//
//     if(sens==5){
//      count++;
//      sf=0;
//    
//     }
//      if(sens==6){
//        count++;
//        sf=1;
//    
//      }
//
//     if(sens==7){
//      count++;
//      cf=0;
//     
//     }
//     delay(1000);
//      if(sens==8){
//        count++;
//        cf=1;
//     
//      }
//    if(count==4) break;
//     }
//  
//}

//Order Now
void b0_press(void *ptr) {
  Serial.println("Order Now");
  init_sens();

       if(pf==0){
   Serial2.print("vis p,0");  // Set visibility to 0 (hidden)
   Serial2.write(0xff); Serial2.write(0xff); Serial2.write(0xff); delay(200);
   Serial2.print("vis pe,0");  // Set visibility to 0 (hidden)
   Serial2.write(0xff); Serial2.write(0xff); Serial2.write(0xff); delay(200);
                }
  else if(pf==1){
   Serial2.print("vis p,1");  // Set visibility to 0 (hidden)
   Serial2.write(0xff); Serial2.write(0xff); Serial2.write(0xff); delay(200);
   Serial2.print("vis pe,1");  // Set visibility to 0 (hidden)
   Serial2.write(0xff); Serial2.write(0xff); Serial2.write(0xff); delay(200);
                 }

       if(vf==0){
   Serial2.print("vis v,0");  // Set visibility to 0 (hidden)
   Serial2.write(0xff); Serial2.write(0xff); Serial2.write(0xff); delay(200);
   Serial2.print("vis ve,0");  // Set visibility to 0 (hidden)
   Serial2.write(0xff); Serial2.write(0xff); Serial2.write(0xff); delay(200);
                }
  else if(vf==1){
   Serial2.print("vis v,1");  // Set visibility to 0 (hidden)
   Serial2.write(0xff); Serial2.write(0xff); Serial2.write(0xff); delay(200);
   Serial2.print("vis ve,1");  // Set visibility to 0 (hidden)
   Serial2.write(0xff); Serial2.write(0xff); Serial2.write(0xff); delay(200);
                 }

       if(sf==0){
   Serial2.print("vis s,0");  // Set visibility to 0 (hidden)
   Serial2.write(0xff); Serial2.write(0xff); Serial2.write(0xff); delay(200);
   Serial2.print("vis se,0");  // Set visibility to 0 (hidden)
   Serial2.write(0xff); Serial2.write(0xff); Serial2.write(0xff); delay(200);
                }
  else if(sf==1){
   Serial2.print("vis s,1");  // Set visibility to 0 (hidden)
   Serial2.write(0xff); Serial2.write(0xff); Serial2.write(0xff); delay(200);
   Serial2.print("vis se,1");  // Set visibility to 0 (hidden)
   Serial2.write(0xff); Serial2.write(0xff); Serial2.write(0xff); delay(200);
                 }
          
       if(cf==0){
   Serial2.print("vis c,0");  // Set visibility to 0 (hidden)
   Serial2.write(0xff); Serial2.write(0xff); Serial2.write(0xff); delay(500);
   Serial2.print("vis ce,0");  // Set visibility to 0 (hidden)
   Serial2.write(0xff); Serial2.write(0xff); Serial2.write(0xff); delay(500);
                }
  else if(cf==1){
   Serial2.print("vis c,1");  // Set visibility to 0 (hidden)
   Serial2.write(0xff); Serial2.write(0xff); Serial2.write(0xff); delay(500);
   Serial2.print("vis ce,1");  // Set visibility to 0 (hidden)
   Serial2.write(0xff); Serial2.write(0xff); Serial2.write(0xff); delay(500);
                 }
}
void main_press(void *ptr) {
  Serial.println("you pressed main");
  init_sens();
  Serial.print("rate is"); Serial.println(rate); Serial1.write(rate);
}
void main2_press(void *ptr) {
  Serial.println("you pressed main2");
  init_sens();
}
void main3_press(void *ptr) {
  Serial.println("you pressed main3");
  init_sens();
}
void next_press(void *ptr) {
  Serial.println("you pressed next");
}

void p_press(void *ptr) {
pp=!pp;
if(pp==0) px=0;}

void v_press(void *ptr) {
vv=!vv;
if(vv==0) vx=0;}

void s_press(void *ptr) {
ss=!ss;
if(ss==0) sx=0;}

void c_press(void *ptr) {
cc=!cc;
if(cc==0) cx=0;}

void pe_press(void *ptr){
px=!px;
if(px==1) pp=1;}

void ve_press(void *ptr) {
vx=!vx;
if(vx==1) vv=1;}

void se_press(void *ptr) {
sx=!sx;
if(sx==1) ss=1;}

void ce_press(void *ptr) {
cx=!cx;
if(cx==1) cc=1;}

void r1_press(void *ptr) {Serial.println("rate=1");rate=1;}
void r2_press(void *ptr) {Serial.println("rate=2");rate=2;}
void r3_press(void *ptr) {Serial.println("rate=3");rate=3;}
void r4_press(void *ptr) {Serial.println("rate=4");rate=4;}
void r5_press(void *ptr) {Serial.println("rate=5");rate=5;}

//confim
void confim_press(void *ptr) {
Serial.println("confim");
Serial2.print("rate.va0.val=0");  // Set visibility to 0 (hidden)
Serial2.write(0xff);Serial2.write(0xff);Serial2.write(0xff);
  delay(500);
  Serial.println(pp); Serial.println(vv); Serial.println(ss); Serial.println(cc);
  Serial.println(px); Serial.println(vx); Serial.println(sx); Serial.println(cx);
  startmoving ();
  pp=0;cc=0;vv=0;ss=0; px=0;cx=0;vx=0;sx=0;
}

void startmoving (){
  digitalWrite(Roven, LOW);
//First Stage
  digitalWrite(enPin1,LOW); 
  digitalWrite(in1,LOW);
  // digitalWrite(dirPin1,LOW); 
   for(int x = 0; x < 3400; x++)
      {
       digitalWrite(stepPin1,HIGH); 
       delayMicroseconds(1500); 
       digitalWrite(stepPin1,LOW); 
       delayMicroseconds(1500); 
      }
   if(pp==1)//if ketchup select
      {
  if(pf==0){
   Serial2.print("vis p,0");  // Set visibility to 0 (hidden)
   Serial2.write(0xff); Serial2.write(0xff); Serial2.write(0xff); delay(200);
   Serial2.print("vis pe,0");  // Set visibility to 0 (hidden)
   Serial2.write(0xff); Serial2.write(0xff); Serial2.write(0xff); delay(200);
                }
  else if(pf==1){
   Serial2.print("vis p,1");  // Set visibility to 0 (hidden)
   Serial2.write(0xff); Serial2.write(0xff); Serial2.write(0xff); delay(200);
   Serial2.print("vis pe,1");  // Set visibility to 0 (hidden)
   Serial2.write(0xff); Serial2.write(0xff); Serial2.write(0xff); delay(200);
                 }
      delay(3000); 
      }
   for(int x = 0; x < 3400; x++)
      {
       digitalWrite(stepPin1,HIGH); 
       delayMicroseconds(1500); 
       digitalWrite(stepPin1,LOW); 
       delayMicroseconds(1500); 
      }

//Second Stage
  digitalWrite(enPin2,LOW); 
   for(int x = 0; x < 1200; x++) 
      {
       digitalWrite(stepPin1,HIGH); 
       digitalWrite(stepPin2,HIGH); 
       delayMicroseconds(1500); 
       digitalWrite(stepPin1,LOW); 
       digitalWrite(stepPin2,LOW); 
       delayMicroseconds(1500); 
      }
  //  digitalWrite(dirPin2,LOW); 
   digitalWrite(enPin1,HIGH); //turnoff first STAGE
   for(int x = 0; x < 10; x++)
      {
       digitalWrite(stepPin2,HIGH); 
       delayMicroseconds(1500); 
       digitalWrite(stepPin2,LOW); 
       delayMicroseconds(1500); 
      }
   if(ss==1)//if sasuge yes
     {
       digitalWrite(in3,HIGH);
       digitalWrite(enPin3,LOW); 
       if(sx==1){
        // digitalWrite(dirPin3,fd4);
        for(int x = 0; x < 1000; x++)
          {
           digitalWrite(stepPin2,HIGH); 
           digitalWrite(stepPin3,HIGH); 
           delayMicroseconds(700); 
           digitalWrite(stepPin2,LOW); 
           digitalWrite(stepPin3,LOW); 
           delayMicroseconds(700); 
          }
           for(int x = 0; x < 1500; x++)
          {
          // digitalWrite(stepPin2,HIGH); 
           digitalWrite(stepPin3,HIGH); 
           delayMicroseconds(700); 
          // digitalWrite(stepPin2,LOW); 
           digitalWrite(stepPin3,LOW); 
           delayMicroseconds(700); 
          }
          for(int x = 0; x < 1000; x++)
          {
           digitalWrite(stepPin2,HIGH); 
           digitalWrite(stepPin3,HIGH); 
           delayMicroseconds(700); 
           digitalWrite(stepPin2,LOW); 
           digitalWrite(stepPin3,LOW); 
           delayMicroseconds(700); 
          }
         // digitalWrite(dirPin3,HIGH); 
//           for(int x = 0; x < 1100; x++)
//          {
//           digitalWrite(stepPin2,HIGH); 
//           digitalWrite(stepPin3,HIGH); 
//           delayMicroseconds(500); 
//           digitalWrite(stepPin2,LOW); 
//           digitalWrite(stepPin3,LOW); 
//           delayMicroseconds(500); 
//          }
       }
        else{
          // digitalWrite(dirPin3,fd4);
       for(int x = 0; x < 2600; x++)
          {
           digitalWrite(stepPin2,HIGH); 
           digitalWrite(stepPin3,HIGH); 
           delayMicroseconds(700); 
           digitalWrite(stepPin2,LOW); 
           digitalWrite(stepPin3,LOW); 
           delayMicroseconds(700); 
          }
           
//           for(int x = 0; x < 1100; x++)
//          {
//           digitalWrite(stepPin2,HIGH); 
//           digitalWrite(stepPin3,HIGH); 
//           delayMicroseconds(1000); 
//           digitalWrite(stepPin2,LOW); 
//           digitalWrite(stepPin3,LOW); 
//           delayMicroseconds(1000); 
//          }
          } 
          for(int x = 0; x < 2000; x++)
          {
           digitalWrite(stepPin2,HIGH); 
           delayMicroseconds(1500); 
           digitalWrite(stepPin2,LOW); 
           delayMicroseconds(1500); 
          }
      }
   else if(ss==0)
      {
       for(int x = 0; x < 4200; x++)
          {
           digitalWrite(stepPin2,HIGH); 
           delayMicroseconds(500); 
           digitalWrite(stepPin2,LOW); 
           delayMicroseconds(500); 
          }
      }
      
  digitalWrite(enPin3,HIGH); 
  digitalWrite(in1,HIGH);
  digitalWrite(enPin1,LOW);
  
   for(int x = 0; x < 1800; x++)
      {
       digitalWrite(stepPin1,HIGH); 
       digitalWrite(stepPin2,HIGH); 
       delayMicroseconds(1500); 
       digitalWrite(stepPin1,LOW); 
       digitalWrite(stepPin2,LOW); 
       delayMicroseconds(1500); 
      }

  digitalWrite(enPin2,HIGH); 
   
   if(vv==1)
     {
      //  digitalWrite(dirPin3,fd4);
      digitalWrite(enPin3,LOW); 
     // digitalWrite(dirPin3,LOW); 
       digitalWrite(in3,LOW);
      if(vx==1){
         for(int x = 0; x < 1000; x++)
          {
           digitalWrite(stepPin1,HIGH); 
           digitalWrite(stepPin3,HIGH); 
           delayMicroseconds(700); 
           digitalWrite(stepPin1,LOW); 
           digitalWrite(stepPin3,LOW); 
           delayMicroseconds(700); 
          }
           for(int x = 0; x < 1500; x++)
          {
          // digitalWrite(stepPin2,HIGH); 
           digitalWrite(stepPin3,HIGH); 
           delayMicroseconds(700); 
          // digitalWrite(stepPin2,LOW); 
           digitalWrite(stepPin3,LOW); 
           delayMicroseconds(700); 
          }
          for(int x = 0; x < 1000; x++)
          {
           digitalWrite(stepPin1,HIGH); 
           digitalWrite(stepPin3,HIGH); 
           delayMicroseconds(700); 
           digitalWrite(stepPin1,LOW); 
           digitalWrite(stepPin3,LOW); 
           delayMicroseconds(700); 
          }
//          digitalWrite(dirPin3,HIGH); 
//           for(int x = 0; x < 1100; x++)
//          {
//           digitalWrite(stepPin1,HIGH); 
//           digitalWrite(stepPin3,HIGH); 
//           delayMicroseconds(500); 
//           digitalWrite(stepPin1,LOW); 
//           digitalWrite(stepPin3,LOW); 
//           delayMicroseconds(500); 
//          }
       }
      else{
       for(int x = 0; x < 2400; x++)//1100
          {
           digitalWrite(stepPin1,HIGH); 
           digitalWrite(stepPin3,HIGH); 
           delayMicroseconds(1500); 
           digitalWrite(stepPin1,LOW); 
           digitalWrite(stepPin3,LOW); 
           delayMicroseconds(1500); 
          }
//          digitalWrite(dirPin3,HIGH); 
//           for(int x = 0; x < 1100; x++)
//          {
//           digitalWrite(stepPin1,HIGH); 
//           digitalWrite(stepPin3,HIGH); 
//           delayMicroseconds(1500); 
//           digitalWrite(stepPin1,LOW); 
//           digitalWrite(stepPin3,LOW); 
//           delayMicroseconds(1500); 
//          }
          } //else
          for(int x = 0; x < 2500; x++)
          {
           digitalWrite(stepPin1,HIGH); 
           delayMicroseconds(1500); 
           digitalWrite(stepPin1,LOW); 
           delayMicroseconds(1500); 
          }
      }
   else if (vv==0)
      {
       for(int x = 0; x < 4500; x++) 
          {
           digitalWrite(stepPin1,HIGH); 
           delayMicroseconds(500); 
           digitalWrite(stepPin1,LOW); 
           delayMicroseconds(500); 
          }
      }
      

  digitalWrite(enPin3,HIGH); 
  digitalWrite(in2,HIGH);
  digitalWrite(enPin2,LOW);
  
   for(int x = 0; x < 1800; x++)
      {
       digitalWrite(stepPin1,HIGH); 
       digitalWrite(stepPin2,HIGH); 
       delayMicroseconds(1500); 
       digitalWrite(stepPin1,LOW); 
       digitalWrite(stepPin2,LOW); 
       delayMicroseconds(1500); 
      }

  digitalWrite(enPin1,HIGH); 
   for(int x = 0; x < 100; x++) 
      {
       digitalWrite(stepPin2,HIGH); 
       delayMicroseconds(1500); 
       digitalWrite(stepPin2,LOW); 
       delayMicroseconds(1500); 
      }

   if(cc==1)
      {
        digitalWrite(enPin4,LOW); 
       // digitalWrite(dirPin4,fd4); 
 for(int x = 0; x < 200; x++)
          {
         //  digitalWrite(stepPin2,HIGH); 
           digitalWrite(stepPin4,HIGH); 
           delayMicroseconds(700); 
          // digitalWrite(stepPin2,LOW); 
           digitalWrite(stepPin4,LOW); 
           delayMicroseconds(700); 
          }
          
        
         if(cx==1){
            // digitalWrite(dirPin3,fd4);
         for(int x = 0; x < 500; x++)
          {
           digitalWrite(stepPin2,HIGH); 
           digitalWrite(stepPin4,HIGH); 
           delayMicroseconds(700); 
           digitalWrite(stepPin2,LOW); 
           digitalWrite(stepPin4,LOW); 
           delayMicroseconds(700); 
          }
           for(int x = 0; x < 1500; x++)
          {
          // digitalWrite(stepPin2,HIGH); 
           digitalWrite(stepPin4,HIGH); 
           delayMicroseconds(700); 
          // digitalWrite(stepPin2,LOW); 
           digitalWrite(stepPin4,LOW); 
           delayMicroseconds(700); 
          }
          for(int x = 0; x < 500; x++)
          {
           digitalWrite(stepPin2,HIGH); 
           digitalWrite(stepPin4,HIGH); 
           delayMicroseconds(700); 
           digitalWrite(stepPin2,LOW); 
           digitalWrite(stepPin4,LOW); 
           delayMicroseconds(700); 
          }
           for(int x = 0; x < 1500; x++)
          {
          // digitalWrite(stepPin2,HIGH); 
           digitalWrite(stepPin4,HIGH); 
           delayMicroseconds(700); 
          // digitalWrite(stepPin2,LOW); 
           digitalWrite(stepPin4,LOW); 
           delayMicroseconds(700); 
          }
           for(int x = 0; x < 1000; x++)
          {
           digitalWrite(stepPin2,HIGH); 
           digitalWrite(stepPin4,HIGH); 
           delayMicroseconds(700); 
           digitalWrite(stepPin2,LOW); 
           digitalWrite(stepPin4,LOW); 
           delayMicroseconds(700); 
          }
//          digitalWrite(dirPin4,HIGH); 
//           for(int x = 0; x < 1100; x++)
//          {
//           digitalWrite(stepPin2,HIGH); 
//           digitalWrite(stepPin4,HIGH); 
//           delayMicroseconds(500); 
//           digitalWrite(stepPin2,LOW); 
//           digitalWrite(stepPin4,LOW); 
//           delayMicroseconds(500); 
//          }
       }
else{
        // digitalWrite(dirPin3,fd4);
       for(int x = 0; x < 1000; x++)
          {
           digitalWrite(stepPin2,HIGH); 
           digitalWrite(stepPin4,HIGH); 
           delayMicroseconds(700); 
           digitalWrite(stepPin2,LOW); 
           digitalWrite(stepPin4,LOW); 
           delayMicroseconds(700); 
          }
           for(int x = 0; x < 1000; x++)
          {
          // digitalWrite(stepPin2,HIGH); 
           digitalWrite(stepPin4,HIGH); 
           delayMicroseconds(700); 
          // digitalWrite(stepPin2,LOW); 
           digitalWrite(stepPin4,LOW); 
           delayMicroseconds(700); 
          }
           for(int x = 0; x < 1000; x++)
          {
           digitalWrite(stepPin2,HIGH); 
           digitalWrite(stepPin4,HIGH); 
           delayMicroseconds(700); 
           digitalWrite(stepPin2,LOW); 
           digitalWrite(stepPin4,LOW); 
           delayMicroseconds(700); 
          }
           
//          digitalWrite(dirPin4,HIGH); 
//           for(int x = 0; x < 1100; x++)
//          {
//           digitalWrite(stepPin2,HIGH); 
//           digitalWrite(stepPin4,HIGH); 
//           delayMicroseconds(1500); 
//           digitalWrite(stepPin2,LOW); 
//           digitalWrite(stepPin4,LOW); 
//           delayMicroseconds(1500); 
//          }

} //else
            for(int x = 0; x < 2000; x++)
          {
           digitalWrite(stepPin2,HIGH); 
           delayMicroseconds(1500); 
           digitalWrite(stepPin2,LOW); 
           delayMicroseconds(1500); 
          }
      }
   else if(cc==0)
      {
       for(int x = 0; x < 2000; x++)
          {
           digitalWrite(stepPin2,HIGH); 
           delayMicroseconds(500); 
           digitalWrite(stepPin2,LOW); 
           delayMicroseconds(500); 
          }
      }

  digitalWrite(enPin4,HIGH); 
  // digitalWrite(dirPin4,fd4); 
  digitalWrite(in4,HIGH);
  
   for(int x = 0; x < 2000; x++)
      {
       digitalWrite(stepPin2,HIGH); 
       delayMicroseconds(1500); 
       digitalWrite(stepPin2,LOW); 
       delayMicroseconds(1500); 
      }

       digitalWrite(enPin4,LOW); 
     digitalWrite(in4,LOW);
      // digitalWrite(dirPin4,LOW);

       for(int x = 0; x < 1600; x++)
      {
       digitalWrite(stepPin4,HIGH); 
       digitalWrite(stepPin2,HIGH); 
       delayMicroseconds(1500); 
       digitalWrite(stepPin4,LOW); 
       digitalWrite(stepPin2,LOW); 
       delayMicroseconds(1500); 
      }
       digitalWrite(enPin2,HIGH); 
     
       
    for(int x = 0; x < 8000; x++) {
    digitalWrite(stepPin4,HIGH);  
    delayMicroseconds(7000); 
    digitalWrite(stepPin4,LOW); 
    delayMicroseconds(7000); 
    }

  digitalWrite(enPin1,HIGH); 
  digitalWrite(enPin2,HIGH); 
  digitalWrite(enPin3,HIGH); 
  digitalWrite(enPin4,HIGH); 
//
 Serial1.write(rate); 
    Serial2.print("rate.va0.val=1");  // Set visibility to 0 (hidden)
    Serial2.write(0xff);Serial2.write(0xff);Serial2.write(0xff);
    delay(1000);
    Serial2.print("page 0");  // Set visibility to 0 (hidden)
    Serial2.write(0xff); Serial2.write(0xff); Serial2.write(0xff);
    delay(1000);
    init_sens();

    fd4=!fd4;

//    if(fd4==0){
//       digitalWrite(dirPin2,LOW); 
//    }
}

void back_press(void *ptr) {
  Serial.println("back");
  init_sens();
}

void setup() {
  Serial.begin(9600);
  Serial1.begin(9600);
  Serial2.begin(9600);
  nexInit();
  delay(100);
  Serial2.write(0xff); Serial2.write(0xff); Serial2.write(0xff);
  servo.attach(8);


  toggleSwitch.setDebounceTime(50); // set debounce time to 50 milliseconds
  pinMode(2, INPUT_PULLUP);  // 

  attachInterrupt(digitalPinToInterrupt(2), switchInterrupt, CHANGE); // Attach interrupt to pin 7
  pinMode(Rpower, OUTPUT); 
  pinMode(Roven, OUTPUT);
  digitalWrite(Roven, HIGH);
  pinMode(Rketchup, OUTPUT);
  
  pinMode(stepPin4,OUTPUT); 
  pinMode(dirPin4,OUTPUT);
  pinMode(enPin4,OUTPUT);
  pinMode(in4,OUTPUT);

  pinMode(stepPin3,OUTPUT); 
  pinMode(dirPin3,OUTPUT);
  pinMode(enPin3,OUTPUT);
  pinMode(in3,OUTPUT);

  pinMode(stepPin2,OUTPUT); 
  pinMode(dirPin2,OUTPUT);
  pinMode(enPin2,OUTPUT);
  pinMode(in2,OUTPUT);
   
  pinMode(stepPin1,OUTPUT); 
  pinMode(dirPin1,OUTPUT);
  pinMode(enPin1,OUTPUT);
  pinMode(in1,OUTPUT);

  b0.attachPush(b0_press, &b0);

  p.attachPush(p_press, &p);
  v.attachPush(v_press, &v);
  s.attachPush(s_press, &s);
  c.attachPush(c_press, &c);

  pe.attachPush(pe_press, &pe);
  ve.attachPush(ve_press, &ve);
  se.attachPush(se_press, &se);
  ce.attachPush(ce_press, &ce);
  
  r1.attachPush(r1_press, &r1);
  r2.attachPush(r2_press, &r2);
  r3.attachPush(r3_press, &r3);
  r4.attachPush(r4_press, &r4);
  r5.attachPush(r5_press, &r5);
  next.attachPush(next_press, &next);
  neword1.attachPush(main_press, &neword1);
  neword2.attachPush(main2_press, &neword2);
  beackcon.attachPush(main3_press, &beackcon);
  back.attachPush(back_press, &back);
  confim.attachPush(confim_press, &confim);
  Serial2.write(0xff); Serial2.write(0xff); Serial2.write(0xff);

//********************************************************************//initial state
  digitalWrite(Roven, HIGH);
  digitalWrite(Rpower, LOW); 
  digitalWrite(Rketchup,LOW); 
  servo.write(120);
  fd4=1;

  digitalWrite(in1,LOW); 
  digitalWrite(in2,LOW); 
  digitalWrite(in3,LOW); 
  digitalWrite(in4,HIGH);

  digitalWrite(enPin1,HIGH); 
  digitalWrite(enPin2,HIGH); 
  digitalWrite(enPin3,HIGH); 
  digitalWrite(enPin4,HIGH);
  
  digitalWrite(dirPin1,LOW); 
  digitalWrite(dirPin2,LOW); 
  digitalWrite(dirPin3,LOW); 
  digitalWrite(dirPin4,LOW); 
  Serial2.print("rate.va0.val=1");  // Set visibility to 0 (hidden)
    Serial2.write(0xff); Serial2.write(0xff); Serial2.write(0xff);
    delay(500);

 init_sens();
}

void loop() {
  digitalWrite(Roven, HIGH);
  nexLoop(nex_listen_list);
  int rec;
 if(Serial1.available()){
 Serial.print("from ESP ");
 rec=Serial1.read();
 Serial.println(rec);
  if(rec==232){
   digitalWrite(Rpower, HIGH); // Turn off the relay
 
 }
 else if(rec==233){
   digitalWrite(Rpower, LOW); // Turn off the relay
 
 }
}

}

void switchInterrupt() {
  int state = digitalRead(2); // Read the current state of the switch

  if (state == LOW) {
    Serial.println("The switch: ON");
    digitalWrite(Rpower, LOW); // Turn on the relay (active low)
  } else {
    Serial.println("The switch: OFF");
    digitalWrite(Rpower, HIGH); // Turn off the relay (active low)
  }
}