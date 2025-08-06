#include <stdint.h>
#include "stdio.h"
#include "disk.h"

void* g_data = (void*)0x20000;

void __attribute__((cdecl)) start(uint16_t bootDrive)
{
    clrscr();
    
    DISK disk;
    if (!DISK_Initialize(&disk, bootDrive))
    {
        printf("Cannot initialize disk!\n");
        goto end;
    }

    DISK_ReadSectors(&disk, 0, 1, g_data);

    print_buffer("Boot sector: ", g_data, 512);

end:
    for (;;);
}