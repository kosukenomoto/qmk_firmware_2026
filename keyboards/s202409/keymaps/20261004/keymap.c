//./util/docker_build.sh s202409:20261004
/*  -*-  eval: (turn-on-orgtbl); -*-
 * default HHKB Layout
 */
#include QMK_KEYBOARD_H

#include "keymap_jp.h"

#define JBASE   0
#define QFN     1
#define SYM     2
#define EXCL    3
#define HYPSPFN 4
#define JFN     5
#define ALTTAB  6

//windows app利用時のmodキーの取りこぼしに対処するウェイトms
#define DELAY_KEY_MS 60

#define Z_SFT   LSFT_T(KC_Z)
#define A_ALT   LALT_T(KC_A)
#define G_GUI   LGUI_T(KC_G)
#define MO_EXCL MO(EXCL)
#define MO_HYPS MO(HYPSPFN)
#define CM_SYS  MO(JFN)

#define CM_CPGU C(KC_PGUP)
#define CM_CPGD C(KC_PGDN)
#define CM_CHOM C(KC_HOME)
#define CM_CEND C(KC_END)

#define CM_ALT4 A(KC_F4)
#define CM_WSCS G(S(KC_S))

#define CM_STAB S(KC_TAB)

enum custom_keycodes {
  CM_LEFT = SAFE_RANGE,
  CM_RGHT,
  CM_UP,
  CM_DOWN,
  CM_QFN,
  CM_NUM,
  CM_ALCT,
  SW_ATAB,
  MC_EXLM,
  MC_DQUO,
  MC_HASH,
  MC_DLR,
  MC_PERC,
  MC_AMPR,
  MC_QUOT,
  MC_LPRN,
  MC_RPRN,
  MC_EQL,
  MC_TILD,
  MC_PIPE,
  MC_GRV,
  MC_LCBR,
  MC_PLUS,
  MC_ASTR,
  MC_RCBR,
  MC_QUES,
  MC_UNDS,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    [JBASE] = LAYOUT_split_3x5_3(  /* Qwerty win jpkey */
        KC_Q,    KC_W,    KC_E,     KC_R,    KC_T,             KC_Y,    KC_U,    KC_I,     KC_O,    KC_P,
        A_ALT,   KC_S,    KC_D,     KC_F,    G_GUI,            KC_H,    KC_J,    KC_K,     KC_L,    CM_NUM,
        Z_SFT,   KC_X,    KC_C,     KC_V,    KC_B,             KC_N,    KC_M,    KC_COMM,  KC_DOT,  KC_SLSH,
                          CM_QFN,   KC_LSFT, KC_LCTL,          CM_QFN,  CM_NUM,  CM_SYS
    ),

    [QFN] = LAYOUT_split_3x5_3( /* [> SPFN <] */
        CM_ALCT,  CM_ALT4,  KC_ESC,   SW_ATAB,  MO_EXCL,        CM_STAB,  KC_HOME,  KC_UP,    KC_END,   KC_TAB,
        KC_LALT,  KC_LSFT,  KC_DEL,   MO_HYPS,  KC_LGUI,        KC_BSPC,  KC_LEFT,  KC_DOWN,  KC_RGHT,  KC_ENT,
        KC_1,     KC_2,     KC_3,     KC_4,     KC_5,           KC_6,     KC_7,     KC_8,     KC_9,     KC_0,
                            _______,  _______,  _______,        _______,  _______,  _______
    ),

    [SYM] = LAYOUT_split_3x5_3( /* [> SPFN <] */
        MC_EXLM,  JP_AT,   MC_HASH,   MC_DLR,   MC_PERC,        JP_CIRC,  MC_AMPR,  MC_ASTR,  MC_PLUS,  MC_GRV,
        MC_UNDS,  KC_SLSH, KC_MINS,   MC_LPRN,  MC_RPRN,        MC_LCBR,  MC_RCBR,  JP_LBRC,  JP_RBRC,  _______,
        MC_QUES,  MC_TILD, JP_COLN,   JP_SCLN,  JP_BSLS,        MC_QUOT,  MC_DQUO,  MC_PIPE,  MC_EQL,   _______,
                            _______,  _______,  _______,        _______,  _______,  _______
    ),

    [EXCL] = LAYOUT_split_3x5_3(
        _______,  _______,  CM_WSCS,  _______,  _______,        _______,  CM_CHOM,  KC_PGUP,  CM_CEND,  _______,
        _______,  _______,  _______,  _______,  _______,        _______,  CM_CPGU,  KC_PGDN,  CM_CPGD,  _______,
        _______,  _______,  _______,  _______,  _______,        _______,  _______,  _______,  _______,  _______,
                            _______,  _______,  _______,        _______,  _______,  _______
    ),

    [HYPSPFN] = LAYOUT_split_3x5_3(
        _______,  _______,  _______,  _______,  _______,        _______,  CM_CHOM,  CM_UP,    CM_CEND,  _______,
        _______,  CM_WSCS,  _______,  _______,  _______,        _______,  CM_LEFT,  CM_DOWN,  CM_RGHT,  _______,
        _______,  _______,  _______,  _______,  _______,        _______,  _______,  _______,  _______,  _______,
                            _______,  _______,  _______,        _______,  _______,  _______
    ),

    [JFN] = LAYOUT_split_3x5_3(
        _______,  _______,  _______,  _______,  _______,        _______,  _______,  _______,  _______,  QK_BOOT,
        KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5,          _______,  _______,  _______,  _______,  _______,
        KC_F6,    KC_F7,    KC_F8,    KC_F9,    KC_F10,         KC_F11,   KC_F12,   _______,  _______,  KC_LSFT,
                            _______,  _______,  _______,        _______,  _______,  _______
    ),

    [ALTTAB] = LAYOUT_split_3x5_3(
        CM_STAB,  _______,  KC_UP,    KC_TAB,   _______,        _______,  _______,  KC_UP,    _______,  _______,
        _______,  KC_LEFT,  KC_DOWN,  KC_RGHT,  _______,        _______,  KC_LEFT,  KC_DOWN,  KC_RGHT,  _______,
        _______,  _______,  _______,  _______,  _______,        _______,  _______,  _______,  _______,  _______,
                            _______,  _______,  _______,        _______,  _______,  _______
    )
};

const char chordal_hold_layout[MATRIX_ROWS][MATRIX_COLS] PROGMEM =
    LAYOUT_split_3x5_3(
         'L', 'L', 'L', 'L', 'L',  'R', 'R', 'R', 'R', 'R',
         'L', 'L', 'L', 'L', 'L',  'R', 'R', 'R', 'R', 'R',
         'L', 'L', 'L', 'L', 'L',  'R', 'R', 'R', 'R', 'R',
                   'L', 'L', 'L',  'R', 'R', 'R'
    );

bool is_flow_tap_key(uint16_t keycode) {
    if (((get_mods() | get_weak_mods()) & (MOD_MASK_CG | MOD_BIT_LALT)) != 0) {
        return false; // Disable Flow Tap on hotkeys.
    }
    switch (get_tap_keycode(keycode)) {
        case KC_SPC:
        case KC_A ... KC_Z:
        case KC_DOT:
        case KC_COMM:
        case KC_SCLN:
        case KC_SLSH:
            return true;
    }
    return false;
}

uint16_t get_flow_tap_term(uint16_t keycode, keyrecord_t* record,
                           uint16_t prev_keycode) {
    if (is_flow_tap_key(keycode) && is_flow_tap_key(prev_keycode)) {
        return FLOW_TAP_TERM;
    }
    return 0;  // Disable Flow Tap.
}

uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case Z_SFT:
            return TAPPING_TERM - 40;
        default:
            return TAPPING_TERM;
    }
}

bool get_permissive_hold(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case Z_SFT:
            return true;
        default:
            return false;
    }
}

// Track each physical key: CM_QFN and CM_NUM both occur more than once.
typedef struct {
    bool down;
    bool tap;
    uint16_t pressed_at;
} layer_tap_state_t;

static layer_tap_state_t layer_taps[MATRIX_ROWS][MATRIX_COLS];
static uint8_t qfn_count;
static uint8_t num_count;
static bool alt_tab_active;
static bool alt_f4_pressed;
static uint8_t symbol_shift_count;

static void restore_held_weak_mods(void) {
    // action_exec() clears weak modifiers on every new key press.
    if (alt_tab_active || alt_f4_pressed) {
        add_weak_mods(MOD_BIT(KC_LALT));
    }
    if (symbol_shift_count) {
        add_weak_mods(MOD_BIT(KC_LSFT));
    }
}

bool pre_process_record_user(uint16_t keycode, keyrecord_t *record) {
    restore_held_weak_mods();
    return true;
}

void post_process_record_user(uint16_t keycode, keyrecord_t *record) {
    restore_held_weak_mods();
    send_keyboard_report();
}

static void clear_alt_tab(void) {
    if (alt_tab_active) {
        alt_tab_active = false;
        if (!alt_f4_pressed) {
            del_weak_mods(MOD_BIT(KC_LALT));
        }
        send_keyboard_report();
        layer_off(ALTTAB);
    }
}

static void alt_f4_keypress(keyrecord_t *record) {
    if (record->event.pressed) {
        if (!alt_f4_pressed) {
            alt_f4_pressed = true;
            add_weak_mods(MOD_BIT(KC_LALT));
            send_keyboard_report();
            wait_ms(DELAY_KEY_MS);
            register_code(KC_F4);
        }
    } else if (alt_f4_pressed) {
        // Release F4 before Alt, preserving other owners of Alt.
        unregister_code(KC_F4);
        alt_f4_pressed = false;
        if (!alt_tab_active) {
            del_weak_mods(MOD_BIT(KC_LALT));
        }
        send_keyboard_report();
    }
}

static void start_alt_tab(void) {
    // This session ends when the last QFN key is released.
    if (!qfn_count) {
        return;
    }
    alt_tab_active = true;
    layer_on(ALTTAB);
    add_weak_mods(MOD_BIT(KC_LALT));
    send_keyboard_report();
    wait_ms(DELAY_KEY_MS);
    tap_code(KC_TAB);
}

static void tap_hnzn(void) {
    const uint8_t saved_weak_mods = get_weak_mods();
    add_weak_mods(MOD_BIT(KC_LALT));
    send_keyboard_report();
    wait_ms(DELAY_KEY_MS);
    tap_code(KC_GRAVE);
    set_weak_mods(saved_weak_mods);
    send_keyboard_report();
    if (host_keyboard_led_state().caps_lock) {
        add_weak_mods(MOD_BIT(KC_LSFT));
        send_keyboard_report();
        tap_code(KC_CAPS);
        set_weak_mods(saved_weak_mods);
        send_keyboard_report();
    }
}

static void tap_screenshot(void) {
    const uint8_t saved_weak_mods = get_weak_mods();
    add_weak_mods(MOD_BIT(KC_LGUI) | MOD_BIT(KC_LSFT));
    send_keyboard_report();
    wait_ms(DELAY_KEY_MS);
    tap_code(KC_S);
    set_weak_mods(saved_weak_mods);
    send_keyboard_report();
}

static void user_layer_tap(keyrecord_t *record, uint8_t layer, uint8_t *count) {
    layer_tap_state_t *state = &layer_taps[record->event.key.row][record->event.key.col];
    if (record->event.pressed) {
        if (!state->down) {
            state->down = true;
            state->tap = true;
            state->pressed_at = timer_read();
            ++*count;
            layer_on(layer);
        }
    } else if (state->down) {
        const bool tapped = state->tap && timer_elapsed(state->pressed_at) < TAPPING_TERM;
        state->down = false;
        if (--*count == 0) {
            layer_off(layer);
            if (layer == QFN) {
                clear_alt_tab();
            }
        }
        if (tapped) {
            if (layer == QFN) {
                // Global matrix rows identify the physical half even when
                // the USB master is on the right.
                if (record->event.key.row < MATRIX_ROWS / 2) {
                    tap_screenshot();
                } else {
                    tap_code(KC_SPC);
                }
            } else {
                tap_hnzn();
            }
        }
    }
}

// Weak modifiers preserve physical Shift, Alt and Ctrl held by the user.
static void shift_keypress(keyrecord_t *record, uint16_t keycode) {
    if (record->event.pressed) {
        if (symbol_shift_count++ == 0) {
            add_weak_mods(MOD_BIT(KC_LSFT));
            send_keyboard_report();
            wait_ms(DELAY_KEY_MS);
        }
        register_code(keycode);
    } else {
        unregister_code(keycode);
        if (symbol_shift_count && --symbol_shift_count == 0) {
            del_weak_mods(MOD_BIT(KC_LSFT));
            send_keyboard_report();
        }
    }
}

static void tap_code_4times(keyrecord_t *record, uint16_t keycode){
    if(record->event.pressed){
        for (int i = 0; i < 4; i++) {
            tap_code(keycode);
        }
    }
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  restore_held_weak_mods();
  if (record->event.pressed) {
    // Any other physical key makes an outstanding layer tap a hold,
    // including another key with the same custom keycode.
    for (uint8_t row = 0; row < MATRIX_ROWS; ++row) {
      for (uint8_t col = 0; col < MATRIX_COLS; ++col) {
        if (row != record->event.key.row || col != record->event.key.col) {
          layer_taps[row][col].tap = false;
        }
      }
    }
  }
  switch (keycode) {
    case CM_ALT4:
      alt_f4_keypress(record);
      return false;
    case CM_QFN:
      user_layer_tap(record, QFN, &qfn_count);
      return false;
    case CM_NUM:
      user_layer_tap(record, SYM, &num_count);
      return false;
    case SW_ATAB:
      if (record->event.pressed) {
        start_alt_tab();
      }
      return false;
    case CM_ALCT:
      if (record->event.pressed) {
        const uint8_t saved_weak_mods = get_weak_mods();
        add_weak_mods(MOD_BIT(KC_LALT) | MOD_BIT(KC_LCTL));
        send_keyboard_report();
        wait_ms(DELAY_KEY_MS);
        set_weak_mods(saved_weak_mods);
        send_keyboard_report();
        start_alt_tab();
      }
      return false;
    case CM_LEFT:
      tap_code_4times(record, KC_LEFT);
      return false;
    case CM_RGHT:
      tap_code_4times(record, KC_RGHT);
      return false;
    case CM_UP:
      tap_code_4times(record, KC_UP);
      return false;
    case CM_DOWN:
      tap_code_4times(record, KC_DOWN);
      return false;

    //以下はシフト考慮不要のためjp defineをそのまま利用可能
    //JP_MINS JP_CIRC JP_YEN  JP_AT   JP_LBRC JP_EISU JP_SCLN JP_COLN
    //JP_RBRC JP_DOT  JP_COMM JP_SLSH JP_BSLS JP_MHEN JP_HENK JP_KANA
    case MC_EXLM: shift_keypress(record, KC_1);    return false;
    case MC_DQUO: shift_keypress(record, KC_2);    return false;
    case MC_HASH: shift_keypress(record, KC_3);    return false;
    case MC_DLR:  shift_keypress(record, KC_4);    return false;
    case MC_PERC: shift_keypress(record, KC_5);    return false;
    case MC_AMPR: shift_keypress(record, KC_6);    return false;
    case MC_QUOT: shift_keypress(record, KC_7);    return false;
    case MC_LPRN: shift_keypress(record, KC_8);    return false;
    case MC_RPRN: shift_keypress(record, KC_9);    return false;
    case MC_EQL:  shift_keypress(record, KC_MINS); return false;
    case MC_TILD: shift_keypress(record, KC_EQL);  return false;
    case MC_PIPE: shift_keypress(record, KC_INT3); return false;
    case MC_GRV:  shift_keypress(record, KC_LBRC); return false;
    case MC_LCBR: shift_keypress(record, KC_RBRC); return false;
    case MC_PLUS: shift_keypress(record, KC_SCLN); return false;
    case MC_ASTR: shift_keypress(record, KC_QUOT); return false;
    case MC_RCBR: shift_keypress(record, KC_NUHS); return false;
    case MC_QUES: shift_keypress(record, KC_SLSH); return false;
    case MC_UNDS: shift_keypress(record, KC_INT1); return false;
  }
  return true;
}
