EE_BIN = GRAYS-HARBOR.ELF
EE_OBJS = main.o
EE_INCS += -I$(PS2DEV)/gsKit/include -I$(PS2SDK)/ports/include
EE_LIBS += -L$(PS2DEV)/gsKit/lib -L$(PS2SDK)/ports/lib -lgskit -ldmakit -lgraph -lromfs -lc -lm

all: grays-harbor.elf
	cp grays-harbor.elf GRAYS-HARBOR.ELF
	genisoimage -iso-level 1 -o grays-harbor.iso SYSTEM.CNF GRAYS-HARBOR.ELF

clean:
	rm -f grays-harbor.elf GRAYS-HARBOR.ELF $(EE_OBJS) grays-harbor.iso SYSTEM.CNF

include $(PS2SDK)/samples/Makefile.pref
include $(PS2SDK)/samples/Makefile.eeglobal
