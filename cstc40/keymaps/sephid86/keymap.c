/* Copyright 2023
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include QMK_KEYBOARD_H

// #define L_OVERRIDE 1

// Defines names for use in layer keycodes and the keymap
enum layer_names {
    _BASE,
    _NUMLCK,
    _FUNC,
    _NAVI,
    _FN
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /*
     * ┌───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┐
     * │Gsc│ Q │ W │ E │ R │ T │ Y │ U │ I │ O │ P │NLC│
     * ├───┼───┼───┼───┼───┼───┼───┼───┼───┼───┼───┼───┤
     * │Tab│ A │ S │ D │ F │ G │ H │ J │ K │ L │ ; │Ent│
     * ├───┼───┼───┼───┼───┼───┼───┼───┼───┼───┼───┼───┤
     * │Sft│ Z │ X │ C │ V │ B │ N │ M │ , │ . │ / │Sft│
     * ├───┼───┼───┼───┼───┼───┴───┼───┼───┼───┼───┼───┤
     * │Ctl│GUI│Alt│FNC│NUM│  Spc  │   │NAV│Alt│App│Ctl│
     * └───┴───┴───┴───┴───┴───────┴───┴───┴───┴───┴───┘
     */
    [_BASE] = LAYOUT_planck_mit(
        // KC_ESC,   KC_Q,     KC_W,     KC_E,     KC_R,     KC_T,    KC_Y,     KC_U,     KC_I,     KC_O,    KC_P,     KC_BSPC,
        KC_ESC,   KC_Q,     KC_W,     KC_E,     KC_R,     KC_T,    KC_Y,     KC_U,     KC_I,     KC_O,    KC_P,     DF(_NUMLCK),
        KC_TAB,   KC_A,     KC_S,     KC_D,     KC_F,     KC_G,    KC_H,     KC_J,     KC_K,     KC_L,    KC_SCLN,  KC_ENT,
        KC_LSFT,  KC_Z,     KC_X,     KC_C,     KC_V,     KC_B,    KC_N,     KC_M,     KC_COMM,  KC_DOT,  KC_SLSH,  KC_RSFT,
        KC_LCTL,  KC_LGUI,  KC_LALT,  MO(_FUNC),  MO(_NUMLCK),  KC_SPC,  _______,  LT(_NAVI,KC_LNG1),  KC_RALT,  KC_APP,   KC_RCTL
    ),

    /*
     * ┌───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┐
     * │ ` │ 1 │ 2 │ 3 │ 4 │ 5 │ 6 │ 7 │ 8 │ 9 │ 0 │   │
     * ├───┼───┼───┼───┼───┼───┼───┼───┼───┼───┼───┼───┤
     * │TRN│   │   │   │   │   │Bsp│ 4 │ 5 │ 6 │Del│TRN│
     * ├───┼───┼───┼───┼───┼───┼───┼───┼───┼───┼───┼───┤
     * │TRN│   │   │   │   │   │   │ 1 │ 2 │ 3 │Up │TRN│
     * ├───┼───┼───┼───┼───┼───┴───┼───┼───┼───┼───┼───┤
     * │TRN│TRN│TRN│   │   │  TRN  │ 0 │   │Lft│Dn │Rht│
     * └───┴───┴───┴───┴───┴───────┴───┴───┴───┴───┴───┘
     */
    [_NUMLCK] = LAYOUT_planck_mit(
        KC_GRV,     KC_1,     KC_2,     KC_3,     KC_4,     KC_5,     KC_6,     KC_7,     KC_8,     KC_9,     KC_0,  DF(_BASE),
        KC_TRNS,  _______,  _______,  _______,  _______,  _______,  KC_BSPC,     KC_4,     KC_5,     KC_6,   KC_DEL,  KC_TRNS,
        KC_TRNS,  _______,  _______,  _______,  _______,  _______,  _______,     KC_1,     KC_2,     KC_3,    KC_UP,  KC_TRNS,
        KC_TRNS,  KC_TRNS,  KC_TRNS,  _______,  _______,            KC_TRNS,     KC_0,  _______,  KC_LEFT,  KC_DOWN,  KC_RIGHT
    ),

    /*
     * ┌───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┐
     * │ ` │F1 │F2 │F3 │F4 │   │Hom│Pdn│Pup│End│   │   │
     * ├───┼───┼───┼───┼───┼───┼───┼───┼───┼───┼───┼───┤
     * │TRN│F5 │F6 │F7 │F8 │   │Lft│Dn │Up │Rht│Dqu│TRN│
     * ├───┼───┼───┼───┼───┼───┼───┼───┼───┼───┼───┼───┤
     * │TRN│F9 │F10│F11│F12│   │Min│Eql│Lbr│Rbr│Bsl│TRN│
     * ├───┼───┼───┼───┼───┼───┴───┼───┼───┼───┼───┼───┤
     * │TRN│TRN│TRN│   │   │  TRN  │   │   │   │   │Ctl│
     * └───┴───┴───┴───┴───┴───────┴───┴───┴───┴───┴───┘
     */
    [_FUNC] = LAYOUT_planck_mit(
        KC_GRV,     KC_F1,    KC_F2,    KC_F3,    KC_F4,  _______,  KC_HOME,  KC_PGDN,  KC_PGUP,  KC_END,  _______,  _______,
        KC_TRNS,    KC_F5,    KC_F6,    KC_F7,    KC_F8,  _______,  KC_LEFT,  KC_DOWN,    KC_UP, KC_RIGHT,  KC_DQUO,  KC_TRNS,
        KC_TRNS,    KC_F9,   KC_F10,   KC_F11,   KC_F12,  _______,  KC_MINS,   KC_EQL,  KC_LBRC,  KC_RBRC,  KC_BSLS,  KC_TRNS,
        KC_TRNS,  KC_TRNS,  KC_TRNS,  _______,  _______,            KC_TRNS,  _______,  _______,  _______,  _______,  KC_RCTL
    ),

    /*
     * ┌───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┐
     * │ ` │ ! │ @ │ # │ $ │ % │ ^ │ & │ * │ ( │ ) │Bsp│
     * ├───┼───┼───┼───┼───┼───┼───┼───┼───┼───┼───┼───┤
     * │Cap│   │Prt│   │   │   │Vup│   │   │   │Quo│TRN│
     * ├───┼───┼───┼───┼───┼───┼───┼───┼───┼───┼───┼───┤
     * │TRN│   │   │   │   │   │Vdn│   │   │   │Up │TRN│
     * ├───┼───┼───┼───┼───┼───┴───┼───┼───┼───┼───┼───┤
     * │TRN│TRN│TRN│   │   │  TRN  │   │   │Lft│Dn │Rht│
     * └───┴───┴───┴───┴───┴───────┴───┴───┴───┴───┴───┘
     */
    [_NAVI] = LAYOUT_planck_mit(
        KC_TILD,   KC_EXLM,    KC_AT,  KC_HASH,   KC_DLR,  KC_PERC,  KC_CIRC,  KC_AMPR, KC_ASTR,  KC_LPRN,  KC_RPRN,  KC_BSPC,
        KC_CAPS,  _______,  KC_PSCR,  _______,  _______,  _______,  _______,  KC_VOLU,  _______,  _______, KC_QUOTE,  KC_TRNS,
        KC_TRNS,  _______,  _______,  _______,  _______,  _______,  _______,  KC_VOLD,  _______,  _______,  KC_UP,  KC_TRNS,
        KC_TRNS,  KC_TRNS,  KC_TRNS,  MO(_FN),  _______,            KC_TRNS,  _______,  _______,  KC_LEFT,  KC_DOWN, KC_RIGHT
    ),
    [_FN] = LAYOUT_planck_mit(
        // _______,  QK_BOOT,  DB_TOGG,  RM_TOGG,  RM_NEXT,  RM_HUEU,  RM_HUED,  RM_SATU,  RM_SATD,  RM_VALU,  RM_VALD,  KC_DEL,
        QK_BOOT,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,
        _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,
        _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,
        _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______
    )

};

const key_override_t tilde_key_override = ko_make_basic(MOD_BIT(KC_RSFT), KC_ESC, KC_TILD);
const key_override_t *key_overrides[] = {
    &tilde_key_override
};

// https://docs.qmk.fm/features/rgb_matrix#custom-rgb-matrix-effects
bool rgb_matrix_indicators_advanced_user(uint8_t led_min, uint8_t led_max) {
    if (host_keyboard_led_state().caps_lock) {
        for (uint8_t i = led_min; i < led_max; i++) {
            if (g_led_config.flags[i] & LED_FLAG_KEYLIGHT) {
                rgb_matrix_set_color(i, RGB_GOLD);
            }
        }
    }

// for (uint8_t i = led_min; i < led_max; i++) {
        switch(get_highest_layer(layer_state|default_layer_state)) {
            case _FUNC:
                rgb_matrix_set_color(18, RGB_GOLDENROD);
                rgb_matrix_set_color(19, RGB_GOLDENROD);
                rgb_matrix_set_color(20, RGB_GOLDENROD);
                rgb_matrix_set_color(21, RGB_GOLDENROD);
                rgb_matrix_set_color(24, RGB_GOLDENROD);
                rgb_matrix_set_color(25, RGB_GOLDENROD);
                rgb_matrix_set_color(26, RGB_GOLDENROD);
                rgb_matrix_set_color(27, RGB_GOLDENROD);
                rgb_matrix_set_color(29, RGB_BLUE);
                rgb_matrix_set_color(30, RGB_BLUE);
                rgb_matrix_set_color(31, RGB_BLUE);
                rgb_matrix_set_color(32, RGB_BLUE);
                rgb_matrix_set_color(37, RGB_CYAN);//dd
                rgb_matrix_set_color(38, RGB_CYAN);
                rgb_matrix_set_color(39, RGB_CYAN);
                rgb_matrix_set_color(40, RGB_CYAN);
                rgb_matrix_set_color(42, RGB_GOLDENROD);
                rgb_matrix_set_color(43, RGB_GOLDENROD);
                rgb_matrix_set_color(44, RGB_GOLDENROD);
                rgb_matrix_set_color(45, RGB_GOLDENROD);
                break;
            case _NUMLCK:
                rgb_matrix_set_color(6, RGB_GREEN);
                rgb_matrix_set_color(8, RGB_BLUE);
                rgb_matrix_set_color(9, RGB_BLUE);
                rgb_matrix_set_color(10, RGB_BLUE);
                rgb_matrix_set_color(12, RGB_BLUE);
                rgb_matrix_set_color(13, RGB_GREEN);
                rgb_matrix_set_color(14, RGB_GREEN);
                rgb_matrix_set_color(15, RGB_GREEN);
                rgb_matrix_set_color(30, RGB_GREEN);
                rgb_matrix_set_color(31, RGB_GREEN);
                rgb_matrix_set_color(32, RGB_GREEN);
                rgb_matrix_set_color(35, RGB_RED);
                rgb_matrix_set_color(36, RGB_GREEN);
                rgb_matrix_set_color(37, RGB_GREEN);
                rgb_matrix_set_color(38, RGB_GREEN);
                rgb_matrix_set_color(39, RGB_GREEN);
                rgb_matrix_set_color(40, RGB_GREEN);
                rgb_matrix_set_color(41, RGB_GREEN);
                rgb_matrix_set_color(42, RGB_GREEN);
                rgb_matrix_set_color(43, RGB_GREEN);
                rgb_matrix_set_color(44, RGB_GREEN);
                rgb_matrix_set_color(45, RGB_GREEN);
                rgb_matrix_set_color(46, RGB_GREEN);
                break;
            case _NAVI:
                rgb_matrix_set_color(8, RGB_BLUE);
                rgb_matrix_set_color(9, RGB_BLUE);
                rgb_matrix_set_color(10, RGB_BLUE);
                rgb_matrix_set_color(12, RGB_BLUE);
                rgb_matrix_set_color(15, RGB_PINK);
                rgb_matrix_set_color(23, RGB_GOLD);
                rgb_matrix_set_color(25, RGB_WHITE);
                rgb_matrix_set_color(30, RGB_PINK);
                break;
            default:
                break;
        }
    // }

// if (get_highest_layer(layer_state) > 0) {
//         uint8_t layer = get_highest_layer(layer_state);
//
//         for (uint8_t row = 0; row < MATRIX_ROWS; ++row) {
//             for (uint8_t col = 0; col < MATRIX_COLS; ++col) {
//                 uint8_t index = g_led_config.matrix_co[row][col];
//
//                 if (index >= led_min && index < led_max && index != NO_LED &&
//                 keymap_key_to_keycode(layer, (keypos_t){col,row}) > KC_TRNS) {
//                     rgb_matrix_set_color(index, RGB_GREEN);
//                 }
//             }
//         }
//     }

    return false;
}

