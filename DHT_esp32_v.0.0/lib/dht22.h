#include"def.h"
#include"lib.h"

void init_lcd();

float h, t;
int altitude;
DHT dht(DHTPIN, DHTTYPE);

void init_sensor(){
  if (isnan(h) || isnan(t)) {
    Serial.println("Failed to read from DHT sensor!");
    return;
  }
  h = dht.readHumidity();
  t = dht.readTemperature();
  /*=====================================*/
  Serial.print("Humidity: ");
  Serial.print(h);
  Serial.print(" %\t");
  Serial.print("Temperature: ");
  Serial.print(t);
  Serial.println(" *C ");
  /*=====================================*/
  Serial.print(bme.readPressure() / VALUE_PRESURE);
  Serial.println(" hPa");
  altitude = bme.readAltitude(SEALEVELPRESSURE_HPA);
  Serial.print(altitude);
  Serial.println(" mm");
  /*=====================================*/
  init_lcd();
}
