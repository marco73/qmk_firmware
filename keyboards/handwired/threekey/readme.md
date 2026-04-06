# threekey

Custom handwired three key keyboard. **See each individual board for pin information.**

* Keyboard Maintainer: QMK Community
* Hardware Supported: RP2040
* Hardware Availability: *n/a*

Compile example for this keyboard (after setting up your build environment):

        qmk compile -kb handwired/threekey/rp2040 -km default

## Default Key Configuration

The default layout is `LAYOUT_ortho_1x3` with three keys:

* Left key (`CSM`): Sends `Ctrl+Shift+M` to toggle mute (for apps like Microsoft Teams).
* Center key (`TD(TD_01)` Tap Dance):
    * 1 tap: `Media Play/Pause`
    * 2 taps: `Media Stop`
    * 5 or more taps: Jump to bootloader (`QK_BOOT`) for firmware flashing.
* Right key (`CSH`): Sends `Ctrl+Shift+H` to hang up/end a meeting (for apps like Microsoft Teams).


See the [build environment setup](https://docs.qmk.fm/#/getting_started_build_tools) and the [make instructions](https://docs.qmk.fm/#/getting_started_make_guide) for more information. Brand new to QMK? Start with our [Complete Newbs Guide](https://docs.qmk.fm/#/newbs).
