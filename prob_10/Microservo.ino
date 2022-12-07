#include <Servo.h>
Servo servo; //Servo = servo
#define MINDEG 0
#define MAXDEG 180
#define MINA0 0
#define MAXA0 1023

int speedValue = 0;
int deg = 0;
int R_LED = 2;
int B_LED = 3;
int G_LED = 4;
int Y_LED = 5;


void setup()
{ 
  pinMode(R_LED , OUTPUT);
  pinMode(B_LED , OUTPUT);
  pinMode(G_LED , OUTPUT);
  pinMode(Y_LED , OUTPUT);
  servo.attach(10);   //servo serial

  Serial.begin(9600);
    
}

void loop()
{
  speedValue = analogRead(A0);
  Serial.print("speedValue :  ");
  Serial.println(speedValue);
  deg = map(speedValue, MINA0, MAXA0, MINDEG, MAXDEG);//Servo Maxdeg = 180 
  Serial.print("deg :  ");
  Serial.println(deg);
  servo.write(deg);
 
  if(deg < 45)  //deg < 45 LED OFF
  {
    digitalWrite(R_LED, LOW); 
    digitalWrite(B_LED, LOW);
    digitalWrite(G_LED, LOW);
    digitalWrite(Y_LED, LOW);
  }
  else if(deg > 45)
  {
    delay(speedValue);  //speedValue = Led Light speed
    digitalWrite(R_LED, HIGH);
    digitalWrite(B_LED, LOW);
    digitalWrite(G_LED, LOW);
    digitalWrite(Y_LED, LOW);
    delay(speedValue);
    digitalWrite(R_LED, LOW);
    digitalWrite(B_LED, HIGH);
    digitalWrite(G_LED, LOW);
    digitalWrite(Y_LED, LOW);
    delay(speedValue);
    digitalWrite(R_LED, LOW);
    digitalWrite(B_LED, LOW);
    digitalWrite(G_LED, HIGH);
    digitalWrite(Y_LED, LOW);
    delay(speedValue);
    digitalWrite(R_LED, LOW);
    digitalWrite(B_LED, LOW);
    digitalWrite(G_LED, LOW);
    digitalWrite(Y_LED, HIGH);
  }
  
}
