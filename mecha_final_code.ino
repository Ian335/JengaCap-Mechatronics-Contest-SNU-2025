#include <Servo.h>

// 모터 핀
const int motor1Pin1 = 24;
const int motor1Pin2 = 26;
const int motor2Pin1 = 28;
const int motor2Pin2 = 30;

// 서보 핀
const int servo1Pin = 2;
const int servo2Pin = 3;

// IR 센서 핀
const int irSensorPin = 4;

Servo servo1;
Servo servo2;

bool hasRun = false;

void setup() {
  // 모터 핀 출력 설정
  pinMode(motor1Pin1, OUTPUT);
  pinMode(motor1Pin2, OUTPUT);
  pinMode(motor2Pin1, OUTPUT);
  pinMode(motor2Pin2, OUTPUT);

  // IR 센서 입력 설정
  pinMode(irSensorPin, INPUT);

  // 서보 연결
  servo1.attach(servo1Pin);
  servo2.attach(servo2Pin);

  // 초기 서보 위치
  servo1.write(90);
  servo2.write(90);
}

void loop() {
  int sensorState = digitalRead(irSensorPin);

  if (sensorState == LOW && hasRun == false) { // 물체 감지됨 
    hasRun = true;

    delay(3000);  // 1. 대기

    // 2. DC모터1 반시계 (6000ms)
    digitalWrite(motor1Pin1, LOW);
    digitalWrite(motor1Pin2, HIGH);
    delay(6000);
    digitalWrite(motor1Pin1, LOW);
    digitalWrite(motor1Pin2, LOW);

    delay(500);

    // 3. 서보2 → 180도 → 400ms → 90도
    servo2.write(180);
    delay(400);
    servo2.write(90);

    delay(500);

    // 4. DC모터2 시계 (2000ms)
    digitalWrite(motor2Pin1, HIGH);
    digitalWrite(motor2Pin2, LOW);
    delay(2000);
    digitalWrite(motor2Pin1, LOW);
    digitalWrite(motor2Pin2, LOW);
    
    delay(500);

    // 5. 서보1 → 0도
    servo1.write(0);

    delay(500);

    // 6. DC모터2 시계 (3000ms)
    digitalWrite(motor2Pin1, HIGH);
    digitalWrite(motor2Pin2, LOW);
    delay(3000);
    digitalWrite(motor2Pin1, LOW);
    digitalWrite(motor2Pin2, LOW);

    // 7. 서보2 → 0도 → 350ms → 90도
    delay(500);

    servo2.write(0);
    delay(350);
    servo2.write(90);

    delay(500);
    // 8. 서보1 → 90도
    servo1.write(90);

    delay(500);
    // 9. DC모터2 반시계 (1500ms)
    digitalWrite(motor2Pin1, LOW);
    digitalWrite(motor2Pin2, HIGH);
    delay(1500);
    digitalWrite(motor2Pin1, LOW);
    digitalWrite(motor2Pin2, LOW);

    delay(500);
    
    // 10. DC모터1 시계 (6000ms)
    digitalWrite(motor1Pin1, HIGH);
    digitalWrite(motor1Pin2, LOW);
    delay(6000);
    digitalWrite(motor1Pin1, LOW);
    digitalWrite(motor1Pin2, LOW);

    // 물체가 사라질 때까지 대기
    while (digitalRead(irSensorPin) == LOW) {
      delay(10);
    }
  }
}
