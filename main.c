#include <gsKit.h>
#include <dmaKit.h>
#include <malloc.h>
#include <tamtypes.h>

int main(int argc, char *argv[]) {
    GSGLOBAL *gsGlobal;
    gsGlobal = gsKit_init_global();
    
    gsGlobal->Mode = GS_MODE_NTSC;
    gsGlobal->Width = 640;
    gsGlobal->Height = 448;
    gsGlobal->PSM = GS_PSM_CT32;
    gsGlobal->PSMZ = GS_PSMZ_16S;
    gsGlobal->DoubleBuffering = GS_SETTING_ON;
    gsGlobal->ZBuffering = GS_SETTING_OFF;
    gsGlobal->Interlace = GS_INTERLACED;
    gsGlobal->Field = GS_FIELD_INTERLACED;
    
    gsKit_init_screen(gsGlobal);
    gsKit_mode_switch(gsGlobal, GS_ON);
    
    while (1) {
        gsKit_clear(gsGlobal, GS_SETREG_RGBAQ(0x80, 0x00, 0x00, 0x80, 0x00));
        
        gsKit_queue_exec(gsGlobal);
        gsKit_sync_flip(gsGlobal);
    }
    
    return 0;
}
