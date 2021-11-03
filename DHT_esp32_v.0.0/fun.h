#include"def.h"
#include"lib.h"

DHT dht(DHTPIN, DHTTYPE);

void init_lcd();

unsigned long currentMillis = 0;                          //Create variable mil.sec
unsigned long previousMillis = 0;
const long interval = 200;                                //Create variable interval
float h, t;
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);             //Create object display

void init_wire(){                                         //Create function init wire
  Wire.begin();                                           //Init work I2C bus
  if(!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) {        //Audit physical connect oled
    Serial.println("SSD1306 allocation failed");
    for(;;);
  } 
}

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
  init_lcd();
}

void init_lcd(){
  display.clearDisplay();                                 //Clear display
  display.setTextSize(1.8);             
  display.setTextColor(WHITE);        
  display.setCursor(0,0); 
  display.print("Temperature: ");              
  display.println(t);
  display.setCursor(0,15);
  display.print("Humidiry: ");   
  display.println(h);
  display.display();
}
