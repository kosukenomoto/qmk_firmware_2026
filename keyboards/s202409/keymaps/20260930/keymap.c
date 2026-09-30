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
#define ARW1    5
#define ARW2    6
#define EXCL    7
#define SYM     8
#define JSYM    9
#define USYM    10
#define JSYM2   11
#define USYM2   12
#define NUM     13
#define FUNC    14
#define ALTTAB  15

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
  CM_CAOFF,
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

    [JBASE] = LAYOUT_split_3x5_3(  /* Qwerty win jpkey */
        KC_Q,    KC_W,    KC_E,     KC_R,    KC_T,             KC_Y,    KC_U,    KC_I,     KC_O,    KC_P,
        A_ALT,   KC_S,    KC_D,     KC_F,    G_GUI,            KC_H,    KC_J,    KC_K,     KC_L,    CM_NUM,
        Z_SFT,   KC_X,    KC_C,     KC_V,    KC_B,             KC_N,    KC_M,    CM_FNCM,  KC_DOT,  KC_SLSH,
                          CM_QFN,   KC_LSFT, KC_LCTL,          CM_QFN,  CM_NUM,  CM_SYS
    ),

    [QFN] = LAYOUT_split_3x5_3( /* [> SPFN <] */
        CM_ALCT,  CM_ALT4,  KC_ESC,   MO_EXCL,  SW_ATAB,        CM_STAB,  KC_HOME,  KC_UP,    KC_END,   KC_TAB,
        KC_LALT,  KC_LSFT,  KC_DEL,   MO_HYPS,  KC_LGUI,        KC_BSPC,  KC_LEFT,  KC_DOWN,  KC_RGHT,  KC_ENT,
        KC_1,     KC_2,     KC_3,     KC_4,     KC_5,           KC_6,     KC_7,     KC_8,     KC_9,     KC_0,
                            _______,  _______,  _______,        _______,  _______,  _______
    ),

    //[JRISE] = LAYOUT_split_3x5_3(
    //    JP_EXLM,  JP_AT,    JP_HASH,  JP_DLR,   JP_PERC,        _______,  _______,  JP_LPRN,  JP_RPRN,  JP_MINS,
    //    JP_UNDS,  JP_PLUS,  JP_EQL,   JP_ASTR,  JP_CIRC,        JP_LCBR,  JP_RCBR,  JP_LBRC,  JP_RBRC,  JP_COLN,
    //    JP_BSLS,  JP_AMPR,  JP_PIPE,  JP_TILD,  JP_GRV,         JP_QUOT,  JP_DQUO,  JP_LABK,  JP_RABK,  JP_QUES,
    //                        _______,  _______,  _______,        _______,  _______,  _______
    //),

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

static void user_shft_func_capson(keyrecord_t *record, bool *modifier_pressed, uint16_t *modifier_pressed_time, bool tapping_term_disable) {
      if (record->event.pressed) {
         *modifier_pressed_time = record->event.time;
         *modifier_pressed = true;
         register_mods(MOD_BIT(KC_RSFT));
      } else {
        unregister_mods(MOD_BIT(KC_RSFT));
        if (*modifier_pressed && (tapping_term_disable || (timer_elapsed(*modifier_pressed_time) < TAPPING_TERM))) {
           //cpas lockがoffだったらCAPSLOCKをonにする
          if (!host_keyboard_led_state().caps_lock) {
              //then caps on の時caps off
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
    case CM_QFN:
      user_lt(record,QFN,KC_SPC,&spfn_pressed,&spfn_pressed_time,false,&mod_switch_keycode);
      return false;
      break;
    case CM_NUM:
      if (get_highest_layer(default_layer_state)==JBASE){
        user_lt_hnzn(record,SYM,&num_pressed,&num_pressed_time,false,&mod_switch_keycode);
      } else {
        user_lt_hnzn(record,SYM,&num_pressed,&num_pressed_time,false,&mod_switch_keycode);
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
      } else {
         user_lt(record,NUM,KC_DOT,&fnsc_pressed,&fnsc_pressed_time,false,&mod_switch_keycode);
      }
      return false;
      break;
    case CM_FNCM:
      if (get_highest_layer(default_layer_state)==JBASE){
        user_lt(record,NUM,KC_COMM,&fncm_pressed,&fncm_pressed_time,false,&mod_switch_keycode);
      } else {
        user_lt(record,NUM,KC_COMM,&fncm_pressed,&fncm_pressed_time,false,&mod_switch_keycode);
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
    case CM_CAOFF:
      if(record->event.pressed){
          if (host_keyboard_led_state().caps_lock) {
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
