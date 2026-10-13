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
    gsGlobal->ZBuffering = GS_SETTING_OFF; // Keep Z-off for 2D intro phase

    gsKit_init_screen(gsGlobal);
    gsKit_mode_switch(gsGlobal, GS_PERSISTENT); // Fixed: required for double buffering

    u64 bgColor = GS_SETREG_RGBA(10, 10, 15, 0);
    u64 gameBgColor = GS_SETREG_RGBA(15, 25, 50, 0);
    u64 blueDiamondColor = GS_SETREG_RGBA(50, 150, 250, 0);
    u64 bloodColor = GS_SETREG_RGBA(180, 20, 20, 0);

    // Intro Logo Animation Loop (240 frames = 4 seconds at 60 FPS)
    int bloodY = 240;
    for (int i = 0; i < 240; i++) {
        gsKit_clear(gsGlobal, bgColor);

        // Pulsing diamond geometry effect
        float pulse = (i % 60) * 0.4f;

        // Top half of diamond
        gsKit_prim_triangle(gsGlobal, 
            320.0f, 130.0f - pulse,  // Top vertex
            260.0f, 190.0f,          // Left vertex
            380.0f, 190.0f,          // Right vertex
            2, blueDiamondColor);

        // Bottom half of diamond
        gsKit_prim_triangle(gsGlobal, 
            260.0f, 190.0f,          // Left vertex
            380.0f, 190.0f,          // Right vertex
            320.0f, 250.0f + pulse,  // Bottom vertex
            2, blueDiamondColor);

        // Dripping blood animation logic
        bloodY += 3;
        if (bloodY > 380) {
            bloodY = 245; // Reset drip back to the base of the diamond
        }
        
        // Draw the dripping blood drop
        gsKit_prim_sprite(gsGlobal, 318.0f, (float)bloodY, 322.0f, (float)(bloodY + 16), 2, bloodColor);

        gsKit_sync_flip(gsGlobal);
        gsKit_queue_exec(gsGlobal);
    }

    // Enable Z-buffering now for the upcoming 3D gameplay loop
    gsGlobal->ZBuffering = GS_SETTING_ON;

    // Main game loop
    while (1) {
        gsKit_clear(gsGlobal, gameBgColor);
        gsKit_sync_flip(gsGlobal);
        gsKit_queue_exec(gsGlobal);
    }

    return 0;
}
