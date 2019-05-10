//Tap Dance Declarations
#include QMK_KEYBOARD_H

  enum custom_kc {
    CT_SCLN = 0,
    TD_FULL,
    COPY_PASTE
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
   [TD_FULL] = ACTION_TAP_DANCE_DOUBLE(KC_ESC, KC_F11),
   [COPY_PASTE] = ACTION_TAP_DANCE_DOUBLE(COPY, PASTE)
  };
