#include <Arduino.h>

// sbr64: define the built in LED pin pasted from Lab 2's blink code
#define LED_PIN 13

// sbr64: put touch sensor pin assignment here
const int sensorPin = A0;

void setup() {
    Serial.begin(115200);

    // sbr64: set sensorPin as an input so the ESP32 can read the touch sensor's signal
    pinMode(sensorPin, INPUT);

    // sbr64: set LED_PIN as an output so we can turn the onboard LED on/off
    pinMode(LED_PIN, OUTPUT);
}

void loop() {
    int sensorValue = analogRead(sensorPin);

    if (sensorValue > 2000) {
        Serial.println("Touch detected!");
        // sbr64: turn the ESP32 LED on when a touch is detected
        digitalWrite(LED_PIN, HIGH);
    } else {
        Serial.println("No touch detected...");
        // sbr64: turn the ESP32 LED off when no touch is detected
        digitalWrite(LED_PIN, LOW);
    }

    delay(200);
}
