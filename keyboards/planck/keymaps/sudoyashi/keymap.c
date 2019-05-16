// Planck keymap, sudoyashi

#include QMK_KEYBOARD_H
#include "muse.h"
#include "tap.h"

extern keymap_config_t keymap_config;

enum layers {
  _QWERTY,
  _COLEMAK,
  _LOWER,
  _RAISE,
  _ADJUST
};

enum keycodes {
  QWERTY,
  COLEMAK = SAFE_RANGE,
  COPY,
  PASTE,
  M_EMAIL
};

#define LOWER MO(_LOWER)
#define RAISE MO(_RAISE)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  /* Colemak
   * ,-----------------------------------------------------------------------------------.
   * | Esc  |   Q  |   W  |   F  |   P  |   G  |   J  |   L  |   U  |   Y  |   ;  | Bksp |
   * |------+------+------+------+------+-------------+------+------+------+------+------|
   * | Tab  |   A  |   R  |   S  |   T  |   D  |   H  |   N  |   E  |   I  |   O  |   '  |
   * |------+------+------+------+------+------|------+------+------+------+------+------|
   * | Shift|   Z  |   X  |   C  |   V  |   B  |   K  |   M  |   ,  |   .  |   /  | Enter|
   * |------+------+------+------+------+------+------+------+------+------+------+------|
   * | Ctrl |  F4  | LGUI | Alt  |Lower |    Space    |Raise | Left | Down | Up   |Right |
   * `-----------------------------------------------------------------------------------'
   */

  [_COLEMAK] = LAYOUT_planck_grid(
      TD(ENT_ESC), KC_Q,    KC_W,    KC_F,    KC_P,    KC_G,    KC_J,    KC_L,    KC_U,    KC_Y,    TD(CT_SCLN), KC_BSPC,
      KC_TAB,      KC_A,    KC_R,    KC_S,    KC_T,    KC_D,    KC_H,    KC_N,    KC_E,    KC_I,    KC_O,        KC_QUOT,
      KC_LSFT,     KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_K,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH,     KC_ENT,
      TD(CT_FULL), KC_LGUI, KC_LALT, KC_F4 ,  LOWER,   KC_SPC,  KC_SPC,  RAISE,   KC_LEFT, KC_DOWN, KC_UP,       KC_RIGHT
  ),

  /* Qwerty
   * ,-----------------------------------------------------------------------------------.
   * | Esc  |   Q  |   W  |   E  |   R  |   T  |   Y  |   U  |   I  |   O  |   P  | Bksp |
   * |------+------+------+------+------+-------------+------+------+------+------+------|
   * | Tab  |   A  |   S  |   D  |   F  |   G  |   H  |   J  |   K  |   L  |   ;  |  '   |
   * |------+------+------+------+------+------|------+------+------+------+------+------|
   * | Shift|   Z  |   X  |   C  |   V  |   B  |   N  |   M  |   ,  |   .  |   /  |Enter |
   * |------------+------+------+------+------+------+------+------+-------+------+------|
   * | Ctrl | F4   | Alt  | Lower| GUI  |    Space    |Raise |Left|Down+PDn|Up+PUp|Right |
   * `-----------------------------------------------------------------------------------'
   */
  [_QWERTY] = LAYOUT_planck_grid(
      TD(ENT_ESC), KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC,
      KC_TAB,      KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,
      KC_LSFT,     KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_ENT ,
      TD(CT_FULL), KC_LGUI, KC_LALT, KC_F4 , LOWER,   KC_SPC,  KC_SPC,   RAISE,   KC_LEFT, KC_DOWN, KC_UP, KC_RIGHT
  ),

/* Lower
 * ,-----------------------------------------------------------------------------------.
 * |   ~  |   !  |   @  |   #  |   $  |   %  |   ^  |   &  |   *  |   -  |  =   | Bksp |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Del  | Vol- | Vol+ | Prev | Play | Next |  (   |   )  |  [   |  ]   |      |  |   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |LShift|      |      |CP+PST|      |      |  <   |  >   |  {   |   }  | Home | PgUp |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Ctrl | F4   | GUI   | Alt  |     |            |      |      |      |  End  | PgDn |
 * `-----------------------------------------------------------------------------------'
 */

[_LOWER] = LAYOUT_planck_grid(
    KC_TILD,   KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, KC_CIRC, KC_AMPR, KC_ASTR, KC_MINUS, KC_EQUAL, KC_BSPC,
    KC_ESC,    KC_VOLU, KC_MPRV, KC_MPLY, KC_MNXT, KC_MSTP, KC_LPRN, KC_RPRN,  KC_LBRC, KC_RBRC, _______,  KC_BSLS,
    KC_LSHIFT, KC_VOLD, M_EMAIL, _______, _______, _______, KC_LABK, KC_RABK, KC_LCBR, KC_RCBR, _______,  _______,
    _______,   _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,  _______
),


/* Raise
 * ,------------------------------------   KC_F5-----------------------------------------------.
 * |   `  |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  | Bksp |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Del  |  F4  |  F1  |  F2  |  F3  |  F5  |  F6  |BrghtU|BrghtD| Home | PgUg |  \   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * | Alt  |  F7  |  F8  |  F9  |  F10 |  F11 |  F12 |ISO # |ISO / | End  | PgDn | Pg Up|
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | LCtrl|  F4  | GUI  |  Alt |      |             |      |      |      |      | Pg Dn|
 * `-----------------------------------------------------------------------------------'
 */
[_RAISE] = LAYOUT_planck_grid(
    KC_GRV,   KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,     KC_9,   KC_0,    KC_BSPC,
    KC_DEL,   KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   _______, KC_HOME, KC_END,  KC_PGUP, KC_PGDN,
    KC_LSHIFT,KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  _______, KC_LEFT, KC_DOWN, KC_UP,   KC_RIGHT,
    BL_STEP,  BL_OFF,  BL_DEC,  BL_INC,  _______, _______, _______, _______, _______, KC_BRID, KC_BRID, _______
),

/* Adjust (Lower + Raise)
 * ,-----------------------------------------------------------------------------------.
 * | Reset|      | Debug|      |      |      |PrtScrn|      |      |      |      |  Del |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |Aud on| MuTog|MusMod|      |      |AGnorm|AGswap|Qwerty|Colemk|      |      |      |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |Audoff|Voice-|Voice+|Mus on|Musoff|MIDIon|MIDIof|      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */

[_ADJUST] = LAYOUT_planck_grid(
    RESET,   _______, DEBUG,   _______, _______, _______, _______, _______, _______, _______, _______, KC_PSCR ,
    AU_ON,   MU_TOG,  MU_MOD,  _______, _______, AG_SWAP, AG_NORM, _______, _______, _______, _______, QWERTY,
    AU_OFF,  MUV_DE,  MUV_IN,  MU_ON,   MU_OFF,  MI_ON,   MI_OFF,  _______, _______, _______, _______, COLEMAK,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
)

};

uint32_t layer_state_set_user(uint32_t state) {
  return update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case COLEMAK:
      if (record->event.pressed) {
        print("COLEMAK\n");
        set_single_persistent_default_layer(_COLEMAK);
      }
      return false;
      break;
    case QWERTY:
      if (record->event.pressed) {
        print("QWERTY\n");
        set_single_persistent_default_layer(_QWERTY);
      }
      return false;
      break;

    // MACRO -- Ctrl + C, only for windows
    case COPY:
      if (record->event.pressed) {
        //Event happens when COPY_PASTE IS PRESSED
        SEND_STRING(SS_LCTRL("c"));
        } else {  //Event happens when COPY IS RELEASED
          }
      break;

    // MACRO -- Ctrl + V, only for windows
    case PASTE:
      if (record->event.pressed) {
        //Event happens when COPY_PASTE IS PRESSED
        SEND_STRING(SS_LCTRL("v"));
        } else {
          }
      break;


    // MACRO -- write down email
    case M_EMAIL:
      if (record->event.pressed) {
        SEND_STRING("joshuapdhawaii@gmail.com");
        } else {
          }
    break;

  }

  return true;
}

bool muse_mode = false;
uint8_t last_muse_note = 0;
uint16_t muse_counter = 0;
uint8_t muse_offset = 70;
uint16_t muse_tempo = 50;


void encoder_update_user(uint8_t index, bool clockwise) {
  if (IS_LAYER_ON(_LOWER)) {
      if (clockwise) {
        tap_code(KC_F3);
      }
     else { tap_code(KC_F2);
      }
  }

  if (IS_LAYER_ON(_RAISE)) {
        if (clockwise) {
      tap_code(KC_UP);
    } else {
      tap_code(KC_DOWN);
    }
  }

  if (IS_LAYER_ON(_COLEMAK)) {
    if (clockwise) {
      tap_code(KC__VOLDOWN);
    }
    else { tap_code(KC__VOLUP);
    }
  }

}
