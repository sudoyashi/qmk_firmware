/* Copyright 2015-2017 Jack Humbert
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
 *
 * Added Tap Dance features: ESC/F11; ;/:
 *
 *
 *
 *
 *
 *
 *
*/
#include QMK_KEYBOARD_H
#include "tap.h"

extern keymap_config_t keymap_config;

enum sudoyashi_layers {
  _QWERTY,
  _COLEMAK,
  _LOWER,
  _RAISE,
  _ADJUST
};

enum sudoyashi_keycodes {
  COLEMAK = SAFE_RANGE,
  QWERTY,
  BACKLIT,
};

#define LOWER MO(_LOWER)
#define RAISE MO(_RAISE)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

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
      KC_ESC,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC,
      KC_TAB,  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,
      KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_ENT ,
      KC_LCTL, KC_LGUI, KC_LALT, KC_F4 , LOWER,   KC_SPC,  KC_SPC,   RAISE,   KC_LEFT, KC_DOWN, KC_UP, KC_RIGHT
  ),

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
      TD(TD_FULL), KC_Q,    KC_W,    KC_F,    KC_P,    KC_G,    KC_J,    KC_L,    KC_U,    KC_Y,    TD(CT_SCLN), KC_BSPC,
      KC_TAB,      KC_A,    KC_R,    KC_S,    KC_T,    KC_D,    KC_H,    KC_N,    KC_E,    KC_I,    KC_O,        KC_QUOT,
      KC_LSFT,     KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_K,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH,     KC_ENT,
      KC_LCTL,     KC_LGUI, KC_LALT, KC_F4 ,  LOWER,   KC_SPC,  KC_SPC,  RAISE,   KC_LEFT, KC_DOWN, KC_UP,       KC_RIGHT
  ),


/* Lower
 * ,-----------------------------------------------------------------------------------.
 * |   ~  |   !  |   @  |   #  |   $  |   %  |   ^  |   &  |   *  |   -  |  =   | Bksp |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Del  | Vol- | Vol+ | Prev | Play | Next |  (   |   )  |  [   |  ]   |      |  |   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |LShift|      |      |     |      |      |  <   |  >   |  {   |   }  | Home | PgUp |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Ctrl | F4   | GUI   | Alt  |     |            |      |      |      |  End  | PgDn |
 * `-----------------------------------------------------------------------------------'
 */

[_LOWER] = LAYOUT_planck_grid(
    KC_TILD,   KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, KC_CIRC, KC_AMPR, KC_ASTR, KC_MINUS, KC_EQUAL, KC_BSPC,
    KC_VOLD,   KC_VOLU, KC_MPRV, KC_MPLY, KC_MNXT, KC_MSTP, KC_LPRN, KC_RPRN, KC_LBRC, KC_RBRC, _______,  KC_PIPE,
    KC_LSHIFT, _______, _______, _______, _______, _______, KC_LABK, KC_RABK, KC_LCBR, KC_RCBR, _______,  _______,
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
    KC_GRV,   KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,     KC_9,    KC_0,    KC_BSPC,
    KC_DEL,   KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   _______, _______, _______, _______, _______,
    KC_LSHIFT,KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_BRID, KC_BRIU,  KC_END,  KC_PGDN, _______,
    _______,  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
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
    RESET,  _______,  DEBUG,   _______, _______, _______, KC_PSCREEN, _______, _______,  _______, _______, KC_DEL ,
    AU_ON,  MU_TOG,  MU_MOD,  _______, _______,  AG_NORM, AG_SWAP,    QWERTY,  COLEMAK,  _______, _______, _______,
    AU_OFF, MUV_DE,   MUV_IN,  MU_ON,   MU_OFF,  MI_ON,   MI_OFF,     TERM_ON, TERM_OFF, _______, _______, _______,
    _______,  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
)

};

#ifdef AUDIO_ENABLE
  float tone_startup[][2]    = SONG(SONIC_RING);
  float tone_qwerty[][2]     = SONG(SONIC_RING);
  float tone_colemak[][2]    = SONG(SONIC_RING);
  float tone_goodbye[][2] = SONG(GOODBYE_SOUND);
#endif

uint32_t layer_state_set_user(uint32_t state) {
  return update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case QWERTY:
      if (record->event.pressed) {
        print("mode just switched to qwerty and this is a huge string\n");
        set_single_persistent_default_layer(_QWERTY);
      }
      return false;
      break;
    case COLEMAK:
      if (record->event.pressed) {
        print("C O L E M A K L Y F E\n");
        set_single_persistent_default_layer(_COLEMAK);
      }
      return false;
      break;
    case BACKLIT:
      if (record->event.pressed) {
        register_code(KC_RSFT);
        #ifdef BACKLIGHT_ENABLE
          backlight_step();
        #endif
        #ifdef KEYBOARD_planck_rev5
          PORTE &= ~(1<<6);
        #endif
      } else {
        unregister_code(KC_RSFT);
        #ifdef KEYBOARD_planck_rev5
          PORTE |= (1<<6);
        #endif
      }
      return false;
      break;
  }

  return true;

}

bool muse_mode = false;
uint8_t last_muse_note = 0;
uint16_t muse_counter = 0;
uint8_t muse_offset = 70;
uint16_t muse_tempo = 50;

bool music_mask_user(uint16_t keycode) {
  switch (keycode) {
    case RAISE:
    case LOWER:
      return false;
    default:
      return true;
  }
}
