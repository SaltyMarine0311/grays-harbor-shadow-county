#include <gsKit.h>
#include <dmaKit.h>
#include <malloc.h>
#include <tamtypes.h>

int main(int argc, char *argv[]) {
    GSGLOBAL *gsGlobal = gsKit_init_global();
    gsGlobal->Mode = GS_MODE_NTSC;
    gsGlobal->Width = 640;
    gsGlobal->Height = 480;
    gsGlobal->PSM = GS_PSM_M8;
    gsGlobal->PSMZ = GS_PSMZ_16S;
    gsGlobal->DoubleBuffering = GS_SETTING_ON;
    gsGlobal->ZBuffering = GS_SETTING_OFF;

    dmaKit_init(DCR_MODE_COMBINED, DCR_STD_PUTL, 1, DCR_MODE_SKID, 0);
    dmaKit_chan_init(DMA_CHANNEL_CHCR);

    gsKit_init_screen(gsGlobal);
    gsKit_mode_switch(gsGlobal, GS_ON);

    while (1) {
        gsKit_clear(gsGlobal, GS_SETREG_RGBAQ(0x80, 0x00, 0x00, 0x80, 0x00));
        gsKit_queue_exec(gsGlobal);
        gsKit_sync_vblank();
    }
    return 0;
}
