#include <Arduino.h>
#include "SDLogger.h"

#define CHIP_SELECT 10

void setup() {
  Serial.begin(115200);

  SDLoggerInit();
  float test[13] = {40.2f, 272.4f, 768.21f, 64.0f, 7827.4f, 9815.91f, 87.93f, 92.32f, 782.3f, 7972.98f, 10.83f, 2.03f, 55.3f};
  SDLoggerLog(test, 13);
  SDLoggerDestroy();
}

void loop() {
  // put your main code here, to run repeatedly:
}