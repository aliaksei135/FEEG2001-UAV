#include <Arduino.h>
#include "Adafruit_Sensor.h"
#include "Adafruit_LSM303_U.h"
#include "LSM303Wrapper.h"

Adafruit_LSM303_Accel_Unified accel = Adafruit_LSM303_Accel_Unified(1111);
Adafruit_LSM303_Mag_Unified mag = Adafruit_LSM303_Mag_Unified(2222);

extern "C" void LSM303Init(){
    bool init = false;
    bool accelInit = false;
    bool magInit = false;
    do{
        //Prevent Double init
        if(!accelInit && accel.begin()){
            accelInit = true;
        }
        if(!magInit && mag.begin()){
            magInit = true;
        }
        init = accelInit && magInit;
    }while(!init);
//     mag.enableAutoRange(true);
}

extern "C" void LSM303Read(float* values){
    sensors_event_t aevent, mevent;
    accel.getEvent(&aevent);
    mag.getEvent(&mevent);
    values[0] = aevent.acceleration.x;
    values[1] = aevent.acceleration.y;
    values[2] = aevent.acceleration.z;
    values[3] = mevent.magnetic.x;
    values[4] = mevent.magnetic.y;
    values[5] = mevent.magnetic.z;
}