#include"def.h"
#include"lib.h"

int altitude;
Adafruit_BME280 bme;

void send_bme280(){
  Serial.print(bme.readPressure() / VALUE_PRESURE);
  Serial.println(" hPa");
  altitude = bme.readAltitude(SEALEVELPRESSURE_HPA);
  Serial.print(altitude);
  Serial.println(" mm");
}
