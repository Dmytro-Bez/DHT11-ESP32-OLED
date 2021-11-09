#include"def.h"
#include"lib.h"

Adafruit_SSD1306 display(SCREEN_WIDTH, 
                        SCREEN_HEIGHT, &Wire, -1);        //Create object display
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
  display.setCursor(0,30);
  display.print("Pressure: ");   
  display.println((bme.readPressure() / VALUE_PRESURE));
  display.setCursor(0,45);
  display.print("Altitude: ");   
  display.println(altitude);
  display.display();
}
