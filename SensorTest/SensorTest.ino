#include <OneWire.h>
#include <DallasTemperature.h>

#define PIN_LEFT 2

OneWire oneWire;
DallasTemperature sensor;

DeviceAddress addr;

void setup() {
  Serial.begin(9600);
  oneWire = OneWire(PIN_LEFT);
  sensor = DallasTemperature(&oneWire);
  sensor.begin();
  sensor.getAddress(addr, 0);
  sensor.setResolution(addr, 12);

}

void loop() {
  sensor.requestTemperatures();
  Serial.print(sensor.getTempC(addr));
  Serial.println(" C");
  delay(500);
}
