#include <Servo.h>

Servo myservo;
const int servoPin = 3;

void setup() {
  myservo.attach(servoPin);
  Serial.begin(9600);
  myservo.write(90);  // 초기 정지 상태
}

void loop() {
  if (Serial.available()) {
    char command = Serial.read();

    if (command == 'a') {
      // 반시계방향 회전
      myservo.write(0);   // 90보다 작으면 반시계
      delay(50);
      myservo.write(90);   // 정지
    } else if (command == 'b') {
      // 시계방향 회전
      myservo.write(180);  // 90보다 크면 시계
      delay(50);
      myservo.write(90);   // 정지
    }
  }
}
