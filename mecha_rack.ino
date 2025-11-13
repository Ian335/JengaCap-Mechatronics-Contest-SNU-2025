#include <Servo.h>

Servo myservo;
const int servoPin = 3;

void setup() {
  myservo.attach(servoPin);
  Serial.begin(9600);
  myservo.write(90);  // initial stop position
}

void loop() {
  if (Serial.available()) {
    char command = Serial.read();

    if (command == 'a') {
      // Counterclockwise rotation
      myservo.write(0);   // less than 90degrees -> counterclockwise rotation
      delay(50);
      myservo.write(90);   // 정지
    } else if (command == 'b') {
      // rotate clockwise
      myservo.write(180);  // greater than 90degrees -> counterclockwise rotation
      delay(50);
      myservo.write(90);   // stop
    }
  }
}
