EE_BIN = grays-harbor.elf
EE_OBJS = main.o
EE_INCS += -I$(PS2DEV)/gsKit/include -I$(PS2SDK)/ports/include
EE_LIBS += -L$(PS2DEV)/gsKit/lib -L$(PS2SDK)/ports/lib -lgskit -ldmakit -lgraph -lromfs -lc -lm

all: $(EE_BIN)
	genisoimage -o grays-harbor.iso -R -J $(EE_BIN)

clean:
	rm -f $(EE_BIN) $(EE_OBJS) grays-harbor.iso

include $(PS2SDK)/samples/Makefile.pref
include $(PS2SDK)/samples/Makefile.eeglobal
