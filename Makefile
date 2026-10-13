EE_BIN = grays-harbor.elf
EE_OBJS = main.o
EE_INCS += -I$(PS2SDK)/ports/include
EE_LIBS += -L$(PS2SDK)/ports/lib -lgsKit -ldmaKit -lgraph -lromfs -lc -lm

all: $(EE_BIN)

clean:
	rm -f $(EE_BIN) $(EE_OBJS)

include $(PS2SDK)/samples/Makefile.pref
include $(PS2SDK)/samples/Makefile.eeglobal
