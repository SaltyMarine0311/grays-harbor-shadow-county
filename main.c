#include <gsKit.h>
#include <dmaKit.h>
#include <malloc.h>
#include <tamtypes.h>

int main(int argc, char *argv[]) {
    GSGLOBAL *gsGlobal;
    gsGlobal = gsKit_init_global();
    
    gsKit_init_screen(gsGlobal);
    
    while (1) {
        gsKit_clear(gsGlobal, GS_SETREG_RGBAQ(0x80, 0x00, 0x00, 0x80, 0x00));
        
        gsKit_queue_exec(gsGlobal);
        gsKit_sync_flip();
    }
    
    return 0;
}
