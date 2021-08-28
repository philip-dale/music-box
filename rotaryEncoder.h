#ifndef ROTAR_ENCODER_H
#define ROTAR_ENCODER_H

#include <Arduino.h>

class rotaryEncoder
{
    public:
        typedef void (* ProcessFunc)(void);

        rotaryEncoder();
        ~rotaryEncoder(){};
        void setup(const uint8_t clkPin, const uint8_t dtPin, const ProcessFunc processFunc);
        void setup(const uint8_t clkPin, const uint8_t dtPin, const uint8_t btnPin, const ProcessFunc processFunc);
        void process();
        bool hasRotated();
        int position(const bool resetAfterRead);
        void reset();
        bool pressed();

    private:
        uint8_t clkPin_;
        uint8_t dtPin_;
        uint8_t btnPin_;
        bool useBtn_;
        ProcessFunc processFunc_;
        int encoderPosCount_; 
        int clkLast_;  
        bool rotated_;
        bool ready_;
};

#endif