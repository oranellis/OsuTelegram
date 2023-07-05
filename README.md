# OsuTelegram
Introducing a contact based keypad designed to make tapping in time on two key rhythm games (osu!) faster, tigher timed and requiring less force leading to faster streaming, better accuracy and less fatigue when playing. The keypad requires an RP2040-Zero Microcontroller (found cheaply online), 2 5mmx3mm magnets, 2 49E Linear Hall effect sensors, 4 bearings (8x4x3mm), two keyswitch springs (choose force based on preference however a lighter spring e.g. 35-40g is recommended for less fatigue), and access to a 3D printer.

To construct the keypad, print the .stl files in the `mdl` folder. Glue the hall effect sensors in the gaps on the base with the rounded section facing into the slot. Wire up the hall sensors to GND, 5V and the two analogue inputs shown on the wiring diagram. Slot the bearings onto the keyswitch ends and push fit the magnets into the holes on the bottom. Glue a strip of 1mm thick foam over the hall sensor pad. Slot the keyswitch and bearings into the base and slot the springs into the base and switches. Glue the top peice onto the base, encasing the bearings and switches. Plug the RP2040-Zero into a computer running linux and run the flashing script, alternatively compile the project and flash the RP2040-Zero yourself if you are able.
