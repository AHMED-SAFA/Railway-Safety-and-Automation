#include <Servo.h>

#define TRIGGER_PIN_1 10
#define ECHO_PIN_1 13
#define TRIGGER_PIN_2 5
const int IR_SENSOR_PIN = 2;
const int IR_SENSOR_PIN2 = 7;
const int IR_SENSOR_PIN3 = 8;

//  int sensorValue = 0;
#define ECHO_PIN_2 6
#define SERVO_PIN 12
#define BUZZER_PIN 3

Servo servoMotor;
bool obstacleDetected = false;

void setup() {
  pinMode(TRIGGER_PIN_1, OUTPUT);
  pinMode(ECHO_PIN_1, INPUT);
  pinMode(TRIGGER_PIN_2, OUTPUT);
  pinMode(ECHO_PIN_2, INPUT);
  pinMode(BUZZER_PIN, OUTPUT);
  servoMotor.attach(SERVO_PIN);

  pinMode(IR_SENSOR_PIN, INPUT);

  Serial.begin(9600);
}

void loop() {
  long duration1, distance1, duration2, distance2;


  int sensorValue = digitalRead(IR_SENSOR_PIN);


  int sensorValue2 = digitalRead(IR_SENSOR_PIN2);


  int sensorValue3 = digitalRead(IR_SENSOR_PIN3);


  if (sensorValue3 == LOW) {
    digitalWrite(BUZZER_PIN, HIGH);
  }

  digitalWrite(TRIGGER_PIN_1, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIGGER_PIN_1, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIGGER_PIN_1, LOW);

  duration1 = pulseIn(ECHO_PIN_1, HIGH);
  distance1 = duration1 * 0.034 / 2;

  if (distance1 <= 7 && !obstacleDetected && sensorValue == HIGH && sensorValue2 == HIGH) {
    servoMotor.write(90);

    obstacleDetected = true;
  }


  if (distance1 <= 7 && !obstacleDetected && (sensorValue == LOW)) {
    // servoMotor.write(90);
    // digitalWrite(BUZZER_PIN, HIGH);
    obstacleDetected = true;
  }

  if (distance1 <= 7 && !obstacleDetected && (sensorValue2 == LOW)) {
    // servoMotor.write(90);
    digitalWrite(BUZZER_PIN, HIGH);
    obstacleDetected = true;
  }

  digitalWrite(TRIGGER_PIN_2, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIGGER_PIN_2, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIGGER_PIN_2, LOW);

  duration2 = pulseIn(ECHO_PIN_2, HIGH);
  distance2 = duration2 * 0.034 / 2;

  if (distance2 <= 7 && obstacleDetected) {
    servoMotor.write(0);
    digitalWrite(BUZZER_PIN, LOW);
    obstacleDetected = false;
  }
}
