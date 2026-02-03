/*  -*-  eval: (turn-on-orgtbl); -*-
 * default HHKB Layout
 */
#include QMK_KEYBOARD_H

#include "keymap_jp.h"

#define JBASE   0
#define UBASE   1
#define JSYM    2
#define USYM    3
#define JSYM2   4
#define USYM2   5
#define JSPFN   6
#define USPFN   7
#define EXCL    8
#define HYPE    9
#define FN      10
#define SYS     11
#define ALTTAB  12

#define KC_MSDN    KC_MS_DOWN
#define KC_MSUP    KC_MS_UP
#define KC_MSLF    KC_MS_LEFT
#define KC_MSRT    KC_MS_RIGHT

#define LT_EXCL LT(EXCL,KC_ESC)
#define LT_SYS  LT(SYS,KC_PSCR)
#define MO_HYPS MO(HYPE)
#define DF_JBAS DF(JBASE)
#define DF_UBAS DF(UBASE)

#define CM_CAPS S(JP_EISU)

#define BK_SFT SFT_T(KC_BSPC)
#define SL_SFT SFT_T(KC_SLSH)
#define SL_ALT LALT_T(KC_SLSH)
#define Z_SFT SFT_T(KC_Z)
#define A_ALT LALT_T(KC_A)

#define CM_CPGU C(KC_PGUP)
#define CM_CPGD C(KC_PGDN)
#define CM_CHOM C(KC_HOME)
#define CM_CEND C(KC_END)
#define CM_GPGU G(KC_PGUP)
#define CM_GPGD G(KC_PGDN)
#define CM_GHOM G(KC_HOME)
#define CM_GEND G(KC_END)

#define CM_ALT4 A(KC_F4)
#define CM_GUIT G(KC_TAB)
#define CM_GUIE G(KC_E)
#define CM_GUIM G(KC_M)
#define CM_SF10 S(KC_F10)
#define CM_WSCS G(S(KC_S))
#define CM_GUID G(KC_D)
#define CM_GUP  G(KC_UP)
#define CM_GDOW G(KC_DOWN)

#define CM_STAB S(KC_TAB)

#define CM_JHNZ A(KC_GRV)
#define CM_UHNZ S(KC_SPC)
//#define CM_UHNZ C(KC_SPC)
//VM利用時はカラビナでALTGRAVに置き換えて解釈
//(VM利用時はカラビナでCNTLがまずcontrol->command command->controlとなる
//　つぎにーカラビナでCommand+SPAVEであればALT+GRAVに変換）

enum custom_keycodes {
  CM_LEFT = SAFE_RANGE,
  CM_RGHT,
  CM_UP,
  CM_DOWN,
  CM_DELE,
  CM_BSPC,
  CM_SPFN,
  CM_FNSC,
  CM_FNQU,
  CM_FNCM,
  CM_ALCT,
  SW_LSFT,
  SW_LALT,
  SW_LCTL,
  SW_LGUI,
  SW_ATAB
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

//  [SPFN] = LAYOUT( /* Qwerty 101 uskey */
//    _______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,
//    _______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,
//    _______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,
//    _______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,
//    _______,_______,_______,_______,_______),

//US for Ubuntu(US layout keyboard setting)
//JP for Windows(jp layout keyboard setting)

  [JBASE] = LAYOUT( /* Qwerty 106 jpkey */
    KC_ESC, KC_1,   KC_2,   KC_3,   KC_4,   KC_5,   KC_6,   KC_7,   KC_8,   KC_9,   KC_0,   JP_MINS,JP_EQL, JP_BSLS,JP_GRV,
    KC_TAB, KC_Q,   KC_W,   KC_E,   KC_R,   KC_T,   KC_Y,   KC_U,   KC_I,   KC_O,   KC_P,   JP_LBRC,JP_RBRC,KC_BSPC,
    KC_LCTL,KC_A,   KC_S,   KC_D,   KC_F,   KC_G,   KC_H,   KC_J,   KC_K,   KC_L,   KC_SCLN,JP_QUOT,KC_ENT,
//    KC_LCTL,KC_A,   KC_S,   KC_D,   KC_F,   KC_G,   KC_H,   KC_J,   KC_K,   KC_L,   CM_FNSC,JP_QUOT,KC_ENT,
    KC_LSFT,KC_Z,   KC_X,   KC_C,   KC_V,   KC_B,   KC_N,   KC_M,   CM_FNCM,CM_FNQU,SL_ALT, KC_RSFT,LT_SYS,
    KC_LGUI,KC_LALT,CM_SPFN,KC_RALT,KC_RGUI),

  [UBASE] = LAYOUT( /* Qwerty 101 uskey */
    KC_ESC, KC_1,   KC_2,   KC_3,   KC_4,   KC_5,   KC_6,   KC_7,   KC_8,   KC_9,   KC_0,   KC_MINS,KC_EQL, KC_BSLS,KC_GRV,
    KC_TAB, KC_Q,   KC_W,   KC_E,   KC_R,   KC_T,   KC_Y,   KC_U,   KC_I,   KC_O,   KC_P,   KC_LBRC,KC_RBRC,KC_BSPC,
    KC_LCTL,KC_A,   KC_S,   KC_D,   KC_F,   KC_G,   KC_H,   KC_J,   KC_K,   KC_L,   KC_SCLN,KC_QUOT,KC_ENT,
//    KC_LCTL,KC_A,   KC_S,   KC_D,   KC_F,   KC_G,   KC_H,   KC_J,   KC_K,   KC_L,   CM_FNSC,KC_QUOT,KC_ENT,
    KC_LSFT,KC_Z,   KC_X,   KC_C,   KC_V,   KC_B,   KC_N,   KC_M,   CM_FNCM,CM_FNQU,SL_ALT, KC_RSFT,LT_SYS,
    KC_LGUI,KC_LALT,CM_SPFN,KC_RALT,KC_RGUI),

  [JSYM] = LAYOUT(
    _______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,
    _______,JP_EXLM,JP_AT,  JP_HASH,JP_DLR, JP_PERC,_______,_______,_______,_______,_______,_______,_______,_______,
    _______,JP_UNDS,JP_PLUS,JP_EQL, JP_ASTR,JP_CIRC,_______,_______,_______,_______,_______,_______,_______,
    _______,JP_BSLS,JP_AMPR,JP_PIPE,JP_TILD,JP_GRV, _______,JP_ZKHK,_______,CM_CAPS,_______,_______,_______,
    _______,_______,_______,_______,_______),

  [USYM] = LAYOUT( /* Qwerty 101 uskey */
    _______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,
    _______,KC_EXLM,KC_AT,  KC_HASH,KC_DLR, KC_PERC,_______,_______,_______,_______,_______,_______,_______,_______,
    _______,KC_UNDS,KC_PLUS,KC_EQL, KC_ASTR,KC_CIRC,_______,_______,_______,_______,_______,_______,_______,
    _______,KC_BSLS,KC_AMPR,KC_PIPE,KC_TILD,KC_GRV, _______,CM_UHNZ,_______,CM_CAPS,_______,_______,_______,
    _______,_______,_______,_______,_______),

  [JSYM2] = LAYOUT(
    _______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,
    _______,_______,JP_LPRN,JP_RPRN,JP_LBRC,JP_RBRC,_______,_______,_______,_______,_______,_______,_______,_______,
    _______,JP_QUOT,JP_DQUO,JP_MINS,JP_LCBR,JP_RCBR,_______,_______,_______,_______,_______,_______,_______,
    _______,JP_QUES,JP_COLN,JP_LABK,JP_RABK,_______,_______,_______,_______,_______,_______,_______,_______,
    _______,_______,_______,_______,_______),

  [USYM2] = LAYOUT( /* Qwerty 101 uskey */
    _______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,
    _______,_______,KC_LPRN,KC_RPRN,KC_LBRC,KC_RBRC,_______,_______,_______,_______,_______,_______,_______,_______,
    _______,KC_QUOT,KC_DQUO,KC_MINS,KC_LCBR,KC_RCBR,_______,_______,_______,_______,_______,_______,_______,
    _______,KC_QUES,KC_COLN,KC_LABK,KC_RABK,_______,_______,_______,_______,_______,_______,_______,_______,
    _______,_______,_______,_______,_______),

  [JSPFN] = LAYOUT( /* Qwerty 101 uskey */
    _______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,
    CM_WSCS,CM_GUIE,CM_ALT4,LT_EXCL,CM_GUID,_______,CM_STAB,KC_HOME,KC_UP,  KC_END, KC_TAB, _______,_______,_______,
    _______,KC_LALT,KC_LSFT,KC_DEL, MO_HYPS,KC_LGUI,KC_BSPC,KC_LEFT,KC_DOWN,KC_RGHT,KC_ENT, _______,_______,
    _______,KC_1   ,KC_2   ,KC_3   ,KC_4   ,KC_5   ,KC_6   ,KC_7   ,KC_8   ,KC_9   ,KC_0   ,_______,_______,
    _______,_______,_______,_______,_______),

  [USPFN] = LAYOUT( /* Qwerty 101 uskey */
    _______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,
    KC_PSCR,_______,CM_ALT4,LT_EXCL,CM_GUID,_______,CM_STAB,KC_HOME,KC_UP,  KC_END, KC_TAB, _______,_______,_______,
    _______,KC_LALT,KC_LSFT,KC_DEL, MO_HYPS,KC_LGUI,KC_BSPC,KC_LEFT,KC_DOWN,KC_RGHT,KC_ENT, _______,_______,
    _______,KC_1   ,KC_2   ,KC_3   ,KC_4   ,KC_5   ,KC_6   ,KC_7   ,KC_8   ,KC_9   ,KC_0   ,_______,_______,
    _______,_______,_______,_______,_______),



  [EXCL] = LAYOUT( /* Qwerty 101 uskey */
    _______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,
    _______,_______,_______,_______,_______,_______,_______,CM_CHOM,KC_PGUP,CM_CEND,_______,_______,_______,_______,
    _______,_______,_______,_______,_______,_______,_______,CM_CPGU,KC_PGDN,CM_CPGD,_______,_______,_______,
    _______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,
    _______,_______,_______,_______,_______),

  [HYPE] = LAYOUT( /* Qwerty 101 uskey */
    _______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,
    _______,_______,_______,_______,_______,_______,_______,_______,CM_UP,  _______,_______,_______,_______,_______,
    _______,_______,_______,CM_DELE,_______,_______,CM_BSPC,CM_LEFT,CM_DOWN,CM_RGHT,_______,_______,_______,
    _______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,
    _______,_______,_______,_______,_______),

  [FN] = LAYOUT( /* Qwerty 101 uskey */
    _______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,
    _______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,
    _______,KC_F1,  KC_F2,  KC_F3,  KC_F4,  KC_F5,  _______,_______,_______,_______,_______,_______,_______,
    _______,KC_F6,  KC_F7,  KC_F8,  KC_F9,  KC_F10, KC_F11, KC_F12, _______,_______,KC_LSFT,_______,_______,
    _______,_______,_______,_______,_______),

  [SYS] = LAYOUT( /* Qwerty 101 uskey */
    _______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,QK_BOOT,
    _______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,
    _______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,
    _______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,
    _______,_______,_______,DF_JBAS,DF_UBAS),

  [ALTTAB] = LAYOUT( /* Qwerty 101 uskey */
    _______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,QK_BOOT,
    _______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,
    _______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,
    _______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,
    _______,_______,_______,_______,_______)
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

//SPFN ============================================
static bool spfn_pressed = false;
static uint16_t spfn_pressed_time = 0;

static bool fnqu_pressed = false;
static uint16_t fnqu_pressed_time = 0;

static bool fnsc_pressed = false;
static uint16_t fnsc_pressed_time = 0;

static bool fncm_pressed = false;
static uint16_t fncm_pressed_time = 0;

static uint16_t mod_switch_keycode = false;

//上関数のIMEON/OFF切り替え専用
//TODO 汎用的な関数を引数に取れるようにすること(関数アドレス)
//static void user_lt_hnzn(keyrecord_t *record, int layer, bool *modifier_pressed, uint16_t *modifier_pressed_time, bool tapping_term_disable) {
//      if (record->event.pressed) {
//        *modifier_pressed_time = record->event.time;
//        *modifier_pressed = true;
//        layer_on(layer);
//      } else {
//        layer_off(layer);
//        if (*modifier_pressed && (tapping_term_disable || (timer_elapsed(*modifier_pressed_time) < TAPPING_TERM))) {
//         if (get_highest_layer(default_layer_state)==JBASE){
//             SEND_STRING(SS_LALT("`"));
//         }else{
//             SEND_STRING(SS_LALT("`"));
//             //VM利用時はカラビナでALTGRAVに置き換えて解釈
//             //(VM利用時はカラビナでCNTLがまずcontrol->command command->controlとなる
//             //　つぎにーカラビナでCommand+SPAVEであればALT+GRAVに変換）
//         }
//        }
//        *modifier_pressed = false;
//      }
//}

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
            uint8_t shift = keyboard_report->mods & (MOD_BIT(KC_LSFT) | MOD_BIT(KC_RSFT));
            uint16_t s = 0;
            if(shift && (get_highest_layer(default_layer_state)==JBASE)){
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
                    //case JP_QUOT: s = JP_DQUO; break;
                    case JP_SCLN: s = JP_COLN; break;
                    case JP_BSLS: s = JP_PIPE; break;
                    case KC_QUOT: s = JP_DQUO; break;
                }
            }
            if(s!=0){
                unregister_mods(shift);
                tap_code16(s);
                register_mods(shift);
            }else{
                if(keycode == KC_QUOT && (get_highest_layer(default_layer_state)==JBASE)){
                    tap_code16(JP_QUOT);
                }else{
                    register_code(keycode);
                    unregister_code(keycode);
                    unregister_code(keycode);
                }
            }
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

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  if (record->event.pressed) {
    // reset the user_lt & user_tt flags
    if (keycode != CM_SPFN)  {spfn_pressed = false;}
    if (keycode != CM_FNSC)  {fnsc_pressed = false;}
    if (keycode != CM_FNQU)  {fnqu_pressed = false;}
    if (keycode != CM_FNCM)  {fncm_pressed = false;}
  }
  switch (keycode) {
    case CM_SPFN:
      if (get_highest_layer(default_layer_state)==JBASE){
        user_lt(record,JSPFN,KC_SPC,&spfn_pressed,&spfn_pressed_time,false,&mod_switch_keycode);
      } else {
        user_lt(record,USPFN,KC_SPC,&spfn_pressed,&spfn_pressed_time,false,&mod_switch_keycode);
      }
      return false;
      break;
    case CM_FNQU:
      if (get_highest_layer(default_layer_state)==JBASE){
        user_lt(record,FN,KC_DOT,&fnqu_pressed,&fnqu_pressed_time,false,&mod_switch_keycode);
      } else {
        user_lt(record,FN,KC_DOT,&fnqu_pressed,&fnqu_pressed_time,false,&mod_switch_keycode);
      }
      return false;
      break;
    case CM_FNSC:
      if (get_highest_layer(default_layer_state)==JBASE){
        user_lt(record,JSYM2,JP_SCLN,&fnsc_pressed,&fnsc_pressed_time,false,&mod_switch_keycode);
      } else {
        user_lt(record,USYM2,KC_SCLN,&fnsc_pressed,&fnsc_pressed_time,false,&mod_switch_keycode);
      }
      return false;
      break;
    case CM_FNCM:
      if (get_highest_layer(default_layer_state)==JBASE){
        user_lt(record,JSYM,JP_COMM,&fncm_pressed,&fncm_pressed_time,false,&mod_switch_keycode);
      } else {
        user_lt(record,USYM,KC_COMM,&fncm_pressed,&fncm_pressed_time,false,&mod_switch_keycode);
      }
      return false;
      break;
    case SW_LSFT:
      mod_layer_switch(record,KC_LSFT,&mod_switch_keycode,0);
      return false;
      break;
    case SW_LALT:
      mod_layer_switch(record,KC_LALT,&mod_switch_keycode,0);
      return false;
      break;
    case SW_LCTL:
      mod_layer_switch(record,KC_LCTL,&mod_switch_keycode,0);
      return false;
      break;
    case SW_LGUI:
      mod_layer_switch(record,KC_LGUI,&mod_switch_keycode,0);
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
      break;
    case CM_BSPC:
      if(record->event.pressed){
        //pressed
        tap_code(KC_BSPC);
        tap_code(KC_BSPC);
        tap_code(KC_BSPC);
        tap_code(KC_BSPC);
      }else{
        //released
      }
      break;
    case CM_DELE:
      if(record->event.pressed){
        //pressed
        tap_code(KC_DEL);
        tap_code(KC_DEL);
        tap_code(KC_DEL);
        tap_code(KC_DEL);
      }else{
        //released
      }
      break;
    default:
      if (record->event.pressed) {
        // reset the flag
        spfn_pressed = false;
        fnqu_pressed = false;
        fnsc_pressed = false;
        fncm_pressed = false;
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
