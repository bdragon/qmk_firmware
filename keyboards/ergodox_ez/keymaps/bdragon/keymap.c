#include QMK_KEYBOARD_H
#include "debug.h"
#include "action_layer.h"
#include "version.h"

#define BASE 0 // default layer
#define LAY1 1 // symbols
#define LAY2 2 // media keys

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  /* Layer 0
   *
   * ,--------------------------------------------------.    ,--------------------------------------------------.
   * |  Esc   |   1  |   2  |   3  |   4  |   5  |      |    |      |   6  |   7  |   8  |   9  |   0  |  Bspc  |
   * |--------+------+------+------+------+-------------|    |------+------+------+------+------+------+--------|
   * |  Caps  |   Q  |   W  |   E  |   R  |   T  |  {   |    |  }   |   Y  |   U  |   I  |   O  |   P  |   \    |
   * |--------+------+------+------+------+------|      |    |      |------+------+------+------+------+--------|
   * |  Ctrl  |   A  |   S  |   D  |   F  |   G  |------|    |------|   H  |   J  |   K  |   L  |   ;  | Enter  |
   * |--------+------+------+------+------+------|  [   |    |  ]   |------+------+------+------+------+--------|
   * | LShift |   Z  |   X  |   C  |   V  |   B  |      |    |      |   N  |   M  |   ,  |   .  |   /  | RShift |
   * `--------+------+------+------+------+-------------'    `-------------+------+------+------+------+--------'
   *   | L1   |  L2  | Ctrl | Alt  | LGui |                                |  -   | Lft  |  Dn  |  Up  | Rgt  |
   *   `----------------------------------'                                `----------------------------------'
   *                                      ,-------------.    ,-------------.
   *                                      | Home | End  |    | PgDn | PgUp |
   *                               ,------|------|------|    |------+------+------.
   *                               |      |      |  ~   |    |  "   |      |      |
   *                               | Tab  |  `   |------|    |------|  '   | Spc  |
   *                               |      |      |      |    |  =   |      |      |
   *                               `--------------------'    `--------------------'
   * NOTE: If it accepts an argument (i.e, is a function), it doesn't need KC_. Otherwise it needs KC_*
   */
  [BASE] = LAYOUT_ergodox(  // layer 0 : default
    // left hand
    KC_ESC,        KC_1,          KC_2,   KC_3,   KC_4,   KC_5,KC_TRNS,
    KC_CAPS,       KC_Q,          KC_W,   KC_E,   KC_R,   KC_T,LSFT(KC_LBRC),
    KC_LCTL,       KC_A,          KC_S,   KC_D,   KC_F,   KC_G,
    KC_LSFT,       KC_Z,          KC_X,   KC_C,   KC_V,   KC_B,KC_LBRC,
    LT(LAY1,KC_NO),LT(LAY2,KC_NO),KC_LCTL,KC_LALT,KC_LGUI,
                                                        KC_HOME,KC_END,
                                                                RSFT(KC_GRV),
                                                  KC_TAB,KC_GRV,KC_TRNS,
    // right hand
    KC_TRNS,      KC_6,   KC_7,   KC_8,   KC_9,  KC_0,    KC_BSPC,
    RSFT(KC_RBRC),KC_Y,   KC_U,   KC_I,   KC_O,  KC_P,    KC_BSLS,
                  KC_H,   KC_J,   KC_K,   KC_L,  KC_SCLN, KC_ENT,
    KC_RBRC,      KC_N,   KC_M,   KC_COMM,KC_DOT,KC_SLSH, KC_RSFT,
                  KC_MINS,KC_LEFT,KC_DOWN,KC_UP, KC_RIGHT,
    KC_PGDN,      KC_PGUP,
    LSFT(KC_QUOT),
    KC_EQL,       KC_QUOT,KC_SPC
  ),

  /* Layer 1
   *
   * ,---------------------------------------------------.    ,--------------------------------------------------.
   * |  Esc    |  F1  |  F2  |  F3  |  F4  |  F5  |      |    |      |  F6  |  F7  |  F8  |  F9  |  F10 |  Bspc  |
   * |---------+------+------+------+------+------+------|    |------+------+------+------+------+------+--------|
   * |         | F11  | F12  |      |      |      |      |    |      |      |      |      |      |      |        |
   * |---------+------+------+------+------+------|      |    |      |------+------+------+------+------+--------|
   * |  Ctrl   |      |      |      |      |      |------|    |------|      |      |      |      |      |        |
   * |---------+------+------+------+------+------|      |    |      |------+------+------+------+------+--------|
   * | LShift  |      |      |      |      |      |      |    |      |      |      |      |      |      | RShift |
   * `---------+------+------+------+------+-------------'    `-------------+------+------+------+------+--------'
   *   |       |      | Ctrl | Alt  | LGui |                                |  -   |      |      |      |      |
   *   `-----------------------------------'                                `----------------------------------'
   *                                       ,-------------.    ,-------------.
   *                                       |      |      |    |      |      |
   *                                ,------|------|------|    |------+------+------.
   *                                |      |      | Del  |    |      |      |      |
   *                                |      |      |------|    |------|      |      |
   *                                |      |      |      |    |  =   |      |      |
   *                                `--------------------'    `--------------------'
   */
  [LAY1] = LAYOUT_ergodox(
    // left hand
    KC_ESC, KC_F1,  KC_F2,  KC_F3,  KC_F4,  KC_F5,  KC_TRNS,
    KC_TRNS,KC_F11, KC_F12, KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,
    KC_LCTL,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,
    KC_LSFT,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,
    KC_TRNS,KC_TRNS,KC_LCTL,KC_LALT,KC_LGUI,
                                    KC_TRNS,KC_TRNS,
                                            KC_DEL,
                            KC_TRNS,KC_TRNS,KC_TRNS,
    // right hand
    KC_TRNS, KC_F6,   KC_F7,  KC_F8,   KC_F9,   KC_F10,  KC_BSPC,
    KC_TRNS, KC_TRNS, KC_TRNS,KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
            KC_TRNS, KC_TRNS,KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
    KC_TRNS, KC_TRNS, KC_TRNS,KC_TRNS, KC_TRNS, KC_TRNS, KC_RSFT,
                      KC_MINS,KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
    KC_MPRV, KC_MNXT,
    KC_TRNS,
    KC_EQL,  KC_TRNS, KC_MPLY
  ),

  /* Layer 2
   *
   * ,--------------------------------------------------.    ,--------------------------------------------------.
   * |        |      |      |      |      |      |      |    |      |      |      |      |      |      |        |
   * |--------+------+------+------+------+-------------|    |------+------+------+------+------+------+--------|
   * |        |      |      |      |      |      |      |    |      |      |      |      |      |      |        |
   * |--------+------+------+------+------+------|      |    |      |------+------+------+------+------+--------|
   * |        |      |      |      |      |      |------|    |------|      |      |      |      |      |        |
   * |--------+------+------+------+------+------|      |    |      |------+------+------+------+------+--------|
   * |        |      |      |      |      |      |      |    |      |      |      |      |      |      |        |
   * `--------+------+------+------+------+-------------'    `-------------+------+------+------+------+--------'
   *   |      |      |      |      |      |                                |      |      |      |      |      |
   *   `----------------------------------'                                `----------------------------------'
   *                                      ,-------------.    ,-------------.
   *                                      | Vol- | Vol+ |    | Prev | Next |
   *                               ,------|------|------|    |------+------+------.
   *                               |      |      |      |    |      |      |      |
   *                               |      |      |------|    |------|      | Play |
   *                               |      |      |      |    |      |      |      |
   *                               `--------------------'    `--------------------'
   */
  [LAY2] = LAYOUT_ergodox(
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
                                        KC_VOLD, KC_VOLU,
                                                KC_TRNS,
                              KC_TRNS, KC_TRNS, KC_TRNS,
    // right hand
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
            KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
                      KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
    KC_MPRV, KC_MNXT,
    KC_TRNS,
    KC_TRNS, KC_TRNS, KC_MPLY
  ),
};

const uint16_t PROGMEM fn_actions[] = {
  [1] = ACTION_LAYER_TAP_TOGGLE(LAY1)                // FN1 - Momentary Layer 1 (Symbols)
};

static uint8_t caps_state = 0;

bool led_update_user(led_t led_state) {
  // Turn on LED when caps lock is on.
  if (led_state.caps_lock != caps_state) {
    led_state.caps_lock ? ergodox_right_led_1_on() : ergodox_right_led_1_off();
    caps_state = led_state.caps_lock;
  }
  return true;
}

// Runs whenever there is a layer state change.
uint32_t layer_state_set_user(uint32_t state) {
  ergodox_board_led_off();
  ergodox_led_all_set(128);
  ergodox_right_led_1_off();
  ergodox_right_led_2_off();
  ergodox_right_led_3_off();
  return state;
}
