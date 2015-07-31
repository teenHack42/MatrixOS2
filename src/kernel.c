#include <common.h>
#include <monitor.h>
#include <multiboot.h>


extern uint32_t placement_address;
uint32_t initial_esp;
struct multiboot *mboot_ptr;

void kernel_main(struct multiboot *mboot_point, uint32_t initial_stack) {
	initial_esp = initial_stack; //Must be first to run
	mboot_ptr = mboot_point; //Must be first to run
	printf("Hello, Crule World!\nHahaha :D");
}
