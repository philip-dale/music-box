#ifndef CAPACITIVE_SENSOR_H
#define CAPACITIVE_SENSOR_H

#include <Arduino.h>
#include "fastPin.h"

class CapacitiveSensor 
{
    public:
        CapacitiveSensor(const uint8_t activePin, const uint8_t sensorPin, const size_t samples);
        ~CapacitiveSensor(){};
        uint32_t readValue();

    private:
        uint32_t riseFallCount();
        size_t samples_;
        PinInfo activePinInfo_;
        PinInfo sensorPinInfo_;
};

#endif //CAPACITIVE_SENSOR_H