#include "ServoValve.h"

ServoValve::ServoValve() {};

void ServoValve::initValve(int _duration) {
  leftServo.attach(PIN_LSERVO);
  rightServo.attach(PIN_RSERVO);
  duration = _duration;
  allClose();
  allOpen();
}

void ServoValve::allClose(void) {
  // 모든 밸브를 닫는 방향으로
  // 오른쪽 밸브 역방향 회전시 열음.
  // 왼쪽 밸브 정방향 회전시 열음.
  int cTime = millis();
  int tDuration = duration;
  setDuration(500); // 1500ms
  rotate(LEFTVALVE, true, 0); 
  rotate(RIGHTVALVE, true, 0);
  //delay(5000);
  while (millis() - cTime < 2000) ; // 2sec
  stopAllValve();
  setDuration(tDuration);
}

void ServoValve::allOpen() {
  // 모든 밸브를 여는 방법으로
  // 초기에 얼마나 열어야할지 고민이 필요.
  int cTime = millis();
  int tDuration = duration;
  setDuration(500); // 1500ms
  rotate(LEFTVALVE, false, 0); 
  rotate(RIGHTVALVE, false, 0);
  //delay(5000);
  while (millis() - cTime < 600) ; // 0.6sec
  stopAllValve();
  setDuration(tDuration);
}

void ServoValve::rotate(int direct, bool pos, int stopTime) {
  // pos true : 정방향 & false : 역방향
  if (direct == LEFTVALVE) {
     if (pos == true) {
       leftServo.writeMicroseconds(1500 + duration);
     }
     else {
       leftServo.writeMicroseconds(1500 - duration);
     }
     delay(stopTime);
  }
  else {
    if (pos == true) {
      rightServo.writeMicroseconds(1500 + duration);
    }
    else {
      //rightServo.write(180);
      rightServo.writeMicroseconds(1500 - duration);
    }
    delay(stopTime);
  }
}

void ServoValve::stopValve(int direct) {
  if (direct == LEFTVALVE)
    leftServo.writeMicroseconds(1500);
  else
    rightServo.writeMicroseconds(1500);
}

void ServoValve::stopAllValve(void) {
  stopValve(LEFTVALVE);
  stopValve(RIGHTVALVE);
}

bool ServoValve::setDuration(int _duration) {
  if (_duration < 100 || _duration > 500)
    return false;
  else {
    duration = _duration;
    return true;  
  }
}
