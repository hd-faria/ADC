# analogRead

Library to read AT90CAN uC analog port.

## Manifesto

- .vscode
- .gitignore
- analogRead.c
- analogRead.h
- README.md
- Makefile
- test.cpp

## Microcontroller Fuses

- BODLEVEL = DISABLED
- TA0SEL = [ ]
- OCDEN = [ ]
- JTAGEN = [X]
- SPIEN = [X]
- WDTON = [ ]
- EESAVE = [ ]
- BOOTSZ = 4096W_7000
- BOOTRST = [ ]
- CKDIV8 = [ ]
- CKOUT = [ ]
- SUT_CKSEL = EXTXOSC_8MHZ_16MHZ_1KCK_65MS

- EXTENDED = 0xFF (valid)
- HIGH = 0x99 (valid)
- LOW = 0xCF (valid)
