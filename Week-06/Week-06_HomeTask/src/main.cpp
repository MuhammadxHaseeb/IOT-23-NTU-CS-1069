#include <Arduino.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <DHT.h>

// --- Pin configuration ---
#define DHTPIN 14        // DHT22 data pin
#define DHTTYPE DHT22    // Change to DHT11 if needed
#define LDR_PIN 34
#define SDA_PIN 21
#define SCL_PIN 22

// --- OLED setup ---
#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);

// --- DHT sensor setup ---
DHT dht(DHTPIN, DHTTYPE);

void setup() {
  Serial.begin(115200);
  Wire.begin(SDA_PIN, SCL_PIN);

  if (!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) {
    Serial.println("SSD1306 allocation failed");
    for (;;);
  }
  display.clearDisplay();
  display.setTextColor(SSD1306_WHITE);
  display.setTextSize(1);
  display.setCursor(0, 0);
  display.println("Initializing...");
  display.display();

  dht.begin();
  delay(1000);
}

void loop() {
  // --- DHT readings ---
  float temperature = dht.readTemperature();
  float humidity = dht.readHumidity();

  // --- LDR readings ---
  int adcValue = analogRead(LDR_PIN);
  float voltage = (adcValue / 4095.0) * 3.3;

  // --- Check sensor validity ---
  if (isnan(temperature) || isnan(humidity)) {
    Serial.println("Error reading DHT22 sensor!");
    return;
  }

  // --- Serial Monitor Output ---
  Serial.printf("Temp: %.2f C  |  Humidity: %.2f %%  |  ADC: %d  |  Voltage: %.2f V\n", temperature, humidity, adcValue, voltage);

  // --- OLED Display Output ---
  display.clearDisplay();
  display.setTextSize(1);
  display.setCursor(0, 0);
  display.println("Hello IoT");
  display.setCursor(0, 12);
  display.print("Temp: ");
  display.print(temperature);
  display.println(" C");
  display.setCursor(0, 24);
  display.print("Humidity: ");
  display.print(humidity);
  display.println(" %");
  display.setCursor(0, 36);
  display.print("LDR ADC: ");
  display.println(adcValue);
  display.setCursor(0, 48);
  display.print("Voltage: ");
  display.print(voltage, 2);
  display.println(" V");
  display.display();

  delay(2000);
}
