#pragma once

// utilities
#define S_T(...)  LSFT_T(__VA_ARGS__)
#define C_T(...)  CTL_T(__VA_ARGS__)

void tap_key(uint16_t keycode)
{
  register_code  (keycode);
  unregister_code(keycode);
}
