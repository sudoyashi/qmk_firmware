//Tap Dance Declarations
#include QMK_KEYBOARD_H

typedef struct {
  bool is_press_action;
  int state;
} tap;

  enum {
    SINGLE_TAP = 1,
    SINGLE_HOLD = 2,
    DOUBLE_TAP = 3,
    DOUBLE_HOLD = 4,
    DOUBLE_SINGLE_TAP = 5, //send two single taps
    TRIPLE_TAP = 6,
    TRIPLE_HOLD = 7
  };

  enum yashi_custom_kc {
    CT_SCLN = 0,
    TD_FULL,
    TD_CTCV
  };

  int cur_dance (qk_tap_dance_state_t *state);
  void copy_dance_finished (qk_tap_dance_state_t *state, void *user_data);
  void copy_dance_reset (qk_tap_dance_state_t *state, void *user_data);


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


  int cur_dance (qk_tap_dance_state_t *state) {
  if (state->count == 1) {
    return SINGLE_TAP;
    }
  else if (state->count == 2) {
    return DOUBLE_TAP;
    }
  else if (state->count == 3) {
    return TRIPLE_TAP;
    }
    else return 8; //magic number. At some point this method will expand to work for more presses
  }

  // initialize xtap state as 0
  static tap xtap_state = {
    .is_press_action = true,
    .state = 0
  };

  void copy_dance_finished (qk_tap_dance_state_t *state, void *user_data) {
    xtap_state.state = cur_dance(state);
    switch (xtap_state.state) {
      case SINGLE_TAP: register_code(KC_LCTL); break;
      case DOUBLE_TAP: register_code(LTKC_C); break;
      case TRIPLE_TAP: register_code(KC_V);
      }
    }
  void copy_dance_reset (qk_tap_dance_state_t *state, void *user_data) {
    xtap_state.state = cur_dance(state);
    switch (xtap_state.state) {
      case SINGLE_TAP: unregister_code(KC_LCTL); break;
      case DOUBLE_TAP: unregister_code(KC_C); break;
      case TRIPLE_TAP: unregister_code(KC_V);
      }
    }

  // Declare tap dance actions
  qk_tap_dance_action_t tap_dance_actions[] = {
   [CT_SCLN] = ACTION_TAP_DANCE_FN_ADVANCED (NULL, dance_cln_finished, dance_cln_reset),
   [TD_FULL] = ACTION_TAP_DANCE_DOUBLE(KC_ESC, KC_F11),
   [TD_CTCV] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, copy_dance_finished, copy_dance_reset)
  };
