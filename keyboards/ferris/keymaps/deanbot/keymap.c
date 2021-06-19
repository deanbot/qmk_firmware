#include QMK_KEYBOARD_H

#include "capsword.c"
#include "oneshot.h"
#include "swapper.h"

// utilities
#define S_T(...)  LSFT_T(__VA_ARGS__)
#define C_T(...)  CTL_T(__VA_ARGS__)
#define A_T(...)  ALT_T(__VA_ARGS__)
#define G_T(...)  LGUI_T(__VA_ARGS__)

enum layer_names {
  _BASE,
  _FN,
  _NAV,
  _MOUSE,
  _SYM,
  _NUM,
  _META,
  _QWERTY
};

enum custom_keycodes {
    SEL_L = SAFE_RANGE,
    SW_PROF,
    SW_WIN,
    SW_LANG,
    OS_SHFT,
    OS_ALT,
    OS_GUI,
    OS_CTRL,
    OS_MEH,
    REPEAT,
    CAPSWORD
};

// define keycodes to make layers easier to read
#define M_NAV MO(_NAV)
#define M_SYM MO(_SYM)
#define SP_MK LT(_MOUSE, KC_SPACE)

// Meta tokens
#define T_QWERTY TO(_QWERTY)
#define T_BASE TO(_BASE)
#define T_MOUSE TO(_MOUSE)
#define T_NAV TO(_NAV)
#define M_META MO(_META)
#define WAKE KC_SYSTEM_WAKE
#define SLEEP KC_SYSTEM_SLEEP
#define M_PREV KC_MEDIA_PREV_TRACK
#define M_NEXT KC_MEDIA_NEXT_TRACK
#define VOL_UP KC_AUDIO_VOL_UP
#define VOL_DOWN KC_AUDIO_VOL_DOWN
#define MUTE KC_AUDIO_MUTE
#define M_STOP KC_MEDIA_STOP
#define M_PAUSE KC_MEDIA_PLAY_PAUSE
#define BR_UP KC_BRIGHTNESS_UP
#define BR_DOWN KC_BRIGHTNESS_DOWN

// Nav tokens
#define HUD LGUI(KC_TAB)
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
#define TERM LCTL(KC_GRAVE)
#define SCREEN_L G(S(KC_LEFT))
#define SCREEN_R G(S(KC_RIGHT))
#define HINT LCTL(KC_SPACE)

// Mouse keycodes
#define INCOG LCTL(LSFT(KC_N))
#define RETAB LCTL(LSFT(KC_T))
#define H_RFRSH C(S(KC_R))
#define DUPT LCTL(LSFT(KC_K))
#define PREVT LCTL(KC_PGUP)
#define NEXTT LCTL(KC_PGDOWN)
#define NEWTAB LCTL(KC_T)
#define CLOSET LCTL(KC_W)
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

// Qmisc tokens
#define TRANS KC_TRANSPARENT

// Shared
#define __________________BLANK_4___________________        TRANS,    TRANS,    TRANS,    TRANS
#define ____________________NO_5____________________        KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO
#define ______________MODS_L______________                  OS_GUI,   OS_ALT,   OS_CTRL,  OS_SHFT
#define ______________MODS_R______________                  OS_SHFT,  OS_CTRL,  OS_ALT,   OS_GUI

// Base layer
#define _________________COLEMAK_L1_________________        KC_Q,     KC_W,     KC_F,     KC_P,     KC_B
#define _________________COLEMAK_L2_________________        KC_A,     KC_R,     KC_S,     KC_T,     KC_G
#define _________________COLEMAK_L3_________________        KC_Z,     KC_X,     KC_C,     KC_D,     KC_V

#define _________________COLEMAK_R1_________________        KC_J,     KC_L,     KC_U,     KC_Y,     KC_QUOT
#define _________________COLEMAK_R2_________________        KC_M,     KC_N,     KC_E,     KC_I,     KC_O
#define _________________COLEMAK_R3_________________        KC_K,     KC_H,     KC_COMM,  KC_DOT,   KC_QUES

// Nav layer
#define __________________NAV_L1____________________        T_BASE,   OS_MEH,   REPEAT,   APP,      SW_LANG
#define __________________NAV_L2____________________        ______________MODS_L______________,     SW_WIN
#define __________________NAV_L3____________________        HUD,      ESC,      SCREEN_R, KC_TAB,   SW_PROF

#define __________________NAV_R1____________________        KC_PGDOWN,KC_HOME,  KC_INS,   KC_END,   TERM
#define __________________NAV_R2____________________        KC_PGUP,  KC_LEFT,  KC_DOWN,  KC_UP,    KC_RIGHT
#define __________________NAV_R3____________________        PS,       KC_ENTER, SEL_L,    DEL,      CAPSWORD

// Sym layer
#define __________________SYM_L1____________________        KC_TILD,  KC_LCBR,  LBRACK,  KC_LPRN,   KC_SCOLON
#define __________________SYM_L2____________________        KC_MINUS, KC_PLUS,  KC_EQUAL,KC_UNDS,   KC_HASH
#define __________________SYM_L3____________________        KC_ASTR,  KC_PIPE,  KC_AT,   KC_SLASH,  KC_PERC

#define __________________SYM_R1____________________        KC_CIRC,  KC_RPRN,  RBRACK,  KC_RCBR,   KC_GRAVE
#define __________________SYM_R2____________________        KC_DLR,   ______________MODS_R______________
#define __________________SYM_R3____________________        KC_COLON, KC_BSLASH,KC_AMPR, KC_EXLM,   TRANS

// Num layer
#define ___________________NUM_L1___________________        KC_7,     KC_5,     KC_3,     KC_1,     KC_9
#define ___________________NUM_L2___________________        ______________MODS_L______________,     KC_F11
#define ___________________NUM_L3___________________        KC_F7,    KC_F5,    KC_F3,    KC_F1,    KC_F9

#define ___________________NUM_R1___________________        KC_8,     KC_0,     KC_2,     KC_4,     KC_6
#define ___________________NUM_R2___________________        KC_F12,   ______________MODS_R______________
#define ___________________NUM_R3___________________        KC_F8,    KC_F10,   KC_F2,    KC_F4,    KC_F6

// Mouse layer
#define _________________MOUSE_L1___________________        CKP_PLS,  MBTN2,    MW_UP,    MBTN3,    CKP_MIN
#define _________________MOUSE_L2___________________        MLEFT,    MUP,      MDOWN,    MRIGHT,   H_RFRSH
#define _________________MOUSE_L3___________________        CKP_0,    MW_LEFT,  MW_DOWN,  MW_RIGHT, BACK

#define _________________MOUSE_R1___________________        DEVT,     PREVT,    TOP,      NEXTT,    T_BASE
#define _________________MOUSE_R2___________________        CLOSET,   ______________MODS_R______________
#define _________________MOUSE_R3___________________        FWD,      NEWTAB,   BOTTOM,   DUPT,     RETAB

// Meta layer
#define _________________META_L1____________________        SLEEP,    WAKE,     KC_NO,    T_BASE,   RESET
#define _________________META_L2____________________        KC_NO,    BR_UP,    BR_DOWN,  T_MOUSE,  KC_NO
#define _________________META_L3____________________        T_QWERTY, KC_NO,    KC_NO,    T_NAV,    EEP_RST

#define _________________META_R1____________________        M_PAUSE,  RGB_SPD,  RGB_SPI,  RGB_MOD,  RGB_TOG
#define _________________META_R2____________________        M_STOP,   RGB_VAD,  RGB_VAI,  RGB_HUD,  RGB_HUI
#define _________________META_R3____________________        MUTE,     M_PREV,   VOL_DOWN, VOL_UP,   M_NEXT

// Qwerty layer
#define ________________QWERTY_L1___________________        KC_Q,     KC_W,     KC_E,     KC_R,     KC_T
#define ________________QWERTY_L2___________________        KC_A,     KC_S,     KC_D,     KC_F,     KC_G
#define ________________QWERTY_L3___________________        KC_Z,     KC_X,     KC_C,     KC_V,     KC_B

#define ________________QWERTY_R1___________________        KC_Y,     KC_U,     KC_I,     KC_O,     KC_P
#define ________________QWERTY_R2___________________        KC_H,     KC_J,     KC_K,     KC_L,     KC_SCLN
#define ________________QWERTY_R3___________________        KC_N,     KC_M,     KC_COMM,  KC_DOT,   KC_SLSH

// layer tokens
#define LAYOUT_ferris(...)       LAYOUT(__VA_ARGS__)
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [_BASE] = LAYOUT_ferris(
    _________________COLEMAK_L1_________________,       _________________COLEMAK_R1_________________,
    _________________COLEMAK_L2_________________,       _________________COLEMAK_R2_________________,
    _________________COLEMAK_L3_________________,       _________________COLEMAK_R3_________________,
                            M_NAV,      OS_SHFT,        SP_MK,      M_SYM
  ),

  [_NAV] = LAYOUT_ferris(
    __________________NAV_L1____________________,       __________________NAV_R1____________________,
    __________________NAV_L2____________________,       __________________NAV_R2____________________,
    __________________NAV_L3____________________,       __________________NAV_R3____________________,
                            TRANS,      TRANS,          BS,         TRANS
  ),

  [_SYM] = LAYOUT_ferris(
    __________________SYM_L1____________________,       __________________SYM_R1____________________,
    __________________SYM_L2____________________,       __________________SYM_R2____________________,
    __________________SYM_L3____________________,       __________________SYM_R3____________________,
                            TRANS,      M_META,         TRANS,      TRANS
  ),

  [_NUM] = LAYOUT_ferris(
    ___________________NUM_L1___________________,       ___________________NUM_R1___________________,
    ___________________NUM_L2___________________,       ___________________NUM_R2___________________,
    ___________________NUM_L3___________________,       ___________________NUM_R3___________________,
                                __________________BLANK_4___________________
  ),

  [_MOUSE] = LAYOUT_ferris(
    _________________MOUSE_L1___________________,       _________________MOUSE_R1___________________,
    _________________MOUSE_L2___________________,       _________________MOUSE_R2___________________,
    _________________MOUSE_L3___________________,       _________________MOUSE_R3___________________,
                            MW_DOWN,    MBTN1,          MBTN1,      MW_DOWN
  ),

  [_META] = LAYOUT_ferris(
    _________________META_L1____________________,       _________________META_R1____________________,
    _________________META_L2____________________,       _________________META_R2____________________,
    _________________META_L3____________________,       _________________META_R3____________________,
                                __________________BLANK_4___________________
  ),

  [_QWERTY] = LAYOUT_ferris(
    ________________QWERTY_L1___________________,        ________________QWERTY_R1___________________,
    ________________QWERTY_L2___________________,        ________________QWERTY_R2___________________,
    ________________QWERTY_L3___________________,        ________________QWERTY_R3___________________,
                                __________________BLANK_4___________________
  )
};

// Callum OSM via https://github.com/callum-oakley/qmk_firmware/tree/master/users/callum
bool is_oneshot_cancel_key(uint16_t keycode) {
    switch (keycode) {
    case M_SYM:
    case M_NAV:
        return true;
    default:
        return false;
    }
}

bool is_oneshot_ignored_key(uint16_t keycode) {
    switch (keycode) {
    case M_SYM:
    case M_NAV:
    case KC_LSFT:
    case OS_SHFT:
    case OS_CTRL:
    case OS_ALT:
    case OS_GUI:
    case OS_MEH:
        return true;
    default:
        return false;
    }
}

bool sw_win_active = false;
bool sw_lang_active = false;

oneshot_state os_shft_state = os_up_unqueued;
oneshot_state os_ctrl_state = os_up_unqueued;
oneshot_state os_alt_state = os_up_unqueued;
oneshot_state os_gui_state = os_up_unqueued;
oneshot_state os_meh_state = os_up_unqueued;

// Used to extract the basic tapping keycode from a dual-role key.
// Example: GET_TAP_KC(MT(MOD_RSFT, KC_E)) == KC_E
#define GET_TAP_KC(dual_role_key) dual_role_key & 0xFF
uint16_t last_keycode = KC_NO;
uint8_t last_modifier = 0;

// Initialize variables holding the bitfield
// representation of active modifiers.
uint8_t mod_state;
uint8_t oneshot_mod_state;

void process_repeat_key(uint16_t keycode, const keyrecord_t *record) {
    if (keycode != REPEAT) {
        last_modifier = oneshot_mod_state > mod_state ? oneshot_mod_state : mod_state;
        switch (keycode) {
            case QK_LAYER_TAP ... QK_LAYER_TAP_MAX:
            case QK_MOD_TAP ... QK_MOD_TAP_MAX:
                if (record->event.pressed) {
                    last_keycode = GET_TAP_KC(keycode);
                }
                break;
            case QK_MOMENTARY ... QK_MOMENTARY_MAX:
                return; // to avoid modifier loss
            default:
                if (record->event.pressed) {
                    last_keycode = keycode;
                }
                break;
        }
    } else { // keycode == REPEAT
        if (record->event.pressed) {
            register_mods(last_modifier);
            register_code16(last_keycode);
        } else {
            unregister_code16(last_keycode);
            unregister_mods(last_modifier);
        }
    }
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    // via https://github.com/callum-oakley/qmk_firmware/tree/master/users/callum
    // single key alt tab and shift alt for layers
    update_swapper(
        &sw_win_active, KC_LALT, KC_TAB, SW_WIN,
        keycode, record
    );
    update_swapper(
        &sw_lang_active, KC_LSHIFT, KC_LALT, SW_LANG,
        keycode, record
    );

    // via https://github.com/callum-oakley/qmk_firmware/tree/master/users/callum
    // one shot implementation w/o timers
    update_oneshot(
        &os_shft_state, KC_LSHIFT, OS_SHFT,
        keycode, record
    );
    update_oneshot(
        &os_ctrl_state, KC_LCTL, OS_CTRL,
        keycode, record
    );
    update_oneshot(
        &os_alt_state, KC_LALT, OS_ALT,
        keycode, record
    );
    update_oneshot(
        &os_gui_state, KC_LGUI, OS_GUI,
        keycode, record
    );
    update_oneshot(
        &os_meh_state, KC_MEH, OS_MEH,
        keycode, record
    );

  switch (keycode) {
    // select line
    case SEL_L:
        if (record->event.pressed) {
            SEND_STRING(SS_TAP(X_HOME) SS_DELAY(100) SS_LSFT(SS_TAP(X_END)));
        }
        break;

    // tab to first profile in edge
    case SW_PROF:
        if (record->event.pressed) {
            SEND_STRING(SS_TAP(X_LALT) SS_DELAY(100) SS_LSFT(SS_TAP(X_TAB)) SS_DELAY(100) SS_TAP(X_SPACE) SS_DELAY(100) SS_TAP(X_TAB));
        }
        break;

        case CAPSWORD:
             if (record->event.pressed) {
                return false;
            } else {
                caps_word_toggle();
                return false;
        }
    }

    process_caps_word(keycode, record);

    process_repeat_key(keycode, record);
    // It's important to update the mod variables *after* calling process_repeat_key, or else
    // only a single modifier from the previous key is repeated (e.g. Ctrl+Shift+T then Repeat produces Shift+T)
    mod_state = get_mods();
    oneshot_mod_state = get_oneshot_mods();

    return true;
}

layer_state_t layer_state_set_user(layer_state_t state) {
    return update_tri_layer_state(state, _SYM, _NAV, _NUM);
}
