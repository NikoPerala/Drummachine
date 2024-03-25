#ifndef EPHO_DRUMMACHINE_CHANNEL_H
#define EPHO_DRUMMACHINE_CHANNEL_H

#include <stdint.h>
#include "pattern.h"

#define PATTERNS_PER_CHANNEL 2
#define ARRANGEMENT_LENGTH 16

/*
 *      NOTE:
 *      Check bitdepth of "type" variable if adding more channel types
 */
#define CHANNEL_OUTPUT_TYPES\
    X(CHANNEL_OUTPUT_TYPE_MIDI)\
    X(CHANNEL_OUTPUT_TYPE_SID)\
    X(CHANNEL_OUTPUT_TYPE_CV)\
    X(CHANNEL_OUTPUT_TYPE_GATE)\
    X(CHANNEL_OUTPUT_TYPE_CV_GATE)

#define X(name) name,
typedef enum {
    CHANNEL_OUTPUT_TYPES
} Channel_output_type;
#undef X

#ifdef XDEBUG
#define X(name) #name,
const char *Channel_output_type_names[] = {
    CHANNEL_OUTPUT_TYPES
};
#undef X
#endif

typedef struct channel {
    Channel_output_type type: 3;
    Pattern patterns[PATTERNS_PER_CHANNEL];
    uint8_t current_step;
    uint8_t current_pattern;
    uint8_t arrangement[ARRANGEMENT_LENGTH];
} Channel;

#endif // EPHO_DRUMMACHINE_CHANNEL_H
