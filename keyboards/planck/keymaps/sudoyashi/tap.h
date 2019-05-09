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
    CTRL,
    COPY,
    PASTE
  };

  int cur_dance (qk_tap_dance_state_t *state);

  //initialize xtap state as 0
  static tap xtap_state = {
    .is_press_action = true,
    .state = 0
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

  int cur_dance (qk_tap_dance_state_t *state) {
    if (state->count == 1) {
      if (state->interrupted || !state->pressed)  return SINGLE_TAP;
      }
    else if (state->count == 2) {
      if (state->interrupted) return DOUBLE_TAP;
      }
    if (state->count == 3) {
      if (state->interrupted || !state->pressed)  return TRIPLE_TAP;
      }
    }


  void x_finished (qk_tap_dance_state_t *state, void *user_data);{
    xtap_state.state = cur_dance(state);
    switch (xtap_state.state) {
      case SINGLE_TAP: register_code(KC_LCTL); break;
      case DOUBLE_TAP: register_code(LCTL(KC_C); break;
      case TRIPLE_TAP: register_code(LCTL(KC_V);
  }
  void x_reset (qk_tap_dance_state_t *state, void *user_data);{
    xtap_state.state = cur_dance(state);
    switch (xtap_state.state) {
      case SINGLE_TAP: unregister_code(KC_LCTL); break;
      case DOUBLE_TAP: unregister_code(LCTL(KC_C); break;
      case TRIPLE_TAP: unregister_code(LCTL(KC_V);


  }

  // Declare tap dance actions
  qk_tap_dance_action_t tap_dance_actions[] = {
   [CT_SCLN] = ACTION_TAP_DANCE_FN_ADVANCED (NULL, dance_cln_finished, dance_cln_reset),
   [TD_FULL] = ACTION_TAP_DANCE_DOUBLE(KC_ESC, KC_F11)
   [TD_CTCV]   = ACTION_TAP_DANCE_FN_ADVANCED(NULL,x_finished, x_reset)
  };
