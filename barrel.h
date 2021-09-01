#ifndef BARREL_H
#define BARREL_H

#include <Arduino.h>

class barrel
{
    public:
        barrel();
        ~barrel(){};
        /* song needs to be kept in scope */
        void setup(const uint16_t * song, const size_t length);
        void nextNote(uint16_t & note, int16_t & gap);
        void previousNote(uint16_t & note, int16_t & gap);

    private:
        const uint16_t * notes_;
        const int16_t * gaps_;
        size_t length_;
        size_t currentIndex_;
        bool ready_;
        
};

#endif