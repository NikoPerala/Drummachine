#include "display_desktop.h"
#include "bitwise.h"

#include <stdio.h>

const int STEP_SIZE = (int) ((float) W_WIDTH / STEPS_PER_PATTERN);
const int STEP_Y = (W_HEIGHT - STEP_SIZE) >> 1;

uint32_t millis()
{
    struct timeval t;
    gettimeofday(&t, NULL);
    return t.tv_sec * 1000 + ( t.tv_usec + 500 ) / 1000;
}

int is_hovered(Vector2 pt, int x, int y, int w, int h)
{
    return (pt.x > x && pt.x < x + w && pt.y > y && pt.y < y + h);
}

void read_inputs_and_set_data(Drummachine *dm)
{
    Vector2 mouse = GetMousePosition();
    Pattern *ptr = &dm->channels[dm->current_channel].patterns[dm->current_pattern];
    for (int i = 0; i < STEPS_PER_PATTERN; ++i){
        if (is_hovered(mouse, i * STEP_SIZE, STEP_Y, STEP_SIZE, STEP_SIZE) && IsMouseButtonPressed(0)){
            TOGGLE_BIT(ptr->steps[i].flags, STEP_FLAG_ON);
        }
    }
}

void init_raylib()
{
    InitWindow(W_WIDTH, W_HEIGHT, W_TITLE);
    SetTargetFPS(W_TARGET_FPS);
}

void close_raylib()
{
    CloseWindow();
}

#define STEP_PADDING 3
void draw_step(int x, int y, int w, int h, Color c)
{
    DrawRectangle(x, y, w, h, BLACK);
    DrawRectangle(x + STEP_PADDING, y + STEP_PADDING, w - STEP_PADDING, h - STEP_PADDING, c);
}

int display(Drummachine dm)
{
    char dbgmsg[100];
    int key;
    
    BeginDrawing();

    Pattern *ptr = &dm.channels[dm.current_channel].patterns[dm.current_pattern];
    Color c;
    for (int i = 0; i < STEPS_PER_PATTERN; ++i){
        c = CHECK_BIT(ptr->steps[i].flags, STEP_FLAG_ON) ? GREEN : (Color) { 0x18, 0x18, 0x18, 0xff };
        c = i == dm.channels[dm.current_channel].current_step ? RED : c;
        draw_step(i * STEP_SIZE, STEP_Y, STEP_SIZE, STEP_SIZE, c);
    }   

    sprintf(dbgmsg, "interval: %d", dm.interval);
    DrawText(dbgmsg, 20, 20, 20, WHITE);

    key = GetKeyPressed();
    EndDrawing();

    return key;
}
