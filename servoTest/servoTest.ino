#include <Servo.h>

Servo myServo;
int servoPin = 13;

void setup() {
  Serial.begin(9600);
  myServo.attach(servoPin);
}

void loop() {
  int angle;
  /*
  for (angle = 0 ; angle < 180 ; angle++) {
    myServo.write(angle);
    delay(5);
  }
  for (angle = 180 ; angle > 0 ; angle--) {
    myServo.write(angle);
    delay(5);
  }
  */
  /*
  myServo.writeMicroseconds(1000);
  delay(2000);
  myServo.writeMicroseconds(1500);
  */
  //myServo.write(0);
  //delay(100);
  //myServo.write(90);
  //delay(1000);
  //myServo.write(180);
  //delay(100);
  myServo.write(180);
  myServo.write(90);
  //delay(1000);
  /*
  delay(1000);
  myServo.write(180);
  delay(1000);  
  myservo.write(90);
  delay(1000);
  */
  while (true);
}
