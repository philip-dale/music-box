#include "musicPlayer.h"
#include "capacitiveKey.h"
#include "HardwareSerial.h"

// #define STATS_MODE

musicPlayer player = musicPlayer();

#define SENSOR_SAMPLES 5

CapacitiveKey keys[] = {
    CapacitiveKey(53, 35, SENSOR_SAMPLES, 1),
    CapacitiveKey(53, 33, SENSOR_SAMPLES, 2),
    CapacitiveKey(53, 31, SENSOR_SAMPLES, 3)
};

const size_t keyCount = sizeof(keys)/sizeof(CapacitiveKey);

void setup()
{
#ifdef STATS_MODE
    Serial.begin(9600);
#endif
    Serial3.begin(9600); // music player serial port
    player.setup(Serial3);
    delay(1000);
}


void loop()
{
#ifdef STATS_MODE

    bool pressed[keyCount];

    for(size_t i=0; i<keyCount; ++i)
    {
        pressed[i] = keys[i].isPressed();
    }

    for(size_t i=0; i<keyCount; ++i)
    {
        if( i < keyCount-1)
        {
            Serial.print(keys[i].getLastVal());
            Serial.print(" - ");
        }
        else
        {
            Serial.println(keys[i].getLastVal());
        }
    }

    for(size_t i=0; i<keyCount; ++i)
    {
        if( i < keyCount-1)
        {
            Serial.print(keys[i].getThreshold());
            Serial.print(" - ");
        }
        else
        {
            Serial.println(keys[i].getThreshold());
        }
    }

    for(size_t i=0; i<keyCount; ++i)
    {
        if( i < keyCount-1)
        {
            Serial.print(pressed[i]);
            Serial.print(" - ");
        }
        else
        {
            Serial.println(pressed[i]);
        }
    }

    delay(1000);
#else
    for(size_t i=0; i<keyCount; ++i)
    {
        if(keys[i].isPressed())
        {
            player.play(keys[i].getTrack());
            delay(200);
        }
    }
    delay(100);
#endif
}
