#include"def.h"
#include"lib.h"
#include"bme280.h"
#include"dht22.h"
#include"ssd1306.h"

unsigned long currentMillis = 0;                          //Create variable mil.sec
unsigned long previousMillis = 0;
const long interval = 200;                                //Create variable interval

void init_wire(){                                         //Create function init wire
  Wire.begin();                                           //Init work I2C bus
  if(!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) {        //Audit physical connect oled
    Serial.println("SSD1306 allocation failed");
    for(;;);
  } 

  bool status = bme.begin(0x76);  
  if (!status) {
    Serial.println("Could not find a valid BME280 sensor, check wiring!");
    while (1);
  }

  if (isnan(h) || isnan(t)) {
    Serial.println("Failed to read from DHT sensor!");
    return;
  }
}

void send_sensor_date(){
  send_dht22();
  send_bme280();
}
