
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
    KC_NLCK,   KC_PSLS,  KC_PAST,  KC_PMNS, \
    KC_P7,     KC_P8,    KC_P9,    KC_PPLS,  \
    KC_P4,     KC_P5,    KC_P6, \
    KC_P1,     KC_P2,    KC_P3, \
    TG(_RGB),  KC_P0,    KC_PDOT,  KC_PENT \
) { \
    { KC_NLCK,  KC_PSLS,  KC_PAST,  KC_PMNS }, \
    { KC_P7,    KC_P8,    KC_P9,    KC_PPLS }, \
    { KC_P4,    KC_P5,    KC_P6,    KC_NO }, \
    { KC_P1,    KC_P2,    KC_P3,    KC_NO }, \
    {TG(_RGB),  KC_P0,    KC_PDOT,  KC_PENT },  \
}

#define LAYOUT_rgb( \
    KC_NLCK,          ,   RGB_MODE_PLAIN,     RGB_MODE_REVERSE, \
    RGB_HUD,    RGB_HUI,  RGB_MODE_BREATHE,   RGB_MODE_FORWARD,  \
    RGB_SAD,    RGB_SAI,  RGB_MODE_SWIRL, \
    RGB_VAD,    RGB_VAI,  RGB_MODE_SNAKE, \
    TG(_BASE),  KC_NO,    RGB_MODE_GRADIENT,  RGB_TOG \
) { \
    { KC_NLCK,    KC_NO,    RGB_MODE_PLAIN,    RGB_MODE_REVERSE }, \
    { RGB_HUD,    RGB_HUI,  RGB_MODE_BREATHE,  RGB_MODE_FORWARD }, \
    { RGB_SAD,    RGB_SAI,  RGB_MODE_SWIRL,    KC_NO }, \
    { RGB_VAD,    RGB_VAI,  RGB_MODE_SNAKE,    KC_NO }, \
    { TG(_BASE),  KC_NO,    RGB_MODE_GRADIENT, RGB_TOG },  \
}
