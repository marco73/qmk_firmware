# MCU name
MCU = atmega32u4

# Processor frequency.
#     This will define a symbol, F_CPU, in all source code files equal to the
#     processor frequency in Hz. You can then use this symbol in your source code to
#     calculate timings. Do NOT tack on a 'UL' at the end, this will be done
#     automatically to create a 32-bit value in your source code.
#
#     This will be an integer division of F_USB below, as it is sourced by
#     F_USB after it has run through any CPU prescalers. Note that this value
#     does not *change* the processor frequency - it should merely be updated to
#     reflect the processor speed set externally so that the code can use accurate
#     software delays.
# F_CPU = 16000000
#
# LUFA specific
#
# Target architecture (see library "Board Types" documentation).
# ARCH = AVR8

# Bootloader selection
BOOTLOADER = atmel-dfu

# Build Options
# Comment out to disable the options.
#
BOOTMAGIC_ENABLE = no		# Virtual DIP switch configuration
#MOUSEKEY_ENABLE = no   	# Mouse keys
EXTRAKEY_ENABLE	= no		# Audio control and System control
#ONSOLE_ENABLE = no			# Console for debug
#COMMAND_ENABLE = no		# Commands for debug and configuration
COMBO_ENABLE = no			# Key combo feature
NKRO_ENABLE = yes 			# USB N-Key Rollover - if this doesn't work, see here: https://github.com/tmk/tmk_keyboard/wiki/FAQ#nkro-doesnt-work
#AUDIO_ENABLE = no			# Enable the audio subsystem.
RGBLIGHT_ENABLE = yes		# Enable keyboard underlight functionality
#LEADER_ENABLE = nos		# Enable leader key chording
#MIDI_ENABLE = no			# MIDI controls
#UNICODE_ENABLE = no		# Unicode
#BLUETOOTH = no				# Current options are AdafruitBLE, RN42
#SPLIT_KEYBOARD = no		# Enables split keyboard support (dual MCU like the let's split and bakingpy's boards) and includes all necessary files located at quantum/split_common
#CUSTOM_MATRIX = no			# Allows replacing the standard matrix scanning routine with a custom one.
#DEBOUNCE_TYPE = no			# Allows replacing the standard key debouncing routine with an alternative or custom one.
#WAIT_FOR_USB = no			# Forces the keyboard to wait for a USB connection to be established before it starts up
#NO_USB_STARTUP_CHECK = no	# Disables usb suspend check after keyboard startup. Usually the keyboard waits for the host to wake it up before any tasks are performed. This is useful for split keyboards as one half will not get a wakeup call but must send commands to the master.
OLED_DRIVER_ENABLE = yes	# Enables the oled driver
