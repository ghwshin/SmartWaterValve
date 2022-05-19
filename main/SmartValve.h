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
    // TODO : 온도 센서 제어 변수
    // TODO : 서보 모터 객체
    float wantTemp;
    String LCDString;

  public:
    SmartValve() = default;
    void initSystem(void);
    float readResistorToTemperature(void);
    float readTemperature(int position);
    String toTemperatureString(void);
    boolean isCorrectTemp(void);
};


#endif //MAIN_SMARTVALVE_H
