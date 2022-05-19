#include "TemperatureControl.h"

void TemperatureControl::initControl(int resolution) {
  // resolution = 9 ~ 12bits.
  lwire = OneWire(PIN_LEFTSENSOR);
  rwire = OneWire(PIN_RIGHTSENSOR);
  mwire = OneWire(PIN_MIDSENSOR);
  lsensor = DallasTemperature(&lwire);
  rsensor = DallasTemperature(&rwire);
  msensor = DallasTemperature(&mwire);
  lsensor.getAddress(laddr, 0);
  rsensor.getAddress(raddr, 0);
  msensor.getAddress(maddr, 0);
  lsensor.setResolution(laddr, resolution);
  rsensor.setResolution(raddr, resolution);
  msensor.setResolution(maddr, resolution);
}

float TemperatureControl::readTemperatureAtPos(int position) {
  float result;
  if (position == LEFTSENSOR) {
    lsensor.requestTemperatures();
    result = lsensor.getTempC(laddr);
  } else if (position == RIGHTSENSOR) {
    rsensor.requestTemperatures();
    result = rsensor.getTempC(raddr);
  } else {
    msensor.requestTemperatures();
    result = msensor.getTempC(maddr);
  }
  return result;
}
