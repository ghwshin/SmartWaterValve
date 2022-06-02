# SmartWaterValve


2022년 부산대학교 기계공학부 종합설계과제(Capstone Design 2)

<스마트 수도밸브> 관련 아두이노 소스 코드 및 자료 입니다.


### 테스트용 프로그램

- I2CScanner : I2C LCD의 Address를 찾기 위해 사용한 프로그램
- LCDTest : LCD 작동 테스트
- SensorTest : 온도 센서 작동 테스트
- servoTest : 서보 모터 작동 테스트

### 클래스

- SmartValve : 온도 변수, LCD String 제어
- ServoValve : 서보 모터 제어
- TemperatureControl : 온도 센서 제어

### 메인 루프 작동

1. 희망 온도를 입력 받는다. (가변 저항)
2. 모든 부분의 온도를 측정하여 업데이트 한다.
3. 모든 부분의 온도와 희망 온도를 출력한다.
4. 출수 온도와 희망 온도의 차이의 오차를 검사하여 모터를 움직여야 하는지 검사한다.
5. 둘 중 어느 부분이 더 높은지 검사하여 상황에 맞게 모터를 움직여 밸브를 조정한다.
