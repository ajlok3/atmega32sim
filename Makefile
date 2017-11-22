CFLAGS = -Wall `pkg-config --cflags gtk+-2.0` -g
LIBS = `pkg-config --libs gtk+-2.0`

SRCS = main.c gui.c chip_atmel_atmega32.c button.c led.c poti.c seg7.c sig_std_logic.c flash.c sram.c
HDRS = gui.h chip_atmel_atmega32.h button.h led.h poti.h seg7.h sig_std_logic.h flash.h sram.h

SRCS_ORIG = main.c gui.c chip_atmel_atmega32-orig.c button.c led.c poti.c seg7.c sig_std_logic.c jit-x86_64.c
HDRS_ORIG = gui.h chip_atmel_atmega32.h button.h led.h poti.h seg7.h sig_std_logic.h jit.h

all: vm-atmega32

vm-atmega32: $(SRCS) $(HDRS)
	$(CC) $(CFLAGS) -o vm-atmega32 $(SRCS) $(LIBS)
clean distclean::
	rm -f vm-atmega32

vm-atmega32-orig: $(SRCS_ORIG) $(HDRS_ORIG)
	$(CC) $(CFLAGS) -o vm-atmega32-orig $(SRCS_ORIG) $(LIBS)
clean distclean::
	rm -f vm-atmega32-orig

dist-fw:
	mkdir ../vm-atmega32-fw/src
	cp $(SRCS) ../vm-atmega32-fw/src
	cp $(HDRS) ../vm-atmega32-fw/src
	cp Makefile ../vm-atmega32-fw/src
	cd ../vm-atmega32-fw/src; mv chip_atmel_atmega32-stub.c chip_atmel_atmega32.c

dist-1:

dist-2:

dist-3:
