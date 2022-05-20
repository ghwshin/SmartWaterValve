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

void setup() {
  Serial.begin(9600);
  Wire.begin();
  // 서보 모터의 각회전 시간을 매개변수로 줌 : PWM
  servos.initValve(100);
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
  //TODO : 5초마다 한번씩 클리어 
  //lcd.clear();
  sv.readResistorToTemperature();
  returnedTemp[0] = tc.readTemperatureAtPos(LEFTSENSOR);
  //returnedTemp[1] = tc.readTemperatureAtPos(RIGHTSENSOR);
  //returnedTemp[2] = tc.readTemperatureAtPos(MIDSENSOR);
  sv.setTemperature(tc.readTemperatureAtPos(LEFTSENSOR), 10, 20);

  lcd.setCursor(0,0);
  lcd.print(sv.toTemperatureString());
  lcd.setCursor(6,7);
  lcd.print(sv.toWantTemperatureString());
}
