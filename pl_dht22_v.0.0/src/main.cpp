#include <Arduino.h>
#include "fun.h"

void setup() {
  Serial.begin(115200); 
  dht.begin();
  init_wire();
}

void loop() {
  currentMillis = millis();                               //Call delay functions
  if (currentMillis - previousMillis >= interval) {
    previousMillis = currentMillis;
    send_sensor_date();
    watch_lcd();
  }
}