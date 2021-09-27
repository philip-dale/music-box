#include "capacitiveSensor.h"
#include "limits.h"

#define SINGLE_READ_MAX 70000 // should not get any where near this number

CapacitiveSensor::CapacitiveSensor(const uint8_t activePin, const uint8_t sensorPin, const size_t samples) :
    samples_(samples)
{
    pinMode(activePin, OUTPUT);
	pinMode(sensorPin, INPUT);
	digitalWrite(activePin, LOW);

    FAST_SET_PIN_INFO(activePinInfo_, activePin);
    FAST_SET_PIN_INFO(sensorPinInfo_ , sensorPin);
}

uint32_t CapacitiveSensor::readValue()
{
    uint32_t count = 0;
    for(uint32_t i=0; i<samples_; ++i)
    {
        const uint32_t newCount = riseFallCount();
        if(newCount == SINGLE_READ_MAX) 
        {
            continue;
        }
        // calculate average count
        count += newCount;
        count /= 2;
    }
    return count;
}

uint32_t CapacitiveSensor::riseFallCount()
{
    //using fast pin as standard calls are too slow.

    // read rise time to 2.5v
    noInterrupts();
	FAST_WRITE_LOW(activePinInfo_); // ensure activePinInfo_ is low so capacitor is not charging
    FAST_MODE_OUTPUT(sensorPinInfo_); FAST_WRITE_LOW(sensorPinInfo_);	// set sensorPinInfo_ to low and output to drain capacitor
	delayMicroseconds(20); // wait for capacitor to drain
	FAST_MODE_INPUT(sensorPinInfo_);	// sensorPinInfo_ to input
	FAST_WRITE_HIGH(activePinInfo_);	// activePinInfo_ to high to start charging capacitor
    interrupts();

    uint32_t count = 0;
	// while sensorPinInfo_ pin is low
    while(!FAST_READ(sensorPinInfo_))
    {  
		++count;
	}

    // now test fall time to less than 2.5v
    noInterrupts();
	FAST_MODE_OUTPUT(sensorPinInfo_); FAST_WRITE_HIGH(sensorPinInfo_); // set sensorPinInfo_ to high and output to charge capacotor
    delayMicroseconds(20); // wait for capacitor to charge
	FAST_MODE_INPUT(sensorPinInfo_);	// sensorPinInfo_ to input
	FAST_WRITE_LOW(activePinInfo_);	// activePinInfo_ LOW to start draining capacitor
    interrupts();

    // while sensorPinInfo_ pin is high
    while(FAST_READ(sensorPinInfo_)) 
    {  
		++count;
	}

    return count;
}