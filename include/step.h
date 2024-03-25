#ifndef EPHO_DRUMMACHINE_STEP_H
#define EPHO_DRUMMACHINE_STEP_H

typedef enum {
    STEP_FLAG_ON,
    STEP_FLAG_GO
} Step_flags;

typedef struct Step {
    uint8_t note;
    uint8_t velocity;
    uint8_t flags;
} Step;

#endif // EPHO_DRUMMACHINE_STEP_H
