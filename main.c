#include <gsKit.h>
#include <dmaKit.h>
#include <malloc.h>
#include <tamtypes.h>

int main(int argc, char *argv[]) {
    GSGLOBAL *gsGlobal = gsKit_init_global(VESA_640x480_65K);
    dmaKit_init(DCR_MODE_COMBINED, DCR_STD_PUTL, 1, DCR_MODE_SKID, 0);
    gsKit_init_screen(gsGlobal);
    gsKit_mode_switch(gsGlobal, GS_ON);

    while (1) {
        gsKit_clear(gsGlobal, GS_SETREG_RGBAQ(0x80, 0x00, 0x00, 0x80, 0x00)); // Red screen test
        gsKit_queue_exec(gsGlobal);
        gsKit_sync_vblank();
    }
    return 0;
}
