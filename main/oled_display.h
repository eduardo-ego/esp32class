#ifndef OLED_DISPLAY_H
#define OLED_DISPLAY_H

#include <Adafruit_SSD1306.h>
extern Adafruit_SSD1306 display;

void initOLED() {
  display.begin(SSD1306_SWITCHCAPVCC, 0x3C);
  display.clearDisplay();
  display.setTextSize(2);
  display.setTextColor(WHITE);
  display.display();
}

void displayText(String text) {
  display.clearDisplay();
  display.setCursor(0, 20);
  display.println(text);
  display.display();
}

Adafruit_SSD1306 display(128, 64, &Wire, -1);

#endif