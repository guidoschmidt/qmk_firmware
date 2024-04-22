#include QMK_KEYBOARD_H

#include "keymap_german.h"

extern keymap_config_t keymap_config;

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.
#define _BASE 0
#define _FN1 1
#define _FNPP 2
#define _FNSP 3

#define DE_LESS DE_CIRC
#define DE_MORE DE_DEG

enum custom_keycodes {
  QWERTY = SAFE_RANGE,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_BASE] = LAYOUT_65_with_macro(
    KC_F1,        KC_F2,       KC_ESC,   KC_1,     KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    DE_ASTR, KC_RBRC, _______, KC_BSPC, KC_DEL , \
    KC_F3,        KC_F4,       KC_TAB,   DE_UDIA,  KC_COMM, KC_DOT,  KC_P,    DE_Y,    KC_F,    KC_G,    KC_C,    KC_T,    DE_Z,    DE_SS,   DE_QUES, DE_ACUT, KC_END, \
    QK_BOOTLOADER,KC_F6,       KC_LCTL,  KC_A,     KC_O,    KC_E,    KC_I,    KC_U,    KC_H,    KC_D,    KC_R,    KC_N,    KC_S,    KC_L,    DE_MINS, KC_PGUP, \
    KC_F7,        KC_F8,       KC_LSFT,  DE_ODIA,  KC_Q,    KC_J,    KC_K,    KC_X,    KC_B,    KC_M,    KC_W,    KC_V,    DE_HASH, KC_RSFT, KC_UP,   KC_PGDN, \
    MO(_FNSP),    KC_F10,      MO(_FN1), MO(_FNPP),KC_LALT, KC_LGUI, KC_SPC,           MO(_FN1),KC_ENT,  KC_RALT, KC_APP, KC_RGUI, KC_LEFT, KC_DOWN, KC_RGHT
  ),

  [_FN1] = LAYOUT_65_with_macro(
    _______, _______,     KC_ESC,  KC_F1,     KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_DEL,  KC_DEL, _______, \
    _______, _______,     RGB_TOG, RGB_MOD,   _______, _______, _______, _______, _______, _______, KC_UP  , _______, _______, _______, _______, _______, _______, \
    _______, _______,     _______, DE_ADIA,   _______, _______, _______, _______, _______, KC_LEFT, KC_DOWN, KC_RGHT, _______, _______, _______, _______, \
    _______, _______,     _______, _______,   _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
    _______, _______,     _______, _______,   _______, _______, _______,          _______, _______, _______, _______, _______, _______, _______, _______
  ),

  [_FNPP] = LAYOUT_65_with_macro(
    _______, _______,     DE_CIRC, RGB_M_P, RGB_M_B, RGB_M_SW, RGB_M_G, _______, _______, KC_NUBS, LSFT(KC_NUBS), RALT(KC_NUBS), DE_TILD, _______, _______, _______, _______, QK_BOOTLOADER, \
    _______, _______,     RGB_TOG, RGB_HUI, RGB_SAI, RGB_VAI, _______, _______, DE_LBRC, DE_LCBR, DE_RCBR, DE_RBRC, _______, _______, _______, _______, _______, \
    _______, _______,     _______, _______, _______, _______, _______, _______, DE_SLSH, DE_LPRN, DE_RPRN, DE_BSLS, _______, _______, _______, _______, \
    _______, _______,     _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
    _______, _______,     _______, _______, _______, _______, _______,          _______, _______, _______, _______, _______, _______, _______, _______
  ),

  [_FNSP] = LAYOUT_65_with_macro(
    _______, _______,     _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
    _______, _______,     RGB_TOG, RGB_MOD, _______, _______, _______, _______, _______, _______, KC_MS_U, _______, _______, _______, _______, _______, _______, \
    _______, _______,     _______, _______, _______, _______, _______, _______, _______, KC_MS_L, KC_MS_D, KC_MS_R, _______, _______, _______, _______, \
    _______, _______,     _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,  _______, _______, _______, \
    _______, _______,     _______, _______, _______, _______, _______,          _______, KC_BTN1, KC_BTN2, _______, _______,  _______, _______, _______
  )
};

bool encoder_update_user(uint8_t index, bool clockwise) {
    if (index == 0) {
        // Base layer (you can also use the enums in `enum layer_names` instead of 0, 1, 2, etc.)
        if (layer_state_is(0)) {
            if (clockwise) {
                tap_code(KC_VOLU);
            } else {
                tap_code(KC_VOLD);
            }
        } else if (layer_state_is(1)) {
            if (clockwise) {
                tap_code(KC_PGDN);
            } else {
                tap_code(KC_PGUP);
            }
        }
    }
    return false;
}
