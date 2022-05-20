#include <LiquidCrystal_I2C.h>
#include <Wire.h>
#include "SmartValve.h"
#include "ServoValve.h"
#include "TemperatureControl.h"
#include "valveEnv.h"

LiquidCrystal_I2C lcd(LCD_ADDR, 16, 2);
SmartValve sv = SmartValve();
ServoValve servos = ServoValve();
TemperatureControl tc = TemperatureControl();
float returnedTemp[3];
int currentTime;
int valveMoveTime = 100;

void setup() {
  Serial.begin(9600);
  Wire.begin();
  // 서보 모터의 각회전 시간을 매개변수로 줌 : PWM
  servos.initValve(200);
  // 12bit resolution
  tc.initControl(12);
  // 밸브 제어가 시작되기 위한 온도 차이 : 1도
  sv.setTempDiff(1.0);

  // LCD 초기화
  lcd.init();
  lcd.backlight();
}

void loop() {
  test();
  //delay(100);
}

// for test.
void test() {
  sv.readResistorToTemperature();
  returnedTemp[0] = tc.readTemperatureAtPos(LEFTSENSOR);
  returnedTemp[1] = tc.readTemperatureAtPos(MIDSENSOR);
  //returnedTemp[2] = tc.readTemperatureAtPos(RIGHTSENSOR);
  returnedTemp[2] = 40;
  sv.setTemperature(returnedTemp[0], returnedTemp[1], returnedTemp[2]);

  lcd.setCursor(0,0);
  lcd.print(sv.toTemperatureString());
  lcd.setCursor(1,7);
  lcd.print(sv.toWantTemperatureString());

  if (!sv.isCorrectTemp()) {
    int startTime = millis();
    if (sv.higherTemperature() == HotCold::Hot) {
      servos.rotate(RIGHTVALVE, true);
      servos.rotate(LEFTVALVE, false);
      delay(valveMoveTime);
      servos.stopAllValve(); 
    }
    else {
      servos.rotate(LEFTVALVE, true);
      servos.rotate(RIGHTVALVE, false);
      delay(valveMoveTime);
      servos.stopAllValve();       
    }
  } else {
    servos.stopAllValve();
  }
}
