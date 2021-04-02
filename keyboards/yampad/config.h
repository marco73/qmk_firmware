#include "config_common.h"

#define VENDOR_ID 0x2021                        // defines your VID, and for most DIY projects, can be whatever you want
#define PRODUCT_ID 0x524                        // defines your PID, and for most DIY projects, can be whatever you want
#define DEVICE_VER 0                            // defines the device version (often used for revisions)
#define MANUFACTURER mattdibi                   // generally who/whatever brand produced the board
#define PRODUCT YamPad                          // the name of the keyboard

#define MATRIX_ROWS 5                           // the number of rows in your keyboard's matrix
#define MATRIX_COLS 4                           // the number of columns in your keyboard's matrix
#define MATRIX_ROW_PINS { C6, D7, E6, B4, B5 }  // pins of the rows, from top to bottom
#define MATRIX_COL_PINS { B1, B3, B2, B6 }      // pins of the columns, from left to right
#define MATRIX_IO_DELAY 30                      // the delay in microseconds when between changing matrix pin state and reading values
#define UNUSED_PINS { D1, D2, D3, B1, B2, B3 }  // pins unused by the keyboard for reference
//#define MATRIX_HAS_GHOST                      // define is matrix has ghost (unlikely)
#define DIODE_DIRECTION COL2ROW                 // COL2ROW or ROW2COL - how your matrix is configured. COL2ROW means the black mark on your diode is facing to the rows, and between the switch and the rows.
//#define DIRECT_PINS { { F1, F0, B0, C7 }, { F4, F5, F6, F7 } }      //pins mapped to rows and columns, from left to right. Defines a matrix where each switch is connected to a separate pin and ground.

#define BACKLIGHT_PIN F4                        // pin of the backlight
#define BACKLIGHT_LEVELS 30                     // number of levels your backlight will have (maximum 31 excluding off)
//#define BACKLIGHT_BREATHING                   // enables backlight breathing
//#define BREATHING_PERIOD 6                    // the length of one backlight "breath" in seconds

#define DEBOUNCE 5                              //the delay when reading the value of the pin (5 is default)

#define LOCKING_SUPPORT_ENABLE                  //mechanical locking support. Use KC_LCAP, KC_LNUM or KC_LSCR instead in keymap
#define LOCKING_RESYNC_ENABLE                   // tries to keep switch state consistent with keyboard LED state
#define IS_COMMAND() (get_mods() == MOD_MASK_SHIFT)     //key combination that allows the use of magic commands (useful for debugging)
#define USB_MAX_POWER_CONSUMPTION 500           // sets the maximum power (in mA) over USB for the device (default: 500)
#define USB_POLLING_INTERVAL_MS 10              // sets the USB polling rate in milliseconds for the keyboard, mouse, and shared (NKRO/media keys) interfaces
#define USB_SUSPEND_WAKEUP_DELAY 200            // set the number of milliseconde to pause after sending a wakeup packet
#define F_SCL 100000L                           // sets the I2C clock rate speed for keyboards using I2C. The default is 400000L, except for keyboards using split_common, where the default is 100000L.

// Features That Can Be Disabled
// If you define these options you will disable the associated feature, which can save on code size.

// #define NO_DEBUG                             // disable debugging
// #define NO_PRINT                             // disable printing/debugging using hid_listen
// #define NO_ACTION_LAYER                      // disable layers
// #define NO_ACTION_TAPPING                    // disable tap dance and other tapping features
// #define NO_ACTION_ONESHOT                    // disable one-shot modifiers
// #define NO_ACTION_MACRO                      // disable old-style macro handling using MACRO(), action_get_macro() (deprecated)
// #define NO_ACTION_FUNCTION                   // disable old-style function handling using fn_actions, action_function() (deprecated)

// Features That Can Be Enabled
// If you define these options you will enable the associated feature, which may increase your code size.
// #define FORCE_NKRO                              // NKRO by default requires to be turned on, this forces it on during keyboard startup regardless of EEPROM setting. NKRO can still be turned off but will be turned on again if the keyboard reboots.
// #define STRICT_LAYER_RELEASE
        // force a key release to be evaluated using the current layer stack instead of remembering which layer it came from (used for advanced cases)
        // Behaviors That Can Be Configured
//#define TAPPING_TERM 200                      //how long before a tap becomes a hold, if set above 500, a key tapped during the tapping term will turn it into a hold too
//#define TAPPING_TERM_PER_KEY                  // enables handling for per key TAPPING_TERM settings
//#define RETRO_TAPPING
        // tap anyway, even after TAPPING_TERM, if there was no other key interruption between press and release
        // See Retro Tapping for details
//#define RETRO_TAPPING_PER_KEY                   // enables handling for per key RETRO_TAPPING settings
//#define TAPPING_TOGGLE 2                        // how many taps before triggering the toggle
//#define PERMISSIVE_HOLD
        // makes tap and hold keys trigger the hold if another key is pressed before releasing, even if it hasn't hit the TAPPING_TERM
        // See Permissive Hold for details
//#define PERMISSIVE_HOLD_PER_KEY     // enabled handling for per key PERMISSIVE_HOLD settings
//#define IGNORE_MOD_TAP_INTERRUPT
            // makes it possible to do rolling combos (zx) with keys that convert to other keys on hold, by enforcing the TAPPING_TERM for both keys.
            // See Ignore Mod Tap Interrupt for details
//#define IGNORE_MOD_TAP_INTERRUPT_PER_KEY    // enables handling for per key IGNORE_MOD_TAP_INTERRUPT settings
//#define TAPPING_FORCE_HOLD
            // makes it possible to use a dual role key as modifier shortly after having been tapped
            // See Tapping Force Hold​
            // Breaks any Tap Toggle functionality (TT or the One Shot Tap Toggle)
//#define TAPPING_FORCE_HOLD_PER_KEY  // enables handling for per key TAPPING_FORCE_HOLD settings
//#define LEADER_TIMEOUT 300
            // how long before the leader key times out
            // If you're having issues finishing the sequence before it times out, you may need to increase the timeout setting. Or you may want to enable the LEADER_PER_KEY_TIMING option, which resets the timeout after each key is tapped.

//#define LEADER_PER_KEY_TIMING   // sets the timer for leader key chords to run on each key press rather than overall
//#define LEADER_KEY_STRICT_KEY_PROCESSING    // Disables keycode filtering for Mod-Tap and Layer-Tap keycodes. Eg, if you enable this, you would need to specify MT(MOD_CTL, KC_A) if you want to use KC_A.
//#define ONESHOT_TIMEOUT 300     // how long before oneshot times out
//#define ONESHOT_TAP_TOGGLE 2    // how many taps before oneshot toggle is triggered
//#define QMK_KEYS_PER_SCAN 4
                    // Allows sending more than one key per scan. By default, only one key event gets
                    // sent via process_record() per scan. This has little impact on most typing, but
                    // if you're doing a lot of chords, or your scan rate is slow to begin with, you can
                    // have some delay in processing key events. Each press and release is a separate
                    // event. For a keyboard with 1ms or so scan times, even a very fast typist isn't
                    // going to produce the 500 keystrokes a second needed to actually get more than a
                    // few ms of delay from this. But if you're doing chording on something with 3-4ms
                    // scan times? You probably want this.

//#define COMBO_COUNT 2             // Set this to the number of combos that you're using in the Combo feature.
//#define COMBO_TERM 200            // how long for the Combo keys to be detected. Defaults to TAPPING_TERM if not defined.

//#define TAP_CODE_DELAY 100        // Sets the delay between register_code and unregister_code, if you're having issues with it registering properly (common on VUSB boards). The value is in milliseconds.

//#define TAP_HOLD_CAPS_DELAY 80    // Sets the delay for Tap Hold keys (LT, MT) when using KC_CAPSLOCK keycode, as this has some special handling on MacOS.  The value is in milliseconds, and defaults to 80 ms if not defined. For macOS, you may want to set this to 200 or higher.

// RGB Light Configuration

#define RGB_DI_PIN F4               // pin the DI on the WS2812 is hooked-up to
#define RGBLIGHT_ANIMATIONS         // run RGB animations
#define RGBLIGHT_LAYERS             // Lets you define lighting layers that can be toggled on or off. Great for showing the current keyboard layer or caps lock state.
//#define RGBLIGHT_MAX_LAYERS       // Defaults to 8. Can be expanded up to 32 if more lighting layers are needed.
                                    // Note: Increasing the maximum will increase the firmware size and slow sync on split keyboards.
#define RGBLIGHT_LAYER_BLINK        // Adds ability to blink a lighting layer for a specified number of milliseconds (e.g. to acknowledge an action).
#define RGBLIGHT_LAYERS_OVERRIDE_RGB_OFF        //If defined, then lighting layers will be shown even if RGB Light is off.
#define RGBLED_NUM 9                // number of LEDs
//#define RGBLIGHT_SPLIT              // Needed if both halves of the board have RGB LEDs wired directly to the RGB output pin on the controllers instead of passing the output of the left half to the input of the right half
//#define RGBLED_SPLIT { 6, 6 }       // number of LEDs connected that are directly wired to RGB_DI_PIN on each half of a split keyboard
                                    // First value indicates number of LEDs for left half, second value is for the right half
                                    // When RGBLED_SPLIT is defined, RGBLIGHT_SPLIT is implicitly defined.
#define RGBLIGHT_HUE_STEP 12        // units to step when in/decreasing hue
#define RGBLIGHT_SAT_STEP 25        // units to step when in/decreasing saturation
#define RGBLIGHT_VAL_STEP 12        // units to step when in/decreasing value (brightness)
// #define RGBW                     // Enables RGBW LED support
