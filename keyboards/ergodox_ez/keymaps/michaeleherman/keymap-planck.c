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

#define LOWER MO(_LOWER)
#define RAISE MO(_RAISE)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
// DVORAK
// ,--------------------------------------------------.      -------------------------------------------------.
// | GESC   |  1   |   2  |   3  |   4  |   5  |   [  |      |   ]  |   6  |  7   |   8  |   9  |   0  |   =  |
// |--------+------+------+------+------+------+------|      +------|------+------+------+------+------+------|
// | TAB    |   '  |   ,  |   .  |   P  |   Y  |OSL(2)|      |OSL(3)|   F  |  G   |   C  |   R  |   L  | BSPC |
// |--------+------+------+------+------+------|      |      |      |------+------+------+------+------+------|
// | GESC   |   A  |   O  |   E  |   U  |   I  |------|      |------|   D  |  H   |   T  |   N  |   s  |   -  |
// |--------+------+------+------+------+------|OSL(1)|      |KC_NO |------+------+------+------+------+------|
// | SHFT(  |   ;  |   Q  |   J  |   K  |   X  |      |      |      |   B  |  M   |   W  |   V  |   Z  |SFTENT|
// |--------+------+------+------+------+------+------'      `------|------+------+------+------+------+------+
// |        |      | LM(2,| LM(2,|LM(2, |                                  |      |      |      |      |      |
// | LT(3)	|   `  | MOD_ | MOD_ |MOD_  | ,-------------.  ,-------------. | LEFT | DOWN |  UP  | RIGHT| TT(1)|
// |	    |	   | LCTL)| LALT)|LGUI) | | KC_NO| KC_NO|  | KC_NO|  =   | |      |      |      |      |      |
// `--------+------+------+------+------' |      |      |  |      |      | `------+------+------+------+------'
//                                 ,------+------+------+  +------+------+------,
//                                 |      |      | PGUP |  | PGDN |      | LT(3,|
//                                 | RET  | DEL  +------+  |------+ BKSP + SPACE|
//                                 |      |      | TT(2)|  | TT(3)|      |   )  |
//                                 `------+------+------'  +------+------'------`

  [0] = LAYOUT_ergodox(KC_GESC,KC_1,KC_2,KC_3,KC_4,KC_5,KC_LBRACKET, //Left 1
  KC_TAB,KC_QUOTE,KC_COMMA,KC_DOT,KC_P,KC_Y,OSL(2),                       //Left 2
  KC_GESC,KC_A,KC_O,KC_E,KC_U,KC_I,                                       //Left 3
  KC_LSFT,KC_SCOLON,KC_Q,KC_J,KC_K,KC_X,OSL(1),                           //Left 4
  LT(3,KC_NO),KC_GRAVE,LM(1,MOD_LCTL),LM(1,MOD_LALT),LM(1,MOD_LGUI),      //Left 5
  KC_NO,KC_NO,KC_PGUP,LOWER,KC_SPACE,TT(2),                           //Left Thumb
  KC_RBRACKET,KC_6,KC_7,KC_8,KC_9,KC_0,KC_EQUAL,                          //Right 1
  OSL(3),KC_F,KC_G,KC_C,KC_R,KC_L,KC_BSPACE,                               //Right 2
  KC_D,KC_H,KC_T,KC_N,KC_S,KC_MINUS,                                      //Right 3
  KC_NO,KC_B,KC_M,KC_W,KC_V,KC_Z,KC_SFTENT,                                 //Right 4
  KC_LEFT,KC_DOWN,KC_UP,KC_RIGHT,TT(1),                                   //Right 5
  KC_NO,KC_EQUAL,KC_PGDN,TT(3),KC_SPACE,RAISE),                 //Right Thumb

// QWERTY
// ,--------------------------------------------------.      -------------------------------------------------.
// | TRNS   | TRNS | TRNS | TRNS | TRNS | TRNS | TRNS |      | TRNS | TRNS | TRNS | TRNS | TRNS | TRNS | TRNS |
// |--------+------+------+------+------+------+------|      +------|------+------+------+------+------+------|
// | TRNS   |   Q  |   W  |   E  |   R  |   T  | TRNS |      | TRNS |   Y  |  U   |   I  |   O  |   P  |   \  |
// |--------+------+------+------+------+------|      |      |      |------+------+------+------+------+------|
// | TRNS   |   A  |   S  |   D  |   F  |   G  |------|      |------|   H  |  J   |   K  |   L  |   ;  |   '  |
// |--------+------+------+------+------+------| TRNS |      | TRNS |------+------+------+------+------+------|
// | TRNS   |   Z  |   X  |   C  |   V  |   B  |      |      |      |   N  |  M   |   ,  |   .  |   /  | TRNS |
// |--------+------+------+------+------+------+------'      `------|------+------+------+------+------+------+
// |        |      |      |      |      |                                  |      |      |      |      |      |
// | TRNS	| TRNS | TRNS | TRNS | TRNS | ,-------------.  ,-------------. | TRNS | TRNS | TRNS | TRNS | TO(0)|
// |	    |	   |      |             | | TRNS | TRNS |  | TRNS | TRNS | |      |      |      |      |      |
// `--------+------+------+------+------' |      |      |  |      |      | `------+------+------+------+------'
//                                 ,------+------+------+  +------+------+------,
//                                 |      |      | TRNS |  | TRNS |      |      |
//                                 | TRNS | TRNS +------+  |------+ TRNS + TRNS |
//                                 |      |      | TRNS |  | TRNS |      |      |
//                                 `------+------+------'  +------+------'------`

  [1] = LAYOUT_ergodox(
  KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,            //Left 1
  KC_TRNS,KC_Q,KC_W,KC_E,KC_R,KC_T,KC_TRNS,                           //Left 2
  KC_TRNS,KC_A, KC_S,KC_D,KC_F,KC_G,                                  //Left 3
  KC_TRNS,KC_Z,KC_X,KC_C,KC_V,KC_B,KC_TRNS,                           //Left 4
  KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,                            //Left 5
  KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,                    //Left Thumb
  KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,            //Right 1
  KC_TRNS,KC_Y,KC_U,KC_I,KC_O,KC_P,KC_BSLASH,                        //Right 2
  KC_H,KC_J,KC_K,KC_L,KC_SCOLON,KC_QUOTE,                             //Right 3
  KC_TRNS,KC_N,KC_M,KC_COMMA,KC_DOT,KC_SLASH,KC_TRNS,                 //Right 4
  KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,TO(0),                              //Right 5
  KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS),                   //Right Thumb

// 10key, function keys

  [2] = LAYOUT_ergodox(
  LGUI(LCTL(KC_Q)), KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_TRNS,     //Left 1
  KC_TRNS, KC_EXLM, KC_AT, KC_LCBR, KC_RCBR, KC_PIPE, KC_TRNS,      //Left 2
  KC_TRNS, KC_HASH, KC_DLR, KC_LPRN, KC_RPRN, KC_GRV,               //Left 3
  KC_LSFT, KC_PERC, KC_CIRC, KC_LBRC, KC_RBRC, KC_TILD, KC_TRNS,    //Left 4
  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,                      //Left 5
  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,             //Left Thumb
  KC_TRNS, KC_F6, KC_F7, KC_F8, KC_F9, KC_F10, KC_F11,              //Right 1
  KC_TRNS, KC_UP, KC_7, KC_8, KC_9, KC_ASTR, KC_F12,                //Right 2
  KC_DOWN, KC_4, KC_5, KC_6, KC_PLUS, KC_TRNS,                      //Right 3
  KC_TRNS, KC_AMPR, KC_1, KC_2, KC_3, KC_BSLS, KC_TRNS,             //Right 4
  KC_TRNS, KC_DOT, KC_0, KC_EQL, KC_TRNS,                           //Right 5
  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS),            //Right Thumb

// Audio, number row

  [3] = LAYOUT_ergodox(
  KC__VOLUP, KC_MRWD, KC_MFFD, KC_TRNS, KC_TRNS, KC_TRNS, KC_MPLY,
  KC__MUTE, KC_1, KC_2, KC_3, KC_4, KC_5, KC_TRNS,
  KC__VOLDOWN, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
  KC_TRNS, KC_6, KC_7, KC_8, KC_9, KC_0, KC_TRNS,
  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS),

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

void keyboard_post_init_user(void) {
  // Customise these values to desired behaviour
//   debug_enable=true;
//   debug_matrix=true;
//   debug_keyboard=true;
  //debug_mouse=true;
}
