#include "SmartValve.h"

void SmartValve::initSystem(void) {
  return ;
}

float SmartValve::readResistorToTemperature(void) {
  int vResistor = analogRead(PIN_VRES);
  int temp = map(vResistor, 0, 1023, 200, 500);
  wantTemp = (float)temp / 10;
  return temp;
}

float SmartValve::readTemperature(int position) {
  return 0.0f;
}

String SmartValve::toTemperatureString(void) {
  return String(wantTemp);
}

bool SmartValve::isCorrectTemp(void) {
  return true;
}
