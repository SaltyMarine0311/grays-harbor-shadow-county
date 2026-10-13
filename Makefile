EE_BIN = main.elf
EE_OBJS = main.o

EE_INCS = -I$(PS2DEV)/gsKit/include
EE_LDFLAGS = -L$(PS2DEV)/gsKit/lib
EE_LIBS = -lkernel

all: $(EE_BIN)

clean:
	rm -f $(EE_OBJS) $(EE_BIN)

include $(PS2DEV)/ps2sdk/samples/Makefile.pref
include $(PS2DEV)/ps2sdk/samples/Makefile.eeglobal

