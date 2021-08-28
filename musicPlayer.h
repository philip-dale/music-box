#ifndef MUSIC_PLAYER_H
#define MUSIC_PLAYER_H

#include <Arduino.h>

class musicPlayer
{
    public: 
        musicPlayer():ready_(false){};
        ~musicPlayer(){};
        void setup(Stream& ser);
        void play(const uint16_t track);
    private:
        Stream* ser_;
        bool ready_;

        uint16_t addChecksum(uint8_t * data);
};

#endif