#include"lib/fun.h"

void setup() {
  Serial.begin(115200); 
  dht.begin();
  init_wire();
  init_bme280();
}
void loop() {
  currentMillis = millis();                               //Call delay functions
  if (currentMillis - previousMillis >= interval) {
    previousMillis = currentMillis;
    init_sensor();  
  }
}
