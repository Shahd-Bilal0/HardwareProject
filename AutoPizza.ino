#include <Nextion.h>

#include <Servo.h>

bool pp=0;
bool vv=0;
bool ss=0;
bool cc=0;

Servo servo;
int angle = 10;

const int relayIN4Pin = 12;

const int stepPin3 = 22; 
const int dirPin3  = 23; 
const int enPin3   = 24;
const int in3      = 25;

const int stepPin4 = 26; 
const int dirPin4  = 27; 
const int enPin4   = 28;
const int in4      = 29;

const int stepPin2 = 34; 
const int dirPin2  = 35; 
const int enPin2   = 36;
const int in2      = 37;

const int stepPin1 = 30; 
const int dirPin1  = 31; 
const int enPin1   = 32;
const int in1      = 33;

NexButton b0 = NexButton(0, 1, "b0");
NexButton b1 = NexButton(0, 2, "b1");

NexCheckbox p = NexCheckbox(1, 5, "p"); 
NexCheckbox v = NexCheckbox(1, 6, "v");
NexCheckbox s = NexCheckbox(1, 7, "s"); 
NexCheckbox c = NexCheckbox(1, 8, "c");

NexButton back   = NexButton(1, 9, "b0"); 
NexButton confim = NexButton(1, 10, "b1");

NexTouch *nex_listen_list[] ={
  &b0,&b1,&p,&v,&s,&c,&back,&confim, NULL
};

void b0_press(void *ptr) {
  Serial.println("Order Now");
}

void p_press(void *ptr) {pp=!pp;}
void v_press(void *ptr) {vv=!vv;}
void s_press(void *ptr) {ss=!ss;}
void c_press(void *ptr) {cc=!cc;}

void confim_press(void *ptr) {
  Serial.println("confim");
  Serial.println(pp); Serial.println(vv); Serial.println(ss); Serial.println(cc);
  startmoving ();
  pp=0;cc=0;vv=0;ss=0;
}

void startmoving (){
  
  digitalWrite(enPin1,LOW); 
  digitalWrite(in1,LOW);
    digitalWrite(dirPin1,LOW); 
   for(int x = 0; x < 3280; x++)
      {
       digitalWrite(stepPin1,HIGH); 
       delayMicroseconds(1500); 
       digitalWrite(stepPin1,LOW); 
       delayMicroseconds(1500); 
      }
   if(pp==1)
      {
        servo.write(30);
       digitalWrite(relayIN4Pin, LOW);
       delay(500);
       digitalWrite(relayIN4Pin, HIGH);
       delay(500);
       digitalWrite(relayIN4Pin, LOW);
       delay(500);
       servo.write(120);
      }
   for(int x = 0; x < 3400; x++)
      {
       digitalWrite(stepPin1,HIGH); 
       delayMicroseconds(1500); 
       digitalWrite(stepPin1,LOW); 
       delayMicroseconds(1500); 
      }

  digitalWrite(enPin2,LOW); 
 
   for(int x = 0; x < 1600; x++) 
      {
       digitalWrite(stepPin1,HIGH); 
       digitalWrite(stepPin2,HIGH); 
       delayMicroseconds(1500); 
       digitalWrite(stepPin1,LOW); 
       digitalWrite(stepPin2,LOW); 
       delayMicroseconds(1500); 
      }
         digitalWrite(dirPin2,LOW); 
  
  digitalWrite(enPin1,HIGH); 
   
   for(int x = 0; x < 180; x++)
      {
       digitalWrite(stepPin2,HIGH); 
       delayMicroseconds(1500); 
       digitalWrite(stepPin2,LOW); 
       delayMicroseconds(1500); 
      }
   if(ss==1)
     {
       Serial.println("hi");
        digitalWrite(in3,HIGH);
       digitalWrite(enPin3,LOW); 
       for(int x = 0; x < 2200; x++)
          {
           digitalWrite(stepPin2,HIGH); 
           digitalWrite(stepPin3,HIGH); 
           delayMicroseconds(1500); 
           digitalWrite(stepPin2,LOW); 
           digitalWrite(stepPin3,LOW); 
           delayMicroseconds(1500); 
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
           delayMicroseconds(1500); 
           digitalWrite(stepPin2,LOW); 
           delayMicroseconds(1500); 
          }
      }
      
      

  digitalWrite(enPin3,HIGH); 
  digitalWrite(in1,HIGH);
  digitalWrite(enPin1,LOW);
   for(int x = 0; x < 1600; x++)
      {
       digitalWrite(stepPin1,HIGH); 
       digitalWrite(stepPin2,HIGH); 
       delayMicroseconds(1500); 
       digitalWrite(stepPin1,LOW); 
       digitalWrite(stepPin2,LOW); 
       delayMicroseconds(1500); 
      }

  digitalWrite(enPin2,HIGH); 
   for(int x = 0; x < 180; x++)
      {
       digitalWrite(stepPin1,HIGH); 
       delayMicroseconds(1500); 
       digitalWrite(stepPin1,LOW); 
       delayMicroseconds(1500); 
     }
   if(vv==1)
     {
      
     
      digitalWrite(enPin3,LOW); 
       digitalWrite(in3,LOW);
       for(int x = 0; x < 2200; x++) 
          {
           digitalWrite(stepPin1,HIGH); 
           digitalWrite(stepPin3,HIGH); 
           delayMicroseconds(1500); 
           digitalWrite(stepPin1,LOW); 
           digitalWrite(stepPin3,LOW); 
           delayMicroseconds(1500); 
          }
          for(int x = 0; x < 2000; x++)
          {
           digitalWrite(stepPin1,HIGH); 
           delayMicroseconds(1500); 
           digitalWrite(stepPin1,LOW); 
           delayMicroseconds(1500); 
          }
      }
   else if (vv==0)
      {
       for(int x = 0; x < 2000; x++) 
          {
           digitalWrite(stepPin1,HIGH); 
           delayMicroseconds(1500); 
           digitalWrite(stepPin1,LOW); 
           delayMicroseconds(1500); 
          }
      }
      

  digitalWrite(enPin3,HIGH); 
  digitalWrite(in2,HIGH);
  digitalWrite(enPin2,LOW);
   for(int x = 0; x < 1600; x++)
      {
       digitalWrite(stepPin1,HIGH); 
       digitalWrite(stepPin2,HIGH); 
       delayMicroseconds(1500); 
       digitalWrite(stepPin1,LOW); 
       digitalWrite(stepPin2,LOW); 
       delayMicroseconds(1500); 
      }

  digitalWrite(enPin1,HIGH); 
   for(int x = 0; x < 180; x++) 
      {
       digitalWrite(stepPin2,HIGH); 
       delayMicroseconds(1500); 
       digitalWrite(stepPin2,LOW); 
       delayMicroseconds(1500); 
      }
   if(cc==1)
      {
        digitalWrite(enPin4,LOW); 
         for(int x = 0; x < 2200; x++)
            {
             digitalWrite(stepPin2,HIGH); 
             digitalWrite(stepPin4,HIGH); 
             delayMicroseconds(1500); 
             digitalWrite(stepPin2,LOW); 
             digitalWrite(stepPin4,LOW); 
             delayMicroseconds(1500); 
            }
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
           delayMicroseconds(1500); 
           digitalWrite(stepPin2,LOW); 
           delayMicroseconds(1500); 
          }
      }

  digitalWrite(enPin4,HIGH); 
  digitalWrite(in4,HIGH);
   for(int x = 0; x < 2000; x++)
      {
       digitalWrite(stepPin2,HIGH); 
       delayMicroseconds(1500); 
       digitalWrite(stepPin2,LOW); 
       delayMicroseconds(1500); 
      }
  digitalWrite(enPin1,HIGH); 
  digitalWrite(enPin2,HIGH); 
  digitalWrite(enPin3,HIGH); 
  digitalWrite(enPin4,HIGH); 
}

void back_press(void *ptr) {
  Serial.println("back");
}

void setup() {
    servo.attach(8);
  servo.write(120);
  nexInit();

  Serial.begin(9600);
  Serial1.begin(9600);
  Serial2.begin(9600);

  Serial2.write(0xff);
  Serial2.write(0xff);
  Serial2.write(0xff);

  b0.attachPush(b0_press, &b0);

  p.attachPush(p_press, &p);
  v.attachPush(v_press, &v);
  s.attachPush(s_press, &s);
  c.attachPush(c_press, &c);

  back.attachPush(back_press, &back);
  confim.attachPush(confim_press, &confim);

  Serial2.write(0xff);
  Serial2.write(0xff);
  Serial2.write(0xff);

  pinMode(relayIN4Pin, OUTPUT);
  
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

//********************************************************************//
  digitalWrite(in1,LOW); 
  digitalWrite(in2,LOW); 
  digitalWrite(in3,LOW); 
  digitalWrite(in4,LOW);
  digitalWrite(in4,HIGH);

  digitalWrite(enPin1,HIGH); 
  digitalWrite(enPin2,HIGH); 
  digitalWrite(enPin3,HIGH); 
  digitalWrite(enPin4,HIGH);
  
  digitalWrite(dirPin1,LOW); 
  digitalWrite(dirPin2,LOW); 
  digitalWrite(dirPin3,LOW); 
  digitalWrite(dirPin4,LOW); 
}

void loop() {
  nexLoop(nex_listen_list);
}
