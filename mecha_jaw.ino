const int IN1 = 24;  // MOTOR driver input 1
const int IN2 = 26;  // MOTOR driver input 2

void setup() {
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  if (Serial.available()) {
    char command = Serial.read();

    if (command == 'a') {
      // clockwise rotation
      digitalWrite(IN1, HIGH);
      digitalWrite(IN2, LOW);
      delay(500);
      stopMotor();
    } else if (command == 'b') {
      // counterclockwise rotation
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
