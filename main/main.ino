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
int coldValveMoveTime = 150;
int hotValveMoveTime = 100;
int currentAngleDur = 400;

int servoCount = 0;

bool isChanged = false;
bool isClosed = false;
unsigned long startTime = 0;
HotCold currenthc;

void setup() {
  Serial.begin(9600);
  Wire.begin();
  // 서보 모터의 각회전 시간을 매개변수로 줌 : PWM
  servos.initValve(currentAngleDur);
  // 12bit resolution
  tc.initControl(10);
  // 밸브 제어가 시작되기 위한 온도 차이 : 2도
  sv.setTempDiff(2.0);

  // LCD 초기화
  lcd.init();
  lcd.backlight();

  temperatureRead();
  temperatureSetLCD();

  if (sv.higherTemperature() == HotCold::Hot)
    currenthc = HotCold(Hot);
  else
    currenthc = HotCold(Cold);
}

void loop() {
  //ServoTest();
  test();
  //test_two();
  //delay(100);
}

void ServoTest() {
  servos.rotate(RIGHTVALVE, true, 2000);
  servos.rotate(RIGHTVALVE, false, 2000);

  servos.rotate(LEFTVALVE, true, 2000);
  servos.rotate(LEFTVALVE, false, 2000);
}

// for test.
void test() {
  temperatureRead();
  temperatureSetLCD();
  delay(500);
  if (sv.getWantTemperature() <= 20.0) {
    isClosed = true;
    servos.allClose();
    delay(600);
  }
  else if (isClosed == true) {
    isClosed = false;
    servos.allOpen();
    delay(600);
  }
  else {
    if (!sv.isCorrectTemp()) {
      temperatureRead();
      temperatureSetLCD();
      if (sv.higherTemperature() == HotCold::Hot) {
        if (isChanged && currenthc == HotCold::Cold) {
          servos.rotate(RIGHTVALVE, true, 50);
          servos.rotate(LEFTVALVE, false, 50);
          servos.stopAllValve();
          delay(800);
          //currentAngleDur -= 10;
          //servos.setDuration(currentAngleDur);
          isChanged = false;
        }
        else {
          isChanged = true;
          servoCount += 1;
          if (servoCount > 10) {
            servoCount = 0;
            servos.setDuration(400);
          }
          currenthc = HotCold::Hot;
          servos.rotate(RIGHTVALVE, true, hotValveMoveTime);
          servos.rotate(LEFTVALVE, false, coldValveMoveTime);
          servos.stopAllValve();   
        }
      }
      else {
        if (isChanged && currenthc == HotCold::Hot) {
          servos.rotate(RIGHTVALVE, false, 50);
          servos.rotate(LEFTVALVE, true, 50);
          servos.stopAllValve();
          delay(800);
          //currentAngleDur -= 10;
          //servos.setDuration(currentAngleDur);
          isChanged = false;
        }
        else {
          isChanged = true;
          servoCount += 1;
          if (servoCount > 10) {
            servoCount = 0;
            servos.setDuration(400);
          }
          currenthc = HotCold::Cold;
          servos.rotate(RIGHTVALVE, false, hotValveMoveTime);
          servos.rotate(LEFTVALVE, true, coldValveMoveTime);
          servos.stopAllValve();  
        }       
      }
    } else {
      servoCount = 0;
      servos.setDuration(400);
      servos.stopAllValve();
    }
  }
}

void temperatureRead(void) {
  sv.readResistorToTemperature(20.0, 50.0); // 매개변수 : 온도 상, 하한
  returnedTemp[0] = tc.readTemperatureAtPos(LEFTSENSOR);
  returnedTemp[1] = tc.readTemperatureAtPos(MIDSENSOR);
  returnedTemp[2] = tc.readTemperatureAtPos(RIGHTSENSOR);
  sv.setTemperature(returnedTemp[0], returnedTemp[1], returnedTemp[2]);
}

void temperatureSetLCD(void) {
  lcd.setCursor(0,0);
  lcd.print(sv.toTemperatureString());
  lcd.setCursor(1,7);
  lcd.print(sv.toWantTemperatureString());
}
