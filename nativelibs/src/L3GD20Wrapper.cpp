#include <Arduino.h>
#include "Adafruit_Sensor.h"
#include "Adafruit_L3GD20_U.h"
#include "L3GD20Wrapper.h"

Adafruit_L3GD20_Unified gyro = Adafruit_L3GD20_Unified(3333);

extern "C" void L3GD20Init(){
    bool init = false;
    do{
        if(gyro.begin(GYRO_RANGE_2000DPS)){
            init = true;
        }
    } while(!init);
//     gyro.enableAutoRange(true);
}

extern "C" void L3GD20Read(float* values){
    sensors_event_t revent;
    gyro.getEvent(&revent);
    values[0] = revent.gyro.x;
    values[1] = revent.gyro.y;
    values[2] = revent.gyro.z;
}