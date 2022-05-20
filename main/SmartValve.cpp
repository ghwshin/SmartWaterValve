#include "SmartValve.h"

SmartValve::SmartValve() {
  inTemp.hotTemp = 0.0f;
  inTemp.coldTemp = 0.0f;
  inTemp.outTemp = 0.0f;
  temperatureDiff = 0.0f;
}

float SmartValve::readResistorToTemperature(void) {
  int vResistor = analogRead(PIN_VRES);
  int temp = map(vResistor, 0, 1023, 200, 500);
  wantTemp = (float)temp / 10;
  return wantTemp;
}

void SmartValve::setTemperature(float cold, float out, float hot) {
  inTemp.hotTemp = hot;
  inTemp.coldTemp = cold;
  if (out >= 50)
    out = 50;
  inTemp.outTemp = out;
}

String SmartValve::toTemperatureString(void) {
  LCDString = "";
  LCDString += String(inTemp.coldTemp, 1);
  LCDString += "  ";
  LCDString += String(inTemp.outTemp, 1);
  LCDString += "  ";
  LCDString += String(inTemp.hotTemp, 1);
  return LCDString;
}

String SmartValve::toWantTemperatureString(void) {
  return String(wantTemp, 1);
}

void SmartValve::setTempDiff(float diff) {
  temperatureDiff = diff;
}

bool SmartValve::isCorrectTemp(void) {
  float hotcoldDiff = abs(inTemp.hotTemp - inTemp.coldTemp);
  return (hotcoldDiff <= temperatureDiff);
}
