// MatrixOS - isr.c
// High level interrupt service routines and interrupt request handlers.

#include <common.h>
#include <arch/i386/isr.h>
#include <monitor.h>

isr_t interrupt_handlers[256];

void register_interrupt_handler ( uint8_t n, isr_t handler ) {
	interrupt_handlers[n] = handler;
}
/*
// This gets called from our ASM interrupt handler stub.
*/
void isr_handler ( registers_t regs ) {
	// This line is important. When the processor extends the 8-bit interrupt number
	// to a 32bit value, it sign-extends, not zero extends. So if the most significant
	// bit (0x80) is set, regs.int_no will be very large (about 0xffffff80).
	uint8_t int_no = regs.int_no & 0xFF;

	if ( interrupt_handlers[int_no] != 0 ) {
		isr_t handler = interrupt_handlers[int_no];
		handler ( &regs );

	} else {
		kprintf ( "unhandled interrupt: %h\n", int_no );
		
		for ( ;; );
	}
}
/*
// This gets called from our ASM interrupt handler stub.
*/
void irq_handler ( registers_t regs ) {
	// Send an EOI (end of interrupt) signal to the PICs.
	// If this interrupt involved the slave.
	if ( regs.int_no >= 40 ) {
		// Send reset signal to slave.
		outb ( 0xA0, 0x20 );
	}

	// Send reset signal to master. (As well as slave, if necessary).
	outb ( 0x20, 0x20 );

	if ( interrupt_handlers[regs.int_no] != 0 ) {
		isr_t handler = interrupt_handlers[regs.int_no];
		handler ( &regs );
	}

}