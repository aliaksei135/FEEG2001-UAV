#include <Arduino.h>
#include "TinyGPSWrapper.h"
void setup() {
  Serial.begin(115200);
  GPSInit();
}

void loop() {
  long start = millis();
  float values[7];
  int valid = GPSRead(values);
  // if(valid == 1){
    for (int i = 0; i < 7; i++){
      Serial.println(values[i]);
    }  
  // }else{
  //   Serial.println("Invalid");
  // }
  long dur = millis() - start;
  Serial.println(dur);
  delay(500);
}