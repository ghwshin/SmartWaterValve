#include "ServoValve.h"

ServoValve::ServoValve() {};

void ServoValve::initValve(int _duration) {
  leftServo.attach(PIN_LSERVO);
  rightServo.attach(PIN_RSERVO);
  duration = _duration;
  allClose();
}

void ServoValve::allClose(void) {
  // TODO : 모든 밸브를 닫는 방향으로
  // 가능한가...? -> 닫는 방향으로 1초동안 돌리면 되지않을까?
  int cTime = millis();
  int tDuration = duration;
  setDuration(500); // 1500ms
  rotate(LEFTVALVE, false); // 역방향 회전
  rotate(RIGHTVALVE, false);
  while (millis() - cTime < 1000) ; // 1sec
  stopAllValve();
  setDuration(tDuration);
}

void ServoValve::allOpen() {
  // TODO : 모든 밸브를 여는 방법으로
  // 초기에 얼마나 열어야할지 고민이 필요.
}

void ServoValve::rotate(int direct, bool pos) {
  // pos true : 정방향 & false : 역방향
  if (direct == LEFTVALVE) {
     if (pos == true) {
       leftServo.writeMicroseconds(1500 + duration);
     }
     else {
       leftServo.writeMicroseconds(1500 - duration);
     }
  }
  else {
    if (pos == true) {
      rightServo.writeMicroseconds(1500 + duration);
    }
    else {
      rightServo.writeMicroseconds(1500 - duration);
    }
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
  if (_duration < 0 || _duration > 500)
    return false;
  else {
    duration = _duration;
    return true;  
  }
}
