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
#define JLEF    6
#define ULEF    7
#define JQFN    8 
#define UQFN    9 
#define HYPSPFN 10 
#define WINFN   11 
#define JFN     12 
#define UFN     13 
#define SYS     14 

#define KC_LANG1 KC_LANGUAGE_1
#define KC_LANG2 KC_LANGUAGE_2

#define CM_JHNZ A(KC_GRV)
#define DF_JBAS DF(JBASE)
#define DF_UBAS DF(UBASE)

#define CM_SYS LT(SYS,KC_LANG1)
//#define CM_JFN LT(JFN,KC_LGUI)
//#define CM_UFN LT(UFN,KC_LGUI)
#define CM_JQFN  LT(JQFN,KC_ESC)
#define CM_UQFN  LT(UQFN,KC_ESC)

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
#define ESC_CTL LCTL_T(KC_ESC)

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
#define LN2_SFT SFT_T(KC_LANG1)//KC_MHEN
//#define ENT_SFT SFT_T(KC_ENT)//KC_MHEN
#define LN1_CTL LCTL_T(KC_TAB)

#define CM_CAPS S(KC_CAPS)
#define CM_GUIE G(KC_E)
#define CM_GUIM G(KC_D)
#define CM_GUUP G(KC_UP)
#define CM_GUDN G(KC_DOWN)
#define CM_ALT4 A(KC_F4)
#define CM_ALTE A(KC_ESC)
#define LT_JLEF LT(JLEF,KC_ESC)
#define LT_ULEF LT(ULEF,KC_ESC)
#define CM_GUIT G(KC_TAB)
#define CM_ALTT A(KC_TAB)
#define CM_WSCS G(S(KC_S))
#define MO_HYPS MO(HYPSPFN)
#define LT_HYPS LT(HYPSPFN,KC_TAB)
#define CM_CPGU C(KC_PGUP)
#define CM_CPGD C(KC_PGDN)
#define CM_CHOM C(KC_HOME)
#define CM_CEND C(KC_END)
#define CM_CBSP C(KC_BSPC)
#define CM_SF10 S(KC_F10)

#define MO_WIFN MO(WINFN)
#define WI_UP   G(KC_UP) 
#define WI_SUP  G(S(KC_UP)) 
#define WI_DOWN G(KC_DOWN) 
#define WI_LEFT G(KC_LEFT)
#define WI_RGHT G(KC_RGHT)
#define WI_APP1 G(KC_1)
#define WI_APP2 G(KC_2)
#define WI_APP3 G(KC_3)
#define WI_APP4 G(KC_4)

enum custom_keycodes {
  CM_LEFT = SAFE_RANGE,
  CM_RGHT,
  CM_UP,
  CM_DOWN,
  CM_SPFN,
  CM_LEFN,
  CM_LISE,
  CM_RISE,
  CM_FNSC,
  CM_HZCL
};

//const uint16_t PROGMEM esc_combo[] = {KC_W, KC_E, COMBO_END};
//const uint16_t PROGMEM guitab_combo[] = {KC_E, KC_R, COMBO_END};
//const uint16_t PROGMEM screenshot_combo[] = {KC_R, KC_T, COMBO_END};
//const uint16_t PROGMEM gui_combo[] = {KC_C, KC_V, COMBO_END};
//const uint16_t PROGMEM altf4_combo[] = {KC_X, KC_C, COMBO_END};
//const uint16_t PROGMEM guie_combo[] = {KC_F, KC_G, COMBO_END};
//const uint16_t PROGMEM guim_combo[] = {KC_V, KC_B, COMBO_END};
//const uint16_t PROGMEM lang1_combo[] = {KC_S, KC_D, COMBO_END};
//const uint16_t PROGMEM lang2_combo[] = {KC_K, KC_L, COMBO_END};
//const uint16_t PROGMEM caps_combo[] = {KC_K, KC_L, COMBO_END};
//combo_t key_combos[] = {
//    COMBO(esc_combo, KC_ESC),
//    COMBO(guitab_combo, CM_GUIT), 
//    COMBO(screenshot_combo, CM_WSCS), 
//    COMBO(gui_combo, KC_LGUI), 
//    COMBO(altf4_combo, CM_ALT4), 
//    COMBO(guie_combo, CM_GUIE), 
//    COMBO(guim_combo, CM_GUIM), 
//    COMBO(lang1_combo, KC_LANG1), 
//    COMBO(lang2_combo, KC_LANG2),
 //   COMBO(caps_combo, JP_CAPS),
//};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    [JBASE] = LAYOUT_split_3x5_3(  /* Qwerty win jpkey */
    //win jpkey(QMK)  GUI(command)   CTL(control)   ALT(option)
        KC_Q,    KC_W,    KC_E,     KC_R,    KC_T,          KC_Y,    KC_U,    KC_I,     KC_O,    KC_P,
        A_ALT,   KC_S,    KC_D,     KC_F,    KC_G,          KC_H,    KC_J,    KC_K,     KC_L,    CM_FNSC,
        Z_SFT,   KC_X,    KC_C,     KC_V,    KC_B,          KC_N,    KC_M,    KC_COMM,  KC_DOT,  KC_SLSH,
                          KC_LCTL,  KC_LSFT, CM_LEFN,       CM_SPFN, CM_LISE, CM_SYS
    ),   

    [UBASE] = LAYOUT_split_3x5_3( /* Qwerty mac uskey */
    //mac uskey(QMK)      ALT(option)       GUI(command)                CTL(control)              
    //mac karabiner(win)  option(ALT)->GUI  command(GUI)->control(CTL)  control(CTL)->option(ALT)                        
        KC_Q,    KC_W,    KC_E,     KC_R,    KC_T,          KC_Y,    KC_U,    KC_I,     KC_O,    KC_P,
        A_ALT,   KC_S,    KC_D,     KC_F,    KC_G,          KC_H,    KC_J,    KC_K,     KC_L,    CM_FNSC,
        Z_SFT,   KC_X,    KC_C,     KC_V,    KC_B,          KC_N,    KC_M,    KC_COMM,  KC_DOT,  KC_SLSH,
                          KC_LCTL,  KC_LSFT, CM_LEFN,       CM_SPFN, CM_LISE, CM_SYS
    ),
    
    [JRISE] = LAYOUT_split_3x5_3( 
        JP_EXLM,  JP_AT,    JP_HASH,  JP_DLR,   JP_PERC,        _______,  JP_SCLN,  JP_LPRN,  JP_RPRN,  JP_MINS,
        JP_UNDS,  JP_PLUS,  JP_EQL,   JP_ASTR,  JP_CIRC,        JP_LCBR,  JP_RCBR,  JP_LBRC,  JP_RBRC,  JP_COLN,
        JP_BSLS,  JP_AMPR,  JP_PIPE,  JP_TILD,  JP_GRV,         JP_QUOT,  JP_DQUO,  JP_LABK,  JP_RABK,  JP_QUES,
                            _______,  _______,  _______,        _______,  _______,  _______ 
    ),

    [URISE] = LAYOUT_split_3x5_3( 
        KC_EXLM,  KC_AT,    KC_HASH,  KC_DLR,   KC_PERC,        _______,  KC_SCLN,  KC_LPRN,  KC_RPRN,  KC_MINS,
        KC_UNDS,  KC_PLUS,  KC_EQL,   KC_ASTR,  KC_CIRC,        KC_LCBR,  KC_RCBR,  KC_LBRC,  KC_RBRC,  KC_COLN,
        KC_BSLS,  KC_AMPR,  KC_PIPE,  KC_TILD,  KC_GRV,         KC_QUOT,  KC_DQUO,  KC_LABK,  KC_RABK,  KC_QUES,
                            _______,  _______,  _______,        _______,  _______,  _______ 
    ),

    [JSPFN] = LAYOUT_split_3x5_3( /* [> SPFN <] */
        CM_GUIE,  CM_ALT4,  KC_ESC,   CM_GUIT,  CM_WSCS,        KC_PGUP,  KC_HOME,  KC_UP,    KC_END,   KC_PGDN,
        KC_LALT,  KC_LSFT,  KC_DEL,   MO_HYPS,  CM_GUIM,        KC_BSPC,  KC_LEFT,  KC_DOWN,  KC_RGHT,  _______,
        KC_1,     KC_2,     KC_3,     KC_4,     KC_5,           KC_6,     KC_7,     KC_8,     KC_9,     KC_0,
                            _______,  _______,  _______,        _______,  _______,  _______
    ),

    [USPFN] = LAYOUT_split_3x5_3( /* [> SPFN <] */
        CM_GUIE,  CM_ALT4,  KC_ESC,   CM_GUIT,  CM_WSCS,        KC_PGUP,  KC_HOME,  KC_UP,    KC_END,   KC_PGDN,
        KC_LALT,  KC_LSFT,  KC_DEL,   MO_HYPS,  CM_GUIM,        KC_BSPC,  KC_LEFT,  KC_DOWN,  KC_RGHT,  _______,
        KC_1,     KC_2,     KC_3,     KC_4,     KC_5,           KC_6,     KC_7,     KC_8,     KC_9,     KC_0,
                            _______,  _______,  _______,        _______,  _______,  _______
    ), 

    [JLEF] = LAYOUT_split_3x5_3( 
        CM_GUIE,  CM_ALT4,  KC_ESC,   CM_GUIT,  CM_WSCS,        _______,  JP_SCLN,  JP_LPRN,  JP_RPRN,  JP_MINS, 
        _______,  _______,  KC_DEL,   MO_HYPS,  CM_GUIM,        JP_LCBR,  JP_RCBR,  JP_LBRC,  JP_RBRC,  JP_COLN, 
        MO_WIFN,  WI_SUP,   _______,  KC_LGUI,  CM_ALTE,        JP_QUOT,  JP_DQUO,  JP_LABK,  JP_RABK,  JP_QUES,
                            _______,  _______,  _______,        _______,  _______,  _______
    ),

    [ULEF] = LAYOUT_split_3x5_3( 
        CM_GUIE,  CM_ALT4,  KC_ESC,   CM_GUIT,  CM_WSCS,        _______,  KC_SCLN,  KC_LPRN,  KC_RPRN,  KC_MINS,
        _______,  _______,  KC_DEL,   MO_HYPS,  CM_GUIM,        KC_LCBR,  KC_RCBR,  KC_LBRC,  KC_RBRC,  KC_COLN,
        MO_WIFN,  WI_SUP,   _______,  KC_LGUI,  CM_ALTE,        KC_QUOT,  KC_DQUO,  KC_LABK,  KC_RABK,  KC_QUES,
                            _______,  _______,  _______,        _______,  _______,  _______
    ),

    [HYPSPFN] = LAYOUT_split_3x5_3( 
        _______,  _______,  _______,  _______,  _______,        CM_CPGU,  CM_CHOM,  CM_UP,    CM_CEND,  CM_CPGD, 
        G(KC_1),  G(KC_2),  G(KC_3),  _______,  _______,        CM_CBSP,  CM_LEFT,  CM_DOWN,  CM_RGHT,  _______,
        _______,  _______,  _______,  _______,  _______,        _______,  _______,  _______,  _______,  _______,
                            _______,  _______,  _______,        _______,  _______,  _______
    ),
    [WINFN] = LAYOUT_split_3x5_3( 
        _______,  _______,  WI_UP,    _______,  _______,        _______,  _______,  _______,  _______,  _______, 
        _______,  WI_LEFT,  WI_DOWN,  WI_RGHT,  _______,        _______,  _______,  _______,  _______,  _______,
        _______,  WI_APP1,  WI_APP2,  WI_APP3,  WI_APP4,        _______,  _______,  _______,  _______,  _______,
                            _______,  _______,  _______,        _______,  _______,  _______
    ),
    
    [JFN] = LAYOUT_split_3x5_3(
        _______,  _______,  _______,  _______,  _______,        _______,  _______,  CM_JHNZ,  _______,  _______, 
        KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5,          KC_BTN1,  CM_SF10,  KC_LANG1, KC_LANG2, _______,
        KC_F6,    KC_F7,    KC_F8,    KC_F9,    KC_F10,         KC_F11,   KC_F12,   _______,  _______,  _______,
                            _______,  _______,  _______,        KC_LSFT,  _______,  _______ 
    ),

    [UFN] = LAYOUT_split_3x5_3( 
        _______,  _______,  _______,  _______,  _______,        _______,  _______,  CM_JHNZ,  _______,  _______,
        KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5,          KC_BTN1,  CM_SF10,  KC_LANG1, KC_LANG2, _______,
        KC_F6,    KC_F7,    KC_F8,    KC_F9,    KC_F10,         KC_F11,   KC_F12,   _______,  _______,  _______,
                            _______,  _______,  _______,        KC_LSFT, _______,   _______ 
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

// シフト数字でJIS配列に沿った記号を出力するための処理
//(シフト数字を使わないのでコメントアウト)
//static bool process_jp_symbols_impl(uint16_t keycode, bool pressed) {
//    if (!pressed) {
//        return true;
//    }
//    uint8_t shift = keyboard_report->mods & (MOD_BIT(KC_LSFT) | MOD_BIT(KC_RSFT));
//    if (!shift) {
//        return true;
//    }
//    uint16_t s;
//    switch (keycode) {
//        // Replace Shift-Symbols like ANSI for JIS.
//        case JP_2:    s = JP_AT; break;
//        case JP_6:    s = JP_CIRC; break;
//        case JP_7:    s = JP_AMPR; break;
//        case JP_8:    s = JP_ASTR; break;
//        case JP_9:    s = JP_LPRN; break;
//        case JP_0:    s = JP_RPRN; break;
//        case JP_GRV:  s = JP_TILD; break;
//        case JP_EQL:  s = JP_PLUS; break;
//        case JP_MINS: s = JP_UNDS; break;
//        case JP_QUOT: s = JP_DQUO; break;
//        case JP_SCLN: s = JP_COLN; break;
//        case JP_BSLS: s = JP_PIPE; break;
//        default: return true;
//    }
//    unregister_mods(shift);
//    tap_code16(s);
//    register_mods(shift);
//    return false;
//}
//
//bool process_jp_symbols(uint16_t keycode, keyrecord_t *record) {
//    return process_jp_symbols_impl(keycode, record->event.pressed);
//}
//void tap_code16jp(uint16_t keycode) {
//    if (process_jp_symbols_impl(keycode, true)) {
//        tap_code16(keycode);
//    }
//}

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

//static bool alttab_pressed = false;
//static void alttab_press(keyrecord_t *record,bool *modifier_pressed){
//  if (record->event.pressed){
//    if(!*modifier_pressed){
//      *modifier_pressed = true;
//      SEND_STRING(SS_DOWN(X_LALT));
//      SEND_STRING(SS_TAP(X_TAB));
//    }else{
//      *modifier_pressed = false;
//      SEND_STRING(SS_UP(X_LALT));
//    }
//  }
//}
//
//static bool alttab_vm_pressed = false;
//static void alttab_vm_press(keyrecord_t *record,bool *modifier_pressed){
//  if (record->event.pressed){
//    if(!*modifier_pressed){
//      *modifier_pressed = true;
//      SEND_STRING(SS_DOWN(X_LCTL));
//      SEND_STRING(SS_TAP(X_LALT));
//      SEND_STRING(SS_UP(X_LCTL));
//      SEND_STRING(SS_DOWN(X_LALT));
//      SEND_STRING(SS_TAP(X_TAB));
//    }else{
//      *modifier_pressed = false;
//      SEND_STRING(SS_UP(X_LALT));
//      SEND_STRING(SS_TAP(X_BTN1));
//    }
//  }
//}
static bool lefn_pressed = false;
static uint16_t lefn_pressed_time = 0;

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
    if (keycode != CM_LEFN) {lefn_pressed = false;}
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
    case CM_LEFN:
      if (get_highest_layer(default_layer_state)==JBASE){
        user_lt(record,JLEF,KC_TAB,&lefn_pressed,&lefn_pressed_time,false);
      } else {
        user_lt(record,ULEF,KC_TAB,&lefn_pressed,&lefn_pressed_time,false);
      }
      return false;
      break;
    case CM_FNSC:
      if (get_highest_layer(default_layer_state)==JBASE){
        user_lt(record,JFN,KC_ENT,&fnsc_pressed,&fnsc_pressed_time,false);
      } else {
        user_lt(record,UFN,KC_ENT,&fnsc_pressed,&fnsc_pressed_time,false);
      }
      return false;
      break;
    case CM_LISE:
      if (get_highest_layer(default_layer_state)==JBASE){
        user_lt(record,JRISE,KC_LANG2,&lise_pressed,&lise_pressed_time,false);
      } else {
        user_lt(record,URISE,KC_LANG2,&lise_pressed,&lise_pressed_time,false);
      }
      return false;
      break;
//    case CM_CTAL:
//      alttab_vm_press(record,&alttab_vm_pressed);
//      if(record->event.pressed){
//        SEND_STRING(SS_DOWN(X_LCTL));
//        SEND_STRING(SS_TAP(X_LALT));
//        SEND_STRING(SS_UP(X_LCTL));
//      }else{
//      }
//      return false;
//      break;
//    case CM_ATAB:
//      alttab_press(record,&alttab_pressed);
//      return false;
//      break;
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
        lefn_pressed = false;
        spfn_pressed = false;
        lise_pressed = false;
        fnsc_pressed = false;
//        if (hzcl_pressed) {register_code(KC_LCTL); is_hzcl_active = true;}
//       hzcl_pressed  = false;
      }
      break;
    }

    switch (get_highest_layer(default_layer_state)){
    // シフト数字でJIS配列に沿った記号を出力するための処理
    //(シフト数字を使わないのでコメントアウト)
    //    case JBASE:
    //        return process_jp_symbols(keycode,record);
    //        break;
        default:
            break;
    }

    return true;
}

