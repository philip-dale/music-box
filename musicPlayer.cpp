#include "musicPlayer.h"

#define MUSIC_PLAYER_START_BYTE     0x7E
#define MUSIC_PLAYER_END_BYTE       0xEF
#define MUSIC_PLAYER_VERSION        0xFF
#define MUSIC_PLAYER_NO_FEEDBACK    0
#define MUSIC_PLAYER_DATA_LENGTH    6
#define MUSIC_PLAYER_SET_TRACK_CMD  3

#define MUSIC_PLAYER_CHECKSUM_HIGH  7
#define MUSIC_PLAYER_CHECKSUM_LOW   8


void musicPlayer::setup(Stream& ser)
{
    ser_ = &ser;
    ready_ = true;
}

void musicPlayer::play(const uint16_t track)
{
    if(ready_)
    {
        uint8_t sendMessage[MUSIC_PLAYER_MESSAGE_LENGTH] = {MUSIC_PLAYER_START_BYTE, MUSIC_PLAYER_VERSION, MUSIC_PLAYER_DATA_LENGTH, 
                                                            MUSIC_PLAYER_SET_TRACK_CMD, MUSIC_PLAYER_NO_FEEDBACK, highByte(track),  
                                                            lowByte(track), 0x00, 0x00, MUSIC_PLAYER_END_BYTE};
        addChecksum(sendMessage);
        ser_->write(sendMessage,MUSIC_PLAYER_MESSAGE_LENGTH);
    }
}

uint16_t musicPlayer::addChecksum(uint8_t (&data)[MUSIC_PLAYER_MESSAGE_LENGTH])
{
    uint16_t sum = 0;
    for(size_t i=1; i<MUSIC_PLAYER_DATA_LENGTH+1; ++i)
    {
        sum += data[i];
    }
    sum = -sum;

    data[MUSIC_PLAYER_CHECKSUM_HIGH] = highByte(sum);
    data[MUSIC_PLAYER_CHECKSUM_LOW] = lowByte(sum);
}