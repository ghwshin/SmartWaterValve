#ifndef MAIN_TEMPERATURECONTROL_H
#define MAIN_TEMPERATURECONTROL_H

#define PIN_LEFTSENSOR 3
#define PIN_RIGHTSENSOR 4
#define PIN_MIDSENSOR 5

#include <Arduino.h>
#include <DallasTemperature.h>

class TemperatureControl {
  private:
    OneWire lwire;
    OneWire rwire;
    OneWire mwire;
    DallasTemperature lsensor;
    DallasTemperature rsensor;
    DallasTemperature msensor;
    DeviceAddress laddr;
    DeviceAddress raddr;
    DeviceAddress maddr;
    
  public:
    TemperatureControl() = default;
    void initControl(int resolution);
    float readTemperatureAtPos(int position);
};

#endif
