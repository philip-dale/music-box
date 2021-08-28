#include "musicPlayer.h"

void musicPlayer::setup(Stream& ser)
{
    ser_ = &ser;
    ready_ = true;
}

void musicPlayer::play(const uint16_t track)
{
    if(ready_)
    {
        uint8_t sendMessage[10] = {0x7E, 0xFF, 06, 03, 00, highByte(track), lowByte(track), 0x00, 0x00, 0xEF};
        addChecksum(sendMessage);
        ser_->write(sendMessage,10);
    }
}

uint16_t musicPlayer::addChecksum(uint8_t * data)
{
    uint16_t sum = 0;
    for(size_t i=1; i<7; ++i)
    {
        sum += data[i];
    }
    sum = -sum;

    data[7] = highByte(sum);
    data[8] = lowByte(sum);
}