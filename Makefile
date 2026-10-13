EE_BIN = shadow_county.elf
EE_OBJS = main.o

EE_INCS += -I$(PS2DEV)/gsKit/include
EE_LIBS += -L$(PS2DEV)/gsKit/lib -lgskit -ldmakit -lpad

all: $(EE_BIN)

clean:
	rm -f $(EE_OBJS) $(EE_BIN)

include $(PS2DEV)/ps2sdk/samples/Makefile.pref
include $(PS2DEV)/ps2sdk/samples/Makefile.eeglobal
