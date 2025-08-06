#pragma once

#include <stdint.h>
#include <stdbool.h>
#include <stdio.h>

typedef struct {
    FILE* File;
} DISK;

bool DISK_Initialize(DISK* disk, const char* fileName);
bool DISK_ReadSectors(DISK* disk, uint32_t lba, uint8_t sectors, void* dataOut);