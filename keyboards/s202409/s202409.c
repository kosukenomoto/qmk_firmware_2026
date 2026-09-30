#include "quantum.h"

void housekeeping_task_kb(void) {
#ifdef AUDIO_ENABLE
    // quantum_task() runs audio_task() only on the USB master. The speaker
    // is on the left PCB, so also run delayed startup audio when it is slave.
    if (!is_keyboard_master()) {
        audio_task();
    }
#endif
}
