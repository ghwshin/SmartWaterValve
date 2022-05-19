#include <LiquidCrystal_I2C.h>
#include <Wire.h>
#include "SmartValve.h"
#include "ServoValve.h"
#include "TemperatureControl.h"
#include "valveEnv.h"

LiquidCrystal_I2C lcd(LCD_ADDR, 16, 2);
SmartValve sv = SmartValve();
ServoValve servos = ServoValve();
TemperatureControl tc;

void setup() {
  Serial.begin(9600);
  Wire.begin();
  servos.initValve(10);
  // 12bit resolution
  tc.initControl(12);
  sv.initSystem();
  lcd.init();
  lcd.backlight();
}

void loop() {
  // for test.
  lcd.clear();
  lcd.print(tc.readTemperatureAtPos(LEFTSENSOR));

  sv.readResistorToTemperature();
  lcd.print(sv.toTemperatureString());
  
  delay(100);
}
