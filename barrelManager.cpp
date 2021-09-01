#include "barrelManager.h"

barrelManager::barrelManager()
{
    songList_[0] = &bridge[0][0];
    lengthList_[0] = sizeof(bridge)/4;
    songList_[1] = &races[0][0];
    lengthList_[1] = sizeof(races)/4;
    songList_[2] = &sleep[0][0];
    lengthList_[2] = sizeof(sleep)/4;
    songList_[3] = &moon[0][0];
    lengthList_[3] = sizeof(moon)/4;
    songList_[4] = &scale[0][0];
    lengthList_[4] = sizeof(scale)/4;
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

void barrelManager::setBarrel(const size_t songIndex)
{
    songIndex_ = songIndex;
    if(songIndex_ >= NUM_OF_SONGS)
    {
        songIndex_ = 0;
    }
    setBarrel();
}

void barrelManager::setBarrel()
{
    barrel_.setup(songList_[songIndex_], lengthList_[songIndex_]);
}