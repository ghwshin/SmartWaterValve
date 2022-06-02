#include <Servo.h>

Servo myServo;
Servo myServo2;
int servoPin = 13;
int servoPin2 = 12;
int startTime;
int currentTime;
bool isMoving = false;
void setup() {
  Serial.begin(9600);
  myServo.attach(servoPin);
  myServo2.attach(servoPin2);
  startTime = millis();
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
  /*
  currentTime = millis();
  if (isMoving) {
    int t = abs(startTime - currentTime);
    if (t >= 1000) {
      Serial.println(t);
      isMoving = false;
      myServo.write(90);
      myServo2.write(90);
      delay(1000);
    }
  }
  else {
    myServo.write(0);
    myServo.write(0);
    isMoving = true;  
    startTime = millis();
  }
  */
  myServo.write(0);
  myServo2.write(0);
  delay(2000);

  myServo.write(180);
  myServo2.write(180);
  delay(2000);
  
  //myServo.write(90);
  //delay(1000);
  /*
  delay(1000);
  myServo.write(180);
  delay(1000);  
  myservo.write(90);
  delay(1000);
  */
  //while (true);
}
