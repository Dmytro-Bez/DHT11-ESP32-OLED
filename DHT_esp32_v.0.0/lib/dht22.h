#include"def.h"
#include"lib.h"

float h, t;
DHT dht(DHTPIN, DHTTYPE);

void send_dht22(){
  h = dht.readHumidity();
  t = dht.readTemperature();
  /*=====================================*/
  Serial.print("Humidity: ");
  Serial.print(h);
  Serial.print(" %\t");
  Serial.print("Temperature: ");
  Serial.print(t);
  Serial.println(" *C ");
}
