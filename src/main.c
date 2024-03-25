#include "drummachine.h"

#ifdef DEBUG
#include <stdio.h>
#endif

#ifdef DESKTOP
#include "display_desktop.h"
#endif

int main(void)
{
#ifdef DESKTOP
    init_raylib();
#endif

    Drummachine dm;
    initialize_drummachine(&dm);
    uint32_t current_time = millis();
    dm.previous_step = current_time;

    for (;;) {
        current_time = millis();
        
        read_inputs_and_set_data(&dm);    
        move_step(&dm, current_time);       
 
 /*
 *      SET OUTPUTS
 */

#ifdef DESKTOP
        int key = display(dm);
        if (key == KEY_Q) break;
#endif
    }

#ifdef DESKTOP
    close_raylib();
#endif

    return 0;
}
