/*
   Consentium IoT - Ultrasonic Distance Measurement
   -------------------------------------------------
   This sketch demonstrates the use of the Consentium Starter Kit 
   to measure distances using an ultrasonic sensor and display 
   the results in both centimeters and inches.

   Designed and developed by Consentium IoT.
   Empowering IoT innovation with cutting-edge solutions.
   Visit us at: https://consentiumiot.com

   Hardware:
   - Ultrasonic Sensor (e.g., HC-SR04)
   - Consentium Starter Kit

   Connections:
   - Trigger Pin to digital pin 4
   - Echo Pin to digital pin 5
*/

#include <ConsentiumStarterKit.h> // Include Consentium Starter Kit library

// Pin definitions for the ultrasonic sensor
const int trigPin = 4; // Trigger pin connected to pin 4
const int echoPin = 5; // Echo pin connected to pin 5

// Initialize the Consentium Starter Kit with sensor pins
ConsentiumStarterKit ultrasonicKit(ULTRASONIC, trigPin, echoPin);

void setup() {
    // Begin serial communication for debugging and output
    Serial.begin(9600);

    // Initialize the sensor
    ultrasonicKit.begin();

    // Consentium IoT Branding message
    Serial.println("Consentium IoT - Ultrasonic Distance Measurement");
    Serial.println("-------------------------------------------------");
    Serial.println("Ready to measure distances...");
}

void loop() {
    // Get the distance from the ultrasonic sensor
    float distanceCm = ultrasonicKit.getDistanceCm();
    float distanceInches = ultrasonicKit.getDistanceInch();

    // Print the distances to the serial monitor with Consentium IoT branding
    Serial.print("[Consentium IoT] Distance: ");
    Serial.print(distanceCm);
    Serial.print(" cm | ");
    Serial.print(distanceInches);
    Serial.println(" in");

    // Wait for half a second before measuring again
    delay(500);
}
