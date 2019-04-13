#pragma once
#include "song_list.h"
#ifdef AUDIO_ENABLE
      #define STARTUP_SONG SONG(SONIC_RING)
    // #define STARTUP_SONG SONG(NO_SOUND)

    #define DEFAULT_LAYER_SONGS { SONG(ZELDA_TREASURE), \
                                  SONG(SONIC_RING), \
                                }
#endif

#define MIDI_BASIC
#define TAPPING_TERM 200

// Most tactile encoders have detents every 4 stages
#define ENCODER_RESOLUTION 4
