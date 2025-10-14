// #include <Arduino.h>

// // put function declarations here:
// int myFunction(int, int);

// void setup() {
//   // put your setup code here, to run once:
//   pinMode(27, OUTPUT);

//   pinMode(19, OUTPUT);
//   digitalWrite(19, HIGH);
//   pinMode(18, OUTPUT);
//   digitalWrite(18, HIGH);
// }

// void loop() {
//   // put your main code here, to run repeatedly:
//   digitalWrite(27, HIGH);
//   delay(1000);
//   digitalWrite(27, LOW);
//   delay(1000);
// }

// // put function definitions here:
// int myFunction(int x, int y) {
//   return x + y;
// }

// #include <Arduino.h>

// #define BUZZER_PIN  27     // GPIO connected to buzzer
// #define PWM_CH      0      // PWM channel (0–15)
// #define FREQ        2000   // Default frequency (Hz)
// #define RESOLUTION  10     // 10-bit resolution (0–1023)

// void setup() {
//   // Setup PWM channel
//   ledcSetup(PWM_CH, FREQ, RESOLUTION);
//   ledcAttachPin(BUZZER_PIN, PWM_CH);

// }

// void loop() {
//    // --- 1. Simple beep pattern ---
//   for (int i = 0; i < 3; i++) {
//     ledcWriteTone(PWM_CH, 2000 + i * 400); // change tone
//     delay(150);
//     ledcWrite(PWM_CH, 0);                  // stop tone
//     delay(150);
//   }

//   // --- 2. Frequency sweep (400Hz → 3kHz) ---
//   for (int f = 400; f <= 3000; f += 100) {
//     ledcWriteTone(PWM_CH, f);
//     delay(20);
//   }
//   ledcWrite(PWM_CH, 0);
//   delay(500);

//   // --- 3. Short melody ---
//   int melody[] = {262, 294, 330, 349, 392, 440, 494, 523};
//   for (int i = 0; i < 8; i++) {
//     ledcWriteTone(PWM_CH, melody[i]);
//     delay(250);
 
//   }
//   ledcWrite(PWM_CH, 0); // stop buzzer

// }

#include <Arduino.h>

// --- LED setup ---
#define LED_PIN   18
#define LED_CH    0
#define LED_FREQ  5000
#define LED_RES   8

// --- Buzzer setup ---
#define BUZZER_PIN  27
#define BUZZER_CH   1
#define BUZZER_FREQ 2000
#define BUZZER_RES  10

void setup() {
  // --- LED PWM setup ---
  ledcSetup(LED_CH, LED_FREQ, LED_RES);
  ledcAttachPin(LED_PIN, LED_CH);

  // --- Buzzer PWM setup ---
  ledcSetup(BUZZER_CH, BUZZER_FREQ, BUZZER_RES);
  ledcAttachPin(BUZZER_PIN, BUZZER_CH);
}

void loop() {
  // --- LED fade effect ---
  for (int d = 0; d <= 255; d=d+20) {
    ledcWrite(LED_CH, d);
    delay(10);
  }
  for (int d = 255; d >= 0; d=d-20) {
    ledcWrite(LED_CH, d);
    delay(10);
  }
  
  // --- Buzzer part ---
  for (int i = 0; i < 3; i++) {
    ledcWriteTone(BUZZER_CH, 2000 + i * 400);
    delay(150);
    ledcWrite(BUZZER_CH, 0);
    delay(150);
  }

  for (int f = 400; f <= 3000; f += 100) {
    ledcWriteTone(BUZZER_CH, f);
    delay(20);
  }
  ledcWrite(BUZZER_CH, 0);
  delay(500);

  int melody[] = {262, 294, 330, 349, 392, 440, 494, 523};
  for (int i = 0; i < 8; i++) {
    ledcWriteTone(BUZZER_CH, melody[i]);
    delay(250);
  }
  ledcWrite(BUZZER_CH, 0);

}
