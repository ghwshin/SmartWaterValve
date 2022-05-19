#include "ServoValve.h"

ServoValve::ServoValve() {};

void ServoValve::initValve(int _duration) {
  leftServo.attach(PIN_LSERVO);
  rightServo.attach(PIN_RSERVO);
  duration = _duration;
}

void ServoValve::allClose(void) {
  
}

void ServoValve::rotate(int direct) {
  
}

void ServoValve::stopValve(int direct) {
  
}

bool ServoValve::setDuration(int _duration) {
  
}
