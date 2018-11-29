/**
 * How to run
 *   $ gcc -o test test.c
 *   $ ./test
 */

#include <stdio.h>

#define FALSE 0
#define TRUE 1

void check_nul()
{
	int i, has_nul;
	char str1[5]  = {'h', 'e', 'l', 'l', 'o'};			// FALSE
	char str2[6]  = {'h', 'e', 'l', 'l', 'o', '\0'};	// TRUE
	char str3[6]  = {'h', 'e', 'l', 'l', 'o', 0};		// TRUE
	char str4[11] = {'h', 'e', 'l', 'l', 'o', '\0', 'w', 'o', 'r', 'l', 'd'};	// TRUE
	char str5[99] = {'h', 'e', 'l', 'l', 'o'};			// TRUE

	has_nul = FALSE;
	for (i = 0; i < sizeof(str1); i++) {
		printf("%d:%c\n", i, str1[i]);
		if ( ! str1[i] ) {
			has_nul = TRUE;
			break;
		}
	}
	printf("has_nul:%d\n", has_nul);

	has_nul = FALSE;
	for (i = 0; i < sizeof(str2); i++) {
		printf("%d:%c\n", i, str2[i]);
		if ( ! str2[i] ) {
			has_nul = TRUE;
			break;
		}
	}
	printf("has_nul:%d\n", has_nul);

	has_nul = FALSE;
	for (i = 0; i < sizeof(str3); i++) {
		printf("%d:%c\n", i, str3[i]);
		if ( ! str3[i] ) {
			has_nul = TRUE;
			break;
		}
	}
	printf("has_nul:%d\n", has_nul);

	has_nul = FALSE;
	for (i = 0; i < sizeof(str4); i++) {
		printf("%d:%c\n", i, str4[i]);
		if ( ! str4[i] ) {
			has_nul = TRUE;
			break;
		}
	}
	printf("has_nul:%d\n", has_nul);

	has_nul = FALSE;
	for (i = 0; i < sizeof(str5); i++) {
		printf("%d:%c\n", i, str5[i]);
		if ( ! str5[i] ) {
			has_nul = TRUE;
			break;
		}
	}
	printf("has_nul:%d\n", has_nul);

}


int main(int argc, char *argv[])
{
	printf("Hello, world!\n");
	check_nul();
	return 0;
}



/*
Console output:

$ gcc -o test test.c
$ ./test
Hello, world!
0:h
1:e
2:l
3:l
4:o
has_nul:0
0:h
1:e
2:l
3:l
4:o
5:
has_nul:1
0:h
1:e
2:l
3:l
4:o
5:
has_nul:1
0:h
1:e
2:l
3:l
4:o
5:
has_nul:1
0:h
1:e
2:l
3:l
4:o
5:
has_nul:1

手元の実行結果では、NUL 終端されているかどうかを正しく判定できています

*/
