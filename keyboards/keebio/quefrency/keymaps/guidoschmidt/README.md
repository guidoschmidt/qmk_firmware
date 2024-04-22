To do this on Windows, use MSYS2 MINGW64 shell.

1. Compile the keyboard firmware.
`qmk compile -kb keebio/quefrency/rev4 -km guidoschmidt`
2. Flash the firmware. In order to reset the Keyboard, press FN + FN on the left
side + SRC LCK (top righ tmost key)
`qmk flash -kb keebio/quefrency/rev4 -km guidoschmidt`


