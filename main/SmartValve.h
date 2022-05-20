#ifndef MAIN_SMARTVALVE_H
#define MAIN_SMARTVALVE_H

#include <Arduino.h>
#define PIN_VRES A0

typedef struct temp {
  float hotTemp;
  float coldTemp;
  float outTemp;
} InternalTemp;

class SmartValve {
  private:
    InternalTemp inTemp;
    float wantTemp;
    float temperatureDiff;
    String LCDString;

  public:
    SmartValve();
    void initSystem(void);
    float readResistorToTemperature(void);
    void setTemperature(float hot, float cold, float out);
    String toTemperatureString(void);
    String toWantTemperatureString(void);
    void setTempDiff(float diff);
    bool isCorrectTemp(void);
};


#endif //MAIN_SMARTVALVE_H
