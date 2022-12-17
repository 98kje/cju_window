#include <Wire.h> 


void setup() 
{
    Serial.begin(9600);
  Wire.begin(7); // 슬레이브 주소 설정 1번과 2번의 주소값은 일치해야함.
  Wire.onRequest(requestEvent); // 마스터에서 요청이 오면
  
    
} // requestEvent()함수 호출
void loop() 
{
  delay(100); // 0.1초의 대기 상태
}
void requestEvent() 
{ // requestEvent()함수
    int Press = analogRead(A1);  //압력센서의 값을 Press에 저장
    Serial.print("Press : ");
    Serial.println(Press); //Press 출력
    Wire.write(Press); //press값 전달
    delay(500);
}
