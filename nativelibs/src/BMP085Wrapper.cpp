#include <Arduino.h>
#include "Adafruit_BMP085.h"
#include "BMP085Wrapper.h"

Adafruit_BMP085 bmp085 = Adafruit_BMP085();
float RefPress;

extern "C" void BMP085Init(float press){
    bool init = false;
    do{
        if(bmp085.begin(BMP085_ULTRAHIGHRES)){
         init = true;
        }
    }while(!init);
    RefPress = press;
}

extern "C" void BMP085Read(float* values){
    values[0] = bmp085.readPressure();
    values[1] = bmp085.readTemperature();
    values[2] = bmp085.readAltitude(RefPress);
}