/*
   Consentium IoT - LM35 Temperature Sensor Reader
   -------------------------------------------------
   This sketch demonstrates how to use the Consentium Starter Kit
   with an LM35 analog temperature sensor to read and display 
   temperature in Celsius and Fahrenheit.

   Designed and developed by Consentium IoT.
   Empowering IoT innovation with cutting-edge solutions.
   Visit us at: https://consentiumiot.com

   Hardware:
   - LM35 Analog Temperature Sensor
   - Consentium Starter Kit or any supported microcontroller

   Connections:
   - LM35 VCC to 5V (or 3.3V for ESP32/ESP8266)
   - LM35 GND to GND
   - LM35 Output to an analog pin (e.g., A0)
*/

#include <ConsentiumStarterKit.h>

// Define the analog pin for the LM35 sensor
const int tempSensorPin = A0;

// Create an instance of the ConsentiumStarterKit for the temperature sensor
ConsentiumStarterKit tempKit(ANALOG_TEMP,tempSensorPin);

void setup() {
    // Initialize serial communication
    Serial.begin(9600);

    // Initialize the temperature sensor
    tempKit.begin();

    // Consentium IoT branding and startup message
    Serial.println("Consentium IoT - LM35 Temperature Sensor Reader");
    Serial.println("-------------------------------------------------");
    Serial.println("Temperature Sensor Initialized!");
}

void loop() {
    // Read temperature in Celsius and Fahrenheit
    float temperatureC = tempKit.getTemperatureC();
    float temperatureF = tempKit.getTemperatureF();

    // Check for sensor initialization errors
    if (temperatureC == -1 || temperatureF == -1) {
        Serial.println("[Consentium IoT] Error: Temperature sensor not initialized!");
    } else {
        // Print temperature readings
        Serial.print("[Consentium IoT] Temperature: ");
        Serial.print(temperatureC);
        Serial.print(" °C | ");
        Serial.print(temperatureF);
        Serial.println(" °F");
    }

    // Wait 1 second before the next reading
    delay(1000);
}
