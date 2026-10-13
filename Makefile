EE_BIN = shadow_county.elf
EE_OBJS = main.o

all: $(EE_BIN)

clean:
rm -f $(EE_OBJS) $(EE_BIN)

include $(PS2DEV)/ps2sdk/samples/Makefile.pref
include $(PS2DEV)/ps2sdk/samples/Makefile.eeglobal
