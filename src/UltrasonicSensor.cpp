#include "UltrasonicSensor.h"

UltrasonicSensor::UltrasonicSensor(int trigPin, int echoPin) {
    _trigPin = trigPin;
    _echoPin = echoPin;
    _duration = 0; // Initialize duration
}

void UltrasonicSensor::beginUltrasonicSensor() {
    pinMode(_trigPin, OUTPUT);
    pinMode(_echoPin, INPUT);
}

long UltrasonicSensor::pingSensor() {
    digitalWrite(_trigPin, LOW);
    delayMicroseconds(2);
    digitalWrite(_trigPin, HIGH);
    delayMicroseconds(10);
    digitalWrite(_trigPin, LOW);

    long duration = pulseIn(_echoPin, HIGH, 30000); // Optional timeout 30ms
    return duration > 0 ? duration : 0; // Return 0 if no echo
}

float UltrasonicSensor::calculateDistanceCm(long duration) {
    return duration > 0 ? duration * 0.034 / 2 : -1; // Return -1 for error
}

float UltrasonicSensor::calculateDistanceInch(long duration) {
    return duration > 0 ? duration * 0.03133 / 2 : -1; // Return -1 for error
}

float UltrasonicSensor::getDistanceCm() {
    _duration = pingSensor();
    return calculateDistanceCm(_duration);
}

float UltrasonicSensor::getDistanceInch() {
    _duration = pingSensor();
    return calculateDistanceInch(_duration);
}
