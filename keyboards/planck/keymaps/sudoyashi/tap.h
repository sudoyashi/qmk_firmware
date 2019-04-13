//Tap Dance Declarations
#include QMK_KEYBOARD_H

typedef struct {
  bool is_press_action;
  int state;
} tap;

  enum yashi_custom_kc {
    TD_UP_PGUP = 0,
    TD_DN_PGDN = 1,
    CT_SE = 2,
    CT_SCLN,
    CT_EGG,
    CT_FLSH,
    X_TAP_DANCE

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
   [TD_UP_PGUP]  = ACTION_TAP_DANCE_DOUBLE(KC_UP, KC_PGUP),
   [TD_DN_PGDN]  = ACTION_TAP_DANCE_DOUBLE(KC_DOWN, KC_PGDN),
   [CT_SCLN] = ACTION_TAP_DANCE_FN_ADVANCED (NULL, dance_cln_finished, dance_cln_reset)
  };
