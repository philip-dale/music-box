#include "rotaryEncoder.h"
#include "barrelManager.h"
#include "musicPlayer.h"

#define RE_CLK_PIN 3
#define RE_DT_PIN 4
#define RE_PUSH_BTN 5

static rotaryEncoder re = rotaryEncoder();
void processRotation()
{
    re.process();
}

barrelManager bm = barrelManager();
musicPlayer player = musicPlayer();

void setup()
{
    Serial3.begin(9600); // music player serial port
    player.setup(Serial3);
    re.setup(RE_CLK_PIN, RE_DT_PIN, RE_PUSH_BTN, processRotation);
    delay(1000);
}

int16_t noteGap = 0;
uint16_t note;
int gapSinceSound = 0;

void loop()
{
    if(re.hasRotated()) {
        gapSinceSound += re.position(true);
    
        if(gapSinceSound > noteGap)
        {
            bm.getBarrel()->playForward(note,noteGap);
            player.play(note);
            gapSinceSound = 0;
        } 
        else if (gapSinceSound < 0)
        {
            bm.getBarrel()->playBackward(note,noteGap);
            player.play(note);
            gapSinceSound = noteGap;
        }
    }

    if(re.pressed())
    {
        bm.nextSong();
    }
    delay(100);
}
