/* Copyright 2020 gtips
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */
#include QMK_KEYBOARD_H

// utilities
#define S_T(...)  LSFT_T(__VA_ARGS__)
#define C_T(...)  CTL_T(__VA_ARGS__)

void tap_key(uint16_t keycode)
{
  register_code  (keycode);
  unregister_code(keycode);
}

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
#define STAB LSFT(KC_TAB)
#define BS LCTL(KC_BSPACE)
#define CBS LCTL(KC_BSPACE)
#define CDEL LCTL(KC_DELETE)
#define CAPS KC_CAPSLOCK
#define CHOME LCTL(KC_HOME)
#define CEND LCTL(KC_END)
#define ALT_F4 LALT(KC_F4)
#define APP KC_APPLICATION
#define DEL_LINE LCTL(LSFT(KC_K))
#define OGUI OSM(MOD_LGUI)
#define OALT OSM(MOD_LALT)
#define OSC OSM(MOD_LCTL)
#define OSS OSM(MOD_LSFT)
#define CKP_0 LCTL(KC_KP_0)
#define CKP_MIN LCTL(KC_KP_MINUS)
#define CKP_PLS LCTL(KC_KP_PLUS)
#define PS KC_PSCREEN

// Mouse keycodes
#define INCOG LCTL(LSFT(KC_N))
#define RETAB LCTL(LSFT(KC_T))
#define DUPT LCTL(LSFT(KC_K))
#define PREVT LCTL(KC_PGUP)
#define NEXTT LCTL(KC_PGDOWN)
#define HRLOAD LCTL(LSFT(KC_R))
#define MLEFT KC_MS_LEFT
#define MDOWN KC_MSDOWN
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
#define BKMKS LCTL(LSFT(KC_B))
#define BACK LALT(KC_LEFT)
#define FWD LALT(KC_RIGHT)
#define DEVT LCTL(LSFT(KC_I))

// misc tokens
#define TRANS KC_TRANSPARENT


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
#define _________________MOUSE_L3___________________        RETAAB,   TOP,      MW_DOWN,  BOTTOM,   BACK

#define _________________MOUSE_R1___________________        LCTL(KC_W),MBTN3,   MW_UP,    MBTN2,    BKMKS
#define _________________MOUSE_R2___________________        LCTL(KC_T),MLEFT,   MDOWN,    MUP,      MRIGHT
#define _________________MOUSE_R3___________________        FWD,      MW_LEFT,  MW_DOWN,  MW_RIGHT, DEVT

// Num layer
#define ___________________NUM_L____________________        KC_7,     KC_5,     KC_3,     C_T(KC_1),KC_9
#define ___________________NUM_R____________________        KC_8,     C_T(KC_0),KC_2,     KC_4,     KC_6

// Sym layer
#define __________________SYM_L1____________________        KC_CIRC,  KC_SCOLON,KC_LABK,  KC_RABK,  KC_AMPR
#define __________________SYM_L2____________________        KC_ASTR,  KC_RCBR,  KC_DLR, KC_RBRACKET,KC_RPRN
#define __________________SYM_L3____________________        KC_LCBR,  KC_COLN,KC_LBRACKET,KC_LPRN,  KC_AT

#define __________________SYM_R1____________________        KC_PIPE,  KC_EQUAL, KC_PLUS,  KC_QUOTE, KC_GRAVE
#define __________________SYM_R2____________________        KC_HASH,  KC_MINUS, KC_SLASH, KC_DQUO,  KC_PERC
#define __________________SYM_R3____________________        KC_TILD,  KC_UNDS,  KC_BSLASH,KC_EXLM,  KC_QUES

// Meta layer
#define _________________META_L1____________________        RGB_VAI,  RGB_SAI,  RGB_HUI,  RGB_MOD,   RGB_TOG
#define _________________META_L2____________________        RGB_VAD,  RGB_SAD,  RGB_HUD,  RGB_RMOD,  KC_NO


enum layer_names {
  _BASE,
  _FN,
  _NAV,
  _MOUSE,
  _NUM,
  _SYM,
  _META
};

enum tap_dance_codes {
  D_FN_TASK_VIEW,
  TD_MB1_NUM,
  TD_MB2_FN
};

// Keycodes
#define NAV OSL(_NAV)
#define MB2_FN TD(TD_MB2_FN)
#define MB1_NUM TD(TD_MB1_NUM)
#define OSS_SYM LT(_SYM, KC_F22)
#define SP_MO LT(_MOUSE, KC_SPACE)
#define BSP_NAV LT(_NAV, KC_BSPACE)

// layer tokens
#define LAYOUT_rev(...)       LAYOUT_reviung41(__VA_ARGS__)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [_BASE] = LAYOUT_rev(
    KC_TAB, _________________COLEMAK_L1_________________,                   _________________COLEMAK_R1_________________,   OSM(MOD_RALT),
    NAV,    _________________COLEMAK_L2_________________,                   _________________COLEMAK_R2_________________,   NAV,
    MB2_FN, _________________COLEMAK_L3_________________,                   _________________COLEMAK_R3_________________,   OSM(MOD_LALT),
                                    MB1_NUM,    SP_MO,        OSS_SYM,          BSP_NAV,    OSC
  ),

  [_FN] = LAYOUT_rev(
    TRANS,  ___________________FN_L1____________________,                   TO(_NAV), ______________FN_R1_______________,   TRANS,
    TRANS,  ___________________FN_L2____________________,                  TO(_MOUSE),______________FN_R2_______________,   TRANS,
    TRANS,  ___________________FN_L3____________________,                   TO(_BASE),______________FN_R2_______________,   TRANS,
                                            __________________BLANK_5___________________
  ),

  [_NAV] = LAYOUT_rev(
    STAB,   __________________NAV_L1____________________                    __________________NAV_R1____________________,   TO(_BASE),
    BS,     __________________NAV_L2____________________,                   __________________NAV_R2____________________,   TRANS,
    CBS,    __________________NAV_L3____________________,                   __________________NAV_R2____________________,   TRANS,
                                    MO(_META),  KC_ENTER,       KC_TAB,         TRANS,      TRANS
  ),

  [_MOUSE] = LAYOUT_rev(
    TRANS,  _________________MOUSE_L1___________________,                   _________________MOUSE_R1___________________,   TO(_BASE),
    TRANS,  _________________MOUSE_L2___________________,                   _________________MOUSE_R2___________________,   TRANS,
    TRANS,  _________________MOUSE_L3___________________,                   _________________MOUSE_R3___________________,   TRANS,
                                    TRANS,      TRANS,          MBTN1,          TRANS,      TRANS
  ),

  [_NUM] = LAYOUT_rev(
    TRANS,  __________________BLANK_5___________________,                   __________________BLANK_5___________________,   TRANS,
    TRANS,  ___________________NUM_L____________________,                   ___________________NUM_R____________________,   TRANS,
    TRANS,  __________________BLANK_5___________________,                   __________________BLANK_5___________________,   TRANS,
                                            __________________BLANK_5___________________
  ),

  [_SYM] = LAYOUT_rev(
    TRANS,  __________________SYM_L1____________________,                   __________________SYM_R1____________________,   TRANS,
    TRANS,  __________________SYM_L2____________________,                   __________________SYM_R1____________________,   TRANS,
    TRANS,  __________________SYM_L3____________________,                   __________________SYM_R3____________________,   TRANS,
                                            __________________BLANK_5___________________
  ),

  [_META] = LAYOUT_rev(
    KC_NO,  _________________META_L1____________________,                   ____________________NO_5____________________,  RESET,
    KC_NO,  _________________META_L2____________________,                   ____________________NO_5____________________,  TRANS,
    KC_NO,  ____________________NO_5____________________,                   ____________________NO_5____________________,  TRANS,
                                            __________________BLANK_5___________________
  ),
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
        // hijack an unused keycode to do mod- and layer-taps with cooler taps than just basic keycodes
        case LT(_SYM, KC_F22):
            if (record->tap.count == 2 && !record->event.pressed) {
                tap_key(CAPS);
            } else if (record->tap.count > 0) {
                if (record->event.pressed) {
                    set_oneshot_mods(MOD_LSFT);
                }
                return false;
            }
            break;
    }
    return true;
}

typedef struct {
    bool    is_press_action;
    int     layer;
    int     state;
} tap;

static tap mtap_state = {
  .is_press_action = true,
  .state = 0,
  .layer = -1
};

enum {
    SINGLE_TAP = 1,
    SINGLE_HOLD,
    DOUBLE_TAP,
    DOUBLE_HOLD,
    DOUBLE_SINGLE_TAP,
    TRIPLE_TAP,
    TRIPLE_HOLD,
    IGNORE_TAP,
    SHIFTED_ON_INITAL,
    MORE_TAPS
};

void mousekey_tap (qk_tap_dance_state_t *state, void *user_data);
void mousekey_finished (qk_tap_dance_state_t *state, void *user_data);
void mousekey_reset (qk_tap_dance_state_t *state, void *user_data);

#define ACTION_TAP_DANCE_MOUSE_LAYER(kc1, layer) \
  { .fn = {mousekey_tap, mousekey_finished, mousekey_reset}, .user_data = (void *)&((qk_tap_dance_pair_t){kc1, layer}),  }

qk_tap_dance_action_t tap_dance_actions[] = {
  //[D_FN_TASK_VIEW] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_fn, dance_fn_finished, dance_fn_reset),
  [TD_MB1_NUM] = ACTION_TAP_DANCE_MOUSE_LAYER(KC_MS_BTN1, _NUM),
  [TD_MB2_FN] = ACTION_TAP_DANCE_MOUSE_LAYER(KC_MS_BTN2, _FN)
};

void mousekey_tap (qk_tap_dance_state_t *state, void *user_data) {
  if (user_data) {
    qk_tap_dance_pair_t *pair = (qk_tap_dance_pair_t *)user_data;
    mtap_state.layer = pair->kc2;
  }
}

void mousekey_finished (qk_tap_dance_state_t *state, void *user_data) {
  uint16_t mouse_key = KC_MS_BTN1;
  int layer = -1;

  if (user_data) {
    qk_tap_dance_pair_t *pair = (qk_tap_dance_pair_t *)user_data;
    mouse_key = pair->kc1;
    layer = pair->kc2;
  }

  uint8_t st = SINGLE_TAP;

  if (state->count == 1) {
      if (!state->pressed) {
        st = SINGLE_TAP;
      } else {
        st = SINGLE_HOLD;
      }
  } else if (state->count == 2) {
      if (state->pressed) {
          st = DOUBLE_HOLD;
      } else {
          st = DOUBLE_TAP;
      }
  } if (state->count == 3) {
      st = DOUBLE_SINGLE_TAP;
  }

  mtap_state.state = st;
  switch (mtap_state.state) {
    case SINGLE_HOLD: layer_on(layer); break;
    case SINGLE_TAP: tap_key(mouse_key); break;
    case DOUBLE_SINGLE_TAP: break;
    case DOUBLE_HOLD: register_code(mouse_key); break;
    case DOUBLE_TAP: tap_key(mouse_key); tap_key(mouse_key); break;
  }
}

void mousekey_reset (qk_tap_dance_state_t *state, void *user_data) {
  uint16_t mouse_key = KC_MS_BTN1;
  int layer = -1;

  if (user_data) {
    qk_tap_dance_pair_t *pair = (qk_tap_dance_pair_t *)user_data;
    mouse_key = pair->kc1;
    layer = pair->kc2;
  }

  switch (mtap_state.state) {
    case SINGLE_HOLD: layer_off(layer); break;
    case TRIPLE_TAP:
    case DOUBLE_HOLD: unregister_code(mouse_key); break;
  }
  mtap_state.state = 0;
}
