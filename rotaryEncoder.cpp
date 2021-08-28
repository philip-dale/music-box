#include "rotaryEncoder.h"

rotaryEncoder::rotaryEncoder() :
    clkPin_(0),
    dtPin_(0),
    processFunc_(nullptr),
    encoderPosCount_(0), 
    clkLast_(0),
    rotated_(false),
    ready_(false)
{}

// clkPin must be connected to a pin with an interupt
void rotaryEncoder::setup(const uint8_t clkPin, const uint8_t dtPin, const ProcessFunc processFunc)
{
    useBtn_ = false;
    clkPin_ = clkPin;
    dtPin_ = dtPin;
    processFunc_ = processFunc;

    encoderPosCount_ = 0; 
    rotated_ = false;

    pinMode (clkPin_,INPUT);
    pinMode (dtPin_,INPUT);
    clkLast_ = digitalRead(clkPin_);
    attachInterrupt(digitalPinToInterrupt(clkPin_), processFunc, CHANGE);
    ready_ = true;
}

void rotaryEncoder::setup(const uint8_t clkPin, const uint8_t dtPin, const uint8_t btnPin, const ProcessFunc processFunc)
{
    btnPin_ = btnPin;
    pinMode (btnPin_,INPUT);
    setup(clkPin, dtPin, processFunc);
    useBtn_ = true;
}

void rotaryEncoder::process()
{
    if(ready_)
    {
        int cVal = digitalRead(clkPin_);
        if (cVal != clkLast_){ // Means the knob is rotating
            // if the knob is rotating, we need to determine direction
            // We do that by reading pin dt.
            if (digitalRead(dtPin_) != cVal) {  // Means pin clk Changed first - We're Rotating Clockwise
                encoderPosCount_ ++;
            } else {// Otherwise dt changed first and we're moving CCW
                encoderPosCount_--;
            }
            rotated_ = true;
        }
        clkLast_ = cVal;
    }
}

bool rotaryEncoder::hasRotated()
{
    return rotated_;
}

int rotaryEncoder::position(const bool resetAfterRead)
{
    int val = encoderPosCount_;
    if(resetAfterRead)
    {
        reset();
    }
    return val;
}

void rotaryEncoder::reset()
{
    encoderPosCount_ = 0;
    rotated_ = false;
}

bool rotaryEncoder::pressed()
{
    if(useBtn_)
    {
        if(digitalRead(btnPin_) == 0)
        {
            // need to debounce the push button, doing it in loop to stop noise slowing loop
            for(int i=0; i<50; i++)
            {
                delay(10);
                if(digitalRead(btnPin_) == 1)
                {
                    return false;
                }
            }
            // wait till it is release to prevent toggling
            while(digitalRead(btnPin_) == 0)
            {
                delay(10);
            }
            return true;
        }
    }
    return false;
}