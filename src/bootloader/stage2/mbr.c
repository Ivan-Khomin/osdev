#include "mbr.h"
#include "memory.h"
#include "stdio.h"

typedef struct {
    // 0x00	1	Drive attributes (bit 7 set = active or bootable)
    uint8_t attributes;

    // 0x01	3	CHS Address of partition start
    uint8_t chsStart[3];

    // 0x04	1	Partition type
    uint8_t partitionType;

    // 0x05	3	CHS address of last partition sector
    uint8_t chsEnd[3];

    // 0x08	4	LBA of partition start
    uint32_t lbaStart;

    // 0x0C	4	Number of sectors in partition
    uint32_t size;

} __attribute__((packed)) MBR_Entry;

uint32_t MBR_DetectPartition(DISK* disk, void* partition)
{
    if (disk->id < 0x80) {
        return 0;
    }

    MBR_Entry* entry = (MBR_Entry*)segoffset_to_linear(partition);
    printf("attributes=%x\n", entry->attributes);
    printf("lbaStart=%x\n", entry->lbaStart);
    printf("size=%x\n", entry->size);

    return entry->lbaStart;
}