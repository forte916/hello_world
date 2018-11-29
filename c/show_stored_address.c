/**
 * How to run
 *   $ gcc -o show_stored_address show_stored_address.c
 *   $ ./show_stored_address
 */

#include <stdio.h>
#include <stdlib.h>

char global_str[] = "global string";
static char static_global_str[] = "static global string";

void show_stored_address()
{
	char local_str[] = "local string";
	static char static_local_str[] = "static local string";
	char *malloc_str = NULL;

	malloc_str = (char *) malloc(32);
	if (malloc_str) {
		sprintf(malloc_str, "%s", "malloc string");
	}

	printf("%p: %s \n", local_str, local_str);
	printf("%p: %s \n", static_local_str, static_local_str);

	printf("%p: %s \n", global_str, global_str);
	printf("%p: %s \n", static_global_str, static_global_str);

	printf("%p: %s \n", malloc_str, malloc_str);
	printf("%p: %s \n", "literal string", "literal string");
}


int main(int argc, char *argv[])
{
	printf("Hello, world!\n");
	show_stored_address();
	return 0;
}

/*
Console output:

$ gcc -o show_stored_address show_stored_address.c
$ ./show_stored_address
$ ./show_stored_address
Hello, world!
0xffffcbbb: local string
0x100402040: static local string
0x100402010: global string
0x100402020: static global string
0x600000440: malloc string
0x100403009: literal string

The variables are stored in one of stack, static(data segment) or heap regions

*/
