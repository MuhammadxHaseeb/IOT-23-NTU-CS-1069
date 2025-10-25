#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64
#define OLED_ADDR 0x3C

Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);

void drawStickman(int x, int y, int scale = 1) {
  display.drawCircle(x, y, 5 * scale, SSD1306_WHITE);
  display.fillCircle(x - 2 * scale, y - 1 * scale, 1, SSD1306_WHITE);
  display.fillCircle(x + 2 * scale, y - 1 * scale, 1, SSD1306_WHITE);
  display.drawLine(x, y + 5 * scale, x, y + 20 * scale, SSD1306_WHITE);
  display.drawLine(x, y + 8 * scale, x - 10 * scale, y + 12 * scale, SSD1306_WHITE);
  display.drawLine(x, y + 8 * scale, x + 10 * scale, y + 12 * scale, SSD1306_WHITE);
  display.drawLine(x, y + 20 * scale, x - 8 * scale, y + 32 * scale, SSD1306_WHITE);
  display.drawLine(x, y + 20 * scale, x + 8 * scale, y + 32 * scale, SSD1306_WHITE);
}

void setup() {
  Wire.begin(21, 22); 

  if (!display.begin(SSD1306_SWITCHCAPVCC, OLED_ADDR)) {
    for (;;); 
  }

  display.clearDisplay();
  drawStickman(64, 15, 1);
  display.display();
}

void loop() {
  // nothing to do
}