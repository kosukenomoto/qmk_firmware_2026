#pragma once

#define CHORDAL_HOLD
#define FLOW_TAP_TERM 150
#define TAPPING_TERM 200
#define TAPPING_TERM_PER_KEY
#define HOLD_ON_OTHER_KEY_PRESS
#define HOLD_ON_OTHER_KEY_PRESS_PER_KEY
#define PERMISSIVE_HOLD
#define PERMISSIVE_HOLD_PER_KEY


#define AUDIO_PIN C6
#define AUDIO_INIT_DELAY
#define NO_MUSIC_MODE // Save 2000 bytes
// PWM duty, not a volume percentage. ~1/6 adds a strong 4 kHz harmonic
// to both 2 kHz (second harmonic) and 1 kHz (fourth harmonic) on LS1.
#define TIMBRE_DEFAULT 17
// PC-98-style "pi-po": 2 kHz then 1 kHz, about 100 ms each at 120 BPM.
#define TEMPO_DEFAULT 120
#define STARTUP_SONG SONG({2000.0f, 13}, {1000.0f, 13})
#define EE_HANDS
#define SPLIT_USB_DETECT
#define SPLIT_WATCHDOG_ENABLE

// The right half occupies global matrix rows 4 through 7.
#define BOOTMAGIC_ROW_RIGHT 4
#define BOOTMAGIC_COLUMN_RIGHT 0
