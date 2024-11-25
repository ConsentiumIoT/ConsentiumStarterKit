/*
   Consentium IoT - Lux Meter Reader
   ---------------------------------
   This sketch demonstrates how to use the Consentium Starter Kit
   with an LDR (Light Dependent Resistor) and a bias resistor to 
   measure and display ambient light intensity in lux.

   Designed and developed by Consentium IoT.
   Empowering IoT innovation with cutting-edge solutions.
   Visit us at: https://consentiumiot.com

   Hardware:
   - LDR (Light Dependent Resistor)
   - Bias Resistor (e.g., 10kΩ)
   - Consentium Starter Kit or any supported microcontroller

   Connections:
   - One terminal of the LDR to VCC
   - The other terminal of the LDR to an analog pin (e.g., A0) and one side of the bias resistor
   - The other side of the bias resistor to GND
*/

#include <ConsentiumStarterKit.h>

// Define the analog pin for the LDR sensor
const int luxSensorPin = A0;

// Define the bias resistor value (e.g., 10kΩ)
const int biasResistor = 10000;

// Define the calibration factor (default is 500)
const float luxFactor = 500.0;

// Create an instance of the ConsentiumStarterKit for the Lux Meter
ConsentiumStarterKit luxKit(LUX_METER, luxSensorPin);

void setup() {
    // Initialize serial communication
    Serial.begin(9600);

    // Initialize the Lux Meter
    luxKit.begin();

    // Consentium IoT branding and startup message
    Serial.println("Consentium IoT - Lux Meter Reader");
    Serial.println("---------------------------------");
    Serial.println("Lux Meter Initialized!");
}

void loop() {
    // Read light intensity in lux
    float luxValue = luxKit.getLuxValue(biasResistor, luxFactor);

    // Check for sensor initialization errors
    if (luxValue == -1) {
        Serial.println("[Consentium IoT] Error: Lux meter not initialized!");
    } else {
        // Print light intensity
        Serial.print("[Consentium IoT] Ambient Light Intensity: ");
        Serial.print(luxValue);
        Serial.println(" lux");
    }

    // Wait 1 second before the next reading
    delay(1000);
}
