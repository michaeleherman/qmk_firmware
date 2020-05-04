#include QMK_KEYBOARD_H
#include "version.h"
#include "keymap_german.h"
#include "keymap_nordic.h"
#include "keymap_french.h"
#include "keymap_spanish.h"
#include "keymap_hungarian.h"
#include "keymap_swedish.h"
// #include "keymap_br_abnt2.h"
#include "keymap_canadian_multilingual.h"
#include "keymap_german_ch.h"

#define KC_MAC_UNDO LGUI(KC_Z)
#define KC_MAC_CUT LGUI(KC_X)
#define KC_MAC_COPY LGUI(KC_C)
#define KC_MAC_PASTE LGUI(KC_V)
#define KC_PC_UNDO LCTL(KC_Z)
#define KC_PC_CUT LCTL(KC_X)
#define KC_PC_COPY LCTL(KC_C)
#define KC_PC_PASTE LCTL(KC_V)
#define NO_TH ALGR(KC_T)
#define NO_ETH ALGR(KC_D)

enum custom_keycodes {
  RGB_SLD = SAFE_RANGE, // can always be here
  TOGGLE_LAYER_COLOR,
  EPRM,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [0] = LAYOUT_ergodox(KC_GESC,KC_1,KC_2,KC_3,KC_4,KC_5,KC_LBRACKET,KC_TAB,KC_QUOTE,KC_COMMA,KC_DOT,KC_P,KC_Y,OSL(1),KC_HYPR,KC_A,KC_O,KC_E,KC_U,KC_I,KC_LSPO,KC_SCOLON,KC_Q,KC_J,KC_K,KC_X,OSL(2),LT(3,KC_NO),KC_GRAVE,LM(2,MOD_LCTL),LM(2,MOD_LALT),LM(2,MOD_LGUI),LALT_T(KC_APPLICATION),KC_MS_BTN1,KC_HOME,KC_ENTER,KC_DELETE,KC_END,KC_RBRACKET,KC_6,KC_7,KC_8,KC_9,LT(0,KC_0),KC_EQUAL,OSL(3),KC_F,KC_G,KC_C,KC_R,KC_L,KC_SLASH,KC_D,KC_H,KC_T,KC_N,KC_S,KC_MINUS,MO(4),KC_B,KC_M,KC_W,KC_V,KC_Z,KC_RSPC,KC_LEFT,KC_DOWN,KC_UP,KC_RIGHT,TT(1),TT(2),KC_EQUAL,KC_PGUP,KC_END,KC_BSPACE,KC_SPACE),

  [1] = LAYOUT_ergodox(KC_TRNS,KC_TRNS,KC_BSLASH,KC_SLASH,KC_ASTR,KC_PLUS,KC_ASRP,KC_TRNS,KC_EXLM,KC_AT,KC_LCBR,KC_RCBR,KC_MINUS,KC_ASUP,KC_TRNS,KC_HASH,KC_DLR,KC_LPRN,KC_RPRN,LSFT(KC_SCOLON),KC_TRNS,KC_PERC,KC_CIRC,KC_LBRACKET,KC_RBRACKET,KC_PIPE,KC_ASDN,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_ASTG,KC_UP,KC_7,KC_8,KC_9,KC_ASTR,KC_TRNS,KC_DOWN,KC_4,KC_5,KC_6,KC_PLUS,KC_TRNS,KC_TRNS,KC_AMPR,KC_1,KC_2,KC_3,KC_BSLASH,KC_TRNS,KC_COMMA,KC_0,KC_DOT,KC_EQUAL,TO(0),KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_KP_0),

  [2] = LAYOUT_ergodox(KC_GESC,KC_1,KC_2,KC_3,KC_4,KC_5,KC_TRNS,KC_TAB,KC_Q,KC_W,KC_E,KC_R,KC_T,KC_TRNS,KC_TRNS,KC_A,KC_S,KC_D,KC_F,KC_G,KC_TRNS,KC_Z,KC_X,KC_C,KC_V,KC_B,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_6,KC_7,KC_8,KC_9,KC_0,KC_MINUS,KC_GRAVE,KC_Y,KC_U,KC_I,KC_O,KC_P,KC_BSLASH,KC_H,KC_J,KC_K,KC_L,KC_SCOLON,KC_QUOTE,KC_TRNS,KC_N,KC_M,KC_COMMA,KC_DOT,KC_SLASH,KC_TRNS,KC_LEFT,KC_UP,KC_DOWN,KC_RIGHT,TO(0),KC_TRNS,KC_EQUAL,KC_PGUP,KC_END,KC_TRNS,KC_TRNS),

  [3] = LAYOUT_ergodox(LGUI(LCTL(KC_Q)), KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_TRNS, KC_TRNS, KC_EXLM, KC_AT, KC_LCBR, KC_RCBR, KC_PIPE, KC_TRNS, KC_TRNS, KC_HASH, KC_DLR, KC_LPRN, KC_RPRN, KC_GRV, KC_LSFT, KC_PERC, KC_CIRC, KC_LBRC, KC_RBRC, KC_TILD, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_F6, KC_F7, KC_F8, KC_F9, KC_F10, KC_F11, KC_TRNS, KC_UP, KC_7, KC_8, KC_9, KC_ASTR, KC_F12, KC_DOWN, KC_4, KC_5, KC_6, KC_PLUS, KC_TRNS, KC_TRNS, KC_AMPR, KC_1, KC_2, KC_3, KC_BSLS, KC_TRNS, KC_TRNS, KC_DOT, KC_0, KC_EQL, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS),

  [4] = LAYOUT_ergodox(KC__VOLUP, KC_MRWD, KC_MFFD, KC_TRNS, KC_TRNS, KC_TRNS, KC_MPLY, KC__MUTE, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC__VOLDOWN, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_F8, KC_F9, KC_F10, KC_F11, KC_TRNS, KC_UP, KC_7, KC_8, KC_9, KC_ASTR, KC_F12, KC_DOWN, KC_4, KC_5, KC_6, KC_PLUS, KC_TRNS, KC_TRNS, KC_AMPR, KC_1, KC_2, KC_3, KC_BSLS, KC_TRNS, KC_TRNS, KC_DOT, KC_0, KC_EQL, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS),

};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case EPRM:
      if (record->event.pressed) {
        eeconfig_init();
      }
      return false;
  }
  return true;
}

uint32_t layer_state_set_user(uint32_t state) {
  uint8_t layer = biton32(state);
  ergodox_board_led_off();
  ergodox_right_led_1_off();
  ergodox_right_led_2_off();
  ergodox_right_led_3_off();
  switch (layer) {
    case 1:
      ergodox_right_led_1_on();
      break;
    case 2:
      ergodox_right_led_2_on();
      break;
    case 3:
      ergodox_right_led_3_on();
      break;
    case 4:
      ergodox_right_led_1_on();
      ergodox_right_led_2_on();
      break;
    case 5:
      ergodox_right_led_1_on();
      ergodox_right_led_3_on();
      break;
    case 6:
      ergodox_right_led_2_on();
      ergodox_right_led_3_on();
      break;
    case 7:
      ergodox_right_led_1_on();
      ergodox_right_led_2_on();
      ergodox_right_led_3_on();
      break;
    default:
      break;
  }
  return state;
};
