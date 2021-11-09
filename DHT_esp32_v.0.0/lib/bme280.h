#include"def.h"
#include"lib.h"

Adafruit_BME280 bme;

bool init_bme280(){
  bool status;
  status = bme.begin(0x76);  
  if (!status) {
    Serial.println("Could not find a valid BME280 sensor, check wiring!");
    while (1);
  }
  return status;
}
