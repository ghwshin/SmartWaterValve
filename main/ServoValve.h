#ifndef TEST_SERVOVALVE_H
#define TEST_SERVOVALVE_H
#include <Servo.h>
#include "valveEnv.h"
#include "arduino.h"

#define PIN_LSERVO 13
#define PIN_RSERVO 12


class ServoValve {
  private:
    Servo leftServo;
    Servo rightServo;
    int duration;

  public:
    ServoValve();
    void initValve(int _duration);
    void allClose();
    void allOpen();
    void rotate(int direct, bool pos);
    void stopValve(int direct);
    void stopAllValve();
    bool setDuration(int _duration);
};


#endif //TEST_SERVOVALVE_H
