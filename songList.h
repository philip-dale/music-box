#ifndef SONG_LIST_H
#define SONG_LIST_H

#define NUM_OF_SONGS 5

#define Sm 20
#define Me 2*Sm
#define Lo 3*Sm
#define Vl 4*Sm
  
// Songs are defined by a 2d array of length n. first length n array is the index of the not to play. the second is the gap between each note.

static const uint16_t bridge[2][24] = {{ 5, 6, 5, 4, 3, 4, 5, 2, 3, 4, 3, 4, 5, 5, 6, 5, 4, 3, 4, 5, 2, 5, 3, 1},
                                       {Sm,Sm,Sm,Sm,Sm,Sm,Me,Sm,Sm,Me,Sm,Sm,Me,Sm,Sm,Sm,Sm,Sm,Sm,Me,Me,Me,Sm,Me}};

static const uint16_t races[2][23] = {{ 5, 5, 3, 5, 6, 5, 3, 3, 2, 2, 4, 5, 5, 5, 3, 5, 6, 5, 3, 2, 3, 2, 1},
                                      {Sm,Sm,Sm,Sm,Sm,Sm,Me,Sm,Lo,Sm,Me,Sm,Sm,Sm,Sm,Sm,Sm,Sm,Me,Me,Sm,Sm,Me}};

static const uint16_t sleep[2][17] = {{ 3, 2, 1, 1, 2, 1, 2, 3, 1, 3, 2, 1, 1, 2, 3, 2, 1},
                                      {Me,Sm,Me,Sm,Sm,Sm,Sm,Me,Sm,Me,Sm,Me,Sm,Sm,Sm,Sm,Lo}};                           

static const uint16_t moon[2][44] = {{ 4, 4, 4, 5, 6, 5, 4, 6, 5, 5, 4, 4, 4, 4, 5, 6, 5, 4, 6, 5, 5, 4, 5, 5, 5, 5, 2, 2, 5, 4, 3, 2, 1, 4, 4, 4, 5, 6, 5, 4, 6, 5, 5, 4},
                                     {Sm,Sm,Sm,Sm,Me,Me,Sm,Sm,Sm,Sm,Vl,Sm,Sm,Sm,Sm,Me,Me,Sm,Sm,Sm,Sm,Vl,Sm,Sm,Sm,Sm,Me,Me,Sm,Sm,Sm,Sm,Vl,Sm,Sm,Sm,Sm,Me,Me,Sm,Sm,Sm,Sm,Vl}};

static const uint16_t scale[2][8] = {{ 1, 2, 3, 4, 5, 6, 7, 8},
                                     {Sm,Sm,Sm,Sm,Sm,Sm,Sm,Sm}};

#endif