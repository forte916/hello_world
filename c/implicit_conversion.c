/**
 * How to run
 *   $ gcc -o implicit_conversion implicit_conversion.c
 *   $ ./implicit_conversion
 */

#include <stdio.h>

void implicit_conversion()
{
	int    a = -1;
	size_t b = -1;

	printf("int    a: %d, %lu, 0x%x\n", a);
	printf("size_t b: %d, %lu, 0x%x\n", b);

	if ( a < 10 ) {     // a is signed type, thus TRUE
		printf("int    a < 10: TRUE\n");
	} else {
		printf("int    a < 10: FALSE\n");
	}

	if ( b < 10 ) {     // b is unsigned type, thus FALSE
		printf("size_t b < 10: TRUE\n");
	} else {
		printf("size_t b < 10: FALSE\n");
	}
}


int main(int argc, char *argv[])
{
	printf("Hello, world!\n");
	implicit_conversion();
	return 0;
}

/*
Console output:

$ gcc -o implicit_conversion implicit_conversion.c
$ ./implicit_conversion
Hello, world!
int    a: -1, 4294953852, 0x8013f700
size_t b: -1, 4294953208, 0x8013f700
int    a < 10: TRUE
size_t b < 10: FALSE

手元の実行結果では、型の違いで比較の結果が変わることが分かります

*/
