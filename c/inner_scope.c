/**
 * How to run
 *   $ gcc -o inner_scope inner_scope.c
 *   $ ./inner_scope
 */

#include <stdio.h>

int main(int argc, char *argv[])
{
	printf("Hello, world!\n");

	// outer scope
	int status = 1;
	printf("outer: %p: %d\n", &status, status);

	{
		// inner scope
		int status = 2;
		printf("inner: %p: %d\n", &status, status);
	}

	printf("outer: %p: %d\n", &status, status);
	return 0;
}

/*
Console output:

$ gcc -o inner_scope inner_scope.c
$ ./inner_scope
Hello, world!
outer: 0xffffcbfc: 1
inner: 0xffffcbf8: 2
outer: 0xffffcbfc: 1

手元の実行結果では、スコープが異なる変数はアドレスが異なることが確認できています

*/
