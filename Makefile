EE_BIN = grays-harbor.elf
EE_OBJS = main.o
EE_LIBS = -lgsKit -ldmaKit -lgraph -lromfs -lc -lm

all: $(EE_BIN)

clean:
	rm -f $(EE_BIN) $(EE_OBJS)

include $(PS2SDK)/samples/Makefile.pref
include $(PS2SDK)/samples/Makefile.eeglobal
