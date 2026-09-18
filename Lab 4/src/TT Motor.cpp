#include <Arduino.h>

// TODO: Define your pins
// Hint: Look at your wiring. Which pins did you use?
const int MOTOR_B_1A = A1; // Replace 0 with your pin number
const int MOTOR_B_1B = A0; // Replace 0 with your pin number


void setup() {

  pinMode(MOTOR_B_1A, OUTPUT);
  pinMode(MOTOR_B_1B, OUTPUT);  

  analogWrite(MOTOR_B_1A, 0); //sbr64 this pin was 255 before and now it's 0
  analogWrite(MOTOR_B_1B, 200); //sbr64 this pin was 0 before. also dropped the value from 255 to 200 so it's a little slower

  delay(3000); //sbr64 changed the delay to 3000 from 5000, so it only runs for 3 seconds

  analogWrite(MOTOR_B_1A, 0);
  analogWrite(MOTOR_B_1B, 0);

}

void loop() {

}

// Note:
// - Please modify the `analogWrite()`, swap the `analogWrite()`, and modify the `delay()`.
// - You don't have to put anything in the loop.
//      - If you would like to run the code again, please press the `RESET BUTTON` on your ESP32.