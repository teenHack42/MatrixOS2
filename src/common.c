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
//  outl: write value(uint32_t_t) to port
*/
void outl ( uint16_t port, uint32_t value ) {
asm volatile ( "outl %1, %0" : : "dN" (port), "a" (value));
}


/*
// Count the length of a char array.
*/
int strlen ( char *src ) {
	int i = 0;

	while ( *src++ ) {
		i++;
	}

	return i;
}

void numToAsciChar ( char *asciInChar, int integerLength ) {
	int x;

	for ( x = 0; x < integerLength; x++ ) {
		asciInChar[x] = asciInChar[x] + 48; //(only works on integers)
	}

}

void intToChar ( int integer, char *numbersInChar ) {
	int32_t integerLength = math_intLength ( integer ), x, endX;
	int32_t number = integer % 10;

	//~ char *numbersInChar[integerLength];

	for ( x = 0; x < integerLength + 1; x++ ) {
		if ( x != 0 ) {
			integer = ( integer - number ) / 10;
			number = ( integer ) % 10;
		}

		endX = integerLength - x - 1;

		numbersInChar[endX] = number;
	}

}

/*
// Copy len bytes from src to dest.
*/
void memcpy ( uint8_t *dest, const uint8_t *src, uint32_t len ) {
	const uint8_t *sp = ( const uint8_t * ) src;
	uint8_t *dp = ( uint8_t * ) dest;

	for ( ; len != 0; len-- ) {
		*dp++ = *sp++;
	}
}

/*
// Write len copies of val into dest.
*/
void memset ( uint8_t *dest, uint8_t val, uint32_t len ) {
	uint8_t *temp = ( uint8_t * ) dest;

	for ( ; len != 0; len-- ) {
		*temp++ = val;
	}
}
