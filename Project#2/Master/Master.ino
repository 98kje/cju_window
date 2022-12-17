#include <Wire.h> // Wire.h 라이브러리 사용
#include <LiquidCrystal.h>

LiquidCrystal lcd(12, 11, 9, 8, 7, 6);

#define MAXPRESS 205
#define MINPRESS 0
#define DELAYTIME 500

const int redled = 5;
const int yellowled = 4;
const int greenled = 3;

int weight = 0;


void setup() 
{
  Wire.begin(); // 인자 값이 없으면 마스터용임을 나타냄
  Serial.begin(9600); // 시리얼 모니터 시작
    lcd.begin(16, 2);
    lcd.print("Kim jae Eun");
    lcd.setCursor(0,1);
    lcd.print("Project#2");
  
    delay(3000); // 3초 정도의 딜레이 이후 초기화 시키기 위함.
    lcd.clear();
  
    pinMode(redled,OUTPUT); //핀모드 설정으로 각각의 아웃풋설정
    pinMode(yellowled,OUTPUT);
    pinMode(greenled,OUTPUT);
}

void loop() 
{
  Wire.requestFrom(7, 1); // 슬레이브 (주소, 바이트)가져오기
  while (Wire.available()) // 읽을 데이터가 있다면
    { 
    int num = Wire.read(); // Num에 저장
        weight = num;
        Serial.println(weight); //weight에 저장한 값을 프린트
  }
  
        if(weight == MINPRESS) //0일때 초록색, 0~205 사이일때 노란색, 205일때 빨간색신호. 
        {
           digitalWrite(greenled,HIGH);
        }
      else
        {
          digitalWrite(greenled,LOW);
        }
  
        if((weight > MINPRESS) && (weight < MAXPRESS))
        {
           digitalWrite(yellowled,HIGH);
        }
      else
        {
          digitalWrite(yellowled,LOW);
        }
  
        if(weight == MAXPRESS)
        {
           digitalWrite(redled,HIGH);
        }
      else
        {
          digitalWrite(redled,LOW);
        }
      lcd.setCursor(0,0);
      lcd.print("Weight");
    lcd.setCursor(2,1);
        lcd.print(weight);
      lcd.setCursor(6,1);
      lcd.print(" kg");
      if (weight == MAXPRESS)
        {
          lcd.setCursor(0,0);
          lcd.print("WARNING !!"); // MAX값이면 이면 WARNING 신호 알림.
        }
  
delay(DELAYTIME);
  
}
