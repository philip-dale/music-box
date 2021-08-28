Digital Music Box

Designed to work on Arduino MEGA2560 but should be modifiable to work with other arduinos.

Rotary encoder is attached to pins 3,4,5. The clk pin has to be connected to a pin with an interupt. This is used to controll the speed of the songs. The faster you turn the faster they play. If not turning, it will not play. Push button in for half second to change the song being played.

A DFPlayer mini mp3 player (https://www.dfrobot.com/index.php?route=product/product&product_id=1121) is connected to the hardware serial port 3. This has the mp3s of the notes that are played. The order they are copied to the memory card is the index that they have when played. This is 1 indexed, so first copied is track 1 4th is track 4 etc. I am using a hardware serial port but will probably work with a software serial port but I have not tried.

mp3s in music folder are my own recodings of a toy xylophone. These are copied to the sd card and put into the DFPlayer mini.