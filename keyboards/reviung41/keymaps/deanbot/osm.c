#include "osm.h"

// the basic states a oneshot modifier can be in
typedef enum {
    UP_OFF,
    DOWN_ON_TO_UP_ON,
    UP_ON,
    DOWN_ON_TO_UP_OFF,
} oneshot_state;

typedef struct modifier_with_state {
    uint16_t      modifier_keycode;
    oneshot_state oneshot_state;
} modifier_with_state;


// array which holds the state of all 8 possible modifiers
// safe to remove soms of these when not used

#define NUMBER_OF_MODIFIERS 8
modifier_with_state modifiers_with_state[NUMBER_OF_MODIFIERS] = {
    {.modifier_keycode = KC_LSFT, .oneshot_state = UP_OFF},
	{.modifier_keycode = KC_LGUI, .oneshot_state = UP_OFF},
	{.modifier_keycode = KC_LCTL, .oneshot_state = UP_OFF},
	{.modifier_keycode = KC_LALT, .oneshot_state = UP_OFF},
	{.modifier_keycode = KC_RSFT, .oneshot_state = UP_OFF},
	{.modifier_keycode = KC_RGUI, .oneshot_state = UP_OFF},
	{.modifier_keycode = KC_RCTL, .oneshot_state = UP_OFF},
	{.modifier_keycode = KC_RALT, .oneshot_state = UP_OFF},
};

// oneshot mods always get registered imidiately to the operating system, but we also
// need to keep track if the mod(s) got combined with a normal key (applied)
bool unapplied_mods_present = false;

// keycode of the last pressed 'normal' key which haven't been released yet
uint16_t repeating_normal_key = 0;

// utility functions (implemented on bottom of this file)
void set_modifier_state(uint16_t modifier_keycode, oneshot_state new_state);
void set_modifier_state_all(oneshot_state new_state);
void set_modifier_state_all_from_to(oneshot_state oneshot_state_from, oneshot_state oneshot_state_to);
oneshot_state get_modifier_state(uint16_t modifier_keycode);
bool all_modifiers_have_state(oneshot_state state);

// registers/unregisters a mod to the operating system on state change if necessary
void update_modifier(uint16_t modifier_keycode, oneshot_state previous_state, oneshot_state current_state) {
    if (previous_state == current_state) {
        return;
    }
    if (previous_state == UP_OFF) {
        register_code(modifier_keycode);
    } else if (current_state == UP_OFF) {
        unregister_code(modifier_keycode);
    }
}

// see comment in corresponding headerfile
bool update_oneshot_modifiers(uint16_t keycode, keyrecord_t *record) {
    // ignored keys
    if (is_oneshot_modifier_ignored_key(keycode)) {
        return true;
    }

    // cancel keys
    if (is_oneshot_modifier_cancel_key(keycode) && record->event.pressed) {
        unapplied_mods_present = false;
        set_modifier_state_all(UP_OFF);
        return false;
    }

    uint16_t modifier_keycode = get_modifier_for_trigger_key(keycode);

    // trigger keys
    if (modifier_keycode != 0) {
        oneshot_state state = get_modifier_state(modifier_keycode);
        if (record->event.pressed) {
            if (state == UP_OFF) {
                set_modifier_state(modifier_keycode, DOWN_ON_TO_UP_ON);
                unapplied_mods_present = (repeating_normal_key == 0);
            } else if (state == UP_ON) {
                set_modifier_state(modifier_keycode, DOWN_ON_TO_UP_OFF);
            }
        } else {
            if (state == DOWN_ON_TO_UP_ON) {
                if (!unapplied_mods_present) {
                    set_modifier_state(modifier_keycode, UP_OFF);
                } else {
                    set_modifier_state(modifier_keycode, UP_ON);
                }
            } else if (state == DOWN_ON_TO_UP_OFF) {
                set_modifier_state(modifier_keycode, UP_OFF);
            }
        }
    }
    // normal keys
    else {
        if (record->event.pressed) {
            if (!all_modifiers_have_state(UP_OFF)) {
                if (unapplied_mods_present) {
                    unapplied_mods_present = false;
                } else {
                    unregister_code(repeating_normal_key);
                    set_modifier_state_all_from_to(UP_ON, UP_OFF);
                }
            }
            repeating_normal_key = keycode;
        } else {
            if (!all_modifiers_have_state(UP_OFF)) {
                unregister_code(keycode);
                set_modifier_state_all_from_to(UP_ON, UP_OFF);
            }
            repeating_normal_key = 0;
        }
    }

    return true;
}

// implementation of utility functions
void set_modifier_state(uint16_t modifier_keycode, oneshot_state new_state) {
    for (size_t i = 0; i < NUMBER_OF_MODIFIERS; i++) {
        oneshot_state previous_state = modifiers_with_state[i].oneshot_state;
        if (modifiers_with_state[i].modifier_keycode == modifier_keycode) {
            modifiers_with_state[i].oneshot_state = new_state;
            update_modifier(modifier_keycode, previous_state, new_state);
            return;
        }
    }
}

void set_modifier_state_all(oneshot_state new_state) {
    for (size_t i = 0; i < NUMBER_OF_MODIFIERS; i++) {
        uint16_t      modifier_keycode        = modifiers_with_state[i].modifier_keycode;
        oneshot_state previous_state          = modifiers_with_state[i].oneshot_state;
        modifiers_with_state[i].oneshot_state = new_state;
        update_modifier(modifier_keycode, previous_state, new_state);
    }
}

void set_modifier_state_all_from_to(oneshot_state oneshot_state_from, oneshot_state oneshot_state_to) {
    for (size_t i = 0; i < NUMBER_OF_MODIFIERS; i++) {
        if (modifiers_with_state[i].oneshot_state == oneshot_state_from) {
            modifiers_with_state[i].oneshot_state = oneshot_state_to;
            uint16_t modifier_keycode             = modifiers_with_state[i].modifier_keycode;
            update_modifier(modifier_keycode, oneshot_state_from, oneshot_state_to);
        }
    }
}

oneshot_state get_modifier_state(uint16_t modifier_keycode) {
    for (size_t i = 0; i < NUMBER_OF_MODIFIERS; i++) {
        if (modifiers_with_state[i].modifier_keycode == modifier_keycode) {
            return modifiers_with_state[i].oneshot_state;
        }
    }
}

bool all_modifiers_have_state(oneshot_state state) {
    for (size_t i = 0; i < NUMBER_OF_MODIFIERS; i++) {
        if (modifiers_with_state[i].oneshot_state != state) {
            return false;
        }
    }
    return true;
}
