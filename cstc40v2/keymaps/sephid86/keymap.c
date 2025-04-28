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
        KC_LCTL,  KC_LGUI,  KC_LALT,  MO(_FUNC),  MO(_NUMLCK),  KC_SPC,  _______,  MO(_NAVI),  KC_RALT,  KC_APP,   KC_RCTL
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
        QK_BOOT,   KC_EXLM,    KC_AT,  KC_HASH,   KC_DLR,  KC_PERC,  KC_CIRC,  KC_AMPR, KC_ASTR,  KC_LPRN,  KC_RPRN,  KC_BSPC,
        KC_CAPS,  _______,  KC_PSCR,  _______,  _______,  _______,  _______,  KC_VOLU,  _______,  _______, KC_QUOTE,  KC_TRNS,
        KC_TRNS,  _______,  _______,  _______,  _______,  _______,  _______,  KC_VOLD,  _______,  _______,  _______,  KC_TRNS,
        KC_TRNS,  KC_TRNS,  KC_TRNS,  _______,  _______,            KC_TRNS,  _______,  _______,  KC_LEFT,  KC_DOWN, KC_RIGHT
    ),
    [_FN] = LAYOUT_planck_mit(
        // _______,  QK_BOOT,  DB_TOGG,  RM_TOGG,  RM_NEXT,  RM_HUEU,  RM_HUED,  RM_SATU,  RM_SATD,  RM_VALU,  RM_VALD,  KC_DEL,
        _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,
        _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,
        _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,
        _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______
    )

};

// const key_override_t delete_key_override = ko_make_basic(MOD_MASK_SHIFT, KC_BSPC, KC_DEL);
// const key_override_t delete2_key_override = ko_make_basic(MOD_MASK_ALT, KC_SPC, KC_DEL);
// const key_override_t tilde_key_override = ko_make_basic(MOD_MASK_SHIFT, KC_ESC, S(KC_GRV));
const key_override_t tilde_key_override = ko_make_basic(MOD_BIT(KC_RSFT), KC_ESC, KC_TILD);

// This globally defines all key overrides to be used
const key_override_t *key_overrides[] = {
    // &delete_key_override,
    // &delete2_key_override,
    &tilde_key_override
};

