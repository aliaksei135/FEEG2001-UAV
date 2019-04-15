#include <Arduino.h>
#include <SPI.h>
#include <SD.h>
#include "SDLogger.h"

File dataFile;
const char TERM_BYTES[] = {0x00, 0x00, 0x00, 0x00};

extern "C" void SDLoggerInit(){
    SD.begin(10); //Hardcode CS, as is 'standard' pin
    dataFile = SD.open("log", O_CREAT|O_WRITE);
    delay(100);
}

extern "C" void SDLoggerLog(float data[], int size){
    Serial.println("Logging");
    if(dataFile){
        Serial.println("Writing");
        char bytes[size * 4]; //Alloc for 4 byte floats
        for(int i=0; i<size;i++){
            unsigned char const * p = reinterpret_cast<unsigned char const *>(&data[i]);
            bytes[i * 4] = p[0];
            bytes[i * 4 + 1] = p[1];
            bytes[i * 4 + 2] = p[2];
            bytes[i * 4 + 3] = p[3];
        }
        Serial.println(bytes);
        dataFile.write(bytes, size*4);
        dataFile.write((const char *)TERM_BYTES, 4);
    }
}

extern "C" void SDLoggerDestroy(){
    dataFile.close();
}
