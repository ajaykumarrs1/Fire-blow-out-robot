

#include <Servo.h>  
Servo myservo;

int pos = 0;   
boolean fire = false;

#define Left 9      // left sensor
#define Right 10    // right sensor
#define Forward 8   //front sensor

#define LM 2       // left motor
#define RM 4       // right motor
#define pump 6
int Beep=3;// select digital pin 9 for the buzzer


void setup()
{
  pinMode(Left, INPUT);
  pinMode(Right, INPUT);
  pinMode(Forward, INPUT);
  pinMode(LM, OUTPUT);
  pinMode(RM, OUTPUT);
  pinMode(pump, OUTPUT);
  pinMode(Beep,OUTPUT);// set buzzer pin as “output”

  myservo.attach(11);
  myservo.write(90);
}

void put_off_fire()
{
    delay (500);

    digitalWrite(LM, HIGH);
    digitalWrite(RM, HIGH);
   
   digitalWrite(pump, HIGH);
   delay(500);
   
    for (pos = 50; pos <= 130; pos += 1) {
    myservo.write(pos);
    delay(10); 
  }
  for (pos = 130; pos >= 50; pos -= 1) {
    myservo.write(pos);
    delay(10);
  }
 
  digitalWrite(pump,LOW);
  myservo.write(90);
 
  fire=false;
}

void loop()
{
   myservo.write(90); //Sweep_Servo(); 

    if (digitalRead(Left) ==1 && digitalRead(Right)==1 && digitalRead(Forward) ==1)
    {
   
    digitalWrite(LM, HIGH);
    digitalWrite(RM, HIGH);
    digitalWrite(Beep,HIGH);
    }
   
    else if (digitalRead(Forward) ==0)
    {
    digitalWrite(LM, HIGH);
    digitalWrite(RM, HIGH);
    digitalWrite(Beep,HIGH);
    fire = true;
    }
   
    else if (digitalRead(Left) ==0)
    {
    digitalWrite(LM, LOW);
    digitalWrite(RM, HIGH);
    digitalWrite(Beep,HIGH);
    }
   
    else if (digitalRead(Right) ==0)
    {
    digitalWrite(LM, HIGH);
    digitalWrite(RM, LOW);
     digitalWrite(Beep,HIGH);
    }
   
delay(300);//change this value to increase the distance

     while (fire == true)
     {
      put_off_fire();
     }
}
