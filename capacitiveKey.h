#ifndef CAPACITIVE_KEY_H
#define CAPACITIVE_KEY_H

#include "Arduino.h"
#include "capacitiveSensor.h"

class CapacitiveKey {

    public:
        CapacitiveKey(const uint8_t activePin, const uint8_t sensorPin, const size_t samples, const uint32_t threshold, const size_t track);
        CapacitiveKey(const uint8_t activePin, const uint8_t sensorPin, const size_t samples, const size_t track);
        ~CapacitiveKey(){};
        bool isPressed();
        size_t getTrack();
        uint32_t getThreshold();
        uint32_t getLastVal();
    
    private:
        bool getPressed();

        bool autoThresh_;
        size_t track_;
        uint32_t threshold_;
        CapacitiveSensor sensor_;
        uint32_t lastVal_;
        bool lastPressed_;
};

#endif