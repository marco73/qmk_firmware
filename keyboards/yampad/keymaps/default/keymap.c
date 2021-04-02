/* Copyright 2017 IslandMan93
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or//////
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

  [_BASE] = LAYOUT_ortho_4x5(
    KC_NLCK,  KC_PSLS,  KC_PAST,  KC_PMNS,
    KC_P7,    KC_P8,    KC_P9,    KC_PPLS,
    KC_P4,    KC_P5,    KC_P6,
    KC_P1,    KC_P2,    KC_P3,
    TO(1),    KC_KP_0,  KC_PDOT,  KC_PENT
),

  [_RGB] = LAYOUT_ortho_4x5(
    KC_NLCK,  _______,  RGB_M_P,   RGB_RMOD,
    RGB_HUD,  RGB_HUI,  RGB_M_B,   RGB_MOD,
    RGB_SAD,  RGB_SAI,  RGB_M_SW,
    RGB_VAD,  RGB_VAI,  RGB_M_SN,
    TO(0),    RESET  ,  RGB_M_G,   RGB_TOG
)
};

//SSD1306 OLED update loop, make sure to enable OLED_DRIVER_ENABLE=yes in rules.mk
#ifdef OLED_DRIVER_ENABLE
#define OLED_TIMEOUT 60000
#define OLED_DISPLAY_WIDTH 128
#define OLED_DISPLAY_HEIGHT 32


oled_rotation_t oled_init_user(oled_rotation_t rotation) {
    if (is_keyboard_master()) {
        return OLED_ROTATION_270;
    } else {
        return OLED_ROTATION_0;
    }
}

void oled_task_user(void) {
    // Host Keyboard Layer Status
    //oled_set_cursor(0, 0);
    //oled_write_P(PSTR("Layer"), false);

    switch (get_highest_layer(layer_state)) {
        case _BASE:
            oled_write_P(PSTR("     "), false);
            break;
        case _RGB:
            oled_write_P(PSTR("RGB  "), false);
            break;
        default:
            // Or use the write_ln shortcut over adding '\n' to the end of your string
            oled_write_ln_P(PSTR("Undef"), false);
    }
    oled_write_P(PSTR(" \n"), false);

    // Host Keyboard LED Status
    led_t led_state = host_keyboard_led_state();
    oled_write_P(led_state.num_lock ? PSTR("NUM  ") : PSTR("     "), false);
    oled_write_P(led_state.caps_lock ? PSTR("CAP  ") : PSTR("     "), false);

    oled_write_P(PSTR("\n"), false);

}
#endif
