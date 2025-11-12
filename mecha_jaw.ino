const int IN1 = 24;  // 모터 드라이버 입력 1
const int IN2 = 26;  // 모터 드라이버 입력 2

void setup() {
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  if (Serial.available()) {
    char command = Serial.read();

    if (command == 'a') {
      // 시계방향 회전
      digitalWrite(IN1, HIGH);
      digitalWrite(IN2, LOW);
      delay(500);
      stopMotor();
    } else if (command == 'b') {
      // 반시계방향 회전
      digitalWrite(IN1, LOW);
      digitalWrite(IN2, HIGH);
      delay(500);
      stopMotor();
    }
  }
}

void stopMotor() {
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
}
