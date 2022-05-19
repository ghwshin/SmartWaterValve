#include <LiquidCrystal_I2C.h>
#include <Wire.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);
int pinNum = A0;

void setup() {
  Wire.begin();
  Serial.begin(9600);

  pinMode(pinNum, INPUT);
  
  lcd.init();
  lcd.backlight();
}

void loop() {
  lcd.clear();
  String vResistor = "Hello world ";
  vResistor += String(analogRead(pinNum));
  lcd.setCursor(0, 0);
  lcd.print(vResistor);
  delay(1000);
}
