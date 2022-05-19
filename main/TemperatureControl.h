#ifndef MAIN_TEMPERATURECONTROL_H
#define MAIN_TEMPERATURECONTROL_H

// information of senser pins.
#define PIN_LEFTSENSOR 3
#define PIN_RIGHTSENSOR 4
#define PIN_MIDSENSOR 5

// information of sensor number.
#define LEFTSENSOR 10
#define RIGHTSENSOR 20
#define MIDSENSOR 30

#include <Arduino.h>
#include <DallasTemperature.h>

class TemperatureControl {
  private:
    // left, right, middle sensors.
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
