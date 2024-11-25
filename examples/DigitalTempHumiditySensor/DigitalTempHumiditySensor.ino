#include <ConsentiumStarterKit.h>

// Define the DHT sensor pin
const int DHT_PIN = 12;

// Create an instance of the DigitalTemperatureHumiditySensor class
ConsentiumStarterKit digitalhtSensor(DIGITAL_TEMP_HUMIDITY,DHT_PIN, DHT11);

void setup() {
    Serial.begin(9600);

    // Initialize the DHT sensor
    digitalhtSensor.begin();
    Serial.println("DHT11 Sensor Initialized!");
}

void loop() {
    // Read temperature in Celsius
    float temperatureC = digitalhtSensor.getDigitalTemperatureC();
    // Read temperature in Fahrenheit
    float temperatureF = digitalhtSensor.getDigitalTemperatureF();
    // Read humidity
    float humidity = digitalhtSensor.getDigitalHumidity();

    // Display the values on the Serial Monitor
    if (temperatureC != -1.0 && temperatureF != -1.0 && humidity != -1.0) {
        Serial.print("Temperature: ");
        Serial.print(temperatureC);
        Serial.print(" °C | ");
        Serial.print(temperatureF);
        Serial.print(" °F | ");
        Serial.print("Humidity: ");
        Serial.print(humidity);
        Serial.println(" %");
    } else {
        Serial.println("Failed to read from the DHT11 sensor.");
    }

    // Wait for 2 seconds before reading again
    delay(2000);
}
