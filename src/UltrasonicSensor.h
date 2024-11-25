#ifndef UltrasonicSensor_h
#define UltrasonicSensor_h

#include "Arduino.h"

class UltrasonicSensor{
    private:
        int _trigPin;
        int _echoPin;

        long _duration;

        long pingSensor();

        float calculateDistanceCm(long duration);
        float calculateDistanceInch(long duration);
    public:
        UltrasonicSensor(int trigPin, int echoPin);

        void beginUltrasonicSensor();

        float getDistanceCm();
        float getDistanceInch();
};

#endif