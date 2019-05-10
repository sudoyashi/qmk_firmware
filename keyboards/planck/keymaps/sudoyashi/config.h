#pragma once
#include "song_list.h"

#define ADVENTURE_TIME \
    H__NOTE(_F5),    \
    Q__NOTE(_F5),    \
    H__NOTE(_F5),    \
    H__NOTE(_G5),    \
    H__NOTE(_E5),    \
    H__NOTE(_E5),    \
    H__NOTE(_D5),    \
    H__NOTE(_C5),    \
    HD_NOTE(_C6),

#ifdef AUDIO_ENABLE
    #define DEFAULT_LAYER_SONGS {SONG(SONIC_RING)}
    #define STARTUP_SONG SONG(ADVENTURE_TIME)
    #define AUDIO_CLICKY
    #define AUDIO_CLICKY_ON
    #define AUDIO_CLICKY_FREQ_MAX 2500.0f
    #define AUDIO_CLICKY_FREQ_RANDOMNESS 0.2f
    #define AUDIO_CLICKY_FREQ_DEFAULT 110.0f
#endif

#define MIDI_BASIC
#define TAPPING_TERM 200

// Most tactile encoders have detents every 4 stages
#define ENCODER_RESOLUTION 4
#define NUMBER_OF_ENCODERS 1
#define ENCODERS_PAD_A { B12 }
#define ENCODERS_PAD_B { B13 }
