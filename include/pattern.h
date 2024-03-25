#ifndef EPHO_DRUMMACHINE_PATTERN_H
#define EPHO_DRUMMACHINE_PATTERN_H

#include "step.h"

#define STEPS_PER_PATTERN 16

typedef struct Pattern {
    Step steps[STEPS_PER_PATTERN];    
    uint8_t count;
} Pattern;

#endif // EPHO_DRUMMACHINE_PATTERN_H
