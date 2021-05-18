#pragma once

#include "common.h"

enum custom_keycodes {
    MAC_SEL_L = SAFE_RANGE,
    MAC_PROF,
    SW_WIN,
    SW_LANG
};

// Media tokens
#define M_PREV KC_MEDIA_PREV_TRACK
#define M_NEXT KC_MEDIA_NEXT_TRACK
#define VOL_UP KC_AUDIO_VOL_UP
#define VOL_DOWN KC_AUDIO_VOL_DOWN
#define M_MUTE KC_AUDIO_MUTE
#define M_STOP KC_MEDIA_STOP
#define M_PAUSE KC_MEDIA_PLAY_PAUSE
#define BR_UP KC_BRIGHTNESS_UP
#define BR_DOWN KC_BRIGHTNESS_DOWN

// Nav tokens
#define REDO LCTL(KC_Y)
#define COPY LCTL(KC_C)
#define CUT LCTL(KC_X)
#define PASTE LCTL(KC_V)
#define UNDO LCTL(KC_Z)
#define ESC KC_ESCAPE
#define BS KC_BSPACE
#define DEL KC_DELETE
#define APP KC_APPLICATION
#define DEL_LINE LCTL(LSFT(KC_K))
#define CKP_0 LCTL(KC_KP_0)
#define CKP_MIN LCTL(KC_KP_MINUS)
#define CKP_PLS LCTL(KC_KP_PLUS)
#define PS KC_PSCREEN
#define SEL_HOME LSFT(KC_HOME)
#define SEL_END LSFT(KC_END)
#define SEL_WORD LSFT(KC_D)
#define FOC_0 LCTL(KC_0)
#define FOC_1 LCTL(KC_1)
#define FOC_2 LCTL(KC_2)
#define FOC_3 LCTL(KC_3)
#define TERM LCTL(KC_GRAVE)
#define SCREEN_L G(S(KC_LEFT))
#define SCREEN_R G(S(KC_RIGHT))

// Mouse keycodes
#define INCOG LCTL(LSFT(KC_N))
#define RETAB LCTL(LSFT(KC_T))
#define DUPT LCTL(LSFT(KC_K))
#define PREVT LCTL(KC_PGUP)
#define NEXTT LCTL(KC_PGDOWN)
#define NEWTAB LCTL(KC_T)
#define MLEFT KC_MS_LEFT
#define MDOWN KC_MS_DOWN
#define MUP KC_MS_UP
#define MRIGHT KC_MS_RIGHT
#define MW_UP KC_MS_WH_UP
#define MW_DOWN KC_MS_WH_DOWN
#define MW_LEFT KC_MS_WH_LEFT
#define MW_RIGHT KC_MS_WH_RIGHT
#define TOP LCTL(KC_HOME)
#define BOTTOM LCTL(KC_END)
#define MBTN3 KC_MS_BTN3
#define MBTN2 KC_MS_BTN2
#define MBTN1 KC_MS_BTN1
#define BACK LALT(KC_LEFT)
#define FWD LALT(KC_RIGHT)
#define DEVT LCTL(LSFT(KC_I))

// sym tokens
#define LBRACK KC_LBRACKET
#define RBRACK KC_RBRACKET

// misc tokens
#define TRANS KC_TRANSPARENT
