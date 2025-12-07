// Copyright 2023 ZSA Technology Labs, Inc <@zsa>
// Copyright 2023 Christopher Courtney, aka Drashna Jael're  (@drashna) <drashna@live.com>
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H
#include "config.h"

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [0] = LAYOUT_voyager(
        KC_ESCAPE,              LT(KC_F1,  KC_1),       LT(KC_F2,  KC_2),       LT(KC_F3,  KC_3),       LT(KC_F4,  KC_4),       LT(KC_F5,  KC_5),         LT(KC_F6,  KC_6),       LT(KC_F7,  KC_7),       LT(KC_F8,  KC_8),       LT(KC_F9,  KC_9),       LT(KC_F10,  KC_0),      KC_QUOT,
        KC_TAB,                 KC_Q,                   KC_W,                   KC_F,                   KC_P,                   KC_B,                     KC_J,                   KC_L,                   KC_U,                   KC_Y,                   CW_TOGG,                KC_F12,
        MO(1),                  MT(MOD_LALT, KC_A),     MT(MOD_LGUI, KC_R),     MT(MOD_LCTL, KC_S),     MT(MOD_LSFT, KC_T),     KC_G,                     KC_M,                   MT(MOD_RSFT, KC_N),     MT(MOD_RCTL, KC_E),     MT(MOD_RGUI, KC_I),     MT(MOD_RALT, KC_O),     MO(1),
        _______,                KC_Z,                   KC_X,                   KC_C,                   KC_D,                   KC_V,                     KC_K,                   KC_H,                   KC_COMMA,               KC_DOT,                 KC_SLASH,               _______,
                                                                                                        LT(2, KC_SPACE),        KC_BSPC,                  KC_DELETE,              KC_ENTER
    ),

    [1] = LAYOUT(
        _______,                _______,                _______,                _______,                _______,                _______,                   _______,                _______,                _______,                _______,                _______,                _______,
        KC_GRAVE,               KC_EXLM,                KC_AT,                  KC_HASH,                KC_DLR,                 KC_PERC,                   KC_CIRC,                KC_AMPR,                KC_ASTR,                KC_PIPE,                _______,                _______,
        _______,                KC_LBRC,                KC_LCBR,                KC_COLN,                KC_LPRN,                KC_ASTR,                   KC_MINUS,               KC_RPRN,                KC_UNDS,                KC_RCBR,                KC_RBRC,                _______,
        _______,                _______,                KC_TILD,                KC_DQUO,                KC_EQUAL,               KC_LABK,                   KC_RABK,                KC_SCLN,                KC_GRAVE,               KC_PLUS,                KC_BSLS,                _______,
                                                                                                        _______,                _______,                   _______,                _______
    ),

    [2] = LAYOUT(
        _______,                TOGGLE_LAYER_COLOR,     _______,                _______,                _______,                _______,                   _______,                _______,                _______,                _______,                _______,                QK_BOOT,
        _______,                _______,                KC_AUDIO_VOL_DOWN,      KC_AUDIO_VOL_UP,        KC_AUDIO_MUTE,          _______,                   _______,                KC_HOME,                KC_UP,                  KC_END,                 KC_PAGE_UP,             _______,
        _______,                KC_MEDIA_PREV_TRACK,    KC_MEDIA_NEXT_TRACK,    KC_MEDIA_STOP,          KC_MEDIA_PLAY_PAUSE,    _______,                   _______,                KC_LEFT,                KC_DOWN,                KC_RIGHT,               KC_PGDN,                _______,
        _______,                _______,                _______,                _______,                _______,                _______,                   _______,                LCTL(LSFT(KC_TAB)),     LCTL(KC_TAB),           _______,                _______,                _______,
                                                                                                        _______,                _______,                   _______,                _______
    ),
};

const char chordal_hold_layout[MATRIX_ROWS][MATRIX_COLS] PROGMEM = LAYOUT(
  'L', 'L', 'L', 'L', 'L', 'L', 'R', 'R', 'R', 'R', 'R', 'R',
  'L', 'L', 'L', 'L', 'L', 'L', 'R', 'R', 'R', 'R', 'R', 'R',
  'L', 'L', 'L', 'L', 'L', 'L', 'R', 'R', 'R', 'R', 'R', 'R',
  'L', 'L', 'L', 'L', 'L', 'L', 'R', 'R', 'R', 'R', 'R', 'R',
  '*', '*', '*', '*'
);

// took the weak symbol version and removed the space key from it.
bool is_flow_tap_key(uint16_t keycode) {
    if ((get_mods() & (MOD_MASK_CG | MOD_BIT_LALT)) != 0) {
        return false; // Disable Flow Tap on hotkeys.
    }
    switch (get_tap_keycode(keycode)) {
        case KC_A ... KC_Z:
        case KC_DOT:
        case KC_COMM:
        case KC_SCLN:
        case KC_SLSH:
            return true;
    }
    return false;
}

