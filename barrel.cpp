#include "barrel.h"


barrel::barrel():
    currentIndex_(0),
    notes_(nullptr),
    gaps_(nullptr),
    length_(0),
    ready_(false)
{}

void barrel::setup(uint16_t * song, const size_t length)
{
    currentIndex_ = 0;
    notes_ = song;
    gaps_ = (int16_t*)(song+length);
    length_ = length;
    ready_ = true;
}

void barrel::playForward(uint16_t & note, int16_t & gap)
{
    if(ready_)
    {
        note = notes_[currentIndex_];
        gap = gaps_[currentIndex_];

        currentIndex_++;
        if (currentIndex_ >= length_)
        {
            currentIndex_ = 0;
        }
    }
}

void barrel::playBackward(uint16_t & note, int16_t & gap)
{
    if(ready_)
    {
        currentIndex_ = currentIndex_==0 ? length_-1 : currentIndex_-1;
        note = notes_[currentIndex_];

        gap = currentIndex_==0 ? gaps_[length_-1] : gaps_[currentIndex_-1];
    }
}