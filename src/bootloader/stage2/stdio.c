#include "stdio.h"
#include "x86.h"

void putc(char c)
{
    switch (c)
    {
    case '\n':
        putc('\r');
        goto PUTCHAR;
        break;
    case '\t':
        for (int i = 0; i < 4; i++)
            putc(' ');
        break;
    default:
    PUTCHAR:
        x86_Video_WriteCharTeletype(c, 0);
    }
}

void puts(const char* str)
{
    while (*str)
    {
        putc(*str);
        str++;
    }
}