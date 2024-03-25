#include <stddef.h>
#include "drummachine.h"
#include "bitwise.h"

// For synchronous channels
uint8_t time_to_take_a_step(Drummachine *dm, uint32_t time)
{
    if (time - dm->previous_step >= dm->interval){
        dm->previous_step = time;
        return 1;
    }
    return 0;
}

void initialize_drummachine(Drummachine *dm)
{
    Channel *ch   = NULL;
    Pattern *ptr  = NULL;
    Step    *step = NULL;

    set_tempo(dm, 120);

    for (int c = 0; c < CHANNELS_IN_MACHINE; ++c){
        ch = &dm->channels[c];
        ch->type = CHANNEL_OUTPUT_TYPE_MIDI;
        ch->current_step = 0;
        ch->current_pattern = 0;
        
        for (int p = 0; p < PATTERNS_PER_CHANNEL; ++p){
            ptr = &ch->patterns[p];
            ptr->count = STEPS_PER_PATTERN - 1;
            for (int s = 0; s < STEPS_PER_PATTERN; ++s){
                step = &ptr->steps[s];
                step->note = 0;
                step->velocity = 0x80;
                step->flags = 0;
            }
        }
    }
}

void move_step(Drummachine *dm, uint32_t time)
{
    if (time_to_take_a_step(dm, time)){
        for (int i = 0; i < CHANNELS_IN_MACHINE; ++i){

            Channel *ch = &dm->channels[i];
            Pattern *ptr = &dm->channels[i].patterns[ch->current_pattern];
            
            ch->current_step++;
            if (ch->current_step > ptr->count){
                ch->current_step = 0;
            }

            SET_BIT(ptr->steps[ch->current_step].flags, STEP_FLAG_GO);
        }
    }
}

void set_tempo(Drummachine *dm, uint16_t tempo)
{
    dm->tempo = tempo;
    dm->interval = 1.f / tempo * 60 * 1000; // ms
}

