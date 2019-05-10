//Tap Dance Declarations
#include QMK_KEYBOARD_H

typedef struct {
  bool is_press_action;
  int state;
} tap;

  enum custom_kc {
    CT_SCLN = 0,
    ENT_ESC,
    CPPS,
    CT_FULL
  };


  void dance_cln_finished (qk_tap_dance_state_t *state, void *user_data) {
    if (state->count == 1) {
      register_code (KC_SCLN);
    } else {
      register_code (KC_RSFT);
      register_code (KC_SCLN);
    }
  }

  void dance_cln_reset (qk_tap_dance_state_t *state, void *user_data) {
    if (state->count == 1) {
      unregister_code (KC_SCLN);
    } else {
      unregister_code (KC_RSFT);
      unregister_code (KC_SCLN);
    }
  }


  // Declare tap dance actions
  qk_tap_dance_action_t tap_dance_actions[] = {
   [CT_SCLN] = ACTION_TAP_DANCE_FN_ADVANCED (NULL, dance_cln_finished, dance_cln_reset),
   [ENT_ESC] = ACTION_TAP_DANCE_DOUBLE(KC_ENT, KC_ESC),
   [CPPS] = ACTION_TAP_DANCE_DOUBLE(COPY, PASTE),
   [CT_FULL] = ACTION_TAP_DANCE_DOUBLE(KC_LCTL, KC_F11)
  };
