#include <Arduino.h>
#include <SoftwareSerial.h>
#include "TinyGPS++.h"
#include "TinyGPSWrapper.h"

#define PMTK_SET_NMEA_OUTPUT_RMCONLY "$PMTK314,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0*29"
#define PMTK_SET_NMEA_OUTPUT_RMCGGA "$PMTK314,0,1,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0*28"
#define PMTK_SET_NMEA_OUTPUT_ALLDATA "$PMTK314,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0*28"
#define PMTK_SET_NMEA_OUTPUT_OFF "$PMTK314,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0*28"

#define PMTK_SET_NMEA_UPDATE_1HZ  "$PMTK220,1000*1F"
#define PMTK_SET_NMEA_UPDATE_5HZ  "$PMTK220,200*2C"

TinyGPSPlus gps;
SoftwareSerial ss(8, 7); //Hardcode RX TX pins

extern "C" void GPSInit(){
    ss.begin(9600);
    ss.println(PMTK_SET_NMEA_OUTPUT_RMCGGA);
    ss.println(PMTK_SET_NMEA_UPDATE_5HZ);
}

extern "C" void GPSRead(double* values){
    while(ss.available() > 0){
        if(gps.encode(ss.read())){
            //Valid NMEA sentence found
            values[0] = gps.location.lat();
            values[1] = gps.location.lng();
            values[2] = gps.speed.mps();
            values[3] = gps.course.deg();
            values[4] = gps.altitude.meters();
            values[5] = gps.satellites.value();
            values[6] = gps.location.age();
        }
    }
}
