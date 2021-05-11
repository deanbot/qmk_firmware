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
#include "common.h"
#include "keycodes.h"
#include "layers.h"

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
#define TO_MOUSE TO(_MOUSE)
#define MB2_FN TD(TD_MB2_FN)
#define MB1_NUM TD(TD_MB1_NUM)
#define OSS_SYM LT(_SYM, KC_F22)
#define OSMEH_ALT ALT_T(KC_F23)
#define SP_MO LT(_MOUSE, KC_SPACE)
#define BSP_NAV LT(_NAV, KC_BSPACE)

// layer tokens
#define LAYOUT_rev(...)       LAYOUT_reviung41(__VA_ARGS__)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [_BASE] = LAYOUT_rev(
    KC_TAB, _________________COLEMAK_L1_________________,                   _________________COLEMAK_R1_________________,   OSM(MOD_RALT),
    NAV,    _________________COLEMAK_L2_________________,                   _________________COLEMAK_R2_________________,   NAV,
    MB2_FN, _________________COLEMAK_L3_________________,                   _________________COLEMAK_R3_________________,   OSM(MOD_LALT),
                                    MB1_NUM,    SP_MO,        OSS_SYM,          BSP_NAV,    OSMEH_ALT
  ),

  [_FN] = LAYOUT_rev(
    TRANS,  ___________________FN_L1____________________,                   TO(_NAV), ______________FN_R1_______________,   TRANS,
    TRANS,  ___________________FN_L2____________________,                   TO_MOUSE, ______________FN_R2_______________,   TRANS,
    TRANS,  ___________________FN_L3____________________,                   TO(_BASE),______________FN_R2_______________,   TRANS,
                                            __________________BLANK_5___________________
  ),

  [_NAV] = LAYOUT_rev(
    STAB,   __________________NAV_L1____________________,                   __________________NAV_R1____________________,   TO(_BASE),
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
    TRANS,  __________________SYM_L2____________________,                   __________________SYM_R2____________________,   TRANS,
    TRANS,  __________________SYM_L3____________________,                   __________________SYM_R3____________________,   TRANS,
                                            __________________BLANK_5___________________
  ),

  [_META] = LAYOUT_rev(
    KC_NO,  _________________META_L1____________________,                   ____________________NO_5____________________,   RESET,
    KC_NO,  _________________META_L2____________________,                   ____________________NO_5____________________,   TRANS,
    KC_NO,  ____________________NO_5____________________,                   ____________________NO_5____________________,   TRANS,
                                            __________________BLANK_5___________________
  ),
};

// hijack an unused keycode to do mod- and layer-taps with cooler taps than just basic keycodes
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    // tap: oss, double-tap: caps, hold: LT
    case OSS_SYM:
      if (record->tap.count == 2 && !record->event.pressed) {
        tap_key(CAPS);
      } else if (record->tap.count > 0) {
        if (record->event.pressed) {
          set_oneshot_mods(MOD_LSFT);
        }
        return false;
      }
      break;

    // tap: osmeh, hold: alt
    case OSMEH_ALT:
      if (record->tap.count > 0) {
        if (record->event.pressed) {
          set_oneshot_mods(MOD_MEH);
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
