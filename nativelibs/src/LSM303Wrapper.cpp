#include "Adafruit_Sensor.h"
#include "LSM303Wrapper.h"

Adafruit_LSM303_Accel_Unified accel = Adafruit_LSM303_Accel_Unified(1111);
Adafruit_LSM303_Mag_Unified mag = Adafruit_LSM303_Mag_Unified(2222);

extern "C" void LSM303Init(){
    accel.begin();
    mag.begin();
    mag.setAutoRange(true);
}

extern "C" void LSM303Read(float* values){
    sensors_event_t aevent, mevent;
    accel.getEvent(&aevent);
    mag.getEvent(&mevent);
    values[0] = aevent.acceleration;
    values[1] = mevent.magnetic;
}