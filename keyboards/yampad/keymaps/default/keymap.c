/* Copyright 2017 IslandMan93
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published byqmk
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
#define _FUNC 1
#define _RGB 2

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* Keymap _BASE: (Base Layer) Default Layer
 * ,-------------------.
 * | NL | /  | *  | -  |
 * |----|----|----|----|
 * | 7  | 8  | 9  |    |
 * |----|----|----| +  |
 * | 4  | 5  | 6  |    |
 * |----|----|----|----|
 * | 1  | 2  | 3  |    |
 * |----|----|----| En |
 * |TG1 | 0  | .  |    |
 * `-------------------'
 */

  [_BASE] = LAYOUT_ortho_4x5(
    KC_NLCK,  KC_PSLS,  KC_PAST,  KC_PMNS,
    KC_P7,    KC_P8,    KC_P9,    KC_PPLS,
    KC_P4,    KC_P5,    KC_P6,
    KC_P1,    KC_P2,    KC_P3,
    TO(1),    KC_KP_0,  KC_PDOT,  KC_PENT
),

/* Keymap _FUNC: Function Layer
 * ,-------------------.
 * | NL | -  | -  |VOLU|
 * |----|----|----|----|
 * |F17 |F18 |F19 |    |
 * |----|----|----|VOLD|
 * |F24 |F15 |F16 |    |
 * |----|----|----|----|
 * |F21 |F22 |F23 |    |
 * |----|----|----|MUTE|
 * |TG2  |F20 | - |    |
 * `-------------------'
 */

  [_FUNC] = LAYOUT_ortho_4x5(
    KC_NLCK, KC_NO ,  KC_NO ,   KC_VOLU,
    KC_F17,  KC_F18,  KC_F19,   KC_VOLD,
    KC_F24,  KC_F15,  KC_F16,
    KC_F21,  KC_F22,  KC_F23,
    TO(2),   KC_F20,  KC_NO ,   KC_MUTE
),

/* Keymap _RGB: RGB Function Layer
 * ,-------------------.
 * | NL | -  |R_P |RMOD|
 * |----|----|----|----|
 * |HUD |HUI |R_B |    |
 * |----|----|----|MOD |
 * |SAD |SAI |R_G |    |
 * |----|----|----|----|
 * |VAD |VAS |R_SW|    |
 * |----|----|----|RTOG|
 * |TG0 |RST |R_SN|    |
 * `-------------------'
 */

  [_RGB] = LAYOUT_ortho_4x5(
    KC_NLCK,  KC_NO  ,  RGB_M_P,   RGB_RMOD,
    RGB_HUD,  RGB_HUI,  RGB_M_B,   RGB_MOD,
    RGB_SAD,  RGB_SAI,  RGB_M_G,
    RGB_VAD,  RGB_VAI,  RGB_M_SW,
    TO(0),    RESET  ,  RGB_M_SN,   RGB_TOG
)
};

// SSD1306 OLED update loop, make sure to enable OLED_DRIVER_ENABLE=yes in rules.mk
// #ifdef OLED_DRIVER_ENABLE
#define OLED_TIMEOUT 60000

extern rgblight_config_t rgblight_config;

oled_rotation_t oled_init_user(oled_rotation_t rotation) {
    return OLED_ROTATION_270;  // flips the display 270 degrees
}

void oled_task_user(void) {

        oled_set_cursor(0, 0);
        oled_write_P(PSTR("Layer"), false);

        switch (get_highest_layer(layer_state)) {
            case _BASE:
                oled_write_P(PSTR(" BAS "), false);
                break;
            case _FUNC:
                oled_write_P(PSTR(" FUNC"), false);
                break;
            case _RGB:
                oled_write_P(PSTR(" RGB "), false);
                break;
            default:
                // Or use the write_ln shortcut over adding '\n' to the end of your string
                oled_write_ln_P(PSTR("Undef"), false);
        }

        // Host Keyboard LED Status
        uint8_t led_usb_state = host_keyboard_leds();
        oled_write_P(PSTR("\n"), false);

        oled_write_P(PSTR("State"), false);
        oled_write_P(led_usb_state & (1<<USB_LED_NUM_LOCK) ? PSTR("NUM  ") : PSTR("     "), false);
        oled_write_P(led_usb_state & (1<<USB_LED_CAPS_LOCK) ? PSTR("CAPS ") : PSTR("     "), false);
        //oled_write_P(led_usb_state & (1<<USB_LED_SCROLL_LOCK) ? PSTR("scr:*") : PSTR("     "), false);

        // Host Keyboard RGB backlight status
        oled_write_P(PSTR("\n"), false);
        oled_write_P(PSTR("\n"), false);
        oled_write_P(PSTR("Light"), false);

        static char led_buf[30];
        snprintf(led_buf, sizeof(led_buf) - 1, "RGB:%cM: %2d\nh: %2ds: %2dv: %2d\n",
            rgblight_config.enable ? '*' : '.', (uint8_t)rgblight_config.mode,
            (uint8_t)(rgblight_config.hue / RGBLIGHT_HUE_STEP),
            (uint8_t)(rgblight_config.sat / RGBLIGHT_SAT_STEP),
            (uint8_t)(rgblight_config.val / RGBLIGHT_VAL_STEP));
        oled_write(led_buf, false);
    }

// RGBLight notification on layer change
const rgblight_segment_t PROGMEM my_capslock_layer[] = RGBLIGHT_LAYER_SEGMENTS( {3, 1, HSV_RED} );      // Light 3 LEDs, starting with LED 4
const rgblight_segment_t PROGMEM my_numlock_layer[] = RGBLIGHT_LAYER_SEGMENTS( {5, 1, HSV_RED} );       // Light 3 LEDs, starting with LED 4
const rgblight_segment_t PROGMEM my_layer1_layer[] = RGBLIGHT_LAYER_SEGMENTS( {8, 1, HSV_CYAN} );
const rgblight_segment_t PROGMEM my_layer2_layer[] = RGBLIGHT_LAYER_SEGMENTS( {8, 1, HSV_BLUE} );
const rgblight_segment_t PROGMEM my_layer3_layer[] = RGBLIGHT_LAYER_SEGMENTS( {8, 1, HSV_GREEN} );

const rgblight_segment_t* const PROGMEM my_rgb_layers[] = RGBLIGHT_LAYERS_LIST(
    my_capslock_layer,  // 0
    my_numlock_layer,   // 1
    my_layer1_layer,    // 2
    my_layer2_layer,    // 3 Overrides other layers
    my_layer3_layer     // 4 Overrides other layers
);

void keyboard_post_init_user(void) {
    // Enable the LED layers
    rgblight_layers = my_rgb_layers;
}

bool led_update_user(led_t led_state) {
    rgblight_set_layer_state(0, led_state.caps_lock);
    rgblight_set_layer_state(1, led_state.num_lock);
    return true;
}

layer_state_t default_layer_state_set_user(layer_state_t state) {
    rgblight_set_layer_state(2, layer_state_cmp(state, _BASE));
    return state;
}

layer_state_t layer_state_set_user(layer_state_t state) {
    rgblight_set_layer_state(3, layer_state_cmp(state, _FUNC));
    rgblight_set_layer_state(4, layer_state_cmp(state, _RGB));
    return state;
}

