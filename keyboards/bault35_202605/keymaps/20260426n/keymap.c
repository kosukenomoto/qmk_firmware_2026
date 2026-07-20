//./util/docker_build.sh bault35_202601:20260201/
/*  -*-  eval: (turn-on-orgtbl); -*-
 * default HHKB Layout
 */
#include QMK_KEYBOARD_H

#include "keymap_jp.h"

#define JBASE   0
#define UBASE   1
#define JQFN    2
#define UQFN    3
#define NUM     4
#define ARW1    5
#define ARW2    6
#define EXCL    7
#define SYM     8
#define JSYM    9
#define USYM    10
#define JSYM2   11
#define USYM2   12
#define FUNC    13
#define ALTTAB  14

//windows app利用時のmodキーの取りこぼしに対処するウェイトms
#define DELAY_KEY_MS 60

//#define JSPFN   99
//#define USPFN   98

#define SP_SFT  LSFT_T(KC_SPC)
#define ET_SFT  LSFT_T(KC_ENT)
#define SL_SFT  SFT_T(KC_SLSH)
#define DO_SFT  SFT_T(KC_DOT)
#define Z_SFT   LSFT_T(KC_Z)
#define F_CTL   LCTL_T(KC_F)
#define J_CTL   RCTL_T(KC_J)
#define A_ALT   LALT_T(KC_A)
#define D_ALT   LALT_T(KC_D)
#define K_ALT   RALT_T(KC_K)
#define L_ALT   RALT_T(KC_L)
#define G_GUI   LGUI_T(KC_G)
#define H_GUI   RGUI_T(KC_H)
#define LT_ARW2 LT(ARW2,KC_ENT)
#define LT_EXCL LT(EXCL,KC_ESC)
#define LT_NUM  LT(NUM,KC_DOT)
#define LT_FUNC LT(FUNC,KC_BSPC)
#define MO_EXCL MO(EXCL)
#define MO_SYM MO(SYM)
#define MO_JSM MO(JSYM)
#define MO_USM MO(USYM)
#define MO_JSM2 MO(JSYM2)
#define MO_USM2 MO(USYM2)
#define MO_NUM  MO(NUM)
#define LM_NUM  LM(NUM,MOD_LSFT)

//#define KC_MSDN    KC_MS_DOWN
//#define KC_MSUP    KC_MS_UP
//#define KC_MSLF    KC_MS_LEFT
//#define KC_MSRT    KC_MS_RIGHT
//#define LT_EXCL LT(EXCL,KC_ESC)
//#define J_JSYM  LT(JSYM3,KC_J)
//#define F_JSYM  LT(JSYM3,KC_F)
#define MO_HYPS MO(HYPE)
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
  TS_LCTL,
  TS_RSFT,
  TS_LSFT,
  SW_LSFT,
  SW_LALT,
  SW_LCTL,
  SW_LGUI,
  SW_ATAB,
  M_ALTF4,
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
  MC_CAPS,
  MC_PLUS,
  MC_ASTR,
  MC_RCBR,
  MC_LABK,
  MC_RABK,
  MC_QUES,
  MC_UNDS,
  CTLPGDN,
  CTLPGUP,
  CTLHOME,
  CTLEND,
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
    KC_Q,   KC_W,   KC_E,   KC_R,   KC_T,   KC_Y,   KC_U,   KC_I,   KC_O,   KC_P,   CM_FUNC,
    A_ALT,  KC_S,   KC_D,   KC_F,   G_GUI,  KC_H,   KC_J,   KC_K,   L_ALT,  CM_NUM,
    Z_SFT,  KC_X,   KC_C,   KC_V,   KC_B,   KC_N,   KC_M,   CM_FNCM,CM_FNSC,KC_LSFT,
    _______,KC_LCTL,_______,CM_QFN, _______,_______,KC_LCTL,_______),
//    TS_LCTL,KC_LCTL,TS_RSFT,CM_QFN, LM_NUM, CM_QFN),

  [UBASE] = LAYOUT( /* Qwerty 101 uskey */
    KC_Q,   KC_W,   KC_E,   KC_R,   KC_T,   KC_Y,   KC_U,   KC_I,   KC_O,   KC_P,   CM_FUNC,
    A_ALT,  KC_S,   KC_D,   KC_F,   G_GUI,  KC_H,   KC_J,   KC_K,   L_ALT,  CM_NUM,
    Z_SFT,  KC_X,   KC_C,   KC_V,   KC_B,   KC_N,   KC_M,   CM_FNCM,CM_FNSC,SL_SFT,
    _______,KC_LCTL,_______,CM_QFN, _______,_______,KC_LCTL,_______),

  [JQFN] = LAYOUT( /* Qwerty 101 uskey */
    CM_ALCT,M_ALTF4,KC_ESC, MO_EXCL,SW_ATAB,CM_STAB,KC_HOME,KC_UP,  KC_END, KC_TAB,KC_F2,
    KC_LALT,TS_LSFT,KC_DEL, LT_ARW2,KC_LGUI,KC_BSPC,KC_LEFT,KC_DOWN,KC_RGHT,KC_ENT,
    KC_1,   KC_2,   KC_3,   KC_4,   KC_5,   KC_6,   KC_7,   KC_8,   KC_9,   KC_0,
    _______,_______,_______,_______,_______,_______,_______,_______),

  [UQFN] = LAYOUT( /* Qwerty 101 uskey */
    CM_GUIE,M_ALTF4,KC_ESC, _______,_______,CM_STAB,KC_HOME,KC_UP,  KC_END, KC_TAB,KC_F2,
    KC_LALT,TS_LSFT,KC_DEL, LT_ARW2,KC_LGUI,KC_BSPC,KC_LEFT,KC_DOWN,KC_RGHT,KC_ENT,
    TS_LSFT,CM_ALCT,SW_ATAB,MS_BTN1,CM_SF10,_______,KC_HOME,KC_PGUP,KC_PGDN,KC_END,
    _______,_______,_______,_______,_______,_______,_______,_______),

  [NUM] = LAYOUT( /* Qwerty 101 uskey */
    _______,KC_7,   KC_8,   KC_9,   _______,_______,_______,_______,_______,_______,QK_BOOT,
    _______,KC_4,   KC_5,   KC_6,   KC_MINS,_______,_______,_______,_______,_______,
    KC_0,   KC_1,   KC_2,   KC_3,   _______,_______,_______,_______,_______,_______,
    _______,_______,_______,_______,_______,_______,_______,_______),

  [ARW1] = LAYOUT( /* Qwerty 101 uskey */
    _______,_______,_______,_______,_______,CM_STAB,KC_HOME,KC_UP,  KC_ENT, KC_TAB,_______,
    _______,_______,_______,_______,_______,KC_BSPC,KC_LEFT,KC_DOWN,KC_RGHT,_______,
    _______,_______,_______,_______,_______,_______,_______,_______,_______,_______,
    _______,_______,_______,_______,_______,_______,_______,_______),

  [ARW2] = LAYOUT( /* Qwerty 101 uskey */
    _______,_______,_______,_______,_______,_______,_______,CM_UP,  _______,_______,_______,
    _______,_______,_______,_______,_______,_______,CM_LEFT,CM_DOWN,CM_RGHT,_______,
    _______,_______,_______,_______,_______,_______,_______,_______,_______,_______,
    _______,_______,_______,_______,_______,_______,_______,_______),

  [EXCL] = LAYOUT( /* Qwerty 101 uskey */
    _______,_______,CM_WSCS,_______,_______,_______,CTLHOME,KC_PGUP,CTLEND, _______,_______,
    _______,_______,_______,_______,_______,_______,CTLPGUP,KC_PGDN,CTLPGDN,_______,
    _______,_______,_______,_______,_______,_______,_______,_______,_______,_______,
    _______,_______,_______,_______,_______,_______,_______,_______),

  [SYM] = LAYOUT( /* Qwerty 101 uskey */
    MC_EXLM,JP_AT,  MC_HASH,MC_DLR, MC_PERC,_______,_______,JP_LBRC,JP_RBRC,JP_SCLN,_______,
    MC_UNDS,MC_PLUS,MC_EQL, MC_ASTR,JP_CIRC,MC_LCBR,MC_RCBR,MC_LPRN,MC_RPRN,JP_COLN,
    JP_BSLS,MC_AMPR,MC_PIPE,MC_TILD,MC_GRV, MC_QUOT,MC_DQUO,MC_LABK,MC_RABK,MC_QUES,
    _______,_______,_______,_______,_______,_______,_______,_______),

  [JSYM] = LAYOUT( /* Qwerty 101 uskey */
    MC_EXLM,JP_AT,  MC_HASH,MC_DLR, MC_PERC,_______,_______,_______,_______,_______,_______,
    MC_UNDS,MC_PLUS,MC_EQL, MC_ASTR,JP_CIRC,_______,_______,_______,_______,_______,
    JP_BSLS,MC_AMPR,MC_PIPE,MC_TILD,MC_GRV, _______,_______,CM_IME, _______,_______,
    _______,_______,_______,_______,_______,_______,_______,_______),

  [JSYM2] = LAYOUT( /* Qwerty 101 uskey */
    MC_LABK,MC_RABK,JP_LBRC,JP_RBRC,MC_LCBR,_______,_______,_______,_______,_______,QK_BOOT,
    MC_QUOT,MC_DQUO,MC_LPRN,MC_RPRN,MC_RCBR,_______,CM_SF10,_______,_______,_______,
    MC_QUES,KC_SLSH,JP_COLN,JP_SCLN,_______,_______,_______,_______,_______,_______,
    _______,_______,_______,_______,_______,_______,_______,_______),

//  [JSYM2] = LAYOUT( /* Qwerty 101 uskey */
//    MC_DQUO,MC_LABK,MC_LPRN,JP_LBRC,MC_LCBR,_______,_______,_______,_______,_______,QK_BOOT,
//    MC_QUOT,MC_RABK,MC_RPRN,JP_RBRC,MC_RCBR,_______,CM_SF10,_______,_______,_______,
//    MC_QUES,KC_SLSH,JP_COLN,JP_SCLN,_______,_______,_______,_______,_______,_______,
//    _______,_______,_______,_______,_______,_______,_______,_______),

//  [JSYM2] = LAYOUT( /* Qwerty 101 uskey */
//    MC_LCBR,MC_RCBR,JP_LBRC,JP_RBRC,_______,_______,_______,_______,_______,_______,_______,
//    MC_QUOT,MC_DQUO,MC_LPRN,MC_RPRN,_______,_______,_______,_______,_______,_______,
//    _______,_______,MC_LABK,MC_RABK,_______,_______,_______,_______,_______,_______,
//    _______,_______,_______,_______,_______,_______,_______,_______),

  [USYM] = LAYOUT( /* Qwerty 101 uskey */
    KC_EXLM,KC_AT,  KC_HASH,KC_DLR, KC_PERC,_______,_______,_______,_______,_______,_______,
    KC_UNDS,KC_EQL, KC_COMM,KC_ASTR,KC_CIRC,_______,_______,_______,_______,_______,
    KC_BSLS,KC_AMPR,KC_PIPE,KC_TILD,KC_GRV, _______,_______,_______,_______,_______,
    _______,_______,_______,_______,_______,_______,_______,_______),

  [USYM2] = LAYOUT( /* Qwerty 101 uskey */
    KC_COMM,KC_LPRN,KC_RPRN,KC_LBRC,KC_RBRC,_______,_______,_______,_______,_______,_______,
    KC_QUOT,KC_DQUO,KC_DOT, KC_LCBR,KC_RCBR,_______,_______,_______,_______,_______,
    KC_QUES,KC_COLN,KC_LABK,KC_RABK,KC_SCLN,_______,_______,_______,_______,_______,
    _______,_______,_______,_______,_______,_______,_______,_______),

  [FUNC] = LAYOUT( /* Qwerty 101 uskey */
    KC_F1,  KC_F2,  KC_F3,  KC_F4,  KC_F5  ,KC_F6,  KC_F7,  KC_F8,  KC_F9,  KC_F10,_______,
    KC_F11, KC_F12 ,_______,_______,_______,_______,_______,_______,_______,_______,
    _______,_______,_______,_______,_______,_______,_______,_______,_______,_______,
    _______,_______,_______,_______,_______,_______,_______,_______),

  [ALTTAB] = LAYOUT( /* Qwerty 101 uskey */
    CM_STAB,_______,_______,_______,KC_TAB ,_______,_______,KC_UP,  _______,_______,_______,
    _______,_______,_______,_______,_______,_______,KC_LEFT,KC_DOWN,KC_RGHT,_______,
    _______,_______,_______,_______,_______,_______,_______,_______,_______,_______,
    _______,_______,_______,_______,_______,_______,_______,_______),

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

enum combos {
  CB_SPC_Q,
  CB_SPC_W,
  CB_SPC_E,
  CB_SPC_S,
  CB_SPC_X,

  CB_JK,
  CB_WE,
  CB_AS,
  CB_FD,
  CB_KL,
  CB_SD,
  CB_QW,
  CB_SPC_A,
  CB_SPC_ENT,
  CB_L_ENT,
};
const uint16_t PROGMEM cb_spc_q_combo[]   =  {CM_QFN,  KC_Q,    COMBO_END};
const uint16_t PROGMEM cb_spc_w_combo[]   =  {CM_QFN,  KC_W,    COMBO_END};
const uint16_t PROGMEM cb_spc_e_combo[]   =  {CM_QFN,  KC_E,    COMBO_END};
const uint16_t PROGMEM cb_spc_s_combo[]   =  {CM_QFN,  KC_S,    COMBO_END};
const uint16_t PROGMEM cb_spc_x_combo[]   =  {CM_QFN,  KC_X,    COMBO_END};

const uint16_t PROGMEM cb_jk_combo[] =  {KC_J, KC_K, COMBO_END};
const uint16_t PROGMEM cb_we_combo[] =  {KC_W, KC_E, COMBO_END};
const uint16_t PROGMEM cb_sd_combo[] =  {KC_S,  KC_D, COMBO_END};

const uint16_t PROGMEM cb_fd_combo[] =  {KC_F, KC_D, COMBO_END};
const uint16_t PROGMEM cb_kl_combo[] =  {KC_K, L_ALT,  COMBO_END};

const uint16_t PROGMEM cb_qw_combo[] =  {KC_Q,  KC_W,  COMBO_END};
const uint16_t PROGMEM cb_spc_a_combo[]   =  {CM_QFN,  KC_A,    COMBO_END};
const uint16_t PROGMEM cb_spc_ent_combo[] =  {CM_QFN,  CM_NUM,  COMBO_END};
const uint16_t PROGMEM cb_l_ent_combo[]   =  {L_ALT,    CM_NUM,  COMBO_END};
const uint16_t PROGMEM cb_as_combo[] =       {KC_A,    KC_S,  COMBO_END};

combo_t key_combos[] = {
  // AとSが同時にホールドされている間、Left Shiftを送信
  [CB_SPC_Q] =   COMBO(cb_spc_q_combo,   G(KC_E)),
  //[CB_SPC_W] =   COMBO(cb_spc_w_combo,   M_ALTF4),
  [CB_SPC_E] =   COMBO(cb_spc_e_combo,   KC_ESC),
  //[CB_SPC_S] =   COMBO(cb_spc_s_combo,   CM_WSCS),
  [CB_SPC_X] =   COMBO(cb_spc_x_combo,   G(KC_D)),

  [CB_SD] = COMBO(cb_sd_combo, MO(SYM)),
  [CB_KL] = COMBO(cb_kl_combo, MO(SYM)),

  [CB_FD] = COMBO(cb_fd_combo, G(KC_D)),
  [CB_QW] = COMBO(cb_qw_combo, A(KC_F4)),
  [CB_SPC_A] =   COMBO(cb_spc_a_combo,   KC_LSFT),
  [CB_SPC_ENT] = COMBO(cb_spc_ent_combo, KC_RSFT),
  [CB_L_ENT] = COMBO(cb_l_ent_combo,   KC_RSFT),
  [CB_AS] =    COMBO(cb_as_combo,      KC_LSFT),
};

const char chordal_hold_layout[MATRIX_ROWS][MATRIX_COLS] PROGMEM =
    LAYOUT(
        'L','L','L','L','L','R','R','R','R','R','R',
        'L','L','L','L','L','R','R','R','R','R',
        'L','L','L','L','L','R','R','R','R','R',
        'L','L','L','*','R','R','R','R'
    );

uint16_t get_flow_tap_term(uint16_t keycode, keyrecord_t* record,
                           uint16_t prev_keycode) {
    if (is_flow_tap_key(keycode) && is_flow_tap_key(prev_keycode)) {
        switch (keycode) {
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
uint16_t get_quick_tap_term(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        default:
            return QUICK_TAP_TERM;
    }
}

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

//SPFN ============================================
static bool num_pressed = false;
static uint16_t num_pressed_time = 0;

static bool spfn_pressed = false;
static uint16_t spfn_pressed_time = 0;

static bool sftf_pressed = false;
static uint16_t sftf_pressed_time = 0;

static bool sftf2_pressed = false;
static uint16_t sftf2_pressed_time = 0;

static bool uctlf_pressed = false;
static uint16_t uctlf_pressed_time = 0;

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
//                register_code(KC_LALT);
//                wait_ms(DELAY_KEY_MS);    // ② DELAY_KEY_MS 待つ（ここでお好みのmsに調整
//                tap_code(KC_GRAVE);
//                unregister_code(KC_LALT);
//         }else{
//                register_code(KC_LALT);
//                wait_ms(DELAY_KEY_MS);    // ② DELAY_KEY_MS 待つ（ここでお好みのmsに調整
//                tap_code(KC_GRAVE);
//                unregister_code(KC_LALT);
//         }
//        }
//        *modifier_pressed = false;
//      }
//}

static void user_shft_func(keyrecord_t *record, bool *modifier_pressed, uint16_t *modifier_pressed_time, bool tapping_term_disable) {
      if (record->event.pressed) {
         *modifier_pressed_time = record->event.time;
         *modifier_pressed = true;
         register_mods(MOD_BIT(KC_RSFT));
      } else {
        unregister_mods(MOD_BIT(KC_RSFT));
        if (*modifier_pressed && (tapping_term_disable || (timer_elapsed(*modifier_pressed_time) < TAPPING_TERM))) {
           if (get_highest_layer(default_layer_state)==JBASE){
                register_code(KC_LALT);
                wait_ms(DELAY_KEY_MS);    // ② DELAY_KEY_MS 待つ（ここでお好みのmsに調整
                tap_code(KC_GRAVE);
                unregister_code(KC_LALT);
           }else{
                register_code(KC_LALT);
                wait_ms(DELAY_KEY_MS);    // ② DELAY_KEY_MS 待つ（ここでお好みのmsに調整
                tap_code(KC_GRAVE);
                unregister_code(KC_LALT);
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
static void user_ctrl_func(keyrecord_t *record, bool *modifier_pressed, uint16_t *modifier_pressed_time, bool tapping_term_disable) {
      if (record->event.pressed) {
         *modifier_pressed_time = record->event.time;
         *modifier_pressed = true;
         register_mods(MOD_BIT(KC_LCTL));
      } else {
        unregister_mods(MOD_BIT(KC_LCTL));
        if (*modifier_pressed && (tapping_term_disable || (timer_elapsed(*modifier_pressed_time) < TAPPING_TERM))) {
           if (get_highest_layer(default_layer_state)==JBASE){
               SEND_STRING(SS_LALT("`"));
           }else{
               SEND_STRING(SS_LALT("`"));
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

//tapならhold keyをMODキーに差し替える
//holdならMODキーを有効にする。
static void tap_hold_modkey_func(keyrecord_t *record, bool *modifier_pressed, uint16_t *modifier_pressed_time, bool tapping_term_disable,
                                   uint16_t mod_keycode,uint16_t *mod_switch_keycode,int layer) {
      if (record->event.pressed) {
         *modifier_pressed_time = record->event.time;
         *modifier_pressed = true;
         register_mods(MOD_BIT(mod_keycode));
      } else {
         unregister_mods(MOD_BIT(mod_keycode));
         if (*modifier_pressed && (tapping_term_disable || (timer_elapsed(*modifier_pressed_time) < TAPPING_TERM))) {
             //then tapping
             *mod_switch_keycode = mod_keycode;
             if(layer == 0){
                 layer_clear();
             }else{
                 layer_on(layer);
             }
             //set_mods(get_mods() | MOD_BIT(*mod_switch_keycode));
             register_code(*mod_switch_keycode);
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
        wait_ms(DELAY_KEY_MS);
    }
}
static void user_lt_hnzn(keyrecord_t *record,
        int layer,
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
            register_code(KC_LALT);
            wait_ms(DELAY_KEY_MS);    // ② DELAY_KEY_MS 待つ（ここでお好みのmsに調整
            tap_code(KC_GRAVE);
            unregister_code(KC_LALT);
        }
    *modifier_pressed = false;
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
//            uint8_t shift = keyboard_report->mods & (MOD_BIT(KC_LSFT) | MOD_BIT(KC_RSFT));
//            uint16_t s = 0;
//            if(shift && (get_highest_layer(default_layer_state)==JBASE)){
//                switch (keycode) {
//                    // Replace Shift-Symbols like ANSI for JIS.
//                    case JP_2:    s = JP_AT; break;
//                    case JP_6:    s = JP_CIRC; break;
//                    case JP_7:    s = JP_AMPR; break;
//                    case JP_8:    s = JP_ASTR; break;
//                    case JP_9:    s = JP_LPRN; break;
//                    case JP_0:    s = JP_RPRN; break;
//                    case JP_GRV:  s = JP_TILD; break;
//                    case JP_EQL:  s = JP_PLUS; break;
//                    case JP_MINS: s = JP_UNDS; break;
//                    case JP_SCLN: s = JP_COLN; break;
//                    case JP_BSLS: s = JP_PIPE; break;
//                    case KC_QUOT: s = JP_DQUO; break;
//                }
//            }
//            if(s!=0){
//                unregister_mods(shift);
//                tap_code16(s);
//                register_mods(shift);
//            }else{
//                if(keycode == KC_QUOT && (get_highest_layer(default_layer_state)==JBASE)){
//                    tap_code16(JP_QUOT);
//                }else{
                    register_code(keycode);
                    unregister_code(keycode);
//                }
//            }
        }
    *modifier_pressed = false;
    }
}
//ctl+home ctl+end ctl+pgup ctl+pgdn
static void ctrl_keypress(keyrecord_t *record,uint16_t keycode){
      if (record->event.pressed) {
         // コンボが成立してキーが「押された」ときの処理
         register_code(KC_LCTL);   // ① ALTを押し下げる
         wait_ms(DELAY_KEY_MS);    // ② DELAY_KEY_MS 待つ（ここでお好みのmsに調整）
         register_code(keycode);     // ③ F4を押し下げる
      } else {
         // キーが「離された」ときの処理
         unregister_code(keycode);   // ④ F4を離す
         unregister_code(KC_LCTL); // ⑤ ALTを離す
      }
}

static void shift_keypress(keyrecord_t *record,uint16_t keycode){
      if (record->event.pressed) {
         // コンボが成立してキーが「押された」ときの処理
         register_code(KC_LSFT);   // ① ALTを押し下げる
         wait_ms(DELAY_KEY_MS);    // ② DELAY_KEY_MS 待つ（ここでお好みのmsに調整）
         register_code(keycode);     // ③ F4を押し下げる
      } else {
         // キーが「離された」ときの処理
         unregister_code(keycode);   // ④ F4を離す
         unregister_code(KC_LSFT); // ⑤ ALTを離す
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
    if (keycode != TS_LCTL)  {uctlf_pressed = false;}
    if (keycode != TS_RSFT)  {sftf2_pressed = false;}
    if (keycode != TS_LSFT)  {sftf_pressed = false;}
    if (keycode != CM_QFN)   {spfn_pressed = false;}
    if (keycode != CM_NUM)   {num_pressed = false;}
    if (keycode != CM_FNSC)  {fnsc_pressed = false;}
    if (keycode != CM_FUNC)  {fnqu_pressed = false;}
    if (keycode != CM_FNCM)  {fncm_pressed = false;}
  }
  switch (keycode) {
    case TS_LCTL:
        user_ctrl_func(record,&uctlf_pressed,&uctlf_pressed_time,false);
      return false;
      break;
    case TS_RSFT:
        user_shft_func(record,&sftf2_pressed,&sftf2_pressed_time,false);
      return false;
      break;
    case TS_LSFT:
        tap_hold_modkey_func(record,&sftf_pressed,&sftf_pressed_time,false,KC_LSFT,&mod_switch_keycode,0);
      return false;
      break;
    case CM_QFN:
      if (get_highest_layer(default_layer_state)==JBASE){
        user_lt(record,JQFN,KC_SPC,&spfn_pressed,&spfn_pressed_time,false,&mod_switch_keycode);
      } else {
        user_lt(record,UQFN,KC_SPC,&spfn_pressed,&spfn_pressed_time,false,&mod_switch_keycode);
      }
      return false;
      break;
    case CM_NUM:
      if (get_highest_layer(default_layer_state)==JBASE){
        user_lt_hnzn(record,JSYM2,&num_pressed,&num_pressed_time,false,&mod_switch_keycode);
      } else {
        user_lt_hnzn(record,JSYM2,&num_pressed,&num_pressed_time,false,&mod_switch_keycode);
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
         user_lt(record,JSYM,KC_DOT,&fnsc_pressed,&fnsc_pressed_time,false,&mod_switch_keycode);
     //    mod_layer_switch(record,KC_LSFT,&mod_switch_keycode,0);
     //    user_lt(record,NUM,KC_DOT,&fnsc_pressed,&fnsc_pressed_time,false,&mod_switch_keycode);
      } else {
         user_lt(record,NUM,KC_DOT,&fnsc_pressed,&fnsc_pressed_time,false,&mod_switch_keycode);
      //   user_lt(record,USYM2,KC_DOT,&fnsc_pressed,&fnsc_pressed_time,false,&mod_switch_keycode);
      }
      return false;
      break;
    case CM_FNCM:
      if (get_highest_layer(default_layer_state)==JBASE){
        user_lt(record,JSYM2,KC_COMM,&fncm_pressed,&fncm_pressed_time,false,&mod_switch_keycode);
      } else {
        user_lt(record,SYM,KC_COMM,&fncm_pressed,&fncm_pressed_time,false,&mod_switch_keycode);
      }
      return false;
      break;
    case M_ALTF4:
      if (record->event.pressed) {
         // コンボが成立してキーが「押された」ときの処理
         register_code(KC_LALT);   // ① ALTを押し下げる
         wait_ms(DELAY_KEY_MS);    // ② DELAY_KEY_MS 待つ（ここでお好みのmsに調整）
         register_code(KC_F4);     // ③ F4を押し下げる
      } else {
         // キーが「離された」ときの処理
         unregister_code(KC_F4);   // ④ F4を離す
         unregister_code(KC_LALT); // ⑤ ALTを離す
      }
      return false; // QMKにこれ以上の処理をさせない
      break;
    case CM_IME:
      if(record->event.pressed){
          if (host_keyboard_led_state().caps_lock) {
              //then caps on の時caps off
            SEND_STRING(SS_DOWN(X_LSFT));
            SEND_STRING(SS_TAP(X_CAPS));
            SEND_STRING(SS_UP(X_LSFT));
          }
          SEND_STRING(SS_DOWN(X_LALT) SS_DELAY(DELAY_KEY_MS) SS_TAP(X_GRAVE) SS_UP(X_LALT));
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

    //jp106 key layout code remotedesktop shiftkey s(KC_HOO)でシフトキー取りこぼすため以下対応
    //以下はシフト考慮不要のためjp defineをそのまま利用可能
    //JP_MINS
    //JP_CIRC
    //JP_YEN
    //JP_AT
    //JP_LBRC
    //JP_EISU
    //JP_SCLN
    //JP_COLN
    //JP_RBRC
    //JP_DOT
    //JP_COMM
    //JP_SLSH
    //JP_BSLS
    //JP_MHEN
    //JP_HENK
    //JP_KANA
    case MC_EXLM:
      shift_keypress(record, KC_1);
      return false;
      break;
    case MC_DQUO:
      shift_keypress(record, KC_2);
      return false;
      break;
    case MC_HASH:
      shift_keypress(record, KC_3);
      return false;
      break;
    case MC_DLR:
      shift_keypress(record, KC_4);
      return false;
      break;
    case MC_PERC:
      shift_keypress(record, KC_5);
      return false;
      break;
    case MC_AMPR:
      shift_keypress(record, KC_6);
      return false;
      break;
    case MC_QUOT:
      shift_keypress(record, KC_7);
      return false;
      break;
    case MC_LPRN:
      shift_keypress(record, KC_8);
      return false;
      break;
    case MC_RPRN:
      shift_keypress(record, KC_9);
      return false;
      break;
    case MC_EQL:
      shift_keypress(record, KC_MINS);
      return false;
      break;
    case MC_TILD:
      shift_keypress(record, KC_EQL);
      return false;
      break;
    case MC_PIPE:
      shift_keypress(record, KC_INT3);
      return false;
      break;
    case MC_GRV:
      shift_keypress(record, KC_LBRC);
      return false;
      break;
    case MC_LCBR:
      shift_keypress(record, KC_RBRC);
      return false;
      break;
    case MC_CAPS:
      shift_keypress(record, KC_CAPS);
      return false;
      break;
    case MC_PLUS:
      shift_keypress(record, KC_SCLN);
      return false;
      break;
    case MC_ASTR:
      shift_keypress(record, KC_QUOT);
      return false;
      break;
    case MC_RCBR:
      shift_keypress(record, KC_NUHS);
      return false;
      break;
    case MC_LABK:
      shift_keypress(record, KC_COMM);
      return false;
      break;
    case MC_RABK:
      shift_keypress(record, KC_DOT);
      return false;
      break;
    case MC_QUES:
      shift_keypress(record, KC_SLSH);
      return false;
      break;
    case MC_UNDS:
      shift_keypress(record, KC_INT1);
      return false;
      break;
    case CTLPGDN:
      ctrl_keypress(record, KC_PGDN);
      return false;
      break;
    case CTLPGUP:
      ctrl_keypress(record, KC_PGUP);
      return false;
      break;
    case CTLHOME:
      ctrl_keypress(record, KC_HOME);
      return false;
      break;
    case CTLEND:
      ctrl_keypress(record, KC_END);
      return false;
      break;
    default:
      if (record->event.pressed) {
        // reset the flag
        uctlf_pressed = false;
        sftf_pressed = false;
        sftf2_pressed = false;
        spfn_pressed = false;
        num_pressed = false;
        fnqu_pressed = false;
        fnsc_pressed = false;
        fncm_pressed = false;
      }
      break;
    }

//    switch (get_highest_layer(default_layer_state)){
//        case JBASE:
//            return process_jp_symbols(keycode,record);
//            break;
//        default:
//            break;
//    }

    return true;
}
