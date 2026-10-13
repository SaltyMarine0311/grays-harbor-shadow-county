#include <tamtypes.h>
#include <kernel.h>
#include <sifrpc.h>
#include <gsKit.h>
#include <dmaKit.h>

int main(int argc, char *argv[]) {
    SifInitRpc(0);

    GSGLOBAL *gsGlobal = gsKit_init_global();
    if (!gsGlobal) {
        return 1;
    }

    gsGlobal->Mode = GS_MODE_NTSC;
    gsGlobal->Height = 448;
    gsGlobal->Width = 640;
    gsGlobal->PSM = GS_PSM_CT32;
    gsGlobal->PSMZ = GS_PSMZ_16S;
    gsGlobal->DoubleBuffering = GS_SETTING_ON;
    gsGlobal->ZBuffering = GS_SETTING_ON;

    gsKit_init_screen(gsGlobal);
    gsKit_mode_switch(gsGlobal, GS_ONESHOT);

    u64 bgColor = GS_SETREG_RGBA(15, 25, 50, 0);

    while (1) {
        gsKit_clear(gsGlobal, bgColor);
        gsKit_sync_flip(gsGlobal);
        gsKit_queue_exec(gsGlobal);
    }

    return 0;
}
