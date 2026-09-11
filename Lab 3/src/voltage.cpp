
#include <Arduino.h>

// function prototype
float voltage(float analogvalue);

// Put your potentiometer pin assignment here
const int sensorPin = A0;

void setup() {
    Serial.begin(115200);
}

void loop() {
    // This is the line for printing in the serial
    // sbr64: instead of reading and printing in one line, initialize sensorValue and read the sensorPin analog pinout into it
    int sensorValue = analogRead(sensorPin);

    // sbr64: sensorVoltage calls the voltage() function below to convert sensorValue to voltage
    float sensorVoltage = voltage(sensorValue);

    // sbr64:print the voltage from the potentiometer to the serial monitor
    Serial.println(sensorVoltage);

    // sbr64:delay changed from 50ms to 200ms as the serial output was too fast to read
    delay(200);
}

// function to calculate output voltage
// sbr64: filled in the formula below so this function  converts sensorValue to sensorVoltage
float voltage(float analogvalue){
    float voltage;
    //analogRead(sensorPin); gives us 0-4095 values
    //use the formula (Analog value*Reference voltage) / (Sensor Resolution) to calculate the output voltage
    voltage = (analogvalue * 3.3) / 4095.0;
    return voltage;
}

