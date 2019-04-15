#include <Arduino.h>
#include <Servo.h>

Servo aileronServos;
Servo elevatorServo;
Servo rudderServo;

void setup() {
  Serial.begin(9600);
  aileronServos.attach(5);
  elevatorServo.attach(6);
  rudderServo.attach(3);
}

void loop() {
  Serial.println("Starting loop...");
  aileronServos.write(180);
  delay(1000);
  elevatorServo.write(180);
  delay(1000);
  rudderServo.write(180);
  delay(1000);
  aileronServos.write(0);
  delay(1000);
  elevatorServo.write(0);
  delay(1000);
  rudderServo.write(0);
  delay(1000);
}