#include "SmartValve.h"

SmartValve::SmartValve() {
  inTemp.hotTemp = 0.0f;
  inTemp.coldTemp = 0.0f;
  inTemp.outTemp = 0.0f;
  temperatureDiff = 0.0f;
}

float SmartValve::readResistorToTemperature(float lower_bound, float higher_bound) {
  int vResistor = analogRead(PIN_VRES);
  int temp = map(vResistor, 0, 1023, lower_bound * 10, higher_bound * 10);
  wantTemp = (float)temp / 10;
  return wantTemp;
}

void SmartValve::setTemperature(float cold, float out, float hot) {
  inTemp.hotTemp = hot;
  inTemp.coldTemp = cold;
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
  return "target : " + String(wantTemp, 1);
}

float SmartValve::getWantTemperature(void) {
  return wantTemp;
}

void SmartValve::setTempDiff(float diff) {
  temperatureDiff = diff;
}

bool SmartValve::isCorrectTemp(void) {
  return (abs(inTemp.outTemp - wantTemp) <= temperatureDiff);
}

int SmartValve::temperatureToAngleTime(int tempDiff) {
  return map(tempDiff, 0, 30, 0, 1000);
}

HotCold SmartValve::higherTemperature(void) {
  if (inTemp.outTemp > wantTemp)
    return HotCold(Hot);
  else
    return HotCold(Cold);
}
