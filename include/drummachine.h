#ifndef EPHO_DRUMMACHINE_H_
#define EPHO_DRUMMACHINE_H_

#include <stdint.h>
#include "channel.h"

#ifndef CHANNELS_IN_MACHINE
#define CHANNELS_IN_MACHINE 4
#endif

typedef struct Drummachine {
    Channel channels[CHANNELS_IN_MACHINE];
    uint8_t current_channel;
    uint8_t current_pattern;
    uint32_t previous_step;
    uint16_t tempo;
    uint16_t interval;
} Drummachine;

uint8_t time_to_take_a_step(Drummachine *dm, uint32_t time);
void initialize_drummachine(Drummachine *dm);
void move_step(Drummachine *dm, uint32_t time);
void set_tempo(Drummachine *dm, uint16_t tempo);

#endif // EPHO_DRUMMACHINE_H_
