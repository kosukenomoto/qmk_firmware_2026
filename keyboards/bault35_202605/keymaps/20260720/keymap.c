//./util/docker_build.sh bault35_202601:20260720/
/*  -*-  eval: (turn-on-orgtbl); -*-
 * default HHKB Layout
 */
#include QMK_KEYBOARD_H

#include "keymap_jp.h"

#define JBASE   0
#define JQFN    1
#define ARW2    2
#define EXCL    3
#define SYM     4
#define JSYM    5
#define JSYM2   6
#define FUNC    7
#define ALTTAB  8

//windows app利用時のmodキーの取りこぼしに対処するウェイトms
#define DELAY_KEY_MS 60

#define A_ALT   LALT_T(KC_A)
#define L_ALT   RALT_T(KC_L)
#define G_GUI   LGUI_T(KC_G)
#define Z_SFT   LSFT_T(KC_Z)
#define LT_ARW2 LT(ARW2,KC_ENT)
#define MO_EXCL MO(EXCL)

#define CM_SF10 S(KC_F10)
#define CM_WSCS G(S(KC_S))
#define CM_STAB S(KC_TAB)

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
  CM_ALCT,
  TS_LSFT,
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

  [JBASE] = LAYOUT( /* Qwerty 106 jpkey */
    KC_Q,   KC_W,   KC_E,   KC_R,   KC_T,   KC_Y,   KC_U,   KC_I,   KC_O,   KC_P,   CM_FUNC,
    A_ALT,  KC_S,   KC_D,   KC_F,   G_GUI,  KC_H,   KC_J,   KC_K,   L_ALT,  CM_NUM,
    Z_SFT,  KC_X,   KC_C,   KC_V,   KC_B,   KC_N,   KC_M,   CM_FNCM,CM_FNSC,KC_LSFT,
    _______,KC_LCTL,_______,CM_QFN, _______,_______,KC_LCTL,_______),

  [JQFN] = LAYOUT( /* Qwerty 101 uskey */
    CM_ALCT,M_ALTF4,KC_ESC, MO_EXCL,SW_ATAB,CM_STAB,KC_HOME,KC_UP,  KC_END, KC_TAB,KC_F2,
    KC_LALT,TS_LSFT,KC_DEL, LT_ARW2,KC_LGUI,KC_BSPC,KC_LEFT,KC_DOWN,KC_RGHT,KC_ENT,
    KC_1,   KC_2,   KC_3,   KC_4,   KC_5,   KC_6,   KC_7,   KC_8,   KC_9,   KC_0,
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

enum combos {
  CB_SPC_Q,
  CB_SPC_E,
  CB_SPC_X,
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
const uint16_t PROGMEM cb_spc_e_combo[]   =  {CM_QFN,  KC_E,    COMBO_END};
const uint16_t PROGMEM cb_spc_x_combo[]   =  {CM_QFN,  KC_X,    COMBO_END};

const uint16_t PROGMEM cb_sd_combo[] =  {KC_S,  KC_D, COMBO_END};

const uint16_t PROGMEM cb_fd_combo[] =  {KC_F, KC_D, COMBO_END};
const uint16_t PROGMEM cb_kl_combo[] =  {KC_K, L_ALT,  COMBO_END};

const uint16_t PROGMEM cb_qw_combo[] =  {KC_Q,  KC_W,  COMBO_END};
const uint16_t PROGMEM cb_spc_a_combo[]   =  {CM_QFN,  KC_A,    COMBO_END};
const uint16_t PROGMEM cb_spc_ent_combo[] =  {CM_QFN,  CM_NUM,  COMBO_END};
const uint16_t PROGMEM cb_l_ent_combo[]   =  {L_ALT,    CM_NUM,  COMBO_END};
const uint16_t PROGMEM cb_as_combo[] =       {KC_A,    KC_S,  COMBO_END};

combo_t key_combos[] = {
  [CB_SPC_Q] =   COMBO(cb_spc_q_combo,   G(KC_E)),
  [CB_SPC_E] =   COMBO(cb_spc_e_combo,   KC_ESC),
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
            *mod_switch_keycode = 0;
            layer_clear();
        }
        layer_off(layer);
        if (*modifier_pressed && (tapping_term_disable || (timer_elapsed(*modifier_pressed_time) < TAPPING_TERM))) {
            register_code(keycode);
            unregister_code(keycode);
        }
    *modifier_pressed = false;
    }
}
//ctl+home ctl+end ctl+pgup ctl+pgdn
static void ctrl_keypress(keyrecord_t *record,uint16_t keycode){
      if (record->event.pressed) {
         register_code(KC_LCTL);
         wait_ms(DELAY_KEY_MS);
         register_code(keycode);
      } else {
         unregister_code(keycode);
         unregister_code(KC_LCTL);
      }
}

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

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  if (record->event.pressed) {
    // reset the user_lt & user_tt flags
    if (keycode != TS_LSFT)  {sftf_pressed = false;}
    if (keycode != CM_QFN)   {spfn_pressed = false;}
    if (keycode != CM_NUM)   {num_pressed = false;}
    if (keycode != CM_FNSC)  {fnsc_pressed = false;}
    if (keycode != CM_FUNC)  {fnqu_pressed = false;}
    if (keycode != CM_FNCM)  {fncm_pressed = false;}
  }
  switch (keycode) {
    case TS_LSFT:
      tap_hold_modkey_func(record,&sftf_pressed,&sftf_pressed_time,false,KC_LSFT,&mod_switch_keycode,0);
      return false;
    case CM_QFN:
      user_lt(record,JQFN,KC_SPC,&spfn_pressed,&spfn_pressed_time,false,&mod_switch_keycode);
      return false;
    case CM_NUM:
      user_lt_hnzn(record,JSYM2,&num_pressed,&num_pressed_time,false,&mod_switch_keycode);
      return false;
    case CM_FUNC:
      user_lt(record,FUNC,KC_MINS,&fnqu_pressed,&fnqu_pressed_time,false,&mod_switch_keycode);
      return false;
    case CM_FNSC:
      user_lt(record,JSYM,KC_DOT,&fnsc_pressed,&fnsc_pressed_time,false,&mod_switch_keycode);
      return false;
    case CM_FNCM:
      user_lt(record,JSYM2,KC_COMM,&fncm_pressed,&fncm_pressed_time,false,&mod_switch_keycode);
      return false;
    case M_ALTF4:
      if (record->event.pressed) {
         register_code(KC_LALT);
         wait_ms(DELAY_KEY_MS);
         register_code(KC_F4);
      } else {
         unregister_code(KC_F4);
         unregister_code(KC_LALT);
      }
      return false; // QMKにこれ以上の処理をさせない
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
      if(record->event.pressed){
        tap_code(KC_LEFT);
        tap_code(KC_LEFT);
        tap_code(KC_LEFT);
        tap_code(KC_LEFT);
      }
      break;
    case CM_RGHT:
      if(record->event.pressed){
        tap_code(KC_RGHT);
        tap_code(KC_RGHT);
        tap_code(KC_RGHT);
        tap_code(KC_RGHT);
      }
      break;
    case CM_UP:
      if(record->event.pressed){
        tap_code(KC_UP);
        tap_code(KC_UP);
        tap_code(KC_UP);
        tap_code(KC_UP);
      }
      break;
    case CM_DOWN:
      if(record->event.pressed){
        tap_code(KC_DOWN);
        tap_code(KC_DOWN);
        tap_code(KC_DOWN);
        tap_code(KC_DOWN);
      }
      break;

    //jp106 key layout code remotedesktop shiftkey s(KC_HOO)でシフトキー取りこぼすため以下対応
    //以下はシフト考慮不要のためjp defineをそのまま利用可能
    //JP_MINS JP_CIRC JP_YEN JP_AT JP_LBRC JP_EISU JP_SCLN JP_COLN JP_RBRC
    //JP_DOT JP_COMM JP_SLSH JP_BSLS JP_MHEN JP_HENK JP_KANA
    case MC_EXLM:
      shift_keypress(record, KC_1);
      return false;
    case MC_DQUO:
      shift_keypress(record, KC_2);
      return false;
    case MC_HASH:
      shift_keypress(record, KC_3);
      return false;
    case MC_DLR:
      shift_keypress(record, KC_4);
      return false;
    case MC_PERC:
      shift_keypress(record, KC_5);
      return false;
    case MC_AMPR:
      shift_keypress(record, KC_6);
      return false;
    case MC_QUOT:
      shift_keypress(record, KC_7);
      return false;
    case MC_LPRN:
      shift_keypress(record, KC_8);
      return false;
    case MC_RPRN:
      shift_keypress(record, KC_9);
      return false;
    case MC_EQL:
      shift_keypress(record, KC_MINS);
      return false;
    case MC_TILD:
      shift_keypress(record, KC_EQL);
      return false;
    case MC_PIPE:
      shift_keypress(record, KC_INT3);
      return false;
    case MC_GRV:
      shift_keypress(record, KC_LBRC);
      return false;
    case MC_LCBR:
      shift_keypress(record, KC_RBRC);
      return false;
    case MC_PLUS:
      shift_keypress(record, KC_SCLN);
      return false;
    case MC_ASTR:
      shift_keypress(record, KC_QUOT);
      return false;
    case MC_RCBR:
      shift_keypress(record, KC_NUHS);
      return false;
    case MC_LABK:
      shift_keypress(record, KC_COMM);
      return false;
    case MC_RABK:
      shift_keypress(record, KC_DOT);
      return false;
    case MC_QUES:
      shift_keypress(record, KC_SLSH);
      return false;
    case MC_UNDS:
      shift_keypress(record, KC_INT1);
      return false;
    case CTLPGDN:
      ctrl_keypress(record, KC_PGDN);
      return false;
    case CTLPGUP:
      ctrl_keypress(record, KC_PGUP);
      return false;
    case CTLHOME:
      ctrl_keypress(record, KC_HOME);
      return false;
    case CTLEND:
      ctrl_keypress(record, KC_END);
      return false;
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

    return true;
}
