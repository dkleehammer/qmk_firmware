#include QMK_KEYBOARD_H
#include "debug.h"
#include "action_layer.h"
#include "version.h"

#define BASE 0 // default layer
#define SYMB 3 // symbols
#define MDIA 2 // media keys
#define GAME 1 // gaming layer

enum custom_keycodes {
  PLACEHOLDER = SAFE_RANGE, // can always be here
  EPRM,
  VRSN,
  RGB_SLD
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/* Keymap 0: Basic layer
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |  ESC/~ |   1  |   2  |   3  |   4  |   5  | L3   |           | L1   |   6  |   7  |   8  |   9  |   0  |  BKSP  |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * | Tab    |   Q  |   W  |   E  |   R  |   T  |  _   |           |  =   |   Y  |   U  |   I  |   O  |   P  |   \    |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |`/Hyper |   A  |   S  |   D  |   F  |   G  |------|           |------|   H  |   J  |   K  |   L  |   ;  | Enter  |
 * |--------+------+------+------+------+------|[/HYPR|           |]/MEH |------+------+------+------+------+--------|
 * |(/LShift|Z/Ctrl|   X  |   C  |   V  |   B  |      |           |      |   N  |   M  |   ,  |   .  |//Ctrl|)/RSHFT |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   | CTRL |'"/L1| Alt  | Cmd  |$   |                                  |'/Cmd |  -   |  =   |   [  |   ]  |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        | App  | Cmd  |       | L3   |Ctrl/Esc|
 *                                 ,------|------|------|       |------+--------+------.
 *                                 |      |      | Home |       | PgUp |        |      |
 *                                 | Space|  Cmd |------|       |------| BKSP/L2|Space |
 *                                 |      |      | End  |       | PgDn |        |      |
 *                                 `--------------------'       `----------------------'
 */
// If it accepts an argument (i.e, is a function), it doesn't need KC_.
// Otherwise, it needs KC_*
[BASE] = LAYOUT_ergodox(  // layer 0 : default
        // left hand
        KC_GESC,         KC_1,         KC_2,   KC_3,   KC_4,   KC_5,   TG(GAME),
        KC_TAB,        KC_Q,         KC_W,   KC_E,   KC_R,   KC_T,   KC_MINS,
        ALL_T(KC_GRV),        KC_A,         KC_S,   KC_D,   KC_F,   KC_G,
        KC_LSFT,        KC_Z,  KC_X,   KC_C,   KC_V,   KC_B,   ALL_T(KC_LBRC),
        KC_LCTL, LT(SYMB,KC_QUOT),   KC_LALT ,KC_LGUI, KC_DLR,
                                              ALT_T(KC_APP),  KC_LGUI,
                                                              KC_HOME,
                                               KC_SPC,KC_LGUI,KC_END,
        // right hand
             TG(SYMB),     KC_6,   KC_7,  KC_8,   KC_9,   KC_0,             KC_BSPC,
             KC_EQL ,    KC_Y,   KC_U,  KC_I,   KC_O,   KC_P,             KC_BSLS,
                          KC_H,   KC_J,  KC_K,   KC_L,   KC_SCLN,KC_ENT,
      MEH_T(KC_RBRC) ,    KC_N,   KC_M,  KC_COMM,KC_DOT, CTL_T(KC_SLSH),   KC_RSFT,
                                  GUI_T(KC_QUOT), KC_MINS, KC_EQL , KC_LBRC,KC_RBRC,
             TG(GAME),        CTL_T(KC_ESC),
             KC_PGUP,
             KC_PGDN,LT(MDIA,KC_BSPC), KC_SPC
    ),
/* Keymap 1: Symbol Layer
 *
 * ,---------------------------------------------------.           ,--------------------------------------------------.
 * |Version  |  F1  |  F2  |  F3  |  F4  |  F5  |      |           |      |  F6  |  F7  |  F8  |  F9  |  F10 |   F11  |
 * |---------+------+------+------+------+------+------|           |------+------+------+------+------+------+--------|
 * |         |   !  |   @  |   {  |   }  |   |  |      |           |      |   Up |   7  |   8  |   9  |   *  |   F12  |
 * |---------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |         |   #  |   $  |   (  |   )  |   `  |------|           |------| Down |   4  |   5  |   6  |   +  |        |
 * |---------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |         |   %  |   ^  |   [  |   ]  |   ~  |      |           |      |   &  |   1  |   2  |   3  |   \  |        |
 * `---------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   | EPRM  |      |      |      |      |                                       |BKSPC |    . |   0  |   =  |      |
 *   `-----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |Animat|      |       |Toggle|Solid |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |Bright|Bright|      |       |      |Hue-  |Hue+  |
 *                                 |ness- |ness+ |------|       |------|      |      |
 *                                 |      |      |      |       |      |      |      |
 *                                 `--------------------'       `--------------------'
 */
// SYMBOLS
[SYMB] = LAYOUT_ergodox(
       // left hand
       VRSN,   KC_F1,  KC_F2,  KC_F3,  KC_F4,  KC_F5,  TO(BASE),
       KC_TRNS,KC_EXLM,KC_AT,  KC_LCBR,KC_RCBR,KC_PIPE,KC_TRNS,
       KC_TRNS,KC_HASH,KC_DLR, KC_LPRN,KC_RPRN,KC_GRV,
       KC_TRNS,KC_PERC,KC_CIRC,KC_LBRC,KC_RBRC,KC_TILD,KC_TRNS,
          EPRM,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,
                                       RGB_MOD,KC_TRNS,
                                               KC_TRNS,
                               RGB_VAD,RGB_VAI,KC_TRNS,
       // right hand
       TO(BASE), KC_F6,   KC_F7,  KC_F8,   KC_F9,   KC_F10,  KC_F11,
       KC_TRNS, KC_UP,   KC_7,   KC_8,    KC_9,    KC_ASTR, KC_F12,
                KC_DOWN, KC_4,   KC_5,    KC_6,    KC_PLUS, KC_TRNS,
       KC_TRNS, KC_AMPR, KC_1,   KC_2,    KC_3,    KC_BSLS, KC_TRNS,
                         KC_BSPC,KC_DOT,  KC_0,    KC_EQL,  KC_TRNS,
       RGB_TOG, RGB_SLD,
       KC_TRNS,
       KC_TRNS, RGB_HUD, RGB_HUI
),
/* Keymap 2: Media and mouse keys
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |        |      |      |      |      |      |      |           |      |      |      |      |      |      | DELETE |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |        |      | Lclk | MsUp | Rclk |      |      |           |      |      |      |  Up  |      |      |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |MsLeft|MsDown|MsRght|      |------|           |------|      | Left | Down | Right|      |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |           |      |      |Mute |VolDn | VolUp|      |        |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |      |      |      |      |      |                                       | Prev | Play | Next  |      |      |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |      |       |      |      |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      |      |       |      |      |Brwser|
 *                                 |      |      |------|       |------|      |Back  |
 *                                 |      |      |      |       |      |      |      |
 *                                 `--------------------'       `--------------------'
 */
// MEDIA AND MOUSE
[MDIA] = LAYOUT_ergodox(
       KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
       KC_TRNS, KC_TRNS, KC_BTN1, KC_MS_U, KC_BTN2, KC_TRNS, KC_TRNS,
       KC_TRNS, KC_TRNS, KC_MS_L, KC_MS_D, KC_MS_R, KC_TRNS,
       KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
       KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
                                           KC_TRNS, KC_TRNS,
                                                    KC_TRNS,
                                  KC_TRNS, KC_TRNS, KC_TRNS,
    // right hand
       KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_DEL,
       KC_TRNS,  KC_TRNS, KC_TRNS, KC_UP, KC_TRNS, KC_TRNS, KC_TRNS,
                 KC_TRNS, KC_LEFT, KC_DOWN, KC_RIGHT, KC_TRNS, KC_TRNS,
       KC_TRNS,  KC_TRNS, KC_MUTE, KC_VOLD, KC_VOLU, KC_TRNS, KC_TRNS,
                          KC_MPRV, KC_MPLY, KC_MNXT, KC_TRNS, KC_TRNS,
       KC_TRNS, KC_TRNS,
       KC_TRNS,
       KC_TRNS, KC_TRNS, KC_WBAK
),
/* Keymap 3: GAMIN
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |        |      |      |      |      |      | BASE |           | BASE |      |      |      |      |      |        |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |        | TAB  |  Q   |  W   |  E   |  R   |      |           |      |      |      |      |      |      |        |
 * |--------+------+------+------+------+------|  T   |           |      |------+------+------+------+------+--------|
 * |  TAB   |      |  A   |  S   |  D   |  F   |------|           |------|      |      |      |      |      | BASE   |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |SHIFT |  Z   |   X  |  C   |  G   |  Y   |           |      |      |      |      |      |      |       |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |      |      |      |      |  V   |                                       |      |      |      |      |      |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |      |       |      |      |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      |      |       |      |      |      |
 *                                 |      |  V   |------|       |------|      | BASE |
 *                                 |      |      | TAB  |       |      |      |      |
 *                                 `--------------------'       `--------------------'
 */
// MEDIA AND MOUSE
[GAME] = LAYOUT_ergodox(
       KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, TO(BASE),
       KC_TRNS, KC_TAB , KC_Q   , KC_W, KC_E, KC_R, KC_T,
       KC_TRNS , KC_LSFT , KC_A   , KC_S, KC_D, KC_F,
       KC_TRNS, KC_LCTL, KC_Z   , KC_X, KC_C, KC_G, KC_Y,
       KC_TRNS, KC_TRNS, KC_TRNS, KC_NO, KC_V,
                                           KC_H, KC_TRNS,
                                                    KC_TRNS,
                                  KC_TRNS, KC_V, KC_TAB,
    // right hand
       TO(BASE),  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
       KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
                 KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, TO(BASE),
       KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
                          KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
       KC_TRNS, KC_TRNS,
       KC_TRNS,
       KC_TRNS, KC_TRNS, TO(BASE)
),
};

const uint16_t PROGMEM fn_actions[] = {
    [1] = ACTION_LAYER_TAP_TOGGLE(SYMB)                // FN1 - Momentary Layer 1 (Symbols)
};

const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt)
{
  // MACRODOWN only works in this function
      switch(id) {
        case 0:
        if (record->event.pressed) {
          SEND_STRING (QMK_KEYBOARD "/" QMK_KEYMAP " @ " QMK_VERSION);
        }
        break;
        case 1:
        if (record->event.pressed) { // For resetting EEPROM
          eeconfig_init();
        }
        break;
      }
    return MACRO_NONE;
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    // dynamically generate these.
    case EPRM:
      if (record->event.pressed) {
        eeconfig_init();
      }
      return false;
      break;
    case VRSN:
      if (record->event.pressed) {
        SEND_STRING (QMK_KEYBOARD "/" QMK_KEYMAP " @ " QMK_VERSION);
      }
      return false;
      break;
    case RGB_SLD:
      if (record->event.pressed) {
        #ifdef RGBLIGHT_ENABLE
          rgblight_mode(1);
        #endif
      }
      return false;
      break;
  }
  return true;
}

// Runs just one time when the keyboard initializes.
void matrix_init_user(void) {

};


// Runs constantly in the background, in a loop.
void matrix_scan_user(void) {

    uint8_t layer = biton32(layer_state);

    ergodox_board_led_off();
    ergodox_right_led_1_off();
    ergodox_right_led_2_off();
    ergodox_right_led_3_off();
    if(layer % 2){
      ergodox_right_led_1_on();
    }
    if((layer >> 1) % 2) {
      ergodox_right_led_2_on();
    }
    if((layer >> 2) % 2) {
      ergodox_right_led_3_on();
    }
};
