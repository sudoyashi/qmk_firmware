#pragma once
#include "song_list.h"
#ifdef AUDIO_ENABLE
      #define STARTUP_SONG SONG(SONIC_RING)
    // #define STARTUP_SONG SONG(NO_SOUND)

    #define DEFAULT_LAYER_SONGS { SONG(SONIC_RING), \
                                  SONG(ZELDA_TREASURE), \
                                }
    #define MUSIC_ON_SONG SONG(VIOLIN_SOUND)
    #define MUSIC_OFF_SONG SONG(VICTORY_FANFARE_SHORT)
#endif

#define MIDI_BASIC
#define TAPPING_TERM 200

// Most tactile encoders have detents every 4 stages
#define ENCODER_RESOLUTION 4
