#include "capacitiveKey.h"
#include "limits.h"

#define THRESHOLD_MULTIPLIER 1.2
#define THRESHOLD_LOWER_MULTIPLIER 0.75

CapacitiveKey::CapacitiveKey(const uint8_t activePin, const uint8_t sensorPin, const size_t samples, const uint32_t threshold, const size_t track) : 
    sensor_(CapacitiveSensor(activePin, sensorPin, samples)),
    autoThresh_(false),
    lastPressed_(false)
{
    threshold_ = threshold;
    track_ = track;
    lastVal_ = __UINT32_MAX__;
}

CapacitiveKey::CapacitiveKey(const uint8_t activePin, const uint8_t sensorPin, const size_t samples, const size_t track) : 
    sensor_(CapacitiveSensor(activePin, sensorPin, samples)),
    autoThresh_(true),
    lastPressed_(false)
{
    threshold_ = __UINT32_MAX__;
    track_ = track;
    lastVal_ = __UINT32_MAX__; 
}

bool CapacitiveKey::isPressed()
{
    bool pressed = getPressed();
    if(lastPressed_)
    {
        lastPressed_ = pressed;
        return false;
    }

    lastPressed_ = pressed;
    return pressed;
}

bool CapacitiveKey::getPressed()
{
    lastVal_ = sensor_.readValue();
    if(lastVal_ > threshold_)
    {
        return true;
    }

    if(!autoThresh_ || ( lastVal_ > threshold_*THRESHOLD_LOWER_MULTIPLIER))
    {
        return false;
    }

    // threshold_ = __UINT32_MAX__;

    threshold_ = lastVal_*THRESHOLD_MULTIPLIER;

    return false;
}

size_t CapacitiveKey::getTrack()
{
    return track_;
}

uint32_t CapacitiveKey::getThreshold()
{
    return threshold_;
}

uint32_t CapacitiveKey::getLastVal()
{
    return lastVal_;
}