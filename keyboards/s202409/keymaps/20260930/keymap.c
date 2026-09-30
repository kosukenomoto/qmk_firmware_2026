//./util/docker_build.sh s202409:20260930
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
        CM_ALCT,  CM_ALT4,  KC_ESC,   MO_EXCL,  SW_ATAB,        CM_STAB,  KC_HOME,  KC_UP,    KC_END,   KC_TAB,
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
        _______,  _______,  _______,  _______,  _______,        _______,  CM_LEFT,  CM_DOWN,  CM_RGHT,  _______,
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
        CM_STAB,  _______,  KC_UP,    _______,  KC_TAB,         _______,  _______,  KC_UP,    _______,  _______,
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
    if ((get_mods() & (MOD_MASK_CG | MOD_BIT_LALT)) != 0) {
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

static bool num_pressed = false;
static uint16_t num_pressed_time = 0;

static bool spfn_pressed = false;
static uint16_t spfn_pressed_time = 0;

static uint16_t mod_switch_keycode = false;

//ホールド中のキーをMODキーに差し替える。
//layerの指定が0だったらデフォルトレイヤーでMODキーを動作させる
static void mod_layer_switch (keyrecord_t *record,
        uint16_t mod_keycode,uint16_t *mod_switch_keycode,int layer){
    if (record->event.pressed) {
        *mod_switch_keycode = mod_keycode;
        if(layer == 0){
            layer_clear();
        }else{
            layer_on(layer);
        }
        register_code(*mod_switch_keycode);
        wait_ms(DELAY_KEY_MS);
    }
}

//MODキー差替のクリア（レイヤー移動もクリア）
static void clear_mod_switch(uint16_t *mod_switch_keycode){
    if(*mod_switch_keycode){
        unregister_code(*mod_switch_keycode);
        *mod_switch_keycode = 0;
        layer_clear();
    }
}

static bool is_tapped(bool modifier_pressed, uint16_t modifier_pressed_time){
    return modifier_pressed && timer_elapsed(modifier_pressed_time) < TAPPING_TERM;
}

//ホールドでレイヤー、タップで半角/全角（ALT+`）
static void user_lt_hnzn(keyrecord_t *record,
        int layer,
        bool *modifier_pressed,
        uint16_t *modifier_pressed_time,
        uint16_t *mod_switch_keycode){  //mod差し替えフラグ兼KEYCODE

    if (record->event.pressed) {
        *modifier_pressed = true;
        *modifier_pressed_time = record->event.time;
        layer_on(layer);
    } else {
        clear_mod_switch(mod_switch_keycode);
        layer_off(layer);
        if (is_tapped(*modifier_pressed, *modifier_pressed_time)) {
            register_code(KC_LALT);
            wait_ms(DELAY_KEY_MS);
            tap_code(KC_GRAVE);
            unregister_code(KC_LALT);
            //cpas lockがonだったらCAPSLOCKをOFFにする
            if (host_keyboard_led_state().caps_lock) {
                SEND_STRING(SS_DOWN(X_LSFT));
                SEND_STRING(SS_TAP(X_CAPS));
                SEND_STRING(SS_UP(X_LSFT));
            }
        }
        *modifier_pressed = false;
    }
}

//ホールドでレイヤー、タップでkeycode
static void user_lt(keyrecord_t *record,
        int layer,
        uint16_t keycode,
        bool *modifier_pressed,
        uint16_t *modifier_pressed_time,
        uint16_t *mod_switch_keycode){  //mod差し替えフラグ兼KEYCODE

    if (record->event.pressed) {
        *modifier_pressed = true;
        *modifier_pressed_time = record->event.time;
        layer_on(layer);
    } else {
        clear_mod_switch(mod_switch_keycode);
        layer_off(layer);
        if (is_tapped(*modifier_pressed, *modifier_pressed_time)) {
            tap_code(keycode);
        }
        *modifier_pressed = false;
    }
}

//jp106 key layout code remotedesktop shiftkey s(KC_HOO)でシフトキー取りこぼすため
//SHIFTを押してからDELAY_KEY_MS待ってキーを押す
static void shift_keypress(keyrecord_t *record,uint16_t keycode){
      if (record->event.pressed) {
         register_code(KC_LSFT);
         wait_ms(DELAY_KEY_MS);
         register_code(keycode);
      } else {
         unregister_code(keycode);
         unregister_code(KC_LSFT);
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
  if (record->event.pressed) {
    // reset the user_lt flags
    if (keycode != CM_QFN)   {spfn_pressed = false;}
    if (keycode != CM_NUM)   {num_pressed = false;}
  }
  switch (keycode) {
    case CM_QFN:
      user_lt(record,QFN,KC_SPC,&spfn_pressed,&spfn_pressed_time,&mod_switch_keycode);
      return false;
    case CM_NUM:
      user_lt_hnzn(record,SYM,&num_pressed,&num_pressed_time,&mod_switch_keycode);
      return false;
    case SW_ATAB:
      mod_layer_switch(record,KC_LALT,&mod_switch_keycode,ALTTAB);
      if(record->event.pressed){
        tap_code(KC_TAB);
      }
      return false;
    case CM_ALCT:
      if(record->event.pressed){
        register_code(KC_LALT);
        register_code(KC_LCTL);
        unregister_code(KC_LCTL);
        unregister_code(KC_LALT);
      }
      mod_layer_switch(record,KC_LALT,&mod_switch_keycode,ALTTAB);
      if(record->event.pressed){
        tap_code(KC_TAB);
      }
      return false;
    case CM_LEFT:
      tap_code_4times(record, KC_LEFT);
      break;
    case CM_RGHT:
      tap_code_4times(record, KC_RGHT);
      break;
    case CM_UP:
      tap_code_4times(record, KC_UP);
      break;
    case CM_DOWN:
      tap_code_4times(record, KC_DOWN);
      break;

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
