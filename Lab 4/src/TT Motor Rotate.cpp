#include <Arduino.h>

// TODO: Define your pins
// Hint: Look at your wiring. Which pins did you use?
const int MOTOR_B_1A = A1; //sbr64 A1 goes to the driver's B-1A
const int MOTOR_B_2A = A0; //sbr64 A0 goes to the other driver pin

void setup() {
  // TODO: Initialize Serial communication
  Serial.begin(9600); //sbr64 starts serial at 9600 so the monitor works, 9600 is the PlatformIO default

  // TODO: Set your motor pins as OUTPUTs
  pinMode(MOTOR_B_1A,OUTPUT); //sbr64 makes this pin an output so the esp32 can drive the motor driver
  pinMode(MOTOR_B_2A,OUTPUT); //sbr64 same thing for the other pin

  Serial.println("Motor is ready"); //sbr64 prints once so I know setup finished
}

void loop() {
  // --- SECTION 1: Clokwise (5s) ---
  Serial.println("Clockwise"); //sbr64 prints which step it's on

  // TODO: Write HIGH to one pin and LOW to the other
  digitalWrite(MOTOR_B_1A,LOW); //sbr64 this pin low
  digitalWrite(MOTOR_B_2A,HIGH); //sbr64 this one high, my motor is wired so this way is clockwise

  delay(5000); //sbr64 keeps it spinning for 5 seconds

  // --- SECTION 2: Stop (2s) ---
  Serial.println("Stop"); //sbr64 prints stop

  // TODO: Turn off the motor
  digitalWrite(MOTOR_B_1A,LOW); //sbr64 both pins low means no voltage across the motor
  digitalWrite(MOTOR_B_2A,LOW); //sbr64 so it stops

  delay(2000); //sbr64 stays stopped for 2 seconds

  // --- SECTION 3: Counterclockwise (5s) ---
  Serial.println("Counterclockwise"); //sbr64 prints which step it's on

  // TODO: Write HIGH to one pin and LOW to the other
  digitalWrite(MOTOR_B_1A, HIGH); //sbr64 flipped from section 1
  digitalWrite(MOTOR_B_2A, LOW); //sbr64 flipped from section 1, so the motor spins the other way (counterclockwise)

  delay(5000); //sbr64 spins the other way for 5 seconds

  // --- SECTION 4: Stop (2s) ---
  Serial.println("Stop"); //sbr64 prints stop again

  // TODO: Turn off the motor
  digitalWrite(MOTOR_B_1A, LOW); //sbr64 both low again
  digitalWrite(MOTOR_B_2A, LOW); //sbr64 motor off

  delay(2000); //sbr64 waits 2 seconds, then loop() starts over at section 1
}


// Note:
// - Please uncomment the necessary lines and fill in the blank to complete the assignment.
