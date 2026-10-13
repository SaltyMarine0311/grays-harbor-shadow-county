EE_BIN = shadow_county.elf
EE_OBJS = main.o

EE_INCS += -I$(PS2DEV)/gsKit/include -I$(GSKIT)/include
EE_LIBS += -L$(PS2DEV)/gsKit/lib -L$(GSKIT)/lib -lgskit -ldmakit -lgraph -lmath3d -lpacket -ldmac -lkernel -lpad

all: $(EE_BIN)

clean:
rm -f $(EE_BIN) $(EE_OBJS)

include $(PS2SDK)/samples/Makefile.pref
include $(PS2SDK)/samples/Makefile.eeglobal
