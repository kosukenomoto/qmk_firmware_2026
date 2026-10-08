"""Run keymap callback regressions with a minimal QMK mock: python3 test_keymap.py."""
import argparse,pathlib,re,subprocess,tempfile
root=pathlib.Path(__file__).resolve().parents[3]
parser=argparse.ArgumentParser(description=__doc__)
parser.add_argument('--keymap', default='20261004', choices=['20260930', '20261004'])
args=parser.parse_args()
src=root/f'keyboards/s202409/keymaps/{args.keymap}/keymap.c'
temporary=tempfile.TemporaryDirectory(prefix='s202409-tests-')
d=pathlib.Path(temporary.name)
s=src.read_text()+(root/'keyboards/s202409/keymap_jp.h').read_text()
keys=sorted(set(re.findall(r'\bKC_[A-Z0-9_]+\b',s)))
values={f'KC_{chr(65+i)}':4+i for i in range(26)}
values.update(KC_LCTL=224,KC_LSFT=225,KC_LALT=226,KC_LGUI=227,KC_RSFT=229)
for key in keys:
 if key not in values:values[key]=40+len([v for v in values.values() if 40<=v<224])
h='''#pragma once
#include <stdint.h>
#include <stdbool.h>
#define PROGMEM
#define MATRIX_ROWS 8
#define MATRIX_COLS 5
#define LAYOUT_split_3x5_3(...) {{0}}
#define SAFE_RANGE 0x6000
#define QK_BOOT 0x7000
#define _______ 0
#define MOD_BIT(k) (1u << ((k) & 7))
#define MOD_BIT_LALT MOD_BIT(KC_LALT)
#define MOD_MASK_CG (MOD_BIT(KC_LCTL) | MOD_BIT(KC_LGUI))
#define MOD_MASK_SHIFT (MOD_BIT(KC_LSFT) | MOD_BIT(KC_RSFT))
#define FLOW_TAP_TERM 150
#define TAPPING_TERM 200
#define S(k) (0x0200 | (k))
#define C(k) (0x0100 | (k))
#define A(k) (0x0400 | (k))
#define G(k) (0x0800 | (k))
#define MO(k) (k)
#define LSFT_T(k) (0x1000 | (k))
#define LALT_T(k) (0x2000 | (k))
#define LGUI_T(k) (0x3000 | (k))
typedef struct {struct {bool pressed; uint16_t time; struct {uint8_t row,col;} key;} event; struct {uint8_t count;} tap;} keyrecord_t;
typedef struct {bool caps_lock;} led_t;
static uint16_t now;
static uint8_t physical_mods,weak_mods;
static uint32_t layers;
static unsigned taps[256];
static uint8_t tap_mods[256];
static bool caps;
static uint8_t report_mods;
static unsigned alt_ctrl_reports;
static bool pressed_codes[256];
typedef struct {uint16_t time; uint8_t mods; bool f4;} mock_report_t;
static mock_report_t reports[128];
static unsigned report_count;
uint8_t get_mods(void){return physical_mods;}
void del_mods(uint8_t m){physical_mods&=~m;}
void set_mods(uint8_t m){physical_mods=m;}
bool get_chordal_hold_default(keyrecord_t *a, keyrecord_t *b){return true;}
uint8_t get_weak_mods(void){return weak_mods;}
void add_weak_mods(uint8_t m){weak_mods|=m;}
void del_weak_mods(uint8_t m){weak_mods&=~m;}
void set_weak_mods(uint8_t m){weak_mods=m;}
void send_keyboard_report(void){
 report_mods=physical_mods|weak_mods;
 if((report_mods & 5)==5) ++alt_ctrl_reports;
 if(report_count<128)reports[report_count++]=(mock_report_t){now,report_mods,pressed_codes[KC_F4]};
}
uint16_t timer_read(void){return now;}
uint16_t timer_elapsed(uint16_t t){return now-t;}
void wait_ms(uint16_t ms){now+=ms;}
void layer_on(uint8_t l){layers|=1u<<l;}
void layer_off(uint8_t l){layers&=~(1u<<l);}
void register_code(uint8_t k){pressed_codes[k]=true;send_keyboard_report();}
void unregister_code(uint8_t k){pressed_codes[k]=false;send_keyboard_report();}
void tap_code(uint8_t k){++taps[k];tap_mods[k]=physical_mods|weak_mods;send_keyboard_report();}
led_t host_keyboard_led_state(void){return (led_t){caps};}
uint16_t get_tap_keycode(uint16_t k){return k&255;}
'''
h+='\n'.join(f'#define {k} {v}' for k,v in values.items())+'\n'
# Functions refer to keycodes, so macros must precede them.
pos=h.index('typedef struct');defs=h[h.index('#define KC_'):];h=h[:pos]+defs+h[pos:h.index('#define KC_')]
if args.keymap == '20261004':
 h += '#define SCREENSHOT_QFN\n#define QFN_LEFT_TAP_KEY KC_S\n#define QFN_LEFT_TAP_MODS (MOD_BIT(KC_LGUI) | MOD_BIT(KC_LSFT))\n'
else:
 h += '#define QFN_LEFT_TAP_KEY KC_SPC\n#define QFN_LEFT_TAP_MODS 0\n'
(d/'qmk_stub.h').write_text(h)
c='''#include <assert.h>
#include <string.h>
#include <stdio.h>
#include "KEYMAP"
static void reset(void){
 memset(layer_taps,0,sizeof layer_taps); memset(taps,0,sizeof taps);
 memset(tap_mods,0,sizeof tap_mods); qfn_count=num_count=symbol_shift_count=0;
 alt_tab_active=false; physical_mods=weak_mods=report_mods=0;
 layers=0;now=0;caps=false;alt_ctrl_reports=0;
 memset(pressed_codes,0,sizeof pressed_codes);report_count=0;
#ifdef SCREENSHOT_QFN
 alt_f4_pressed=false;
#endif
}
static void tap_event(uint16_t k,uint8_t row,uint8_t col,bool down,uint8_t count){
 keyrecord_t r={.event={.pressed=down,.time=now,.key={row,col}},.tap={count}};
 if(down)weak_mods=0; // QMK action_exec clears weak mods before callbacks.
 assert(pre_process_record_user(k,&r));
 if(process_record_user(k,&r))post_process_record_user(k,&r);
}
static void event(uint16_t k,uint8_t row,uint8_t col,bool down){tap_event(k,row,col,down,0);}
int main(void){
 reset();event(CM_QFN,3,0,true);now+=40;event(CM_QFN,3,0,false);
 assert(taps[QFN_LEFT_TAP_KEY]==1 && layers==0);
 assert(tap_mods[QFN_LEFT_TAP_KEY]==QFN_LEFT_TAP_MODS && weak_mods==0);
 reset();event(CM_QFN,3,0,true);event(CM_QFN,7,0,true);now+=250;
 event(CM_QFN,3,0,false);assert(layers & (1u<<QFN));
 event(CM_QFN,7,0,false);assert(layers==0 && taps[KC_SPC]==0);
 reset();event(CM_NUM,5,4,true);event(CM_NUM,7,1,true);now+=250;
 event(CM_NUM,5,4,false);assert(layers & (1u<<SYM));
 event(CM_NUM,7,1,false);assert(layers==0 && taps[KC_GRAVE]==0);
 reset();event(CM_QFN,3,0,true);event(CM_NUM,7,1,true);
 event(SW_ATAB,0,3,true);assert(tap_mods[KC_TAB] & MOD_BIT(KC_LALT));
 event(KC_TAB,0,3,true);assert(weak_mods & MOD_BIT(KC_LALT));
 event(CM_NUM,7,1,false);assert(alt_tab_active && (layers & (1u<<QFN)));
 layer_on(JFN);event(CM_QFN,3,0,false);
 assert(!alt_tab_active && !(weak_mods & MOD_BIT(KC_LALT)) && layers==(1u<<JFN));
 reset();physical_mods=MOD_BIT(KC_LSFT);
 event(MC_EXLM,0,0,true);event(MC_HASH,0,2,true);
 event(MC_EXLM,0,0,false);assert(weak_mods & MOD_BIT(KC_LSFT));
 event(KC_A,1,0,true);assert(weak_mods & MOD_BIT(KC_LSFT));
 event(MC_HASH,0,2,false);assert(weak_mods==0 && physical_mods==MOD_BIT(KC_LSFT));
 #ifdef SCREENSHOT_QFN
 // Thumb Shift tap toggles IME (Alt+`) and turns Caps Lock off.
 reset();physical_mods=MOD_BIT(KC_LALT);caps=true;
 tap_event(SFT_IME,3,1,true,1);tap_event(SFT_IME,3,1,false,1);
 assert(taps[KC_GRAVE]==1 && taps[KC_CAPS]==1 && physical_mods==MOD_BIT(KC_LALT) && weak_mods==0);
 // Thumb Shift hold is left to QMK as a plain Shift.
 reset();assert(process_record_user(SFT_IME,&(keyrecord_t){.event={.pressed=true}}));
 assert(taps[KC_GRAVE]==0);
 // CM_NUM tap types a colon.
 reset();event(CM_NUM,5,4,true);now+=30;event(CM_NUM,5,4,false);
 assert(taps[JP_COLN]==1 && taps[JP_SCLN]==0 && taps[KC_GRAVE]==0 && layers==0);
 // With Shift held, CM_NUM tap types an unshifted semicolon, then restores Shift.
 reset();physical_mods=MOD_BIT(KC_LSFT);
 event(CM_NUM,5,4,true);now+=30;event(CM_NUM,5,4,false);
 assert(taps[JP_SCLN]==1 && taps[JP_COLN]==0 && tap_mods[JP_SCLN]==0);
 assert(physical_mods==MOD_BIT(KC_LSFT));
#else
 reset();physical_mods=MOD_BIT(KC_LALT);caps=true;
 event(CM_NUM,7,1,true);now+=30;event(CM_NUM,7,1,false);
 assert(taps[KC_GRAVE]==1 && taps[KC_CAPS]==1 && physical_mods==MOD_BIT(KC_LALT) && weak_mods==0);
#endif
 reset();event(CM_QFN,3,0,true);event(CM_ALCT,0,0,true);
 assert(alt_ctrl_reports>0 && alt_tab_active);
 event(CM_QFN,3,0,false);assert(weak_mods==0 && layers==0);
 reset();now=65520;event(CM_QFN,3,0,true);now=20;
 event(CM_QFN,3,0,false);assert(taps[QFN_LEFT_TAP_KEY]==1);
 reset();assert(!process_record_user(CM_LEFT,&(keyrecord_t){.event={.pressed=true}}));
 assert(taps[KC_LEFT]==4);
 #ifdef SCREENSHOT_QFN
 // Right thumb taps still send Space.
 reset();event(CM_QFN,7,0,true);now+=40;event(CM_QFN,7,0,false);
 assert(taps[KC_SPC]==1 && taps[KC_S]==0 && layers==0);
 // Holding the left thumb uses QFN and never takes a screenshot.
 reset();event(CM_QFN,3,0,true);assert(layers & (1u<<QFN));now+=250;
 event(CM_QFN,3,0,false);assert(taps[KC_S]==0 && taps[KC_SPC]==0 && layers==0);
 // A layer chord cancels the left thumb's tap, even before TAPPING_TERM.
 reset();event(CM_QFN,3,0,true);event(KC_ESC,0,2,true);now+=20;
 event(KC_ESC,0,2,false);event(CM_QFN,3,0,false);
 assert(taps[KC_S]==0 && taps[KC_SPC]==0 && layers==0);
 // One screenshot per completed short tap, none on initial press.
 reset();event(CM_QFN,3,0,true);assert(taps[KC_S]==0);now+=20;
 event(CM_QFN,3,0,false);event(CM_QFN,3,0,true);now+=20;
 event(CM_QFN,3,0,false);assert(taps[KC_S]==2 && taps[KC_SPC]==0);
 // Restore modifiers that were already held when the macro ran.
 reset();physical_mods=MOD_BIT(KC_LSFT);event(CM_QFN,3,0,true);
 weak_mods=MOD_BIT(KC_LSFT);now+=20;event(CM_QFN,3,0,false);
 assert(tap_mods[KC_S]==QFN_LEFT_TAP_MODS);
 assert(physical_mods==MOD_BIT(KC_LSFT) && weak_mods==MOD_BIT(KC_LSFT));
  // Alt-only report precedes F4 by at least 60 ms. Release F4 before Alt.
 reset();event(CM_ALT4,0,1,true);
 assert(reports[0].mods==MOD_BIT(KC_LALT) && !reports[0].f4);
 assert(reports[1].f4 && reports[1].mods==MOD_BIT(KC_LALT));
 assert((uint16_t)(reports[1].time-reports[0].time)>=60);
 unsigned release_start=report_count;
 event(CM_ALT4,0,1,false);
 assert(!reports[release_start].f4 && reports[release_start].mods==MOD_BIT(KC_LALT));
 assert(!reports[release_start+1].f4 && reports[release_start+1].mods==0);
 assert(!alt_f4_pressed && weak_mods==0);
 // A new key press must not clear Alt while F4 remains down.
 reset();event(CM_ALT4,0,1,true);event(KC_Q,0,0,true);
 assert(pressed_codes[KC_F4] && (weak_mods & MOD_BIT(KC_LALT)));
 event(CM_ALT4,0,1,false);assert(!pressed_codes[KC_F4] && weak_mods==0);
 // The macro does not release a physically held Alt.
 reset();physical_mods=MOD_BIT(KC_LALT);
 event(CM_ALT4,0,1,true);event(CM_ALT4,0,1,false);
 assert(physical_mods==MOD_BIT(KC_LALT) && weak_mods==0);
 // Ending Alt+F4 must not end an existing Alt+Tab session.
 reset();event(CM_QFN,3,0,true);event(SW_ATAB,0,3,true);
 event(CM_ALT4,0,1,true);event(CM_ALT4,0,1,false);
 assert(alt_tab_active && (weak_mods & MOD_BIT(KC_LALT)));
 event(CM_QFN,3,0,false);assert(weak_mods==0);
 // Ending QFN/Alt+Tab while F4 is held must retain Alt for F4.
 reset();event(CM_QFN,3,0,true);event(SW_ATAB,0,3,true);
 event(CM_ALT4,0,1,true);event(CM_QFN,3,0,false);
 assert(!alt_tab_active && alt_f4_pressed && (weak_mods & MOD_BIT(KC_LALT)));
 event(CM_ALT4,0,1,false);assert(weak_mods==0);
 puts("PASS: 22 keymap regressions (mock QMK callbacks)");
#else
 puts("PASS: 9 keymap regressions (mock QMK callbacks)");
#endif
}
'''.replace('KEYMAP',str(src))
(d/'test.c').write_text(c)
subprocess.run(['gcc','-std=gnu11','-Wall','-Werror','-Wno-unused-parameter','-DQMK_KEYBOARD_H="qmk_stub.h"','-I'+str(d),'-I'+str(root/'keyboards/s202409'),str(d/'test.c'),'-o',str(d/'test')],check=True)
subprocess.run([str(d/'test')],check=True)
