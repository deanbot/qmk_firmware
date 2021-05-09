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
    TD_MB_CMD,
    TD_MB1_NUM,
    TD_MB2_FN
};

#define NUM OSL(_NUM)
#define NAV OSL(_NAV)
#define SYM OSL(_SYM)
#define FN OSL(_FN)

#define MB2_FN TD(TD_MB2_FN)
#define MB1_NUM TD(TD_MB1_NUM)
#define OSS_SYM LT(_SYM, KC_F22)
#define SP_MO LT(_MOUSE, KC_SPACE)
#define BSP_NAV LT(_NAV, KC_BSPACE)

#define PREV KC_MEDIA_PREV_TRACK
#define NEXT KC_MEDIA_NEXT_TRACK
#define VOL_UP KC_AUDIO_VOL_UP
#define VOL_DOWN KC_AUDIO_VOL_DOWN
#define MUTE KC_AUDIO_MUTE
#define STOP KC_MEDIA_STOP
#define PAUSE KC_MEDIA_PLAY_PAUSE
#define BR_UP KC_BRIGHTNESS_UP
#define BR_DOWN KC_BRIGHTNESS_DOWN

#define STAB LSFT(KC_TAB)
#define BS LCTL(KC_BSPACE)
#define CBS LCTL(KC_BSPACE)
#define CDEL LCTL(KC_DELETE)
#define CAPS KC_CAPSLOCK
#define CHOME LCTL(KC_HOME)
#define CEND LCTL(KC_END)
#define TO_META OSL(_META)
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

#define TRANS KC_TRANSPARENT

#define LAYOUT_rev(...)                     LAYOUT_reviung41(__VA_ARGS__)

#define _________________COLEMAK_L1_________________        KC_Q,     KC_W,     KC_F,     KC_P,     KC_B
#define _________________COLEMAK_L2_________________        KC_A,     KC_R,     KC_S, CTL_T(KC_T),KC_G
#define _________________COLEMAK_L3_________________        LSFT_T(KC_Z),     KC_X,     KC_C,     KC_D,     KC_V

#define _________________COLEMAK_R1_________________        KC_J,     KC_L,     KC_U,     KC_Y,     KC_QUOT
#define _________________COLEMAK_R2_________________        KC_M,  CTL_T(KC_N), KC_E,     KC_I,     KC_O
#define _________________COLEMAK_R3_________________        KC_K,     KC_H,     KC_COMM,  KC_DOT,   LSFT_T(KC_SLSH)


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [_BASE] = LAYOUT_rev(
      KC_TAB,  _________________COLEMAK_L1_________________,                _________________COLEMAK_R1_________________,   OSM(MOD_RALT),
      NAV,     _________________COLEMAK_L2_________________,                _________________COLEMAK_R2_________________,   NAV,
      MB2_FN,  _________________COLEMAK_L3_________________,                _________________COLEMAK_R3_________________,   OSM(MOD_LALT),
                                           MB1_NUM,   SP_MO,    OSS_SYM,    BSP_NAV,    OSC
  ),

  [_FN] = LAYOUT_reviung41(
    TRANS,    PREV,     NEXT,     VOL_UP,   VOL_DOWN, MUTE,                TO(_NAV),   KC_F7,     KC_F8,    KC_F9,    KC_F10,   TRANS,
    TRANS,   KC_LSHIFT, KC_LCTRL, KC_LALT,  KC_LGUI,  STOP,                TO(_MOUSE), KC_F4,     KC_F5,    KC_F6,    KC_F11,   TRANS,
    TRANS,    TRANS,    TRANS,    BR_UP,    BR_DOWN,  PAUSE,               TO(_BASE),  KC_F1,     KC_F2,    KC_F3,    KC_F12,   TRANS,
                                            TRANS,    TRANS,    TRANS,     TRANS,      TRANS
  ),

  [_NAV] = LAYOUT_reviung41(
    STAB,     KC_INSERT, KC_PGUP, CHOME,    KC_PGDOWN,KC_ESCAPE,           ALT_F4,     CKP_0,     CKP_MIN,  CKP_PLS,  PS,       TO(_BASE),
    BS,       KC_LEFT,   KC_UP,   KC_DOWN,  KC_RIGHT, KC_DELETE,           APP,        KC_LGUI,   KC_LALT,  KC_LCTRL, KC_LSHIFT,TRANS,
    CBS,      CAPS,      KC_HOME, CEND,     KC_END,   CDEL,                DEL_LINE,   OGUI,      OALT,     OSC,     OSS,     TRANS,
                                            TO_META,  KC_ENTER, KC_TAB,    TRANS,      TRANS
  ),

  [_MOUSE] = LAYOUT_reviung41(
    TRANS,  LCTL(LSFT(KC_N)),    LCTL(KC_PGUP),  KC_MS_BTN1,    LCTL(KC_PGDOWN), LCTL(LSFT(KC_R)),       LCTL(KC_W),       KC_MS_BTN3,      KC_MS_WH_UP,      KC_MS_BTN2,       LCTL(LSFT(KC_B)),  TO(_BASE),
    TRANS,  KC_LSHIFT,           KC_LALT,        KC_MS_WH_UP,   KC_LCTRL,        LCTL(LSFT(KC_K)),       LCTL(KC_T),       KC_MS_LEFT,      KC_MS_DOWN,       KC_MS_UP,         KC_MS_RIGHT,       TRANS,
    TRANS,  LCTL(LSFT(KC_T)),    LCTL(KC_HOME),  KC_MS_WH_DOWN, LCTL(KC_END),    LALT(KC_LEFT),          LALT(KC_RIGHT),   KC_MS_WH_LEFT,   KC_MS_WH_DOWN,    KC_MS_WH_RIGHT,   LCTL(LSFT(KC_I)),  TRANS,
                                                                TRANS,           TRANS,         KC_MS_BTN1,   TRANS,            TRANS
  ),

  [_NUM] = LAYOUT_reviung41(
    TRANS,    TRANS,    TRANS,    TRANS,    TRANS,    TRANS,               TRANS,      TRANS,     TRANS,    TRANS,    TRANS,    TRANS,
    TRANS,    KC_7,     KC_5,     KC_3, CTL_T(KC_1),  KC_9,                KC_8,    CTL_T(KC_0),  KC_2,     KC_4,     KC_6,     TRANS,
    TRANS,    TRANS,    TRANS,    TRANS,    TRANS,    TRANS,               TRANS,      TRANS,     TRANS,    TRANS,    TRANS,    TRANS,
                                            TRANS,    TRANS,    TRANS,     TRANS,      TRANS
  ),

  [_SYM] = LAYOUT_reviung41(
    TRANS,    KC_CIRC,  KC_SCOLON, KC_LABK,  KC_RABK,    KC_AMPR,          KC_PIPE,    KC_EQUAL, KC_PLUS,  KC_QUOTE, KC_GRAVE, TRANS,
    TRANS,    KC_LCBR,  KC_COLN,   KC_LBRACKET, KC_LPRN, KC_AT,            KC_HASH,    KC_MINUS, KC_SLASH, KC_DQUO,  KC_PERC,  TRANS,
    TRANS,    KC_ASTR,  KC_RCBR,   KC_DLR,  KC_RBRACKET, KC_RPRN,          KC_TILD,    KC_UNDS,  KC_BSLASH, KC_EXLM, KC_QUES,  TRANS,
                                            TRANS,       TRANS,    TRANS,    TRANS,    TRANS

  ),

  [_META] = LAYOUT_reviung41(
    RGB_VAI,   RGB_SAI, RGB_HUI,  RGB_MOD,  TRANS,   RGB_TOG,               TRANS,      TRANS,  TRANS,  TRANS,  TRANS,  RESET,
    RGB_VAD,   RGB_SAD, RGB_HUD,  RGB_RMOD, TRANS,   TRANS,                 TRANS,      TRANS,  TRANS,  TRANS,  TRANS,  TRANS,
    TRANS,     TRANS,   TRANS,    TRANS,    TRANS,   TRANS,                 TRANS,      TRANS,  TRANS,  TRANS,  TRANS,  TRANS,
                                            TRANS,   TRANS,     TRANS,      TRANS,      TRANS
  ),
};

void tap_key(uint16_t keycode)
{
  register_code  (keycode);
  unregister_code(keycode);
}

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
    int state;
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
