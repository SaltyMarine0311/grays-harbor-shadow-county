#include "main.h"
int main(int argc, char *argv[]) {
    SifInitRpc(0);
    GSGLOBAL *gsGlobal = gsKit_init_global();
    if (gsGlobal == NULL) return 1;
    gsGlobal->Mode = GS_MODE_NTSC;
    gsGlobal->Height = 448;
    gsGlobal->Width = 640;
    gsGlobal->PSM = GS_PSM_CT32;
    gsGlobal->PSMZ = GS_PSMZ_16S;
    gsGlobal->DoubleBuffering = GS_SETTING_ON;
    gsGlobal->ZBuffering = GS_SETTING_OFF;
    gsKit_init_screen(gsGlobal);
    gsKit_mode_switch(gsGlobal, GS_PERSISTENT);
    gsKit_set_test(gsGlobal, GS_ATEST_OFF);
    u64 redColor = GS_SETREG_RGBA(255, 0, 0, 0);
    while (1) {
        gsKit_clear(gsGlobal, redColor);
        gsKit_sync_flip(gsGlobal);
        gsKit_queue_exec(gsGlobal);
    }
    return 0;
}
