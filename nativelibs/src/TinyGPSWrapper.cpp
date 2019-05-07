#include <Arduino.h>
#include "TinyGPS++.h"
#include "TinyGPSWrapper.h"

// #define PMTK_SET_NMEA_OUTPUT_RMCONLY "$PMTK314,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0*29"
#define PMTK_SET_NMEA_OUTPUT_RMCGGA "$PMTK314,0,1,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0*28"
// #define PMTK_SET_NMEA_OUTPUT_ALLDATA "$PMTK314,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0*28"
// #define PMTK_SET_NMEA_OUTPUT_OFF "$PMTK314,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0*28"

#define PMTK_SET_NMEA_UPDATE_1HZ  "$PMTK220,1000*1F"
#define PMTK_SET_NMEA_UPDATE_5HZ  "$PMTK220,200*2C"

TinyGPSPlus gps;
float lat, lng, spd, crs, alt;

extern "C" void GPSInit(){
    Serial.begin(115200);
    Serial1.begin(9600);
    Serial1.println(PMTK_SET_NMEA_OUTPUT_RMCGGA);
    Serial1.println(PMTK_SET_NMEA_UPDATE_1HZ);
    Serial1.println("$PMTK386,0.4*39"); //Set 0.4m/s nav ignore threshold
}
// 
// extern "C" void GPSRead(float* values){
//     while(Serial1.available()){
//         if(gps.encode(Serial1.read())){
//             //Valid NMEA sentence found
//             values[0] = gps.location.lat();
//             values[1] = gps.location.lng();
//             values[2] = gps.speed.mps();
//             values[3] = gps.course.deg();
//             values[4] = gps.altitude.meters();
//             
//             break;
//         }
//     }
// }


extern "C" void GPSUpdate(){
    while(Serial1.available()){
        if(gps.encode(Serial1.read())){
            //Valid NMEA sentence found
            lat = gps.location.lat();
            lng = gps.location.lng();
            spd = gps.speed.mps();
            crs = gps.course.deg();
            alt = gps.altitude.meters();
            
            break;
        }
    }
}


extern "C" float getLat(){
    Serial.println(lat);
    return lat;
}

extern "C" float getLng(){
    return lng;
}

extern "C" float getSpeed(){
    return spd;
}

extern "C" float getCourse(){
    return crs;
}

extern "C" float getAlt(){
    return alt;
}