#include QMK_KEYBOARD_H
#include "muse.h"
#include "eeprom.h"
#include "keymap_german.h"
#include "keymap_nordic.h"
#include "keymap_french.h"
#include "keymap_spanish.h"
#include "keymap_hungarian.h"
#include "keymap_swedish.h"
#include "keymap_br_abnt2.h"
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

enum planck_keycodes {
    RGB_SLD = SAFE_RANGE,
    // TOGGLE_LAYER_COLOR,
    EPRM,
};

enum planck_layers {
    _BASE,
    _QWERTY,
    _LOWER,
    _RAISE,
    _ADJUST,

};

enum { TD_LBR_LBR = 0,
       TD_RBR_RBR };

qk_tap_dance_action_t tap_dance_actions[] =
    {
        // tap once for bracket, twice for brace
        [TD_LBR_LBR] = ACTION_TAP_DANCE_DOUBLE(KC_LBRACKET, KC_LCBR),
        [TD_RBR_RBR] = ACTION_TAP_DANCE_DOUBLE(KC_RBRACKET, KC_RCBR)

};

#define LOWER MO(_LOWER)
#define RAISE MO(_RAISE)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /* Dvorak
     * ,-----------------------------------------------------------------------------------.
     * | ESC  |   "  |   ,  |   .  |   P  |   Y  |   F  |   G  |   C  |   R  |   L  | Bksp |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * | TAB  |   A  |   O  |   E  |   U  |   I  |   D  |   H  |   T  |   N  |   S  |  -   |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * | Shift|   ;  |   Q  |   J  |   K  |   X  |   B  |   M  |   W  |   V  |   Z  |SFTENT|
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * | LM(4,| LM(4,| LM(4,| LM(4,|      |      |      |      |      |      |      |      |
     * | MOD_ | MOD_ | MOD_ | MOD_ | Lower| Space| NO   | Raise| LEFT | RIGHT|  UP  | DOWN |
     * | HYPR)| LCtrl| LALT | LGUI |      |      |      |      |      |      |      |      |
     * `-----------------------------------------------------------------------------------'
     */
    [_BASE] = LAYOUT_planck_grid(KC_ESCAPE, KC_QUOTE, KC_COMMA, KC_DOT, KC_P, KC_Y, KC_F, KC_G, KC_C, KC_R, KC_L, KC_BSPACE, KC_TAB, KC_A, KC_O, KC_E, KC_U, KC_I, KC_D, KC_H, KC_T, KC_N, KC_S, KC_MINUS, KC_LSHIFT, KC_SCOLON, KC_Q, KC_J, KC_K, KC_X, KC_B, KC_M, KC_W, KC_V, KC_Z, KC_SFTENT, LM(_QWERTY, MOD_HYPR), LM(_QWERTY, MOD_LCTL), LM(_QWERTY, MOD_LALT), LM(_QWERTY, MOD_LGUI), LOWER, KC_SPACE, KC_NO, RAISE, KC_LEFT, KC_DOWN, KC_UP, KC_RIGHT),

    /* QWERTY
     * ,-----------------------------------------------------------------------------------.
     * | ESC  |   Q  |   W  |   E  |   R  |   T  |   Y  |   U  |   I  |   O  |   P  | Bksp |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * | TAB  |   A  |   S  |   D  |   F  |   G  |   H  |   J  |   K  |   L  |   ;  |  '   |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * |Shift |   Z  |   X  |   C  |   V  |   B  |   N  |   M  |   ,  |   .  |   /  |SFTENT|
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * | DF(  | LCTL | LALT | LGUI |LOWER |Space |  NO  |RAISE | LEFT | RIGHT|  UP  | DOWN |
     * | BASE |      |      |      |      |      |      |      |      |      |      |      |
     * `-----------------------------------------------------------------------------------'
     */

    [_QWERTY] = LAYOUT_planck_grid(KC_GESC, KC_Q, KC_W, KC_E, KC_R, KC_T, KC_Y, KC_U, KC_I, KC_O, KC_P, KC_BSPACE, KC_TAB, KC_A, KC_S, KC_D, KC_F, KC_G, KC_H, KC_J, KC_K, KC_L, KC_SCOLON, KC_QUOTE, KC_LSHIFT, KC_Z, KC_X, KC_C, KC_V, KC_B, KC_N, KC_M, KC_COMMA, KC_DOT, KC_SLASH, KC_SFTENT, DF(_BASE), KC_LCTL, KC_LALT, KC_LGUI, LOWER, KC_SPACE, KC_NO, RAISE, KC_LEFT, KC_DOWN, KC_UP, KC_RIGHT),

    /* RAISE
     * ,-----------------------------------------------------------------------------------.
     * | ~    |   !  |   @  |   #  |   $  |   %  |   ^  |   &  |   *  |   (  |   )  | TRNS |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * | DEL  |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |   _  |   +  |   {  |   }  |  |   |
     * |      |      |      |      |      |      |      |      |      |   [  |   ]  |      |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * | TRNS |  F7  |  F8  |  F9  | F10  | F11  | F12  |   #  |   \  | HOME | END  | TRNS |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * | TRNS |  DF  |  DF  | LM(4,| TRNS | TRNS |      | TRNS | NEXT | VOL  | VOL  | PLAY |
     * |      |(QWRT)|(BASE)| MOD_ |      |      | NO   |      | TRK  | DOWN |  UP  | PAUSE|
     * `-----------------------------------------------------------------------------------'
     */

    [_RAISE] = LAYOUT_planck_grid(KC_TILD, KC_EXLM, KC_AT, KC_HASH, KC_DLR, KC_PERC, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_TRANSPARENT, KC_DELETE, KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_F6, KC_UNDS, KC_PLUS, TD(TD_LBR_LBR), TD(TD_RBR_RBR), KC_PIPE, KC_TRANSPARENT, KC_F7, KC_F8, KC_F9, KC_F10, KC_F11, KC_F12, KC_NONUS_HASH, KC_NONUS_BSLASH, KC_HOME, KC_END, KC_TRANSPARENT, KC_TRANSPARENT, DF(_QWERTY), DF(_BASE), KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_NO, KC_TRANSPARENT, KC_MEDIA_NEXT_TRACK, KC_AUDIO_VOL_DOWN, KC_AUDIO_VOL_UP, KC_MEDIA_PLAY_PAUSE),

    /* LOWER
     * ,-----------------------------------------------------------------------------------.
     * | ~    |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  | TRNS |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * | DEL  |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |   -  |   =  |   {  |   }  |  /   |
     * |      |      |      |      |      |      |      |      |      |   [  |   ]  |      |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * | TRNS |  F7  |  F8  |  F9  | F10  | F11  | F12  |      |   \  | PGUP | PGDN | TRNS |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * | TRNS | TRNS | TRNS | LGUI | TRNS | TRNS |      | TRNS | NEXT | VOL  | VOL  | PLAY |
     * |      |      |      |      |      |      | NO   |      | TRK  | DOWN |  UP  | PAUSE|
     * `-----------------------------------------------------------------------------------'
     */

    [_LOWER] = LAYOUT_planck_grid(KC_GRAVE, KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, KC_7, KC_8, KC_9, KC_0, KC_TRANSPARENT, KC_DELETE, KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_F6, KC_MINUS, KC_EQUAL, TD(TD_LBR_LBR), TD(TD_RBR_RBR), KC_SLASH, KC_TRANSPARENT, KC_F7, KC_F8, KC_F9, KC_F10, KC_F11, KC_F12, KC_NO, KC_BSLASH, KC_PGUP, KC_PGDOWN, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_LGUI, KC_TRANSPARENT, KC_TRANSPARENT, KC_NO, KC_TRANSPARENT, KC_MEDIA_NEXT_TRACK, KC_AUDIO_VOL_DOWN, KC_AUDIO_VOL_UP, KC_MEDIA_PLAY_PAUSE),

    /* ADJUST
     * ,-----------------------------------------------------------------------------------.
     * | TRNS |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |  F7  |  F8  |  F9  | F10  | TRNS |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * | DEL  | TRNS |  AU  |  AU  |  AU  | TRNS | TRNS | RGB  | RGB  | RGB  | TRNS | RESET|
     * |      |      |  ON  |  OFF |  TOG |      |      | TOG  | VAI  | VAD  |      |      |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * | TRNS | TRNS |  MU  |  MU  |  MU  | TRNS | TRNS | RGB  | RGB  | RGB  | TRNS | TRNS |
     * |      |      |  OFF |  OFF |  TOG |      |      | MOD  | HUI  | HUD  |      |      |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * | TRNS | TRNS | TRNS | TRNS | TRNS | TRNS |  NO  | TRNS | TRNS | TRNS | TRNS | TRNS |
     * `-----------------------------------------------------------------------------------'
     */

    [_ADJUST] = LAYOUT_planck_grid(KC_TRANSPARENT, KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_F6, KC_F7, KC_F8, KC_F9, KC_F10,KC_TRANSPARENT,
     KC_DELETE, KC_TRANSPARENT, AU_ON, AU_OFF, AU_TOG, KC_TRANSPARENT, KC_TRANSPARENT, RGB_TOG, RGB_VAI, RGB_VAD, KC_TRANSPARENT, RESET, 
     KC_TRANSPARENT, KC_TRANSPARENT, MU_OFF, MU_OFF, MU_TOG, KC_TRANSPARENT, KC_TRANSPARENT, RGB_MOD, RGB_HUI, RGB_HUD, KC_TRANSPARENT, KC_TRANSPARENT, 
     KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_NO, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT),

};

extern bool         g_suspend_state;
extern rgb_config_t rgb_matrix_config;
bool                disable_layer_color = 0;

void keyboard_post_init_user(void) { rgb_matrix_enable(); }

const uint8_t PROGMEM ledmap[][DRIVER_LED_TOTAL][4] = {
    [0] = {{43, 250, 127}, {43, 250, 127}, {43, 250, 127}, {43, 250, 127}, {43, 250, 127}, {43, 250, 127}, {43, 250, 127}, {43, 250, 127}, {43, 250, 127}, {43, 250, 127}, {43, 250, 127}, {43, 250, 127}, {43, 250, 127}, {43, 250, 127}, {43, 250, 127}, {43, 250, 127}, {43, 250, 127}, {43, 250, 127}, {43, 250, 127}, {43, 250, 127}, {43, 250, 127}, {43, 250, 127}, {43, 250, 127}, {43, 250, 127}, {43, 250, 127}, {43, 250, 127}, {43, 250, 127}, {43, 250, 127}, {43, 250, 127}, {43, 250, 127}, {43, 250, 127}, {43, 250, 127}, {43, 250, 127}, {43, 250, 127}, {43, 250, 127}, {43, 250, 127}, {43, 250, 127}, {43, 250, 127}, {43, 250, 127}, {43, 250, 127}, {43, 250, 127}, {43, 250, 127}, {43, 250, 127}, {43, 250, 127}, {43, 250, 127}, {43, 250, 127}, {43, 250, 127}},

    [1] = {{240, 100, 50}, {240, 100, 50}, {240, 100, 50}, {240, 100, 50}, {240, 100, 50}, {240, 100, 50}, {240, 100, 50}, {240, 100, 50}, {240, 100, 50}, {240, 100, 50}, {240, 100, 50}, {240, 100, 50}, {240, 100, 50}, {240, 100, 50}, {240, 100, 50}, {240, 100, 50}, {240, 100, 50}, {240, 100, 50}, {240, 100, 50}, {240, 100, 50}, {240, 100, 50}, {240, 100, 50}, {240, 100, 50}, {240, 100, 50}, {240, 100, 50}, {240, 100, 50}, {240, 100, 50}, {240, 100, 50}, {240, 100, 50}, {240, 100, 50}, {240, 100, 50}, {240, 100, 50}, {240, 100, 50}, {240, 100, 50}, {240, 100, 50}, {240, 100, 50}, {240, 100, 50}, {240, 100, 50}, {240, 100, 50}, {240, 100, 50}, {240, 100, 50}, {240, 100, 50}, {240, 100, 50}, {240, 100, 50}, {240, 100, 50}, {240, 100, 50}, {240, 100, 50}},

    [2] = {{0, 249, 234}, {0, 249, 234}, {0, 249, 234}, {0, 249, 234}, {0, 249, 234}, {0, 249, 234}, {0, 249, 234}, {0, 249, 234}, {0, 249, 234}, {0, 249, 234}, {0, 249, 234}, {0, 249, 234}, {0, 249, 234}, {0, 249, 234}, {0, 249, 234}, {0, 249, 234}, {0, 249, 234}, {0, 249, 234}, {0, 249, 234}, {0, 249, 234}, {0, 249, 234}, {0, 249, 234}, {0, 249, 234}, {0, 249, 234}, {0, 249, 234}, {0, 249, 234}, {0, 249, 234}, {0, 249, 234}, {0, 249, 234}, {0, 249, 234}, {0, 249, 234}, {0, 249, 234}, {0, 249, 234}, {0, 249, 234}, {0, 249, 234}, {0, 249, 234}, {0, 249, 234}, {0, 249, 234}, {0, 249, 234}, {0, 249, 234}, {0, 249, 234}, {0, 249, 234}, {0, 249, 234}, {0, 249, 234}, {0, 249, 234}, {0, 249, 234}, {0, 249, 234}},

    [3] = {{162, 199, 176}, {162, 199, 176}, {162, 199, 176}, {162, 199, 176}, {162, 199, 176}, {162, 199, 176}, {162, 199, 176}, {162, 199, 176}, {162, 199, 176}, {162, 199, 176}, {162, 199, 176}, {162, 199, 176}, {162, 199, 176}, {162, 199, 176}, {162, 199, 176}, {162, 199, 176}, {162, 199, 176}, {162, 199, 176}, {162, 199, 176}, {162, 199, 176}, {162, 199, 176}, {162, 199, 176}, {162, 199, 176}, {162, 199, 176}, {162, 199, 176}, {162, 199, 176}, {162, 199, 176}, {162, 199, 176}, {162, 199, 176}, {162, 199, 176}, {162, 199, 176}, {162, 199, 176}, {162, 199, 176}, {162, 199, 176}, {162, 199, 176}, {162, 199, 176}, {162, 199, 176}, {162, 199, 176}, {162, 199, 176}, {162, 199, 176}, {162, 199, 176}, {162, 199, 176}, {162, 199, 176}, {162, 199, 176}, {162, 199, 176}, {162, 199, 176}, {162, 199, 176}},

};

void set_layer_color(int layer) {
    for (int i = 0; i < DRIVER_LED_TOTAL; i++) {
        HSV hsv = {
            .h = pgm_read_byte(&ledmap[layer][i][0]),
            .s = pgm_read_byte(&ledmap[layer][i][1]),
            .v = pgm_read_byte(&ledmap[layer][i][2]),
        };
        if (!hsv.h && !hsv.s && !hsv.v) {
            rgb_matrix_set_color(i, 0, 0, 0);
        } else {
            RGB rgb = hsv_to_rgb(hsv);
            rgb_matrix_set_color(i, rgb.r, rgb.g, rgb.b);
        }
    }
}

void rgb_matrix_indicators_user(void) {
    if (g_suspend_state || disable_layer_color) {
        return;
    }
    switch (biton32(layer_state)) {
        case 0:
            set_layer_color(0);
            break;
        case 1:
            set_layer_color(1);
            break;
        case 3:
            set_layer_color(3);
            break;
        case 4:
            set_layer_color(4);
            break;
    }
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case EPRM:
            if (record->event.pressed) {
                eeconfig_init();
            }
            return false;
        case RGB_SLD:
            if (record->event.pressed) {
                rgblight_mode(1);
            }
            return false;
        case RGB_TOG:
            if (record->event.pressed) {
                if (rgb_matrix_config.hsv.v) {
                    rgb_matrix_sethsv(rgb_matrix_config.hsv.h, rgb_matrix_config.hsv.s, 0);
                } else {
                    rgb_matrix_sethsv(rgb_matrix_config.hsv.h, rgb_matrix_config.hsv.s, 255);
                }
            }
            return false;
            // case TOGGLE_LAYER_COLOR:
            //   if (record->event.pressed) {
            //     disable_layer_color ^= 1;
            //   }
            //   return false;
    }
    return true;
}

bool     muse_mode      = false;
uint8_t  last_muse_note = 0;
uint16_t muse_counter   = 0;
uint8_t  muse_offset    = 70;
uint16_t muse_tempo     = 50;

void encoder_update(bool clockwise) {
    if (muse_mode) {
        if (IS_LAYER_ON(_RAISE)) {
            if (clockwise) {
                muse_offset++;
            } else {
                muse_offset--;
            }
        } else {
            if (clockwise) {
                muse_tempo += 1;
            } else {
                muse_tempo -= 1;
            }
        }
    } else {
        if (clockwise) {
#ifdef MOUSEKEY_ENABLE
            register_code(KC_MS_WH_DOWN);
            unregister_code(KC_MS_WH_DOWN);
#else
            register_code(KC_PGDN);
            unregister_code(KC_PGDN);
#endif
        } else {
#ifdef MOUSEKEY_ENABLE
            register_code(KC_MS_WH_UP);
            unregister_code(KC_MS_WH_UP);
#else
            register_code(KC_PGUP);
            unregister_code(KC_PGUP);
#endif
        }
    }
}

void matrix_scan_user(void) {
#ifdef AUDIO_ENABLE
    if (muse_mode) {
        if (muse_counter == 0) {
            uint8_t muse_note = muse_offset + SCALE[muse_clock_pulse()];
            if (muse_note != last_muse_note) {
                stop_note(compute_freq_for_midi_note(last_muse_note));
                play_note(compute_freq_for_midi_note(muse_note), 0xF);
                last_muse_note = muse_note;
            }
        }
        muse_counter = (muse_counter + 1) % muse_tempo;
    }
#endif
}

bool music_mask_user(uint16_t keycode) {
    switch (keycode) {
        case RAISE:
        case LOWER:
            return false;
        default:
            return true;
    }
}
uint32_t layer_state_set_user(uint32_t state) {
    palClearPad(GPIOB, 8);
    palClearPad(GPIOB, 9);
    uint8_t layer = biton32(state);
    switch (layer) {
        case _LOWER:
            palSetPad(GPIOB, 9);
            break;
        case _RAISE:
            palSetPad(GPIOB, 8);
            break;
        case _ADJUST:
            palSetPad(GPIOB, 9);
            palSetPad(GPIOB, 8);
            break;
        default:
            break;
    }
    return update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
}
