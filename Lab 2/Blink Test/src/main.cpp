#include <Arduino.h>
// This is required in PlatformIO but hidden in the standard Arduino IDE.

#define LED_PIN 13

void setup() {
  pinMode(LED_PIN, OUTPUT);
  // TODO: Define your baud rates
  Serial.begin(115200); // Start the Serial connection (sbr64)
}

void loop() {
  // TODO: Define your text output
  Serial.println("Send help!"); // Print the words to the Serial Monitor. (sbr64)

  // TODO: Set up your delay in milliseconds
  // SOS blink pattern: ... --- ... (sbr64)

  // S: three short blinks (sbr64)
  digitalWrite(LED_PIN, HIGH); delay(200); digitalWrite(LED_PIN, LOW); delay(200); // (sbr64)
  digitalWrite(LED_PIN, HIGH); delay(200); digitalWrite(LED_PIN, LOW); delay(200); // (sbr64)
  digitalWrite(LED_PIN, HIGH); delay(200); digitalWrite(LED_PIN, LOW); delay(600); // (sbr64)

  // O: three long blinks (sbr64)
  digitalWrite(LED_PIN, HIGH); delay(600); digitalWrite(LED_PIN, LOW); delay(200); // (sbr64)
  digitalWrite(LED_PIN, HIGH); delay(600); digitalWrite(LED_PIN, LOW); delay(200); // (sbr64)
  digitalWrite(LED_PIN, HIGH); delay(600); digitalWrite(LED_PIN, LOW); delay(600); // (sbr64)

  // S: three short blinks (sbr64)
  digitalWrite(LED_PIN, HIGH); delay(200); digitalWrite(LED_PIN, LOW); delay(200); // (sbr64)
  digitalWrite(LED_PIN, HIGH); delay(200); digitalWrite(LED_PIN, LOW); delay(200); // (sbr64)
  digitalWrite(LED_PIN, HIGH); delay(200); digitalWrite(LED_PIN, LOW); delay(1400); // pause before repeating (sbr64)
}
