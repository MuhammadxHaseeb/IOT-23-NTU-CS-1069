#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

// ---- OLED setup ----
#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64
#define OLED_ADDR 0x3C

Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);

void setup() {
  Wire.begin(21, 22); // SDA=21, SCL=22 for ESP32

  if (!display.begin(SSD1306_SWITCHCAPVCC, OLED_ADDR)) {
    for (;;); // Stop if display not found
  }

  display.clearDisplay();

  // ---- Text and Box ----
  display.setTextSize(1);               // Normal text size
  display.setTextColor(SSD1306_WHITE);  // White text
  display.setCursor(30, 25);            // Start position for text

  display.println("M.haseeb");
  display.println("23-NTU-CS-1069");

  // Draw rectangle around the text
  display.drawRect(15, 15, 100, 40, SSD1306_WHITE);

  // Display all on OLED
  display.display();
}

void loop() {
  // Nothing to do repeatedly
}