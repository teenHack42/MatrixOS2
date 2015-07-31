/*
//  MatrixOS2 - common.c
//  common global functions
*/
#include <common.h>
#include <stdint.h>

/*
//  outb: write value(uint8_t) to port
*/
void outb ( uint16_t port, uint8_t value ){
    asm volatile ( "outb %1, %0" : : "dN" (port), "a" (value));
}

/*
//  inb: return uint8_t from port
*/
uint8_t inb ( uint16_t port ) {
    uint8_t retval;
    asm volatile( "inb %1, %0" : "=a" (retval) : "dN" (port) );
    return retval;
}

/*
//  inw:  return uint16_t from port
*/
uint16_t inw ( uint16_t port ) {
    uint16_t retval;
    asm volatile( "inw %1, %0" : "=a" (retval) : "dN" (port));
    return retval;
}

/*
//  outw: write value(uint16_t) to port
*/
void outw ( uint16_t port, uint16_t value ) {
asm volatile ( "outw %1, %0" : : "dN" (port), "a" (value));
}

/*
//  inl: return uint32_t from port
*/
uint32_t inl ( uint16_t port ) {
    uint32_t retval;
    asm volatile( "inl %1, %0" : "=a" (retval) : "dN" (port));
    return retval;
}

/*
//  outl: write value(u32int_t) to port
*/
void outl ( uint16_t port, uint32_t value ) {
asm volatile ( "outl %1, %0" : : "dN" (port), "a" (value));
}
