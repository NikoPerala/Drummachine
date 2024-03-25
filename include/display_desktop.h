#ifndef EPHO_DRUMMACHINE_RAYLIB_H
#define EPHO_DRUMMACHINE_RAYLIB_H

#include <raylib.h>
#include <stdlib.h>
#include <stdint.h>
#include <sys/time.h>
#include "drummachine.h"


#define W_WIDTH 1000
#define W_HEIGHT 800
#define W_TITLE "Ephotek drummachine prototype"
#define W_TARGET_FPS 60

/*
const int STEP_SIZE = (int) ((float) W_WIDTH / STEPS_PER_PATTERN);
const int STEP_Y = (W_HEIGHT - STEP_SIZE) >> 1;
*/

uint32_t millis();
void init_raylib();
void close_raylib();
int display(Drummachine dm);
void read_inputs_and_set_data(Drummachine *dm);

#endif // EPHO_DRUMMACHINE_RAYLIB_H
