// Copyright 2023 QMK
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H

#include "keymap_jp.h"

#define JBASE   0
#define UBASE   1
#define JLEF    2
#define ULEF    3
#define JRISE   4
#define URISE   5
#define JFN2    6
#define UFN2    7
#define JSPFN   8
#define USPFN   9
#define EXCL    10
#define HYPSPFN 11
#define JFN     12
#define UFN     13
#define SYS     14
#define ALTTAB  15

#define KC_LANG1 KC_LANGUAGE_1
#define KC_LANG2 KC_LANGUAGE_2

#define CM_JHNZ A(KC_GRV)
#define CM_UHNZ S(KC_SPC)
#define DF_JBAS DF(JBASE)
#define DF_UBAS DF(UBASE)

#define CM_SYS LT(SYS,KC_PSCR)
//#define CM_JFN LT(JFN,KC_LGUI)
//#define CM_UFN LT(UFN,KC_LGUI)

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
#define SL_ALT LALT_T(KC_SLSH)
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

#define CM_CAPS S(JP_EISU)
#define CM_STAB S(KC_TAB)
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
#define LT_EXCL LT(EXCL,KC_ESC)
#define MO_EXCL MO(EXCL)
#define LT_HYPS LT(HYPSPFN,KC_TAB)
#define CM_CPGU C(KC_PGUP)
#define CM_CPGD C(KC_PGDN)
#define CM_CHOM C(KC_HOME)
#define CM_CEND C(KC_END)
#define CM_CBSP C(KC_BSPC)
#define CM_SF10 S(KC_F10)

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
    CM_FNSO,
    CM_ALCT,
    SW_ATAB,
    CM_SHHZ,
    CM_SHCL,
    CM_K_QY,
    CM_K_QU,
    CM_K_QI,
    CM_K_QO,
    CM_K_QP,
};

//const uint16_t PROGMEM esc_combo[] = {KC_W, KC_E, COMBO_END};
//const uint16_t PROGMEM guitab_combo[] = {KC_E, KC_R, COMBO_END};
//const uint16_t PROGMEM screenshot_combo[] = {KC_R, KC_T, COMBO_END};
//const uint16_t PROGMEM gui_combo[] = {KC_C, KC_V, COMBO_END};
//const uint16_t PROGMEM altf4_combo[] = {KC_X, KC_C, COMBO_END};
//const uintJ16_t PROGMEM guie_combo[] = {KC_F, KC_G, COMBO_END};
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
        CM_LEFN, KC_W,    KC_E,     KC_R,    KC_T,          KC_Y,    KC_U,    KC_I,     KC_O,    KC_P,
        KC_A,    KC_S,    KC_D,     KC_F,    KC_G,          KC_H,    KC_J,    KC_K,     KC_L,    CM_FNSC,
        KC_Z,    KC_X,    KC_C,     KC_V,    KC_B,          KC_N,    KC_M,    CM_LISE,  CM_FNSO, SL_ALT,
                          KC_LGUI,  CM_SHHZ, KC_LCTL,       CM_SPFN, CM_SHCL, CM_SYS
    ),

    [UBASE] = LAYOUT_split_3x5_3( /* Qwerty mac uskey */
    //mac uskey(QMK)      ALT(option)       GUI(command)                CTL(control)
    //mac karabiner(win)  option(ALT)->GUI  command(GUI)->control(CTL)  control(CTL)->option(ALT)
        CM_LEFN, KC_W,    KC_E,     KC_R,    KC_T,          KC_Y,    KC_U,    KC_I,     KC_O,    KC_P,
        KC_A,    KC_S,    KC_D,     KC_F,    KC_G,          KC_H,    KC_J,    KC_K,     KC_L,    CM_FNSC,
        KC_Z,    KC_X,    KC_C,     KC_V,    KC_B,          KC_N,    KC_M,    CM_LISE,  CM_FNSO, SL_ALT,
                          KC_LGUI,  CM_SHHZ, KC_LCTL,       CM_SPFN, CM_SHCL, CM_SYS
    ),

    [JLEF] = LAYOUT_split_3x5_3(
        _______,  CM_ALT4,  KC_ESC,   CM_ALCT,  SW_ATAB,        CM_K_QY,  CM_K_QU,  CM_K_QI,  CM_K_QO,  CM_K_QP,
        _______,  _______,  _______,  _______,  KC_LGUI,        _______,  _______,  _______,  _______,  _______,
        _______,  _______,  _______,  _______,  _______,        _______,  _______,  _______,  _______,  _______,
                            _______,  _______,  _______,        _______,  _______,  _______
    ),

    [ULEF] = LAYOUT_split_3x5_3(
        _______,  CM_ALT4,  KC_ESC,   CM_ALCT,  SW_ATAB,        CM_K_QY,  CM_K_QU,  CM_K_QI,  CM_K_QO,  CM_K_QP,
        _______,  _______,  _______,  _______,  KC_LGUI,        _______,  _______,  _______,  _______,  _______,
        _______,  _______,  _______,  _______,  _______,        _______,  _______,  _______,  _______,  _______,
                            _______,  _______,  _______,        _______,  _______,  _______
    ),

    [JRISE] = LAYOUT_split_3x5_3(
        JP_EXLM,  JP_AT,    JP_HASH,  JP_DLR,   JP_PERC,        _______,  _______,  JP_LPRN,  JP_RPRN,  JP_MINS,
        JP_UNDS,  JP_PLUS,  JP_EQL,   JP_ASTR,  JP_CIRC,        JP_LCBR,  JP_RCBR,  JP_LBRC,  JP_RBRC,  JP_COLN,
        JP_BSLS,  JP_AMPR,  JP_PIPE,  JP_TILD,  JP_GRV,         JP_QUOT,  JP_DQUO,  JP_LABK,  JP_RABK,  JP_QUES,
                            _______,  _______,  _______,        _______,  _______,  _______
    ),

    [URISE] = LAYOUT_split_3x5_3(
        KC_EXLM,  KC_AT,    KC_HASH,  KC_DLR,   KC_PERC,        _______,  _______,  KC_LPRN,  KC_RPRN,  KC_MINS,
        KC_UNDS,  KC_PLUS,  KC_EQL,   KC_ASTR,  KC_CIRC,        KC_LCBR,  KC_RCBR,  KC_LBRC,  KC_RBRC,  KC_COLN,
        KC_BSLS,  KC_AMPR,  KC_PIPE,  KC_TILD,  KC_GRV,         KC_QUOT,  KC_DQUO,  KC_LABK,  KC_RABK,  KC_QUES,
                            _______,  _______,  _______,        _______,  _______,  _______
    ),

    [JFN2] = LAYOUT_split_3x5_3(
        _______,  JP_LPRN,  JP_RPRN,  JP_LBRC,  JP_RBRC,        _______,  _______,  _______,  _______,  _______,
        JP_QUOT,  JP_DQUO,  JP_MINS,  JP_LCBR,  JP_RCBR,        KC_BTN1,  CM_SF10,  JP_ZKHK,  CM_CAPS,  _______,
        JP_QUES,  JP_COLN,  JP_LABK,  JP_RABK,  _______,        _______,  _______,  _______,  _______,  _______,
                            _______,  _______,  _______,        _______,  _______,  _______
    ),
    [UFN2] = LAYOUT_split_3x5_3(
        _______,  KC_LPRN,  KC_RPRN,  KC_LBRC,  KC_RBRC,        _______,  _______,  _______,  _______,  _______,
        KC_QUOT,  KC_DQUO,  KC_MINS,  KC_LCBR,  KC_RCBR,        KC_BTN1,  CM_SF10,  CM_UHNZ,  CM_CAPS,  _______,
        KC_QUES,  KC_COLN,  KC_LABK,  KC_RABK,  _______,        _______,  _______,  _______,  _______,  _______,
                            _______,  _______,  _______,        _______,  _______,  _______
    ),

    [JSPFN] = LAYOUT_split_3x5_3( /* [> SPFN <] */
        CM_GUIE,  CM_ALT4,  LT_EXCL,  CM_GUIT,  CM_WSCS,        CM_STAB,  KC_HOME,  KC_UP,    KC_END,   KC_TAB,
        KC_LALT,  KC_LSFT,  KC_DEL,   MO_HYPS,  KC_LGUI,        KC_BSPC,  KC_LEFT,  KC_DOWN,  KC_RGHT,  KC_ENT,
        KC_1,     KC_2,     KC_3,     KC_4,     KC_5,           KC_6,     KC_7,     KC_8,     KC_9,     KC_0,
                            _______,  _______,  _______,        _______,  _______,  _______
    ),

    [USPFN] = LAYOUT_split_3x5_3( /* [> SPFN <] */
        CM_GUIE,  CM_ALT4,  LT_EXCL,  CM_GUIT,  CM_WSCS,        CM_STAB,  KC_HOME,  KC_UP,    KC_END,   KC_TAB,
        KC_LALT,  KC_LSFT,  KC_DEL,   MO_HYPS,  KC_LGUI,        KC_BSPC,  KC_LEFT,  KC_DOWN,  KC_RGHT,  KC_ENT,
        KC_1,     KC_2,     KC_3,     KC_4,     KC_5,           KC_6,     KC_7,     KC_8,     KC_9,     KC_0,
                            _______,  _______,  _______,        _______,  _______,  _______
    ),

    [EXCL] = LAYOUT_split_3x5_3(
        _______,  _______,  _______,  _______,  _______,        _______,  CM_CHOM,  KC_PGUP,  CM_CEND,  _______,
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
        _______,  _______,  _______,  _______,  _______,        _______,  _______,  _______,  _______,  _______,
        KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5,          KC_BTN1,  CM_SF10,  JP_ZKHK,  CM_CAPS,  _______,
        KC_F6,    KC_F7,    KC_F8,    KC_F9,    KC_F10,         KC_F11,   KC_F12,   _______,  _______,  KC_LSFT,
                            _______,  _______,  _______,        _______,  _______,  _______
    ),

    [UFN] = LAYOUT_split_3x5_3(
        _______,  _______,  _______,  _______,  _______,        _______,  _______,  _______,  _______,  _______,
        KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5,          KC_BTN1,  CM_SF10,  CM_UHNZ,  CM_CAPS,  _______,
        KC_F6,    KC_F7,    KC_F8,    KC_F9,    KC_F10,         KC_F11,   KC_F12,   _______,  _______,  KC_LSFT,
                            _______,  _______,  _______,        _______,  _______,  _______
    ),

    [SYS] = LAYOUT_split_3x5_3(
        _______,  _______,  _______,  _______,  _______,        _______,  _______,  _______,  _______,  QK_BOOT,
        _______,  _______,  _______,  _______,  _______,        _______,  _______,  _______,  _______,  _______,
        _______,  _______,  _______,  _______,  _______,        _______,  _______,  _______,  _______,  _______,
                            _______,  _______,  _______,        DF_JBAS,  DF_UBAS,  _______
    ),

    [ALTTAB] = LAYOUT_split_3x5_3(
        _______,  _______,  _______,  CM_STAB,  KC_TAB,         _______,  _______,  KC_UP,    _______,  _______,
        _______,  _______,  _______,  _______,  _______,        _______,  KC_LEFT,  KC_DOWN,  KC_RGHT,  _______,
        _______,  _______,  _______,  _______,  _______,        _______,  _______,  _______,  _______,  _______,
                            _______,  _______,  _______,        _______,  _______,  _______
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
        case A_ALT:
            return 60;
        case SL_SFT:
            return 60;
        case Z_SFT:
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
//            if (get_highest_layer(default_layer_state)==JBASE){
//              SEND_STRING("`");
//            }else{
//              SEND_STRING(SS_DOWN(X_LSFT));
//              SEND_STRING(SS_TAP(X_SPC));
//              SEND_STRING(SS_UP(X_LSFT));
//            }
//          *modifier_pressed = false;
//          }
//        }
//}

static void user_mt_cpslck(keyrecord_t *record, uint16_t modcode, bool *modifier_pressed, uint16_t *modifier_pressed_time, bool tapping_term_disable) {
         if (record->event.pressed) {
         *modifier_pressed = true;
         *modifier_pressed_time = record->event.time;
       } else {
       	  if (!*modifier_pressed) unregister_code(modcode);
          if (*modifier_pressed && (tapping_term_disable || (timer_elapsed(*modifier_pressed_time) < TAPPING_TERM))) {
            if (get_highest_layer(default_layer_state)==JBASE){
              SEND_STRING(SS_TAP(X_CAPS));
            }else{
              SEND_STRING(SS_DOWN(X_LSFT));
              SEND_STRING(SS_TAP(X_CAPS));
              SEND_STRING(SS_UP(X_LSFT));
            }
          *modifier_pressed = false;
          }
        }
}


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
        //set_mods(get_mods() | MOD_BIT(*mod_switch_keycode));
        register_code(*mod_switch_keycode);
    }
}


static void user_lt(keyrecord_t *record,
        int layer,
        uint16_t keycode,
        bool *modifier_pressed,
        uint16_t *modifier_pressed_time,
        bool tapping_term_disable,
        uint16_t *mod_switch_keycode){  //mod差し替えフラグ兼KEYCODE

    if (record->event.pressed) {
        *modifier_pressed = true;
        *modifier_pressed_time = record->event.time;
        layer_on(layer);
    } else {
        //もしMODキー差替有効中だったらMODキーをクリア（レイヤー移動もクリア）
        if(*mod_switch_keycode){
            unregister_code(*mod_switch_keycode);
            //set_mods(get_mods() & ~MOD_BIT(*mod_switch_keycode));
            *mod_switch_keycode = 0;
            layer_clear();
        }
        layer_off(layer);
        if (*modifier_pressed && (tapping_term_disable || (timer_elapsed(*modifier_pressed_time) < TAPPING_TERM))) {
            register_code(keycode);
            unregister_code(keycode);
            unregister_code(keycode);
        }
    *modifier_pressed = false;
    }
}

//static void user_lt(keyrecord_t *record, int layer, uint16_t keycode, bool *modifier_pressed, uint16_t *modifier_pressed_time, bool tapping_term_disable) {
//    if (record->event.pressed) {
//      *modifier_pressed = true;
//      *modifier_pressed_time = record->event.time;
//      layer_on(layer);
//    } else {
//      layer_off(layer);
//      if (*modifier_pressed && (tapping_term_disable || (timer_elapsed(*modifier_pressed_time) < TAPPING_TERM))) {
//        register_code(keycode);
//        unregister_code(keycode);
//        unregister_code(keycode);
//      }
//      *modifier_pressed = false;
//    }
//}

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


//static bool shhz_pressed = false;
//static uint16_t shhz_pressed_time = 0;
//static bool is_shhz_active = false;

static bool shcl_pressed = false;
static uint16_t shcl_pressed_time = 0;
static bool is_shcl_active = false;

static bool spfn_pressed = false;
static uint16_t spfn_pressed_time = 0;

static bool lise_pressed = false;
static uint16_t lise_pressed_time = 0;

static bool fnsc_pressed = false;
static uint16_t fnsc_pressed_time = 0;

static bool fnso_pressed = false;
static uint16_t fnso_pressed_time = 0;

static bool lefn_pressed = false;
static uint16_t lefn_pressed_time = 0;

static uint16_t mod_switch_keycode = false;

static bool shift_at_active = false;
static uint16_t shift_at_timer;

//void matrix_scan_user(void){
//    // 安全のため：shiftが押されたままになっていたら解除
//    if (!get_mods() && shift_at_active && !(keyboard_report->mods & MOD_BIT(KC_LSFT))) {
//        unregister_code(KC_LSFT);
//        shift_at_active = false;
//    }
//}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  if (record->event.pressed) {
    // reset the user_lt & user_tt flags
    if (keycode != CM_LEFN) {lefn_pressed = false;}
    if (keycode != CM_SPFN) {spfn_pressed = false;}
    if (keycode != CM_LISE) {lise_pressed = false;}
    if (keycode != CM_FNSC) {fnsc_pressed = false;}
    if (keycode != CM_FNSO) {fnso_pressed = false;}
//    if (keycode != CM_SHHZ){
//       if (shhz_pressed) {register_code(KC_LSFT); is_shhz_active = true;}
//       shhz_pressed  = false;
//    }
    if (keycode != CM_SHCL){
       if (shcl_pressed) {register_code(KC_LSFT); is_shcl_active = true;}
       shcl_pressed  = false;
    }

  }
  switch (keycode) {
    case CM_SHHZ:
          if (record->event.pressed) {
                shift_at_timer = timer_read();
                shift_at_active = true;
                return false;
            } else {
                if (timer_elapsed(shift_at_timer) < TAPPING_TERM) {
                    // タップなら @ を送る（Shift + 2）
                    register_code(KC_LSFT);
                    tap_code(KC_2);
                    unregister_code(KC_LSFT);
                } else {
                    // 長押しだったら Shift を解除
                    unregister_code(KC_LSFT);
                }
                shift_at_active = false;
                return false;
            }
      return false;
      break;
    case CM_SHCL:
      if (get_highest_layer(default_layer_state)==JBASE){
        user_mt_cpslck(record,KC_LSFT,&shcl_pressed,&shcl_pressed_time,false);
      } else {
        user_mt_cpslck(record,KC_LSFT,&shcl_pressed,&shcl_pressed_time,false);
      }
      return false;
      break;

    case CM_SPFN:
      if (get_highest_layer(default_layer_state)==JBASE){
        user_lt(record,JSPFN,KC_SPC,&spfn_pressed,&spfn_pressed_time,false,&mod_switch_keycode);
      } else {
        user_lt(record,USPFN,KC_SPC,&spfn_pressed,&spfn_pressed_time,false,&mod_switch_keycode);
      }
      return false;
      break;
    case CM_FNSC:
      if (get_highest_layer(default_layer_state)==JBASE){
        user_lt(record,JFN2,KC_SCLN,&fnsc_pressed,&fnsc_pressed_time,false,&mod_switch_keycode);
      } else {
        user_lt(record,UFN2,KC_SCLN,&fnsc_pressed,&fnsc_pressed_time,false,&mod_switch_keycode);
      }
      return false;
      break;
    case CM_FNSO:
      if (get_highest_layer(default_layer_state)==JBASE){
        user_lt(record,JFN,KC_DOT,&fnso_pressed,&fnso_pressed_time,false,&mod_switch_keycode);
      } else {
        user_lt(record,UFN,KC_DOT,&fnso_pressed,&fnso_pressed_time,false,&mod_switch_keycode);
      }
      return false;
      break;
    case CM_LISE:
      if (get_highest_layer(default_layer_state)==JBASE){
        user_lt(record,JRISE,KC_COMM,&lise_pressed,&lise_pressed_time,false,&mod_switch_keycode);
      } else {
        user_lt(record,URISE,KC_COMM,&lise_pressed,&lise_pressed_time,false,&mod_switch_keycode);
      }
      return false;
      break;
    case CM_LEFN:
      if (get_highest_layer(default_layer_state)==JBASE){
        user_lt(record,JLEF,KC_Q,&lefn_pressed,&lefn_pressed_time,false,&mod_switch_keycode);
      } else {
        user_lt(record,ULEF,KC_Q,&lefn_pressed,&lefn_pressed_time,false,&mod_switch_keycode);
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
    case SW_ATAB:
      mod_layer_switch(record,KC_LALT,&mod_switch_keycode,ALTTAB);
      if(record->event.pressed){
        //pressed
        tap_code(KC_TAB);
      } else {
        //released
      }
      return false;
      break;
    case CM_ALCT:
      if(record->event.pressed){
        //pressed
        register_code(KC_LALT);
        register_code(KC_LCTL);
        unregister_code(KC_LCTL);
        unregister_code(KC_LALT);
      }else{
        //released
      }
      mod_layer_switch(record,KC_LALT,&mod_switch_keycode,ALTTAB);
      if(record->event.pressed){
        //pressed
        tap_code(KC_TAB);
      } else {
        //released
      }
      return false;
      break;
    case CM_K_QY:
      if(record->event.pressed){
        //pressed
        tap_code(KC_Q);
        tap_code(KC_Y);
      }else{
        //released
      }
      return false;
      break;
    case CM_K_QU:
      if(record->event.pressed){
        //pressed
        tap_code(KC_Q);
        tap_code(KC_U);
      }else{
        //released
      }
      return false;
      break;
    case CM_K_QI:
      if(record->event.pressed){
        //pressed
        tap_code(KC_Q);
        tap_code(KC_I);
      }else{
        //released
      }
      return false;
      break;
    case CM_K_QO:
      if(record->event.pressed){
        //pressed
        tap_code(KC_Q);
        tap_code(KC_O);
      }else{
        //released
      }
      return false;
      break;
    case CM_K_QP:
      if(record->event.pressed){
        //pressed
        tap_code(KC_Q);
        tap_code(KC_P);
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
        fnso_pressed = false;
        lefn_pressed = false;
//        if (shhz_pressed) {register_code(KC_LSFT); is_shhz_active = true;}
//        shhz_pressed  = false;
        if (shcl_pressed) {register_code(KC_LSFT); is_shcl_active = true;}
        shcl_pressed  = false;

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
