#include <stdint.h>
#include "stdio.h"
#include "memory.h"
#include <hal/hal.h>
#include <arch/i686/io.h>
#include <arch/i686/irq.h>
#include <debug.h>

extern uint8_t __bss_start;
extern uint8_t __end;

void timer(Registers* regs)
{
    printf(".");
}

void __attribute__((section(".entry"))) start(uint16_t bootDrive)
{
    memset(&__bss_start, 0, (&__end) - (&__bss_start));

    HAL_Initialize();
    
    printf("Hello from kernel!\n");

    log_debug("Main", "This is an debug msg!");
    log_info("Main", "This is an info msg!");
    log_warn("Main", "This is a warning msg!");
    log_err("Main", "This is an error msg!");
    log_crit("Main", "This is a critical msg!");
    
    // i686_IRQ_RegisterHandler(0, timer);
    
end:
    for (;;);
}