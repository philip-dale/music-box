#ifndef BARREL_H
#define BARREL_H

#include <Arduino.h>

class barrel
{
    public:
        barrel();
        ~barrel(){};
        /* song needs to be kept in scope */
        void setup(uint16_t * song, const size_t length);
        void playForward(uint16_t & note, int16_t & gap);
        void playBackward(uint16_t & note, int16_t & gap);

    private:
        uint16_t * notes_;
        int16_t * gaps_;
        size_t length_;
        size_t currentIndex_;
        bool ready_;
        
};

#endif