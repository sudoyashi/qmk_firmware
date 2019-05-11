#include QMK_KEYBOARD_H

extern keymap_config_t keymap_config;


enum layers {
  _COLEMAK,
  _QWERTY,
  _LOWER,
  _RAISE,
  _ADJUST
};
enum custom_keycodes {
  COLEMAK = SAFE_RANGE,
  QWERTY,
  LOWER,
  RAISE,
  ADJUST,
  COPY,
  PASTE,
  M_EMAIL
};


#include "tap.h"
#define LOWER MO(_LOWER)
#define RAISE MO(_RAISE)
#define ADJUST MO(_ADJUST)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  /*  Colemak
   *
   * ,-----------------------------------------.    ,-----------------------------------------.
   * |Esc++ |  Q   |  W   |  F   |  P   |  G   |    |  J   |  L   |  U   |  Y   |  ;++ | Bksp |
   * |------+------+------+------+------+------|    |------+------+------+------+------+------|
   * | Tab  |  A   |  R   |  S   |  T   |  D   |    |  H   |  N   |  E   |  I   |  O   |  '   |
   * |------+------+------+------+------+------|    |------+------+------+------+------+------|
   * | Shift|  Z   |  X   |  C   |  V   |  B   |    |  N   |  M   |  ,   |  .   |  /   | Enter|
   * |------+------+------+------+------+------|    |------+------+------+------+------+------|
   * | Ctrl | Win  | Alt  | Lower| Space| Space|    | Space| Space| Raise|  @   |  _   |Adjust|
   * `-----------------------------------------'    `-----------------------------------------'
   *
   */

  [_COLEMAK] = LAYOUT_ortho_4x12( \
    TD(ENT_ESC),  KC_Q,    KC_W,    KC_F,    KC_P,    KC_G,    KC_J,    KC_L,    KC_U,    KC_Y,    TD(CT_SCLN), KC_BSPC, \
    KC_TAB,       KC_A,    KC_R,    KC_S,    KC_T,    KC_D,    KC_H,    KC_N,    KC_E,    KC_I,    KC_O,        KC_QUOT, \
    KC_LSFT,      KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_K,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH,     KC_ENT , \
    TD(CT_FULL),      KC_LGUI, KC_LALT, LOWER,   KC_SPC,  KC_SPC,  KC_SPC,  KC_SPC,  RAISE,   KC_AT,   KC_MINS,     ADJUST \
  ),

  /* Qwerty
   *
   * ,-----------------------------------------.    ,-----------------------------------------.
   * | Esc++|  Q   |  W   |  E   |  R   |  T   |    |  Y   |  U   |  I   |  O   |  P   | Bksp |
   * |------+------+------+------+------+------|    |------+------+------+------+------+------|
   * | Tab  |  A   |  S   |  D   |  F   |  G   |    |  H   |  J   |  K   |  L   |  ;++ |  '   |
   * |------+------+------+------+------+------|    |------+------+------+------+------+------|
   * | Shift|  Z   |  X   |  C   |  V   |  B   |    |  N   |  M   |  ,   |  .   |  /   | Enter|
   * |------+------+------+------+------+------|    |------+------+------+------+------+------|
   * | Ctrl | Win  | Alt  | Lower| Space| Space|    | Space| Space| Raise|  @   |  -   |Adjust|
   * `-----------------------------------------'    `-----------------------------------------'
   *
   */
[_QWERTY] = LAYOUT_ortho_4x12(
  TD(ENT_ESC),  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,        KC_BSPC, \
  KC_ESC,       KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    TD(CT_SCLN), KC_QUOT, \
  KC_LSFT,      KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH,     KC_ENT , \
  TD(CT_FULL),  KC_LGUI, KC_LALT, LOWER,   KC_SPC,  KC_SPC,  KC_SPC,  KC_SPC,  RAISE,   KC_AT,   KC_MINS,     ADJUST \
  ),

/* Lower
 * ,-----------------------------------------.    ,-----------------------------------------.
 * |  ~   |  1   |  2   |  3   |  4   |  5   |    |  6   |  7   |  8   |  9   |  0   | Bspc |
 * |------+------+------+------+------+------|    |------+------+------+------+------+------|
 * | Vol- | Vol+ | < M  | PLAY |  M > | STOP |    |      |      |  -   |      |      |  |   |
 * |------+------+------+------+------+------|    |------+------+------+------+------+------|
 * |      |      |      |      |      |      |    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|    |------+------+------+------+------+------|
 * |      |      |      |      |      |      |    |      |      |      |      |      |      |
 * `-----------------------------------------'    `-----------------------------------------'
 *
 */

[_LOWER] = LAYOUT_ortho_4x12( \
  KC_TILD, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, KC_CIRC, KC_AMPR, KC_ASTR, KC_MINUS, KC_EQUAL, KC_BSPC, \
  KC_VOLD, KC_VOLU, KC_MPRV, KC_MPLY, KC_MNXT, KC_MSTP, _______, _______, KC_MINS, KC_EQL, _______, KC_BSLS, \
  _______, _______, _______, TD(CPPS), _______, _______, _______, KC_LABK, KC_RABK, KC_LCBR, KC_RCBR, _______, \
  _______, KC_F4,   KC_LALT, _______, _______, _______, _______, _______, _______, _______, _______, _______ \
),

/* Raise
 * ,-----------------------------------------.    ,-----------------------------------------.
 * |  `   |  1   |  2   |  3   |  4   |  5   |    |  6   |  &   |  Ins  |      |      |      |
 * |------+------+------+------+------+------|    |------+------+------+------+------+------|
 * | Del  |  F1  |  F2  |  F3  |  F4  |  F5  |    |  F6  |      | Home  | End | PgUp | PgDn |
 * |------+------+------+------+------+------|    |------+------+------+------+------+------|
 * |      |  F7  |  F8  |  F9  | F10  | F11  |    |  F12 |      | ←    |  ↓   |  ↑   |  →   |
 * |------+------+------+------+------+------|    |------+------+------+------+------+------|
 * |      |      |      |      |      |      |    |      |      |      |      |      |      |
 * `-----------------------------------------'    `-----------------------------------------'
 *
 */

[_RAISE] = LAYOUT_ortho_4x12( \
  KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_BSPC, \
  KC_DEL,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   _______, KC_HOME, KC_END,  KC_PGUP, KC_PGDN, \
  _______, KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  _______ ,KC_LEFT, KC_DOWN,  KC_UP,  KC_RIGHT, \
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,  _______ \
),


/* Adjust
 * ,-----------------------------------------------------------------------------------.
 * |      | Reset|      |      |      |      |      |      |      |      |      |  Del |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |      |      |      |      |AGSwag|AGNorm|      |      |      |      |Qwerty|
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |Colemk|
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_ADJUST] =  LAYOUT_ortho_4x12( \
  RESET,   _______, _______, _______, _______, RGB_M_P, RGB_M_B, RGB_M_R, RGB_M_SW, RGB_M_SN, RGB_M_K, KC_PSCR, \
  RGB_M_T, _______, _______, _______, _______, AG_SWAP, AG_NORM, RGB_TOG, RGB_HUI, RGB_VAI, RGB_SAI, QWERTY, \
  _______, _______, _______, _______, _______, _______, _______, RGB_MOD, RGB_HUD, RGB_VAD, RGB_SAD, COLEMAK, \
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______ \
)


};

void persistent_default_layer_set(uint16_t default_layer) {
  eeconfig_update_default_layer(default_layer);
  default_layer_set(default_layer);
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case QWERTY:
      if (record->event.pressed) {
        persistent_default_layer_set(1UL<<_QWERTY);
      }
      return false;
      break;
    case COLEMAK:
      if (record->event.pressed) {
        persistent_default_layer_set(1UL<<_COLEMAK);
      }
      return false;
      break;
    case LOWER:
      if (record->event.pressed) {
        layer_on(_LOWER);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      } else {
        layer_off(_LOWER);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      }
      return false;
      break;
    case RAISE:
      if (record->event.pressed) {
        layer_on(_RAISE);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      } else {
        layer_off(_RAISE);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      }
      return false;
      break;
    case ADJUST:
      if (record->event.pressed) {
        layer_on(_ADJUST);
      } else {
        layer_off(_ADJUST);
      }
      return false;
      break;
  }
  return true;
}
