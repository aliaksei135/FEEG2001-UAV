#include "Adafruit_Sensor.h"
#include "L3GD20Wrapper.h"

Adafruit_L3GD20_Unified gyro = Adafruit_L3GD20_Unified(3333);

extern "C" void L3GD20Init(){
    gyro.begin();
    gyro.enableAutoRange(true);
}

extern "C" void L3GD20Read(float* values){
    sensors_event_t revent;
    gyro.getEvent(&revent);
    values[0] = revent.gyro;
}