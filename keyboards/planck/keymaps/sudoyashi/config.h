#pragma once
#include "song_list.h"

#ifdef AUDIO_ENABLE
    #define DEFAULT_LAYER_SONGS {SONG(SONIC_RING)}
    #define STARTUP_SONG SONG(SONIC_RING)
#endif

#define MIDI_BASIC
#define TAPPING_TERM 200

// Most tactile encoders have detents every 4 stages
#define ENCODER_RESOLUTION 4
#define NUMBER_OF_ENCODERS 1
#define ENCODERS_PAD_A { B12 }
#define ENCODERS_PAD_B { B13 }
