#include <Arduino.h>
#include "Adafruit_BMP085.h"
#include "BMP085Wrapper.h"

Adafruit_BMP085 bmp085;

extern "C" void BMP085Init(){
    bmp085 = Adafruit_BMP085();
    bmp085.begin(BMP085_ULTRAHIGHRES);
}

extern "C" void BMP085Read(float* values){
    values[0] = bmp085.readPressure();
    values[1] = bmp085.readTemperature();
    values[2] = bmp085.readAltitude(values[2]);
}