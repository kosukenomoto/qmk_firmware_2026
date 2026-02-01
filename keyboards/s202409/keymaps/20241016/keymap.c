// Copyright 2023 QMK
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H

#include "keymap_jp.h"

#define JBASE   0
#define UBASE   1
#define JRISE   2
#define URISE   3
#define JSPFN   4
#define USPFN   5
#define JQFN    6 
#define UQFN    7 
#define JLEF    8
#define ULEF    9
#define HYPSPFN 10 
#define JFN     11 
#define UFN     12 
#define SYS     13 

#define CM_JHNZ A(KC_GRV)
#define DF_JBAS DF(JBASE)
#define DF_UBAS DF(UBASE)

#define LM_JGUI LM(JBASE,KC_LGUI)
#define LM_UGUI LM(UBASE,KC_LGUI)

#define CM_SYS LT(SYS,KC_ESC)
//#define CM_JFN  LT(JFN,KC_ESC)
//#define CM_UFN  LT(UFN,KC_ESC)
#define CM_JQFN  LT(JQFN,KC_Q)
#define CM_UQFN  LT(UQFN,KC_Q)

#define CM_JRISE  LT(JRISE,KC_ESC)
#define CM_URISE  LT(URISE,KC_ESC)

#define CM_JFN  LT(JFN,KC_SCLN)
#define CM_UFN  LT(UFN,KC_SCLN)

#define HZ_CTL  LCTL_T(CM_JHNZ)
#define SC_ALT  LALT_T(KC_SCLN)

#define K1_ALT  LALT_T(KC_1)
#define X_ALT   LALT_T(KC_X)
#define DOT_ALT LALT_T(KC_DOT)

#define A_ALT   LALT_T(KC_A)
#define Z_ALT   LALT_T(KC_Z)
#define JSL_ALT LALT_T(JP_SLSH)
#define USL_ALT LALT_T(KC_SLSH)
#define ESC_ALT LALT_T(KC_ESC)

#define SL_SFT SFT_T(KC_SLSH)
#define A_SFT   SFT_T(KC_A)
#define Z_SFT   SFT_T(KC_Z)
#define ESC_SFT SFT_T(KC_ESC)
#define SC_SFT  SFT_T(KC_SCLN)

#define TAB_CTL LCTL_T(KC_TAB)
#define F_CTL   LCTL_T(KC_F)
#define J_CTL   LCTL_T(KC_J)
#define X_CTL   LCTL_T(KC_X)
#define DT_CTL  LCTL_T(KC_DOT)
#define G_GUI   LGUI_T(KC_G)
#define H_GUI   LGUI_T(KC_H)
#define CM_SJSS SFT_T(JP_SLSH)
#define CM_SUSS SFT_T(KC_SLSH)
#define CM_SHTZ SFT_T(KC_Z)

#define CM_GUIE G(KC_E)
#define CM_GUIM G(KC_M)
#define CM_ALT4 A(KC_F4)
#define LT_JLEF LT(JLEF,KC_ESC)
#define LT_ULEF LT(ULEF,KC_ESC)
#define CM_GUIT G(KC_TAB)
#define CM_ALTT A(KC_TAB)
#define CM_WSCS G(S(KC_S))
#define MO_HYPS MO(HYPSPFN)

#define CM_CPGU C(KC_PGUP)
#define CM_CPGD C(KC_PGDN)
#define CM_CHOM C(KC_HOME)
#define CM_CEND C(KC_END)

#define CM_SF10 S(KC_F10)

enum custom_keycodes {
  CM_LEFT = SAFE_RANGE,
  CM_RGHT,
  CM_UP,
  CM_DOWN,
  CM_SPFN,
  CM_SPFN2,
  CM_LISE,
  CM_RISE,
  CM_LANG,
  CM_FNSC,
  CM_HZCL
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    [JBASE] = LAYOUT_split_3x5_3(  /* Qwerty win jpkey */
    //win jpkey(QMK)  GUI(command)   CTL(control)   ALT(option)
        CM_JQFN, KC_W,    KC_E,     KC_R,    KC_T,          KC_Y,    KC_U,    KC_I,     KC_O,    KC_P,
        A_ALT,   KC_S,    KC_D,     KC_F,    KC_G,          KC_H,    KC_J,    KC_K,     KC_L,    CM_FNSC,
        Z_SFT,   KC_X,    KC_C,     KC_V,    KC_B,          KC_N,    KC_M,    KC_COMM,  KC_DOT,  SL_SFT,
                          KC_LCTL,  CM_LISE, CM_SPFN2,      CM_SPFN, KC_LSFT, CM_SYS
    ),   

    [UBASE] = LAYOUT_split_3x5_3( /* Qwerty mac uskey */
    //mac uskey(QMK)      ALT(option)       GUI(command)                CTL(control)              
    //mac karabiner(win)  option(ALT)->GUI  command(GUI)->control(CTL)  control(CTL)->option(ALT)                        
        CM_UQFN, KC_W,    KC_E,     KC_R,    KC_T,          KC_Y,    KC_U,    KC_I,     KC_O,    KC_P,
        A_ALT,   KC_S,    KC_D,     KC_F,    KC_G,          KC_H,    KC_J,    KC_K,     KC_L,    CM_FNSC,
        Z_SFT,   KC_X,    KC_C,     KC_V,    KC_B,          KC_N,    KC_M,    KC_COMM,  KC_DOT,  SL_SFT,
                          KC_LCTL,  CM_LISE, CM_SPFN2,      CM_SPFN, KC_LSFT, CM_SYS
    ),
    
    [JRISE] = LAYOUT_split_3x5_3(
        JP_EXLM,  JP_AT,    JP_HASH,  JP_DLR,   JP_PERC,        JP_AMPR,  JP_ASTR,  JP_LPRN,  JP_RPRN,  JP_MINS,
        JP_UNDS,  JP_PLUS,  JP_EQL,   JP_ASTR,  JP_CIRC,        JP_LCBR,  JP_RCBR,  JP_LBRC,  JP_RBRC,  JP_COLN,
        JP_BSLS,  JP_AMPR,  JP_PIPE,  JP_TILD,  JP_GRV,         JP_QUOT,  JP_DQUO,  JP_LABK,  JP_RABK,  JP_QUES,
                            _______,  _______,  _______,        _______,  _______,  _______ 
    ),

    [URISE] = LAYOUT_split_3x5_3( 
        KC_EXLM,  KC_AT,    KC_HASH,  KC_DLR,   KC_PERC,        KC_AMPR,  KC_ASTR,  KC_LPRN,  KC_RPRN,  KC_MINS,
        KC_UNDS,  KC_PLUS,  KC_EQL,   KC_ASTR,  KC_CIRC,        KC_LCBR,  KC_RCBR,  KC_LBRC,  KC_RBRC,  KC_COLN,
        KC_BSLS,  KC_AMPR,  KC_PIPE,  KC_TILD,  KC_GRV,         KC_QUOT,  KC_DQUO,  KC_LABK,  KC_RABK,  KC_QUES,
                            _______,  _______,  _______,        _______,  _______,  _______ 
    ),

    [JSPFN] = LAYOUT_split_3x5_3( /* [> SPFN <] */
        CM_GUIE,  CM_ALT4,  LT_JLEF,  CM_GUIT,  CM_WSCS,        _______,  KC_HOME,  KC_UP,    KC_END,   JP_MINS,
        KC_LALT,  KC_LSFT,  KC_DEL,   MO_HYPS,  CM_GUIM,        KC_BSPC,  KC_LEFT,  KC_DOWN,  KC_RGHT,  KC_ENT,
        KC_1,     KC_2,     KC_3,     KC_4,     KC_5,           KC_6,     KC_7,     KC_8,     KC_9,     KC_0,
                            _______,  _______,  _______,        _______,  _______,  _______   
    ),

    [USPFN] = LAYOUT_split_3x5_3( /* [> SPFN <] */
        CM_GUIE,  CM_ALT4,  LT_ULEF,  CM_GUIT,  CM_WSCS,        _______,  KC_HOME,  KC_UP,    KC_END,   KC_MINS,
        KC_LALT,  KC_LSFT,  KC_DEL,   MO_HYPS,  CM_GUIM,        KC_BSPC,  KC_LEFT,  KC_DOWN,  KC_RGHT,  KC_ENT,
        KC_1,     KC_2,     KC_3,     KC_4,     KC_5,           KC_6,     KC_7,     KC_8,     KC_9,     KC_0,
                            _______,  _______,  _______,        _______,  _______,  _______   
    ), 

    [JQFN] = LAYOUT_split_3x5_3( /* [> QFN<] */
        _______,  CM_ALT4,  LT_JLEF,  CM_GUIT,  CM_WSCS,        _______,  KC_HOME,  KC_UP,    KC_END,   KC_MINS,
        KC_LALT,  KC_LSFT,  KC_DEL,   MO_HYPS,  CM_GUIM,        KC_BSPC,  KC_LEFT,  KC_DOWN,  KC_RGHT,  KC_ENT,
        _______,  _______,  _______,  _______,  _______,        _______,  _______,  _______,  _______,  _______,
                            KC_F2,    KC_LGUI,  CM_GUIE,        _______,  _______,  _______   
    ),

    [UQFN] = LAYOUT_split_3x5_3( /* [> QFN<] */
        _______,  CM_ALT4,  LT_ULEF,  CM_GUIT,  CM_WSCS,        _______,  KC_HOME,  KC_UP,    KC_END,   KC_MINS,
        KC_LALT,  KC_LSFT,  KC_DEL,   MO_HYPS,  CM_GUIM,        KC_BSPC,  KC_LEFT,  KC_DOWN,  KC_RGHT,  KC_ENT,
        _______,  _______,  _______,  _______,  _______,        _______,  _______,  _______,  _______,  _______,
                            KC_F2,    KC_LGUI,  CM_GUIE,        _______,  _______,  _______   
    ), 
    [JLEF] = LAYOUT_split_3x5_3( 
        _______,  _______,  _______,  _______,  _______,        _______,  CM_CHOM,  KC_PGUP,  CM_CEND,  _______, 
        _______,  _______,  _______,  _______,  _______,        _______,  CM_CPGU,  KC_PGDN,  CM_CPGD,  _______,
        _______,  _______,  _______,  _______,  _______,        _______,  _______,  _______,  _______,  _______,
                            _______,  _______,  _______,         _______,  _______,  _______
    ),

    [ULEF] = LAYOUT_split_3x5_3( 
        _______,  _______,  _______,  _______,  _______,        _______,  CM_CHOM,  KC_PGUP,  CM_CEND,  _______, 
        _______,  _______,  _______,  _______,  _______,        _______,  CM_CPGU,  KC_PGDN,  CM_CPGD,  _______,
        _______,  _______,  _______,  _______,  _______,        _______,  _______,  _______,  _______,  _______,
                            _______,  _______,  _______,         _______,  _______,  _______
    ),

    [HYPSPFN] = LAYOUT_split_3x5_3( 
        _______,  _______,  _______,  _______,  _______,        _______,  _______,  CM_UP,    _______,  _______, 
        _______,  _______,  KC_LGUI,  _______,  _______,        _______,  CM_LEFT,  CM_DOWN,  CM_RGHT,  _______,
        _______,  _______,  _______,  _______,  _______,        _______,  _______,  _______,  _______,  _______,
                            _______,  _______,  _______,        _______,  _______,  _______
    ),
    
    [JFN] = LAYOUT_split_3x5_3(
        _______,  _______,  _______,  _______,  _______,        _______,  _______,  _______,  _______,  _______, 
        KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5,          KC_BTN1,  CM_SF10,  CM_JHNZ,  _______,  _______,
        KC_F6,    KC_F7,    KC_F8,    KC_F9,    KC_F10,         KC_F11,   KC_F12,   _______,  _______,  _______,
                            _______,  _______,  _______,        _______,  _______,  _______ 
    ),

    [UFN] = LAYOUT_split_3x5_3( 
        _______,  _______,  _______,  _______,  _______,        _______,  _______,  _______,  _______,  _______,
        KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5,          KC_BTN1,  CM_SF10,  CM_JHNZ,  _______,  _______,
        KC_F6,    KC_F7,    KC_F8,    KC_F9,    KC_F10,         KC_F11,   KC_F12,   _______,  _______,  _______,
                            _______,  _______,  _______,        _______,  _______,  _______ 
    ),
/*  */
    [SYS] = LAYOUT_split_3x5_3( 
        _______,  _______,  _______,  _______,  _______,        _______,  _______,  _______,  _______,  QK_BOOT,
        _______,  _______,  _______,  _______,  _______,        _______,  _______,  _______,  _______,  _______,
        _______,  _______,  _______,  _______,  _______,        _______,  _______,  _______,  _______,  _______,
                            _______,  _______,  _______,        _______,  DF_UBAS,  _______ 
    )
};

uint16_t get_quick_tap_term(uint16_t keycode, keyrecord_t *record){
    switch (keycode) {
        default:
            return QUICK_TAP_TERM; 
    }
}

uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case G_GUI:
            return 60;
        case H_GUI:
            return 60;
        case J_CTL:
            return 60;
        case X_CTL:
            return 60;
        case F_CTL:
            return 60;
        case SC_ALT:
            return 60;
        case A_ALT:
            return 60;
        case SL_SFT:
            return 60;
        case Z_SFT:
            return 60;
        case CM_JQFN:
            return 60;
        case CM_UQFN:
            return 60;
        default:
            return TAPPING_TERM; 
    }
}

bool get_permissive_hold(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        default:
            return false; 
    }
}

bool get_ignore_mod_tap_interrupt(uint16_t keycode, keyrecord_t *record){
    switch (keycode) {
        default:
            return true; 
    }
} 

bool get_hold_on_other_key_press(uint16_t keycode, keyrecord_t *record){
    switch (keycode) {
        default:
            return false; 
    }
} 
static bool process_jp_symbols_impl(uint16_t keycode, bool pressed) {
    if (!pressed) {
        return true;
    }
    uint8_t shift = keyboard_report->mods & (MOD_BIT(KC_LSFT) | MOD_BIT(KC_RSFT));
    if (!shift) {
        return true;
    }
    uint16_t s;
    switch (keycode) {
        // Replace Shift-Symbols like ANSI for JIS.
        case JP_2:    s = JP_AT; break;
        case JP_6:    s = JP_CIRC; break;
        case JP_7:    s = JP_AMPR; break;
        case JP_8:    s = JP_ASTR; break;
        case JP_9:    s = JP_LPRN; break;
        case JP_0:    s = JP_RPRN; break;
        case JP_GRV:  s = JP_TILD; break;
        case JP_EQL:  s = JP_PLUS; break;
        case JP_MINS: s = JP_UNDS; break;
        case JP_QUOT: s = JP_DQUO; break;
        case JP_SCLN: s = JP_COLN; break;
        case JP_BSLS: s = JP_PIPE; break;
        default: return true;
    }
    unregister_mods(shift);
    tap_code16(s);
    register_mods(shift);
    return false;
}

bool process_jp_symbols(uint16_t keycode, keyrecord_t *record) {
    return process_jp_symbols_impl(keycode, record->event.pressed);
}

void tap_code16jp(uint16_t keycode) {
    if (process_jp_symbols_impl(keycode, true)) {
        tap_code16(keycode);
    }
}

//上関数のIMEON/OFF切り替え専用
//TODO 汎用的な関数を引数に取れるようにすること(関数アドレス)
//static void user_lt_hnzn(keyrecord_t *record, int layer, bool *modifier_pressed, uint16_t *modifier_pressed_time, bool tapping_term_disable) {
//    if (record->event.pressed) {
//      *modifier_pressed_time = record->event.time;
//      *modifier_pressed = true;
//      layer_on(layer);
//    } else {
//      layer_off(layer);
//      if (*modifier_pressed && (tapping_term_disable || (timer_elapsed(*modifier_pressed_time) < TAPPING_TERM))) {
//        if (get_highest_layer(default_layer_state)==JBASE){
//          SEND_STRING(SS_LALT("`"));
//        }else{
//          SEND_STRING(SS_LALT("`"));
//        }
//      }
//    }
//}

//static void user_mt_hnzn(keyrecord_t *record, uint16_t modcode, bool *modifier_pressed, uint16_t *modifier_pressed_time, bool tapping_term_disable) {
//         if (record->event.pressed) {
//         *modifier_pressed = true;
//         *modifier_pressed_time = record->event.time;
//       } else {
//       	  if (!*modifier_pressed) unregister_code(modcode);
//          if (*modifier_pressed && (tapping_term_disable || (timer_elapsed(*modifier_pressed_time) < TAPPING_TERM))) {
//              SEND_STRING(SS_LALT("`"));
//          }
//          *modifier_pressed = false;
//       }
// }

static void user_lt(keyrecord_t *record, int layer, uint16_t keycode, bool *modifier_pressed, uint16_t *modifier_pressed_time, bool tapping_term_disable) {
    if (record->event.pressed) {
      *modifier_pressed = true;
      *modifier_pressed_time = record->event.time;
      layer_on(layer);
    } else {
      layer_off(layer);
      if (*modifier_pressed && (tapping_term_disable || (timer_elapsed(*modifier_pressed_time) < TAPPING_TERM))) {
        register_code(keycode);
        unregister_code(keycode);
        unregister_code(keycode);
      }
      *modifier_pressed = false;
    }
}

// static void user_mt(keyrecord_t *record, uint16_t modcode, uint16_t keycode, bool *modifier_pressed, uint16_t *modifier_pressed_time, bool tapping_term_disable) {
//         if (record->event.pressed) {
//         *modifier_pressed = true;
//         *modifier_pressed_time = record->event.time;
//       } else {
// 	if (!*modifier_pressed) unregister_code(modcode);
//         if (*modifier_pressed && (tapping_term_disable || (timer_elapsed(*modifier_pressed_time) < TAPPING_TERM))) {
//           register_code(keycode);
//           unregister_code(keycode);
//           unregister_code(keycode);
//         }
//         *modifier_pressed = false;
//       }
// }

static bool spfn_pressed = false;
static uint16_t spfn_pressed_time = 0;
static bool lise_pressed = false;
static uint16_t lise_pressed_time = 0;
static bool fnsc_pressed = false;
static uint16_t fnsc_pressed_time = 0;
//static bool hzcl_pressed = false;
//static uint16_t hzcl_pressed_time = 0;
//static bool is_hzcl_active = false;

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  if (record->event.pressed) {
    // reset the user_lt & user_tt flags
    if (keycode != CM_SPFN) {spfn_pressed = false;}
    if (keycode != CM_LISE) {lise_pressed = false;}
    if (keycode != CM_FNSC) {fnsc_pressed = false;}
//    if (keycode != CM_RISE) {lise_pressed = false;}
//    if (keycode != CM_HZCL){
//       if (hzcl_pressed) {register_code(KC_LCTL); is_hzcl_active = true;}
//       hzcl_pressed  = false;
//    }
  }
  switch (keycode) {
    case CM_SPFN:
      if (get_highest_layer(default_layer_state)==JBASE){
        user_lt(record,JSPFN,KC_SPC,&spfn_pressed,&spfn_pressed_time,false);
      } else {
        user_lt(record,USPFN,KC_SPC,&spfn_pressed,&spfn_pressed_time,false);
      }
      return false;
      break;
    case CM_SPFN2:
      if (get_highest_layer(default_layer_state)==JBASE){
        user_lt(record,JSPFN,KC_TAB,&spfn_pressed,&spfn_pressed_time,false);
      } else {
        user_lt(record,USPFN,KC_TAB,&spfn_pressed,&spfn_pressed_time,false);
      }
      return false;
      break;
    case CM_FNSC:
      if (get_highest_layer(default_layer_state)==JBASE){
        user_lt(record,JFN,KC_SCLN,&fnsc_pressed,&fnsc_pressed_time,false);
      } else {
        user_lt(record,UFN,KC_SCLN,&fnsc_pressed,&fnsc_pressed_time,false);
      }
      return false;
      break;
    case CM_LISE:
      if (get_highest_layer(default_layer_state)==JBASE){
        user_lt(record,JRISE,KC_SPC,&lise_pressed,&lise_pressed_time,false);
      } else {
        user_lt(record,URISE,KC_SPC,&lise_pressed,&lise_pressed_time,false);
      }
      return false;
      break;
    case CM_LANG:
      if(record->event.pressed){
        SEND_STRING(SS_LALT("`"));
      }else{
        SEND_STRING(SS_LALT("`"));
      }
      return false;
      break;
//    case CM_HZCL:
//      if (get_highest_layer(default_layer_state)==JBASE){
//        user_mt_hnzn(record,KC_LCTL,&hzcl_pressed,&hzcl_pressed_time,false);
//      } else {
//        user_mt_hnzn(record,KC_LCTL,&hzcl_pressed,&hzcl_pressed_time,false);
//      }
//      return false;
//      break;
    case CM_LEFT:
      if(record->event.pressed){
        //pressed
        tap_code(KC_LEFT);
        tap_code(KC_LEFT);
        tap_code(KC_LEFT);
        tap_code(KC_LEFT);                        
      } else {
        //released
      }
      return false;
      break;
    case CM_RGHT:
      if(record->event.pressed){
        //pressed
        tap_code(KC_RGHT);
        tap_code(KC_RGHT);
        tap_code(KC_RGHT);
        tap_code(KC_RGHT);
      }else{
        //released
      }
      return false;
      break;
    case CM_UP:
      if(record->event.pressed){
        //pressed
        tap_code(KC_UP);
        tap_code(KC_UP);
        tap_code(KC_UP);
        tap_code(KC_UP);
      }else{
        //released
      }
      return false;
      break;
    case CM_DOWN:
      if(record->event.pressed){
        //pressed
        tap_code(KC_DOWN);
        tap_code(KC_DOWN);
        tap_code(KC_DOWN);
        tap_code(KC_DOWN);
      }else{
        //released
      }
      return false;
      break;
    default:
      if (record->event.pressed) {
        // reset the flag
        spfn_pressed = false;
        lise_pressed = false;
        fnsc_pressed = false;
//        if (hzcl_pressed) {register_code(KC_LCTL); is_hzcl_active = true;}
//       hzcl_pressed  = false;
      }
      break;
    }

    switch (get_highest_layer(default_layer_state)){
        case JBASE:
            return process_jp_symbols(keycode,record);
            break;
        default:
            break;
    }

    return true;
}