#include <Servo.h>

// Motor Pin
const int motor1Pin1 = 24;
const int motor1Pin2 = 26;
const int motor2Pin1 = 28;
const int motor2Pin2 = 30;

// Server Pin
const int servo1Pin = 2;
const int servo2Pin = 3;

// IR sensor Pin
const int irSensorPin = 4;

Servo servo1;
Servo servo2;

bool hasRun = false;

void setup() {
  // set motor pins as output
  pinMode(motor1Pin1, OUTPUT);
  pinMode(motor1Pin2, OUTPUT);
  pinMode(motor2Pin1, OUTPUT);
  pinMode(motor2Pin2, OUTPUT);

  // set IR sensors as input
  pinMode(irSensorPin, INPUT);

  // ATTACH SERVOS
  servo1.attach(servo1Pin);
  servo2.attach(servo2Pin);

  // initial servo positions
  servo1.write(90);
  servo2.write(90);
}

void loop() {
  int sensorState = digitalRead(irSensorPin);

  if (sensorState == LOW && hasRun == false) { // object detection
    hasRun = true;

    delay(3000);  // 1. wait

    // 2. DC motor1 counterclockwise (6000ms)
    digitalWrite(motor1Pin1, LOW);
    digitalWrite(motor1Pin2, HIGH);
    delay(6000);
    digitalWrite(motor1Pin1, LOW);
    digitalWrite(motor1Pin2, LOW);

    delay(500);

    // 3. servo 2 → 180degrees → 400ms → back to 90degrees
    servo2.write(180);
    delay(400);
    servo2.write(90);

    delay(500);

    // 4. DC motor2 clockwise (2000ms)
    digitalWrite(motor2Pin1, HIGH);
    digitalWrite(motor2Pin2, LOW);
    delay(2000);
    digitalWrite(motor2Pin1, LOW);
    digitalWrite(motor2Pin2, LOW);
    
    delay(500);

    // 5. servo1 → 0degrees
    servo1.write(0);

    delay(500);

    // 6. DC motor2 clockwise (3000ms)
    digitalWrite(motor2Pin1, HIGH);
    digitalWrite(motor2Pin2, LOW);
    delay(3000);
    digitalWrite(motor2Pin1, LOW);
    digitalWrite(motor2Pin2, LOW);

    // 7. servo2 → 0degrees → 350ms → back to 90degrees
    delay(500);

    servo2.write(0);
    delay(350);
    servo2.write(90);

    delay(500);
    // 8. servo1 → 90degrees
    servo1.write(90);

    delay(500);
    // 9. DCmotor2 counterclockwise (1500ms)
    digitalWrite(motor2Pin1, LOW);
    digitalWrite(motor2Pin2, HIGH);
    delay(1500);
    digitalWrite(motor2Pin1, LOW);
    digitalWrite(motor2Pin2, LOW);

    delay(500);
    
    // 10. DCmotor1 clockwise (6000ms)
    digitalWrite(motor1Pin1, HIGH);
    digitalWrite(motor1Pin2, LOW);
    delay(6000);
    digitalWrite(motor1Pin1, LOW);
    digitalWrite(motor1Pin2, LOW);

    // wait until object is ejected
    while (digitalRead(irSensorPin) == LOW) {
      delay(10);
    }
  }
}
