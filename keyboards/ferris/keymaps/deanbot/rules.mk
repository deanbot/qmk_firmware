# BOOTLOADER = atmel-dfu

TAP_DANCE_ENABLE = no

MOUSEKEY_ENABLE = yes

RGBLIGHT_ENABLE = no

COMBO_ENABLE = yes

# reduce filesize
CONSOLE_ENABLE = no
COMMAND_ENABLE = no
EXTRAFLAGS += -flto

SRC += swapper.c
SRC += oneshot.c
