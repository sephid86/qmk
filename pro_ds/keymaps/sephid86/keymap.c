// Copyright 2021 JZ-Skyloong (@JZ-Skyloong)
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H

// #define L_OVERRIDE 1

// Defines names for use in layer keycodes and the keymap
enum layer_names {
    _BASE,
    _CAPS,
    _DEFBASE,
    _NUMLCK,
    _ARROW,
    _FN
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /*
     * ┌───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┐
     * │Esc│ 1 │ 2 │ 3 │ 4 │ 5 │ 6 │ 7 │ 8 │ 9 │ 0 │ - │ = │Bsp│
     * ├───┼───┼───┼───┼───┼───┼───┼───┼───┼───┼───┼───┼───┼───┤
     * │Tab│ Q │ W │ E | R │ T │ Y │ U │ I │ O │ P │ [ │ ] │ \ │
     * ├───┼───┼───┼───┼───┼───┼───┼───┼───┼───┼───┼───┼───┼───┤
     * │Cap│ A │ S │ D │ F │ G │ H │ J │ K │ L │ ; │ ' │   |Ent│
     * ├───┼───┼───┼───┼───┼───┼───┼───┼───┼───┼───┼───┼───┼───┤
     * │Sft│ Z │ X │ C │ V │ B │ N │ M │ , │ . │ / │   |Sft|   │
     * ├───┼───┼───┼───┼───┼───┼───┼───┼───┼───┼───┼───┼───┼───┤
     * │Ctl│GUI│Alt│   │Spc│Mut│   │   |Spc|Alt│App│Ctl│   │Mo1|
     * └───┴───┴───┴───┴───┴───┴───┴───┴───┴───┴───┴───┴───┴───┘
     */
    [_BASE] = LAYOUT_all(
         QK_GESC,     KC_1,     KC_2,     KC_3,     KC_4,     KC_5,        KC_6,     KC_7,       KC_8,     KC_9,        KC_0,     KC_MINS,   KC_EQL,   KC_NO,
         LT(_NUMLCK,KC_TAB),     KC_Q,     KC_W,     KC_E,     KC_R,     KC_T,        KC_Y,     KC_U,       KC_I,     KC_O,        KC_P,     KC_LBRC,  KC_RBRC,   KC_BSLS,
        MO(_CAPS),     KC_A,     KC_S,     KC_D,     KC_F,     KC_G,        KC_H,     KC_J,       KC_K,     KC_L,     KC_SCLN,     KC_QUOT,              KC_ENT,
        KC_LSFT,     KC_Z,     KC_X,     KC_C,     KC_V,     KC_B,        KC_N,     KC_M,    KC_COMM,   KC_DOT,     KC_SLSH,               MT(MOD_RSFT,KC_BSPC),
        KC_LCTL,  KC_LGUI,  KC_LALT,             KC_SPC,   KC_SPC,   KC_SPC,            KC_RALT, MO(_FN), KC_APP, DF(_DEFBASE)
    ),

    [_CAPS] = LAYOUT_all(
         KC_GRV,    KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5,       KC_F6,    KC_F7,    KC_F8,    KC_F9,    KC_F10,   KC_F11,   KC_F12,   _______,
        _______,  _______,  _______,  _______,  _______,  _______,     KC_HOME,  _______,  _______,  KC_END,  KC_PGUP,  _______,  _______,  _______,
        _______,  _______,  _______,  _______,  _______,  _______,     KC_LEFT,  KC_DOWN,  KC_UP,  KC_RIGHT,  KC_PGDN,  _______,            _______,
        _______,  _______,  _______,  _______,  _______,  _______,     _______,  _______,  _______,  _______,  _______,            KC_DEL,
        _______,  _______,  _______,            KC_BSPC,  KC_BSPC,     KC_BSPC,            _______,  _______,  _______,            _______
    ),

    [_DEFBASE] = LAYOUT_all(
         KC_ESC,     KC_1,     KC_2,     KC_3,     KC_4,     KC_5,        KC_6,     KC_7,       KC_8,     KC_9,        KC_0,     KC_MINS,   KC_EQL,   KC_BSPC,
         KC_TAB,     KC_Q,     KC_W,     KC_E,     KC_R,     KC_T,        KC_Y,     KC_U,       KC_I,     KC_O,        KC_P,     KC_LBRC,  KC_RBRC,   KC_BSLS,
        MO(_CAPS),     KC_A,     KC_S,     KC_D,     KC_F,     KC_G,        KC_H,     KC_J,       KC_K,     KC_L,     KC_SCLN,     KC_QUOT,              KC_ENT,
        KC_LSFT,     KC_Z,     KC_X,     KC_C,     KC_V,     KC_B,        KC_N,     KC_M,    KC_COMM,   KC_DOT,     KC_SLSH,               KC_RSFT,
        KC_LCTL,  KC_LGUI,  KC_LALT,             KC_SPC,   KC_SPC,   KC_SPC,            KC_RALT, MO(_FN), KC_APP, DF(_BASE)
    ),

    [_NUMLCK] = LAYOUT_all(
        _______,    KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5,       KC_F6,    KC_F7,    KC_F8,    KC_F9,    KC_F10,   KC_F11,   KC_F12,   _______,
        _______,  _______,  _______,  KC_UP,  _______,  _______,     _______,  KC_7,  KC_8,  KC_9,  _______,  _______,  _______,  _______,
        _______,  _______,  KC_LEFT,  KC_DOWN,  KC_RIGHT,  _______,     KC_BSPC,  KC_4,  KC_5,  KC_6,  KC_DEL,  _______,            _______,
        _______,  _______,  _______,  _______,  _______,  _______,     _______,  KC_1,  KC_2,  KC_3,  _______,            _______,
        _______,  _______,  _______,            _______,  _______,                         KC_0,  _______,  _______,  _______,            _______
    ),

    [_ARROW] = LAYOUT_all(
        _______,    KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5,       KC_F6,    KC_F7,    KC_F8,    KC_F9,    KC_F10,   KC_F11,   KC_F12,   _______,
        _______,  _______,  _______,  KC_UP,  _______,  _______,     _______,  _______,  KC_UP,  _______,  _______,  _______,  _______,  _______,
        _______,  _______,  KC_LEFT,  KC_DOWN,  KC_RIGHT,  _______,     _______,  KC_LEFT,  KC_DOWN,  KC_RIGHT,  _______,  _______,            _______,
        _______,  _______,  _______,  _______,  _______,  _______,     _______,  _______,  _______,  _______,  _______,            _______,
        _______,  _______,  _______,            _______,  _______,                         _______,  _______,  _______,  _______,            _______
    ),

    [_FN] = LAYOUT_all(
         QK_BOOT,    KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5,       KC_F6,    KC_F7,    KC_F8,    KC_F9,    KC_F10,   KC_F11,   KC_F12,   TG(_NUMLCK),
        _______,  _______,  _______,  _______,  _______,  _______,     _______,  _______,  _______,  _______,  _______,  _______,  _______,  RM_TOGG,
        _______,  _______,  _______,  _______,  _______,  _______,     _______,  _______,  _______,  _______,  RM_PREV,  RM_NEXT,            _______,
        _______,  _______,  _______,  _______,  _______,  _______,     _______,  _______,  RM_VALD,  RM_VALU,  _______,            _______,
        _______,  _______,  _______,            _______,  _______,                         _______,  _______,  _______,  _______,            _______
    )

};

// const key_override_t delete_key_override = ko_make_basic(MOD_MASK_SHIFT, KC_BSPC, KC_DEL);
// const key_override_t delete2_key_override = ko_make_basic(MOD_MASK_ALT, KC_SPC, KC_DEL);
// const key_override_t tilde_key_override = ko_make_basic(MOD_MASK_SHIFT, KC_ESC, S(KC_GRV));
// const key_override_t tilde_key_override = ko_make_basic(MOD_MASK_SHIFT, KC_ESC, KC_TILDE);

// This globally defines all key overrides to be used
// const key_override_t *key_overrides[] = {
	// &delete_key_override,
	// &delete2_key_override,
	// &tilde_key_override
// };

