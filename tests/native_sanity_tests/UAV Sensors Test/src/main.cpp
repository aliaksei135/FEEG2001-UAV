#include <Arduino.h>
#include <Wire.h>
#include <SPI.h>
#include <Adafruit_Sensor.h>
#include <Adafruit_BMP085_U.h>
#include <Adafruit_L3GD20_U.h>
#include <Adafruit_LSM303.h>

Adafruit_BMP085_Unified press;
Adafruit_L3GD20_Unified gyro;
Adafruit_LSM303_Accel_Unified imu;
Adafruit_LSM303_Mag_Unified cpss;

long prevSample;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  SPI.begin();
  Wire.begin();
  Wire.setClock(3400000);
  
  press = Adafruit_BMP085_Unified(111);
  press.begin(BMP085_MODE_ULTRAHIGHRES);
  gyro = Adafruit_L3GD20_Unified(222);
  gyro.begin();
  gyro.enableAutoRange(true);
  imu = Adafruit_LSM303_Accel_Unified(333);
  imu.begin();
  cpss = Adafruit_LSM303_Mag_Unified(444);
  cpss.begin();
}

void loop() {
  // put your main code here, to run repeatedly:
  sensors_event_t pevent, gevent, ievent, cevent;
  press.getEvent(&pevent);
  gyro.getEvent(&gevent);
  imu.getEvent(&ievent);
  cpss.getEvent(&cevent);
  Serial.println("X: " + (String) gevent.gyro.x + " Y: " + gevent.gyro.y + " Z: " + gevent.gyro.z);
  delay(200)
;}