/*  MatrixOS2 - common.h
//  common global functions
*/
#ifndef COMMON_H
#define COMMON_H

#include <stdint.h>

/*  include stdint.h from compiler for std data types.
//  Not using JM's data types
//  Data Types as follows:
//  uint32_t, int32_t, uint16_t, int16_t, uint8_t, int8_t
*/

//Function definitions for In and Out processor commands
void outb ( uint16_t port, uint8_t value );
uint8_t inb ( uint16_t port );
uint16_t inw ( uint16_t port );
void outw ( uint16_t port, uint16_t value );
uint32_t inl ( uint16_t port );
void outl ( uint16_t port, uint32_t value );

int strlen ( char *src );
void numToAsciChar ( char *asciInChar, int integerLength );
void intToChar ( int integer, char *numbersInChar );

#endif//COMMON_H
