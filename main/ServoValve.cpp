#include "ServoValve.h"

ServoValve::ServoValve() {};

void ServoValve::initValve(int _duration) {
  leftServo.attach(PIN_LSERVO);
  rightServo.attach(PIN_RSERVO);
  duration = _duration;
}

void ServoValve::allClose(void) {
  // TODO : 모든 밸브를 닫는 방향으로
  // 가능한가...? -> 닫는 방향으로 1초동안 돌리면 되지않을까?
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

bool ServoValve::setDuration(int _duration) {
  if (_duration < 0 || _duration > 500)
    return false;
  else {
    duration = _duration;
    return true;  
  }
}
