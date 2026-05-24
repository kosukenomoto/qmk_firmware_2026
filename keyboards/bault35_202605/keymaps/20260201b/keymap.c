//./util/docker_build.sh bault35_202601:20260201
/*  -*-  eval: (turn-on-orgtbl); -*-
 * default HHKB Layout
 */
#include QMK_KEYBOARD_H

#include "keymap_jp.h"

#define JBASE   0
#define UBASE   1
#define NUM     2
#define ARW1    3
#define ARW2    4
#define EXCL    5
#define JSYM    6
#define USYM    7
#define JSYM2   8
#define USYM2   9
#define JQFN    10
#define UQFN    11
#define FUNC    12
#define ALTTAB  14

//#define JSPFN   99
//#define USPFN   98

#define SP_SFT  LSFT_T(KC_SPC)
#define F_CTL   LCTL_T(KC_F)
#define J_CTL   RCTL_T(KC_J)
#define D_ALT   LALT_T(KC_D)
#define K_ALT   RALT_T(KC_K)
#define G_GUI   LGUI_T(KC_G)
#define H_GUI   RGUI_T(KC_H)
#define LT_ARW1 LT(ARW1,KC_A)
#define LT_ARW2 LT(ARW2,KC_S)
#define LT_EXCL LT(EXCL,KC_E)
#define LT_NUM  LT(NUM,KC_DOT)
#define LT_FUNC LT(FUNC,KC_BSPC)
#define TD_Z    TD(Z_CTL_SFT)

//#define KC_MSDN    KC_MS_DOWN
//#define KC_MSUP    KC_MS_UP
//#define KC_MSLF    KC_MS_LEFT
//#define KC_MSRT    KC_MS_RIGHT
//#define LT_EXCL LT(EXCL,KC_ESC)
//#define J_JSYM  LT(JSYM3,KC_J)
//#define F_JSYM  LT(JSYM3,KC_F)
#define MO_HYPS MO(HYPE)
#define MO_JSM2 MO(JSYM2)
#define MO_USM2 MO(USYM2)
#define DF_JBAS DF(JBASE)
#define DF_UBAS DF(UBASE)

#define BK_SFT SFT_T(KC_BSPC)
#define SL_SFT SFT_T(KC_SLSH)
#define SL_ALT LALT_T(KC_SLSH)
#define S_SFT LSFT_T(KC_S)
#define L_SFT RSFT_T(KC_L)
#define Z_SFT LSFT_T(KC_Z)
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

// 状態を定義するための型
typedef struct {
    bool is_press_action;
    uint8_t state;
} tap;

enum {
    SINGLE_TAP = 1,
    SINGLE_HOLD = 2,
    DOUBLE_TAP = 3,
    DOUBLE_HOLD = 4,
};

// Tap DanceのID定義
enum {
    Z_CTL_SFT = 0
};

// 現在の状態を判定する関数
//uint8_t cur_dance(tap_dance_state_t *state) {
//    if (state->count == 1) {
//        if (state->interrupted || !state->pressed) return SINGLE_TAP;
//        else return SINGLE_HOLD;
//    } else if (state->count == 2) {
//        if (state->interrupted || !state->pressed) return DOUBLE_TAP;
//        else return DOUBLE_HOLD;
//    }
//    return 5; // 3回以上のタップ（必要なら定義）
//}
uint8_t cur_dance(tap_dance_state_t *state) {
    if (state->count == 1) {
        // 割り込みがあっても、押しっぱなしならSINGLE_HOLD(Shift)を優先
        //if (state->pressed) return SINGLE_HOLD;
        //else return SINGLE_TAP;
        return SINGLE_TAP;
    } else if (state->count == 2) {
        // ダブルタップ中の割り込みでも、押しっぱなしならDOUBLE_HOLD(Control)を優先
        if (state->pressed) return DOUBLE_HOLD;
        else return DOUBLE_TAP;
    }
    return 5;
}
static tap ztap_state;

// 各アクション実行時の処理
void z_finished(tap_dance_state_t *state, void *user_data) {
    ztap_state.state = cur_dance(state);
    switch (ztap_state.state) {
        case SINGLE_TAP: register_code(KC_Z); break;
        //case SINGLE_HOLD: register_mods(MOD_BIT(KC_LSFT)); break;
        case DOUBLE_TAP: register_code(KC_Z); register_code(KC_Z); break; // ダブルタップでzを2回出す場合
        case DOUBLE_HOLD: register_mods(MOD_BIT(KC_LCTL)); break;
    }
}

// キーを離した時の処理
void z_reset(tap_dance_state_t *state, void *user_data) {
    switch (ztap_state.state) {
        case SINGLE_TAP: unregister_code(KC_Z); break;
        //case SINGLE_HOLD: unregister_mods(MOD_BIT(KC_LSFT)); break;
        case DOUBLE_TAP: unregister_code(KC_Z); break;
        case DOUBLE_HOLD: unregister_mods(MOD_BIT(KC_LCTL)); break;
    }
    ztap_state.state = 0;
}

// Tap Danceの登録
tap_dance_action_t tap_dance_actions[] = {
    [Z_CTL_SFT] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, z_finished, z_reset)
};


enum custom_keycodes {
  CM_LEFT = SAFE_RANGE,
  CM_RGHT,
  CM_UP,
  CM_DOWN,
  CM_QFN,
  CM_NUM,
  CM_FNSC,
  CM_FUNC,
  CM_FNCM,
  CM_IME,
  CM_CAON,
  CM_ALCT,
  CM_SFTF,
  SW_LSFT,
  SW_LALT,
  SW_LCTL,
  SW_LGUI,
  SW_ATAB
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

//  [SPFN] = LAYOUT( /* Qwerty 101 uskey */
//    _______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,
//    _______,_______,_______,_______,_______,_______,_______,_______,_______,_______,
//    _______,_______,_______,_______,_______,_______,_______,_______,_______,_______,
//    _______,_______,_______,_______,_______,_______),

//US for Ubuntu(US layout keyboard setting)
//JP for Windows(jp layout keyboard setting)

  [JBASE] = LAYOUT( /* Qwerty 106 jpkey */
    CM_QFN, KC_W,   LT_EXCL,KC_R,   KC_T,   KC_Y,   KC_U,   KC_I,   KC_O,   KC_P,   LT_FUNC,
    LT_ARW1,LT_ARW2,D_ALT,  F_CTL,  G_GUI,  H_GUI,  J_CTL,  K_ALT,  KC_L,   CM_NUM,
    TD_Z,   KC_X,   KC_C,   KC_V,   KC_B,   KC_N,   KC_M,   CM_FNCM,CM_FNSC,SL_SFT,
    KC_LCTL,SP_SFT,SP_SFT, SP_SFT, SP_SFT,SP_SFT),

  [UBASE] = LAYOUT( /* Qwerty 101 uskey */
    CM_QFN, KC_W,   LT_EXCL,KC_R,   KC_T,   KC_Y,   KC_U,   KC_I,   KC_O,   KC_P,   LT_FUNC,
    LT_ARW1,LT_ARW2,D_ALT,  F_CTL,  G_GUI,  H_GUI,  J_CTL,  K_ALT,  KC_L,   CM_NUM,
    TD_Z,   KC_X,   KC_C,   KC_V,   KC_B,   KC_N,   KC_M,   CM_FNCM,CM_FNSC,SL_SFT,
    KC_LCTL,SP_SFT,SP_SFT, SP_SFT, SP_SFT,SP_SFT),

  [NUM] = LAYOUT( /* Qwerty 101 uskey */
    _______,KC_7,   KC_8,   KC_9,   _______,_______,_______,_______,DF_JBAS,DF_UBAS,QK_BOOT,
    KC_SLSH,KC_4,   KC_5,   KC_6,   KC_DOT ,_______,KC_MINS,CM_IME ,CM_CAON,_______,
    KC_0,   KC_1,   KC_2,   KC_3,   _______,_______,_______,SW_LSFT,_______,_______,
    _______,_______,_______,_______,_______,_______),

  [ARW1] = LAYOUT( /* Qwerty 101 uskey */
    _______,_______,_______,_______,_______,CM_STAB,KC_HOME,KC_UP,  KC_END, KC_TAB,_______,
    _______,_______,_______,_______,_______,KC_BSPC,KC_LEFT,KC_DOWN,KC_RGHT,KC_ENT,
    _______,_______,_______,_______,_______,_______,_______,_______,_______,_______,
    _______,_______,KC_LSFT,KC_LSFT,_______,_______),

  [ARW2] = LAYOUT( /* Qwerty 101 uskey */
    _______,_______,_______,_______,_______,_______,_______,CM_UP,  _______,_______,_______,
    _______,_______,_______,_______,_______,_______,CM_LEFT,CM_DOWN,CM_RGHT,_______,
    _______,_______,_______,_______,_______,_______,_______,_______,_______,_______,
    _______,_______,_______,_______,_______,_______),

  [EXCL] = LAYOUT( /* Qwerty 101 uskey */
    _______,_______,_______,_______,_______,_______,CM_CHOM,KC_PGUP,CM_CEND,_______,_______,
    _______,_______,_______,_______,_______,_______,CM_CPGU,KC_PGDN,CM_CPGD,_______,
    _______,_______,_______,_______,_______,_______,_______,_______,_______,_______,
    _______,_______,_______,_______,_______,_______),

  [JSYM] = LAYOUT(
    JP_EXLM,JP_AT,  JP_HASH,JP_DLR, JP_PERC,_______,_______,_______,_______,_______,_______,
    JP_UNDS,JP_PLUS,JP_EQL ,JP_ASTR,JP_CIRC,_______,_______,_______,_______,_______,
    JP_BSLS,JP_AMPR,JP_PIPE,JP_TILD,JP_GRV, _______,_______,_______,_______,_______,
    _______,_______,_______,_______,_______,_______),

  [USYM] = LAYOUT( /* Qwerty 101 uskey */
    KC_EXLM,KC_AT,  KC_HASH,KC_DLR, KC_PERC,_______,_______,_______,_______,_______,_______,
    KC_UNDS,KC_PLUS,KC_EQL, KC_ASTR,KC_CIRC,_______,_______,_______,_______,_______,
    KC_BSLS,KC_AMPR,KC_PIPE,KC_TILD,KC_GRV, _______,_______,_______,_______,_______,
    _______,_______,_______,_______,_______,_______),

  [JSYM2] = LAYOUT(
    _______,JP_LPRN,JP_RPRN,JP_LBRC,JP_RBRC,_______,_______,_______,_______,_______,_______,
    JP_QUOT,JP_DQUO,JP_MINS,JP_LCBR,JP_RCBR,CM_SF10,_______,_______,_______,_______,
    JP_QUES,JP_COLN,JP_LABK,JP_RABK,JP_SCLN,_______,_______,_______,_______,_______,
    _______,_______,_______,_______,_______,_______),

  [USYM2] = LAYOUT( /* Qwerty 101 uskey */
    _______,KC_LPRN,KC_RPRN,KC_LBRC,KC_RBRC,_______,_______,_______,_______,_______,_______,
    KC_QUOT,KC_DQUO,KC_MINS,KC_LCBR,KC_RCBR,CM_SF10,_______,_______,_______,_______,
    KC_QUES,KC_COLN,KC_LABK,KC_RABK,KC_SCLN,_______,_______,_______,_______,_______,
    _______,_______,_______,_______,_______,_______),

  [JQFN] = LAYOUT( /* Qwerty 101 uskey */
    _______,CM_ALT4,KC_ESC, SW_ATAB,CM_WSCS,_______,_______,_______,_______,_______,_______,
    _______,_______,_______,CM_ALCT,KC_DEL, _______,_______,_______,_______,_______,
    _______,_______,_______,_______,_______,_______,_______,_______,_______,_______,
    _______,_______,_______,_______,_______,_______),
  [UQFN] = LAYOUT( /* Qwerty 101 uskey */
    _______,CM_ALT4,KC_ESC, SW_ATAB,CM_WSCS,_______,_______,_______,_______,_______,_______,
    _______,_______,_______,CM_ALCT,KC_DEL, _______,_______,_______,_______,_______,
    _______,_______,_______,_______,_______,_______,_______,_______,_______,_______,
    _______,_______,_______,_______,_______,_______),

  [FUNC] = LAYOUT( /* Qwerty 101 uskey */
    KC_F1,  KC_F2,  KC_F3,  KC_F4,  KC_F5  ,KC_F6,  KC_F7,  KC_F8,  KC_F9,  KC_F10,_______,
    KC_F11, KC_F12 ,_______,_______,_______,_______,_______,_______,_______,_______,
    _______,_______,_______,_______,_______,_______,_______,_______,_______,_______,
    _______,_______,_______,_______,_______,_______),

  [ALTTAB] = LAYOUT( /* Qwerty 101 uskey */
    _______,_______,_______,KC_TAB, _______,_______,_______,KC_UP,  _______,_______,_______,
    _______,_______,_______,CM_STAB,_______,_______,KC_LEFT,KC_DOWN,KC_RGHT,_______,
    _______,_______,_______,_______,_______,_______,_______,_______,_______,_______,
    _______,_______,_______,_______,_______,_______),

};

  //[JSYM3] = LAYOUT(
  //  JP_EXLM,JP_AT,  JP_HASH,JP_DLR, JP_PERC,_______,JP_SCLN,JP_LPRN,JP_RPRN,JP_MINS,_______,
  //  JP_UNDS,JP_PLUS,JP_EQL, JP_ASTR,JP_CIRC,JP_LCBR,JP_RCBR,JP_LBRC,JP_RBRC,JP_COLN,
  //  JP_BSLS,JP_AMPR,JP_PIPE,JP_TILD,JP_GRV, JP_QUOT,JP_DQUO,JP_LABK,JP_RABK,JP_QUES,
  //  _______,_______,_______,_______,_______,_______),

  //[JSPFN] = LAYOUT( /* Qwerty 101 uskey */
  //  CM_ALCT,CM_ALT4,LT_EXCL,SW_ATAB,CM_WSCS,CM_STAB,KC_HOME,KC_UP,  KC_END, KC_TAB, _______,
  //  KC_LALT,KC_LSFT,KC_DEL, MO_HYPS,KC_LGUI,KC_BSPC,KC_LEFT,KC_DOWN,KC_RGHT,KC_ENT,
  //  KC_1   ,KC_2   ,KC_3   ,KC_4   ,KC_5   ,KC_6   ,KC_7   ,KC_8   ,KC_9   ,KC_0  ,
  //  _______,_______,_______,_______,_______,_______),

  //[USPFN] = LAYOUT( /* Qwerty 101 uskey */
  //  CM_ALCT,CM_ALT4,LT_EXCL,SW_ATAB,CM_WSCS,CM_STAB,KC_HOME,KC_UP,  KC_END, KC_TAB, _______,
  //  KC_LALT,KC_LSFT,KC_DEL, MO_HYPS,KC_LGUI,KC_BSPC,KC_LEFT,KC_DOWN,KC_RGHT,KC_ENT,
  //  KC_1   ,KC_2   ,KC_3   ,KC_4   ,KC_5   ,KC_6   ,KC_7   ,KC_8   ,KC_9   ,KC_0  ,
  //  _______,_______,_______,_______,_______,_______),

//  [HHKB] = LAYOUT(
//    KC_PWR, KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_F6, KC_F7, KC_F8, KC_F9, KC_F10, KC_F11, KC_F12, KC_INS, KC_DEL,
//    KC_CAPS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_PSCR, KC_SCRL, KC_PAUS, KC_UP, KC_TRNS, KC_BSPC,
//    KC_TRNS, KC_VOLD, KC_VOLU, KC_MUTE, KC_TRNS, KC_TRNS, KC_PAST, KC_PSLS, KC_HOME, KC_PGUP, KC_LEFT, KC_RGHT, KC_PENT,
//    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_PPLS, KC_PMNS, KC_END, KC_PGDN, KC_DOWN, KC_TRNS, KC_TRNS,
//    KC_TRNS, KC_TRNS, KC_TRNS, DF_JBAS,DF_UBAS),

const char chordal_hold_layout[MATRIX_ROWS][MATRIX_COLS] PROGMEM =
    LAYOUT(
        'L','L','L','L','L','R','R','R','R','R','R',
        'L','L','L','L','L','R','R','R','R','R',
        'L','L','L','L','L','R','R','R','R','R',
        'L','L','*','*','R','R'
    );

uint16_t get_flow_tap_term(uint16_t keycode, keyrecord_t* record,
                           uint16_t prev_keycode) {
    if (is_flow_tap_key(keycode) && is_flow_tap_key(prev_keycode)) {
        switch (keycode) {
            case SP_SFT:
                return 0;
            case LT_ARW1:
                return FLOW_TAP_TERM - 20;
            default:
              return FLOW_TAP_TERM;  // Longer timeout otherwise.
        }
    }
    return 0;  // Disable Flow Tap.
}

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

uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        default:
            return TAPPING_TERM;
    }
}

bool get_permissive_hold(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case SP_SFT:
            return true;
        default:
            return false;
    }
}
uint16_t get_quick_tap_term(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case SP_SFT:
            return 0;
        default:
            return QUICK_TAP_TERM;
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
static bool num_pressed = false;
static uint16_t num_pressed_time = 0;

static bool spfn_pressed = false;
static uint16_t spfn_pressed_time = 0;

static bool sftf_pressed = false;
static uint16_t sftf_pressed_time = 0;

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
static void user_shift_func(keyrecord_t *record, bool *modifier_pressed, uint16_t *modifier_pressed_time, bool tapping_term_disable) {
      if (record->event.pressed) {
         *modifier_pressed_time = record->event.time;
         *modifier_pressed = true;
         register_mods(MOD_BIT(KC_LSFT));
      } else {
        unregister_mods(MOD_BIT(KC_LSFT));
        if (*modifier_pressed && (tapping_term_disable || (timer_elapsed(*modifier_pressed_time) < TAPPING_TERM))) {
           if (get_highest_layer(default_layer_state)==JBASE){
               SEND_STRING(SS_LALT("`"));
           }else{
               SEND_STRING(SS_LALT("`"));
               //VM利用時はカラビナでALTGRAVに置き換えて解釈
               //(VM利用時はカラビナでCNTLがまずcontrol->command command->controlとなる
               //　つぎにーカラビナでCommand+SPAVEであればALT+GRAVに変換）
           }
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
    if (keycode != CM_SFTF)  {sftf_pressed = false;}
    if (keycode != CM_QFN)   {spfn_pressed = false;}
    if (keycode != CM_NUM)   {num_pressed = false;}
    if (keycode != CM_FNSC)  {fnsc_pressed = false;}
    if (keycode != CM_FUNC)  {fnqu_pressed = false;}
    if (keycode != CM_FNCM)  {fncm_pressed = false;}
  }
  switch (keycode) {
    case CM_SFTF:
        user_shift_func(record,&sftf_pressed,&sftf_pressed_time,false);
      return false;
      break;
    case CM_QFN:
      if (get_highest_layer(default_layer_state)==JBASE){
        user_lt(record,JQFN,KC_Q,&spfn_pressed,&spfn_pressed_time,false,&mod_switch_keycode);
      } else {
        user_lt(record,UQFN,KC_Q,&spfn_pressed,&spfn_pressed_time,false,&mod_switch_keycode);
      }
      return false;
      break;
    case CM_NUM:
      if (get_highest_layer(default_layer_state)==JBASE){
        user_lt(record,NUM,KC_ENT,&num_pressed,&num_pressed_time,false,&mod_switch_keycode);
      } else {
        user_lt(record,NUM,KC_ENT,&num_pressed,&num_pressed_time,false,&mod_switch_keycode);
      }
      return false;
      break;
    case CM_FUNC:
      if (get_highest_layer(default_layer_state)==JBASE){
        user_lt(record,FUNC,KC_MINS,&fnqu_pressed,&fnqu_pressed_time,false,&mod_switch_keycode);
      } else {
        user_lt(record,FUNC,KC_MINS,&fnqu_pressed,&fnqu_pressed_time,false,&mod_switch_keycode);
      }
      return false;
      break;
    case CM_FNSC:
      if (get_highest_layer(default_layer_state)==JBASE){
        user_lt(record,JSYM2,KC_DOT,&fnsc_pressed,&fnsc_pressed_time,false,&mod_switch_keycode);
      } else {
        user_lt(record,USYM2,KC_DOT,&fnsc_pressed,&fnsc_pressed_time,false,&mod_switch_keycode);
      }
      return false;
      break;
    case CM_FNCM:
      if (get_highest_layer(default_layer_state)==JBASE){
        user_lt(record,JSYM,KC_COMM,&fncm_pressed,&fncm_pressed_time,false,&mod_switch_keycode);
      } else {
        user_lt(record,USYM,KC_COMM,&fncm_pressed,&fncm_pressed_time,false,&mod_switch_keycode);
      }
      return false;
      break;
    case CM_IME:
      if(record->event.pressed){
          if (host_keyboard_led_state().caps_lock) {
              //then caps on の時caps off
            SEND_STRING(SS_DOWN(X_LSFT));
            SEND_STRING(SS_TAP(X_CAPS));
            SEND_STRING(SS_UP(X_LSFT));
          }
          SEND_STRING(SS_LALT("`"));
      }
      return false;
      break;
    case CM_CAON:
      if(record->event.pressed){
          if (!host_keyboard_led_state().caps_lock) {
              //then caps off の時caps on
            SEND_STRING(SS_DOWN(X_LSFT));
            SEND_STRING(SS_TAP(X_CAPS));
            SEND_STRING(SS_UP(X_LSFT));
          }
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
        sftf_pressed = false;
        spfn_pressed = false;
        num_pressed = false;
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
