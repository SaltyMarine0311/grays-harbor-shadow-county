#include <stdio.h>
#include <tamtypes.h>
#include <kernel.h>
#include <sifrpc.h>
#include <gsKit.h>

int main(int argc, char *argv[]) {
    // Initialize PS2 SIF RPC services
    SifInitRpc(0);

    // Initialize gsKit graphics engine
    GSGLOBAL *gsGlobal = gsKit_init_global();
    gsGlobal->Mode = GS_MODE_NTSC;
    gsGlobal->Height = 448;
    gsGlobal->Width = 640;
    gsGlobal->PSM = GS_SETMODE_NTSC;

    gsKit_init_screen(gsGlobal);
    gsKit_mode_switch(gsGlobal, GS_ONESHOT);

    // Set background color to dark blue (R: 15, G: 25, B: 50)
    u64 bgColor = GS_SETREG_RGBA(15, 25, 50, 0);

    // Game loop keeps the ELF running on hardware/emulator
    while (1) {
        gsKit_clear(gsGlobal, bgColor);
        gsKit_sync_flip(gsGlobal);
        gsKit_queue_exec(gsGlobal);
    }

    return 0;
}
