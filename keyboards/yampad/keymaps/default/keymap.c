/* Copyright 2017 IslandMan93
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

/**
 * Layer Names
 */
#define _BASE 0
#define _RGB 1

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [_BASE] = LAYOUT(
    KC_NUMLOCK,  KC_KP_SLASH,  KC_KP_ASTERISK,  KC_KP_MINUS,
    KC_P7,       KC_P8,        KC_P9,           KC_KP_PLUS,
    KC_P4,       KC_P5,        KC_P6,           _______,
    KC_P1,       KC_P2,        KC_P3,           _______,
    TG(_RGB), KC_KP_0,      KC_KP_DOT,       KC_KP_ENTER
),

  [_RGB] = LAYOUT(
    KC_NUMLOCK,  _______,  RGB_MODE_PLAIN,     RGB_MODE_REVERSE,
    RGB_HUD,     RGB_HUI,  RGB_MODE_BREATHE,   RGB_MODE_FORWARD,
    RGB_SAD,     RGB_SAI,  RGB_MODE_SWIRL,     _______,
    RGB_VAD,     RGB_VAI,  RGB_MODE_SNAKE,     _______,
    TG(_BASE),   _______,  RGB_MODE_GRADIENT,  RGB_TOG
)

};
