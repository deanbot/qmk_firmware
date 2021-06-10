#pragma once

#include QMK_KEYBOARD_H

// This function should be called inside proces_record_user and does everything needed to get one shot modifiers working.
// Returns true if the keycode needs further handling, false otherwise.

bool update_oneshot_modifiers(uint16_t keycode, keyrecord_t *record);

// TO BE IMPLEMENTED BY THE COMSUMER
// This functiotn should return the keycode of the modifier to be triggered for a given (custom) keycode.
uint16_t get_modifier_for_trigger_key(uint16_t keycode);

// TO BE IMPLEMENTED BY THE COMSUMER
// This function should return true for keycodes that must be ignored in the oneshot modifier behaviour.
// You probably want to ignore layer keys. Trigger keys don't need to be specified here.
bool is_oneshot_modifier_ignored_key(uint16_t keycode);

// TO BE IMPLEMENTED BY THE COMSUMER
// This function should return true for keycodes that should reset all oneshot modifiers.
bool is_oneshot_modifier_cancel_key(uint16_t keycode);
