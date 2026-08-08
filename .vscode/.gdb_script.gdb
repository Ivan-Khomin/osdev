    b *0x7c00
    set disassembly-flavor intel
    layout asm
    target remote | qemu-system-i386 -S -gdb stdio -m 32 -hda /home/invis/projects/osdev/build/i686_debug/image.img
