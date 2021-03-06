// MatrixOS - stdio.h
// stdio file
#include <stdio.h>
#include <common.h>
#include <stdarg.h>
#include <math.h>

//TODO make screen printing buffered

void printf ( char *c, ... ) {
	va_list arguments;

	int i, numberOfArgs = 0, stringLength = strlen ( c );
	int integerArg;

	for ( i = 0; c[i]; i++ ) //checks number arguments is correct
		if ( c[i] == '%' ) {
			numberOfArgs++;
		}

	i = 0;

	va_start ( arguments, *c );

	while ( c[i] ) {

		if ( c[i] == '%' ) {
			if ( c[i+1] == 'd' ) {
				integerArg = va_arg ( arguments, int );

				int numberLength = math_intLength ( integerArg );
				int x;

				char integer[numberLength];

				intToChar ( integerArg, integer ); //sets integer as char

				numToAsciChar ( integer, numberLength ); //sets char to ASCII for printing

				for ( x = 0; x < numberLength; x++ ) {
					monitor_put ( integer[x] );

				}

				i = i + 2;

			} else if ( c[i+1] == 's' ) { //user wants to print a string
				char *charArrayArg;
				charArrayArg = va_arg ( arguments, char* );

				printf ( charArrayArg );
				i = i + 2;

			} else if ( c[i+1] == 'o' ) { //user wants to print a null string
				char *charArrayArg;
				charArrayArg = va_arg ( arguments, char* );
				char *ca = 0;
				uint32_t i = 0;

				while ( 1 ) {
					if ( charArrayArg == 0 ) {
						break;
					}

					i++;
				}

				serialf ( "%d\n\n\n", i );

				printf ( charArrayArg );
				i = i + 2;

			} else if ( c[i+1] == 'c' ) { //user wants to print a char
				char *charArg;
				charArg = va_arg ( arguments, char* );

				monitor_put ( charArg );
				i = i + 2;

			} else if ( c[i+1] == 'h' ) { //user wants to print a hex number

				uint32_t hexArg = va_arg ( arguments, uint32_t );

				int32_t tmp;

				printf ( "0x" );

				char noZeroes = 1;

				int hexCount;

				for ( hexCount = 28; hexCount > 0; hexCount -= 4 ) {
					tmp = ( hexArg >> hexCount ) & 0xF;

					if ( !tmp && noZeroes ) {
						continue;
					}

					if ( tmp >= 0xA ) {
						noZeroes = 0;
						monitor_put ( tmp-0xA+'a' );

					} else {
						noZeroes = 0;
						monitor_put ( tmp+'0' );
					}
				}

				tmp = hexArg & 0xF;

				if ( tmp >= 0xA ) {
					monitor_put ( tmp - 0xA + 'a' );

				} else {
					monitor_put ( tmp+'0' );
				}

				i = i + 2;
			}
		}

		if ( i < stringLength + 1 && c[i] != '%' ) {
			if ( c[i] == 0 ) { //if i is at the terminating 0 '\000' of a string, break from loop
				break;

			} else {
				monitor_put ( c[i] );
				i++;
			}
		}
	}

	va_end ( arguments );
}

void kprintf ( char *c, ... ) {
	va_list arguments;

	int i, numberOfArgs = 0, stringLength = strlen ( c );
	int integerArg;

	for ( i = 0; c[i]; i++ ) //checks number arguments is correct
		if ( c[i] == '%' ) {
			numberOfArgs++;
		}

	i = 0;

	va_start ( arguments, *c );

	while ( c[i] ) {

		if ( c[i] == '%' ) {
			if ( c[i+1] == 'd' ) {
				integerArg = va_arg ( arguments, int );

				int numberLength = math_intLength ( integerArg );
				int x;

				char integer[numberLength];

				intToChar ( integerArg, integer ); //sets integer as char

				numToAsciChar ( integer, numberLength ); //sets char to ASCII for printing

				for ( x = 0; x < numberLength; x++ ) {
					monitor_put ( integer[x] );
					write_serial ( integer[x] );
				}

				i = i + 2;

			} else if ( c[i+1] == 's' ) { //user wants to print a string
				char *charArrayArg;
				charArrayArg = va_arg ( arguments, char* );

				printf ( charArrayArg );
				i = i + 2;

			} else if ( c[i+1] == 'c' ) { //user wants to print a char
				char *charArg;
				charArg = va_arg ( arguments, char* );

				monitor_put ( charArg );
				i = i + 2;

			} else if ( c[i+1] == 'h' ) { //user wants to print a hex number

				uint32_t hexArg = va_arg ( arguments, uint32_t );

				int32_t tmp;

				printf ( "0x" );
				write_serial ( '0' );
				write_serial ( 'x' );

				char noZeroes = 1;

				int hexCount;

				for ( hexCount = 28; hexCount > 0; hexCount -= 4 ) {
					tmp = ( hexArg >> hexCount ) & 0xF;

					if ( !tmp && noZeroes ) {
						continue;
					}

					if ( tmp >= 0xA ) {
						noZeroes = 0;
						monitor_put ( tmp-0xA+'a' );
						//write_serial ( tmp-0xA+'a' );

					} else {
						noZeroes = 0;
						monitor_put ( tmp+'0' );
						//write_serial ( tmp+'0' );
					}
				}

				tmp = hexArg & 0xF;

				if ( tmp >= 0xA ) {
					monitor_put ( tmp - 0xA + 'a' );
					write_serial ( tmp - 0xA + 'a' );

				} else {
					monitor_put ( tmp+'0' );
					write_serial ( tmp+'0' );
				}

				i = i + 2;
			}
		}

		if ( i < stringLength + 1 && c[i] != '%' ) {
			if ( c[i] == 0 ) { //if i is at the terminating 0 '\000' of a string, break from loop
				break;

			} else {
				write_serial ( c[i] );
				monitor_put ( c[i] );
				i++;
			}
		}
	}

	va_end ( arguments );
}
