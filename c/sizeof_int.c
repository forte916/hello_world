/**
 * How to run
 *   $ gcc -o sizeof_int sizeof_int.c
 *   $ ./sizeof_int
 */

#include <stdio.h>

int main(int argc, char *argv[])
{
	printf("Hello, world!\n");

    // Size of various types
	printf("sizeof(unsigned char):       %d\n", sizeof(unsigned char));
	printf("sizeof(unsigned short):      %d\n", sizeof(unsigned short));
	printf("sizeof(unsigned int):        %d\n", sizeof(unsigned int));
	printf("sizeof(unsigned long):       %d\n", sizeof(unsigned long));
	printf("sizeof(unsigned long long):  %d\n", sizeof(unsigned long long));

	return 0;
}

/*
Console output:

$ gcc -o sizeof_int sizeof_int.c
$ ./sizeof_int
Hello, world!
sizeof(unsigned char):       1
sizeof(unsigned short):      2
sizeof(unsigned int):        4
sizeof(unsigned long):       8
sizeof(unsigned long long):  8

手元の実行結果では、char が 1 byte, short が 2 byte, int が 4 byte です

*/
