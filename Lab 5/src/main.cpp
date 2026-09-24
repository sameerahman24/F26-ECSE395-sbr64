#include <Arduino.h>
#include <ESP32Servo.h>

// sbr64: TOUCH SENSOR SETUP (from Lab 3 touch.cpp)

// sbr64: define the built in LED pin pasted from Lab 2's blink code
#define LED_PIN 13

// sbr64: touch sensor pin. moved from A0 to A2 since the servo is on A0 now
const int sensorPin = A2;

// sbr64: SERVO SETUPfrom Lab 4 Servo Motor Random.cpp

// Define the servo and the pin it is connected to, what is your servo pin?
Servo myServo;
const int servoPin = A0; //sbr64 servo signal wire is still on A0

// variable for random angle
int randomAngle;

// sbr64: remembers the last angle so the next one isnt the same spot
int lastAngle = 90;

// Variable for pulse width
int pulseWidth;

// Define the minimum and maximum pulse widths for the servo
const int minPulseWidth = 500; // 0.5 ms
const int maxPulseWidth = 2500; // 2.5 ms

void setup() {
    Serial.begin(115200);

    // sbr64: set sensorPin as an input so the ESP32 can read the touch sensor's signal
    pinMode(sensorPin, INPUT);

    // sbr64: set LED_PIN as an output so we can turn the onboard LED on/off
    pinMode(LED_PIN, OUTPUT);

    // Attach the servo to the specified pin and set its pulse width range
    myServo.attach(servoPin, minPulseWidth, maxPulseWidth);

    // Set the PWM frequency for the servo
    myServo.setPeriodHertz(50); // Standard 50Hz servo
}

void loop() {
    int sensorValue = analogRead(sensorPin); //sbr64 same read as Lab 3

    // sbr64: same threshold as Lab 3. over 2000 means the cat is touching the toy
    if (sensorValue > 2000) {
        Serial.println("Touch detected! start play");
        // sbr64: turn the ESP32 LED on while the toy is playing
        digitalWrite(LED_PIN, HIGH);

        unsigned long startTime = millis(); //sbr64 millis() is the time in ms since the ESP32 turned on, save when play started

        // sbr64: keep moving the servo until 10 seconds (10000 ms) have passed
        while (millis() - startTime < 10000) {
            // Make a Random Angle Between 0 to 180
            randomAngle = random(0, 181); //sbr64 picks a random angle from 0 to 180, it's 181 because random() never picks the top number

            // sbr64: if the new angle is within 40 degrees of the last one, pick again so the servo always makes a real move
            while (abs(randomAngle - lastAngle) < 40) {
                randomAngle = random(0, 181);
            }
            lastAngle = randomAngle; //sbr64 save it for the next check

            //  Map Pulse Width with Angle
            pulseWidth = map(randomAngle, 0, 180, minPulseWidth, maxPulseWidth); //sbr64 turns the random angle into a pulse width, same as Servo Motor.cpp
            myServo.writeMicroseconds(pulseWidth); // writing pulse width to servo

            delay(random(500, 1500)); //sbr64 waits a random time between 0.5 and 1.5 seconds before the next move
        }

        // sbr64: when play over turn the LED off
        digitalWrite(LED_PIN, LOW);
        Serial.println("Done playing and waiting for next touch");

        // sbr64: cooldown wait 2 seconds before checking the sensor again 
        delay(2000);
    }

    delay(50); //sbr64 check the sensor 20 times a second
}
