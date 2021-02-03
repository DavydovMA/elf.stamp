# DavydovMA 2013040600 {
# file:	Makefile
# "Copyright (C) 1990-2019 Free Software DavydovMA, Inc
# URL		: http://domain"
# e-mail:	: dev@domain

SOFT=stamp

# ------------- ---- ------
.PHONY: all clean install uninstall debug
#
CC_Lx32=gcc
CC_Lx64=gcc
CC_Wx32=/bin/i686-w64-mingw32-gcc
CC_Wx64=/bin/x86_64-w64-mingw32-gcc
#CC_Dx16=
#CC_Dx32=
#CC_Rx16=
#CC_Rx32=
#CC_Rx64=
#
LF_not_compile=-c
LF_warnings_all=-Wall
LF_with_sdl=-I/usr/include/SDL -L/usr/lib -lSDL
LF_with_sdl2=-I/usr/include/SDL2 -L/usr/lib -lSDL2
#
AS_Lx64=nasm
AS_Lx32=$(AS_Lx64)
#
LINK=ld
#
EXT_Rx16=.rx86_16
EXT_Rx32=.rx86_32
EXT_Rx64=.rx86_64
EXT_Dx16=.dx86_16.exe
EXT_Dx32=.dx86_32.exe
EXT_Wx32=.wx86_32.exe
EXT_Wx64=.wx86_64.exe
EXT_Lx32=.lx86_32.elf
EXT_Lx64=.lx86_64.elf
# ------------- ---- ------

ifeq ($(shell arch),x86_64)
	CC  := $(CC_Lx64) -Dx86_64
	EXT := $(EXT_Lx64)
endif
ifeq ($(shell arch),i686)
	CC  := $(CC_Lx32) -Dx86_32
	EXT := $(EXT_Lx32)
endif

all:	all_elf all_man1
#	see top
all_elf:
	$(CC) -s main.c -o $(SOFT)$(EXT)
all_man1:
	gzip -k -f ./man/man1/$(SOFT).1
	gzip -k -f ./man/ru/man1/$(SOFT).1

clean:	clean_elf clean_man1
#	see top
clean_elf:
	rm -v -f $(SOFT)$(EXT)
#	shred -vun 1 $(SOFT)$(EXT)
clean_man1:
	rm -v -f ./man/man1/$(SOFT).1.gz
	rm -v -f ./man/ru/man1/$(SOFT).1.gz

install:	install_elf install_man1
#	see top
install_elf:
	mkdir -v -p /usr/local/bin/DavydovMA
	cp -v -f $(SOFT)$(EXT) /usr/local/bin/DavydovMA
	ln -s -f /usr/local/bin/DavydovMA/$(SOFT)$(EXT) /usr/bin/$(SOFT)
install_man1:
	cp -v -f ./man/man1/$(SOFT).1.gz    /usr/share/man/man1
	cp -v -f ./man/ru/man1/$(SOFT).1.gz /usr/share/man/ru/man1

uninstall:	uninstall_elf uninstall_man1
#	see top
uninstall_elf:
	rm -v -f /usr/bin/$(SOFT)
	rm -v -f /usr/local/bin/DavydovMA/$(SOFT)$(EXT)
uninstall_man1:
	rm -v -f /usr/share/man/ru/man1/$(SOFT).1.gz
	rm -v -f /usr/share/man/man1/$(SOFT).1.gz

#debug:

# } DavydovMA 2019021300