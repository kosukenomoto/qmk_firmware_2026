// Copyright (C) 2019, 2020  Keyboard.io, Inc
//
// this is the style you want to emulate.
// This is the canonical layout file for the Quantum project. If you want to add another keyboard,
//
// makeコマンドは下記を実行
// make keyboardio/atreus:20230924:flash
// qmk compile -kb keyboardio/atreus -km 20230924
// qmk flash -kb keyboardio/atreus -km 20230924
// As far as I know, you still need to hold down the Esc key (where it was in the original layout) while pressing QK_BOOT.


#include QMK_KEYBOARD_H
#include "keymap_jp.h"
#include "audio.h"

#define JBASE   0
#define UBASE   1
#define JRISE   2
#define URISE   3
#define SPFN    4
#define SPFN2   5
#define EXCL    9
#define HYPSPFN 10
#define FN      13
#define SYS     14
#define ALTTAB  15

#define KC_MSDN    KC_MS_DOWN
#define KC_MSUP    KC_MS_UP
#define KC_MSLF    KC_MS_LEFT
#define KC_MSRT    KC_MS_RIGHT

#define LT_EXCL LT(EXCL,KC_ESC)
#define LT_SYS  LT(SYS,KC_PSCR)
#define MO_HYPS MO(HYPSPFN)
#define DF_JBAS DF(JBASE)
#define DF_UBAS DF(UBASE)

#define BK_SFT SFT_T(KC_BSPC)
#define SL_SFT SFT_T(KC_SLSH)
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
#define CM_GUIM G(KC_M)
#define CM_GUP  G(KC_UP)
#define CM_GDOW G(KC_DOWN)

#define CM_STAB S(KC_TAB)

#define CM_JHNZ A(KC_GRV)
//#define CM_UHNZ C(KC_SPC)
//VM利用時はカラビナでALTGRAVに置き換えて解釈
//(VM利用時はカラビナでCNTLがまずcontrol->command command->controlとなる
//　つぎにーカラビナでCommand+SPAVEであればALT+GRAVに変換）

enum custom_keycodes {
  CM_LEFT = SAFE_RANGE,
  CM_RGHT,
  CM_UP,
  CM_DOWN,
  CM_SPFN,
  CM_SPFN2,
  CM_LISE,
  CM_FNSC,
  CM_ALCT,
  SW_LSFT,
  SW_LALT,
  SW_LCTL,
  SW_LGUI,
  SW_ATAB
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [JBASE] = LAYOUT( /* Qwerty win jpkey */
    /***********************************************************************************************/
    /* win jpkey(QMK)  GUI(command)   CTL(control)   ALT(option)                                   */
    /***********************************************************************************************/
    KC_Q,      KC_W,     KC_E,     KC_R,     KC_T,                       KC_Y,      KC_U,     KC_I,     KC_O,    KC_P,
    A_ALT,     KC_S,     KC_D,     KC_F,     KC_G,                       KC_H,      KC_J,     KC_K,     KC_L,    CM_FNSC,
    Z_SFT,     KC_X,     KC_C,     KC_V,     KC_B,    CM_ALT4, LT_SYS,   KC_N,      KC_M,     KC_COMM,  KC_DOT,  SL_SFT,
    KC_DEL,    KC_LALT,  KC_LGUI,  KC_LSFT,  CM_LISE, KC_LCTL, KC_LCTL,  CM_SPFN,   KC_LSFT,  KC_LGUI,  KC_LALT, KC_DEL),

  [UBASE] = LAYOUT( /* Qwerty mac uskey */
    /***********************************************************************************************/
    /* mac uskey(QMK)      ALT(option)       GUI(command)                CTL(control)              */
    /* mac karabiner(win)  option(ALT)->GUI  command(GUI)->control(CTL)  control(CTL)->option(ALT) */
    /***********************************************************************************************/
    // [vmware使ってない時]  mac_F14 -> mac_cmd+opt+spc(finder find)
    // [vmware]            mac_F14 ->cwkj win_GUI+e
    // [vmware]            mac_F13 -> win_F2
    KC_Q,      KC_W,     KC_E,     KC_R,     KC_T,                       KC_Y,      KC_U,     KC_I,     KC_O,    KC_P,
    A_ALT,     KC_S,     KC_D,     KC_F,     KC_G,                       KC_H,      KC_J,     KC_K,     KC_L,    CM_FNSC,
    Z_SFT,     KC_X,     KC_C,     KC_V,     KC_B,    CM_ALT4, LT_SYS,   KC_N,      KC_M,     KC_COMM,  KC_DOT,  SL_SFT,
    KC_DEL,    KC_LALT,  KC_LGUI,  KC_LSFT,  CM_LISE, KC_LCTL, KC_LCTL,  CM_SPFN,   KC_LSFT,  KC_LGUI,  KC_LALT, KC_DEL),


    /**********************************************************************************************/
    //   !       @      #     $    %        ||       &     *     (    )    -
    //   _       +      =     -    ^        ||       {     }     [    ]    :
    //   \       `      |     ~    NO       ||       '     "     <    >    ?
   [JRISE] = LAYOUT(
    JP_EXLM,   JP_AT,     JP_HASH, JP_DLR,    JP_PERC,                    JP_TILD,  JP_ASTR,  JP_LPRN, JP_RPRN, JP_MINS,
    JP_UNDS,   JP_PLUS,   JP_EQL,  SW_ATAB,   JP_CIRC,                    JP_LCBR,  JP_RCBR,  JP_LBRC, JP_RBRC, JP_COLN,
    JP_BSLS,   JP_AMPR,   JP_PIPE, CM_ALCT,   JP_GRV,   _______, _______, JP_QUOT,  JP_DQUO,  JP_LABK, JP_RABK, JP_QUES,
    _______,    _______,   _______, _______,   _______,  _______, _______, _______,  _______,  _______, _______, _______ ),

   [URISE] = LAYOUT(
    KC_EXLM,   KC_AT,     KC_HASH, KC_DLR,    KC_PERC,                    KC_TILD,  KC_ASTR,  KC_LPRN, KC_RPRN, KC_MINS,
    KC_UNDS,   KC_PLUS,   KC_EQL,  SW_ATAB,   KC_CIRC,                    KC_LCBR,  KC_RCBR,  KC_LBRC, KC_RBRC, KC_COLN,
    KC_BSLS,   KC_AMPR,   KC_PIPE, CM_ALCT,   KC_GRV,   _______, _______, KC_QUOT,  KC_DQUO,  KC_LABK, KC_RABK, KC_QUES,
    _______,   _______,   _______, _______,   _______,  _______, _______, _______,  _______,  _______, _______, _______  ),

//**********************************************************

  [SPFN] = LAYOUT( /* [> SPFN <] */
    _______,   _______,   LT_EXCL, _______,   _______,                    CM_STAB,  KC_HOME,  KC_UP,    KC_END,  KC_TAB,
    KC_LALT,   KC_LSFT,   _______, MO_HYPS,   KC_LGUI,                     KC_BSPC,  KC_LEFT,  KC_DOWN,  KC_RGHT, KC_ENT,
    KC_1,      KC_2,      KC_3,    KC_4,      KC_5,     _______, _______, KC_6,     KC_7,     KC_8,     KC_9,    KC_0,
    _______,   _______,   _______, _______,   _______,  _______, _______, _______,  _______,  _______,  _______, _______ ),

  [EXCL] = LAYOUT( /* [> MO_JLEF <] */
    _______,   _______, _______, _______, _______,                    _______,  CM_CHOM,  KC_PGUP,  CM_CEND, _______,
    _______,   _______, _______, _______, _______,                    _______,  CM_CPGU,  KC_PGDN,  CM_CPGD, _______,
    _______,   _______, _______, _______, _______,  _______, _______, _______,  _______,  _______,  _______, _______,
    _______,   _______, _______, _______, _______,  _______, _______, _______,  _______,  _______,  _______, _______ ),

  [HYPSPFN] = LAYOUT( /* [> MO_HYPS <] */
    _______,   _______, _______, _______, _______,                    _______,  _______,  CM_UP,   _______,  _______,
    _______,   _______, _______, _______, _______,                    _______,  CM_LEFT,  CM_DOWN, CM_RGHT,  _______,
    _______,   _______, _______, _______, _______,  _______, _______, _______,  _______,  _______,  _______, _______,
    _______,   _______, _______, _______, _______,  _______, _______, _______,  _______,  _______,  _______, _______ ),

  [FN] = LAYOUT(
    _______,   _______, _______, _______, _______,                    _______,  _______,  _______,  _______, _______,
    KC_F1,     KC_F2,   KC_F3,   KC_F4,   KC_F5,                      KC_BTN1,  CM_SF10,  JP_ZKHK,  CM_JHNZ, _______,
    KC_F6,     KC_F7,   KC_F8,   KC_F9,   KC_F10,   KC_F11,  KC_F12,  _______,  _______,  _______,  _______, KC_LSFT,
    _______,   _______, _______, _______, _______,  _______, _______, _______,  _______,  _______,  _______, _______ ),

  [SYS] = LAYOUT( /* [> MO_HYPS <] */
    _______,   _______, _______, _______, _______,                    _______,  _______,  _______, _______,  QK_BOOT,
    _______,   _______, _______, _______, _______,                    _______,  _______,  _______, _______,  _______,
    _______,   _______, _______, _______, _______,  _______, _______, _______,  _______,  _______, _______,  _______,
    _______,   _______, _______, _______, _______,  _______, _______, _______,  _______,  DF_JBAS, DF_UBAS,  _______ ),

  [ALTTAB] = LAYOUT( /* [> SWITCH ALTTAB<] */
    _______,   _______, _______, _______, _______,                    _______,  _______,  KC_UP,   _______,  _______,
    _______,   _______, _______, KC_TAB,  _______,                    _______,  KC_LEFT,  KC_DOWN, KC_RGHT,  _______,
    _______,   _______, _______, CM_STAB, _______,  _______, _______, _______,  _______,  _______, _______,  _______,
    _______,   _______, _______, _______, _______,  _______, _______, _______,  _______,  _______, _______,  _______ )
};

void keyboard_post_init_user(void) {
    // float song1[][2] = SONG( { 2000.0f, 22 }, { 1000.0f, 18 } );
    // AUDIO_INIT_DELAYの時間を待機
    wait_ms(500);
    audio_init();

    // 初期化後にstartup_songを再生
    //PLAY_SONG(song1);
}

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
static bool spfn2_pressed = false;
//static uint16_t spfn2_pressed_time = 0;
static bool spfn_pressed = false;
static uint16_t spfn_pressed_time = 0;
static bool lise_pressed = false;
static uint16_t lise_pressed_time = 0;
static bool fnsc_pressed = false;
static uint16_t fnsc_pressed_time = 0;

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

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  if (record->event.pressed) {
    // reset the user_lt & user_tt flags
    if (keycode != CM_SPFN2) {spfn2_pressed = false;}
    if (keycode != CM_SPFN)  {spfn_pressed = false;}
    if (keycode != CM_LISE)  {lise_pressed = false;}
    if (keycode != CM_FNSC)  {fnsc_pressed = false;}
  }
  switch (keycode) {
    case CM_SPFN:
      if (get_highest_layer(default_layer_state)==JBASE){
        user_lt(record,SPFN,KC_SPC,&spfn_pressed,&spfn_pressed_time,false,&mod_switch_keycode);
      } else {
        user_lt(record,SPFN,KC_SPC,&spfn_pressed,&spfn_pressed_time,false,&mod_switch_keycode);
      }
      return false;
      break;
    case CM_LISE:
      if (get_highest_layer(default_layer_state)==JBASE){
        user_lt(record,JRISE,KC_ESC,&lise_pressed,&lise_pressed_time,false,&mod_switch_keycode);
      } else {
        user_lt(record,URISE,KC_ESC,&lise_pressed,&lise_pressed_time,false,&mod_switch_keycode);
      }
      return false;
      break;
    case CM_FNSC:
      if (get_highest_layer(default_layer_state)==JBASE){
        user_lt(record,FN,KC_SCLN,&fnsc_pressed,&fnsc_pressed_time,false,&mod_switch_keycode);
      } else {
        user_lt(record,FN,KC_SCLN,&fnsc_pressed,&fnsc_pressed_time,false,&mod_switch_keycode);
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
    default:
      if (record->event.pressed) {
        // reset the flag
        spfn_pressed = false;
        spfn2_pressed = false;
        lise_pressed = false;
        fnsc_pressed = false;
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
