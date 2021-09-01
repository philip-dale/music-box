#ifndef BARREL_MANAGER_H
#define BARREL_MANAGER_H


#include <Arduino.h>
#include "barrel.h"                            
#include "songList.h"

class barrelManager
{
    public:
        barrelManager();
        ~barrelManager(){};
        void nextSong();
        barrel* getBarrel();
        void setBarrel(const size_t songIndex);
    private:
        uint16_t * songList_[NUM_OF_SONGS];
        size_t lengthList_[NUM_OF_SONGS];
        size_t songIndex_;
        barrel barrel_;

        void setBarrel();
};

#endif