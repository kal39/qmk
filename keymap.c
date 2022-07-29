#include QMK_KEYBOARD_H

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [0] = LAYOUT_ansi(
             KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_BSPC, KC_HOME,
    KC_MPLY, KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC, KC_BSLS, KC_DEL,
    KC_ESC,  KC_CAPS, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT, KC_ENT,           KC_PGUP,
    MO(1),   KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT,          KC_UP,   KC_PGDN,
    MO(2),   KC_LCTL, KC_LGUI, KC_LALT,                   KC_SPC,                             DM_PLY1, KC_RALT, KC_RCTL, KC_LEFT, KC_DOWN, KC_RGHT
  ),
  [1] = LAYOUT_ansi(
             _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  _______, _______, _______, KC_END,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_PSCR,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______,
    _______, KC_BTN1, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_BTN1,          KC_MS_U, _______,
    _______, _______, _______, _______,                   _______,                            DM_REC1, _______, _______, KC_MS_L, KC_MS_D, KC_MS_R
  ),
  [2] = LAYOUT_ansi(
             _______, KC_F11,  KC_F12,  KC_F13,  KC_F14,  KC_F15,  KC_F16,  KC_F17,  KC_F18,  KC_F19,  KC_F20,  _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______,
    _______, KC_BTN2, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_BTN2,          KC_WH_U, _______,
    _______, _______, _______, _______,                   _______,                            DM_RSTP, _______, _______, KC_WH_L, KC_WH_D, KC_WH_R
  ),
};

bool encoder_update_user(uint8_t index, bool clockwise) {
  if(layer_state_is(0)) tap_code(clockwise ? KC_VOLU : KC_VOLD);
  else if(layer_state_is(1)) tap_code(clockwise ? KC_MNXT : KC_MPRV);
  else if(layer_state_is(2)) tap_code(clockwise ? KC_BRIU : KC_BRID);
  return true;
}
