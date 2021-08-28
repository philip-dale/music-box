#include "barrelManager.h"

barrelManager::barrelManager()
{
    songList_[0] = &bridge[0][0];
    lengthList_[0] = sizeof(bridge)/4;
    songList_[1] = &races[0][0];
    lengthList_[1] = sizeof(races)/4;
    songList_[2] = &scale[0][0];
    lengthList_[2] = sizeof(scale)/4;
    songIndex_ = 0;
    setBarrel();
}

void barrelManager::nextSong()
{
    songIndex_++;
    if(songIndex_ >= NUM_OF_SONGS)
    {
        songIndex_ = 0;
    }
    setBarrel();
}

barrel* barrelManager::getBarrel()
{
    return &barrel_;
}

void barrelManager::setBarrel()
{
    barrel_.setup(songList_[songIndex_], lengthList_[songIndex_]);
}