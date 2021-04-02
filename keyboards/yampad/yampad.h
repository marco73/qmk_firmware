
/* Copyright 2020 Worldspawn <mcmancuso@gmail.com>
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

#pragma once

#include "quantum.h"

#define LAYOUT_base( \
    KC_NUMLOCK,  KC_KP_SLASH,  KC_KP_ASTERISK,  KC_KP_MINUS, \
    KC_P7,       KC_P8,        KC_P9,           KC_KP_PLUS,  \
    KC_P4,       KC_P5,        KC_P6, \
    KC_P1,       KC_P2,        KC_P3, \
    TG(_RGB), KC_KP_0,      KC_KP_DOT,       KC_KP_ENTER \
) { \
    { KC_NUMLOCK,  KC_KP_SLASH,  KC_KP_ASTERISK,  KC_KP_MINUS, }, \
    { KC_P7,       KC_P8,        KC_P9,           KC_KP_PLUS, }, \
    { KC_P4,       KC_P5,        KC_P6,           KC_NO }, \
    { KC_P1,       KC_P2,        KC_P3,           KC_NO }, \
    {TG(_RGB), KC_KP_0,      KC_KP_DOT,       KC_KP_ENTER }  \
}

#define LAYOUT_rgb( \
    KC_NUMLOCK,         ,  RGB_MODE_PLAIN,     RGB_MODE_REVERSE, \
    RGB_HUD,     RGB_HUI,  RGB_MODE_BREATHE,   RGB_MODE_FORWARD,  \
    RGB_SAD,     RGB_SAI,  RGB_MODE_SWIRL, \
    RGB_VAD,     RGB_VAI,  RGB_MODE_SNAKE, \
    TG(_BASE),          ,  RGB_MODE_GRADIENT,  RGB_TOG \
) { \
    { KC_NUMLOCK,  KC_NO,    RGB_MODE_PLAIN,    RGB_MODE_REVERSE, }, \
    { RGB_HUD,     RGB_HUI,  RGB_MODE_BREATHE,  RGB_MODE_FORWARD, }, \
    { RGB_SAD,     RGB_SAI,  RGB_MODE_SWIRL,    KC_NO }, \
    { RGB_VAD,     RGB_VAI,  RGB_MODE_SNAKE,    KC_NO }, \
    { TG(_BASE),   KC_NO,    RGB_MODE_GRADIENT, RGB_TOG }  \
}
