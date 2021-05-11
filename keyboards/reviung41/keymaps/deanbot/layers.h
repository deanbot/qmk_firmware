#pragma once

#include "keycodes.h"
#include "common.h"

// Shared
#define __________________BLANK_5___________________        TRANS,    TRANS,    TRANS,    TRANS,    TRANS
#define ____________________NO_5____________________        KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO
#define ______________MODS_L______________                  KC_LSHIFT,KC_LCTRL, KC_LALT,  KC_LGUI
#define ______________MODS_R______________                  KC_LGUI,  KC_LALT,  KC_LCTRL, KC_LSHIFT

// Base layer
#define _________________COLEMAK_L1_________________        KC_Q,     KC_W,     KC_F,     KC_P,     KC_B
#define _________________COLEMAK_L2_________________        KC_A,     KC_R,     KC_S,     C_T(KC_T),KC_G
#define _________________COLEMAK_L3_________________        S_T(KC_Z),KC_X,     KC_C,     KC_D,     KC_V

#define _________________COLEMAK_R1_________________        KC_J,     KC_L,     KC_U,     KC_Y,     KC_QUOT
#define _________________COLEMAK_R2_________________        KC_M, C_T(KC_N),    KC_E,     KC_I,     KC_O
#define _________________COLEMAK_R3_________________        KC_K,     KC_H,     KC_COMM,  KC_DOT,   S_T(KC_SLSH)

// Fn layer
#define ___________________FN_L1____________________        M_PREV,   M_NEXT,   VOL_UP,   VOL_DOWN, M_MUTE
#define ___________________FN_L2____________________        ______________MODS_L______________,     M_STOP
#define ___________________FN_L3____________________        TRANS,    TRANS,    BR_UP,    BR_DOWN,  M_PAUSE

#define ______________FN_R1_______________                  KC_F7,    KC_F8,    KC_F9,    KC_F10
#define ______________FN_R2_______________                  KC_F4,    KC_F5,    KC_F6,    KC_F11
#define ______________FN_R3_______________                  KC_F1,    KC_F2,    KC_F3,    KC_F12

// Nav layer
#define __________________NAV_L1____________________        KC_INSERT,KC_PGUP,  CHOME,    KC_PGDOWN,KC_ESCAPE
#define __________________NAV_L2____________________        KC_LEFT,  KC_UP,    KC_DOWN,  KC_RIGHT, KC_DELETE
#define __________________NAV_L3____________________        CAPS,     KC_HOME,  CEND,     KC_END,   CDEL

#define __________________NAV_R1____________________        ALT_F4,   CKP_0,    CKP_MIN,  CKP_PLS,  PS
#define __________________NAV_R2____________________        APP,      ______________MODS_R______________
#define __________________NAV_R3____________________        DEL_LINE, OGUI,     OALT,     OSC,      OSS

// Mouse layer
#define _________________MOUSE_L1___________________        INCOG,    PREVT,    MBTN1,    NEXTT,    HRLOAD
#define _________________MOUSE_L2___________________        KC_LSHIFT,KC_LALT,  MW_UP,    KC_LCTRL, DUPT
#define _________________MOUSE_L3___________________        RETAB,   TOP,      MW_DOWN,  BOTTOM,   BACK

#define _________________MOUSE_R1___________________        LCTL(KC_W),MBTN3,   MW_UP,    MBTN2,    BKMKS
#define _________________MOUSE_R2___________________        LCTL(KC_T),MLEFT,   MDOWN,    MUP,      MRIGHT
#define _________________MOUSE_R3___________________        FWD,      MW_LEFT,  MW_DOWN,  MW_RIGHT, DEVT

// Num layer
#define ___________________NUM_L____________________        KC_7,     KC_5,     KC_3,     C_T(KC_1),KC_9
#define ___________________NUM_R____________________        KC_8,     C_T(KC_0),KC_2,     KC_4,     KC_6

// Sym layer
#define __________________SYM_L1____________________        KC_CIRC,  KC_SCOLON,KC_LABK,  KC_RABK,  KC_AMPR
#define __________________SYM_L2____________________        KC_LCBR,  LBRACK,   KC_LPRN,  KC_COLN,  KC_AT
#define __________________SYM_L3____________________        KC_ASTR,  KC_RCBR,  RBRACK,   KC_RPRN,  KC_DLR

#define __________________SYM_R1____________________        KC_PIPE,  KC_EQUAL, KC_PLUS,  KC_QUOTE, KC_GRAVE
#define __________________SYM_R2____________________        KC_HASH,  KC_MINUS, KC_SLASH, KC_DQUO,  KC_PERC
#define __________________SYM_R3____________________        KC_TILD,  KC_UNDS,  KC_BSLASH,KC_EXLM,  KC_QUES

// Meta layer
#define _________________META_L1____________________        RGB_VAI,  RGB_SAI,  RGB_HUI,  RGB_MOD,   RGB_TOG
#define _________________META_L2____________________        RGB_VAD,  RGB_SAD,  RGB_HUD,  RGB_RMOD,  KC_NO
