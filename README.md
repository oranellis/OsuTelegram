# OsuTelegram
This is the contact version of the keypad, the successor to this is the hall-effect based keypad available on the `hall_effect` branch.

Introducing a contact based keypad designed to make tapping in time on two key rhythm games (osu!) faster, tigher timed and requiring less force leading to faster streaming, better accuracy and less fatigue when playing. The keypad only requires an AtMega32u4 dev board (found cheaply online), 4 bearings (TBD size), two keyswitch springs (choose force based on preference however a lighter spring is recommended for less fatigue), 5mm wide nickel strips, and access to a 3D printer. The firmware used for the keypad is QMK, found at https://github.com/qmk/qmk-firmware.

In order to compile the firmware for this keypad, move the `osu_telegram` folder into the keyboards folder in QMK and compile as normal with the keyboard name `osu_telegram` and the keymap `default`.

To construct the keypad, print the .stl files in the `model` folder and superglue 5mm wide nickel strips to the two keys as well as the flat section on the front of keypad base then solder thin wire (26-30 AWG is fine) from the keys to pins TBD and TBD on an AtMega32u4, then solder a wire from the strip on the base to a ground pad on the board.
