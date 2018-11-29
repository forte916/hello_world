/**
 * How to run
 *   $ gcc -o bit_shift bit_shift.c
 *   $ ./bit_shift
 */

#include <stdio.h>

void bit_shift(unsigned char input)
{
	unsigned char output = 0;
	output = (1U << input) >> 1;

	printf("%u to %u \n", input, output);
}


int main(int argc, char *argv[])
{
	printf("Let's calculate (1U << input) >> 1 \n");
	bit_shift(1);
	bit_shift(2);
	bit_shift(3);
	bit_shift(4);
	bit_shift(5);
	return 0;
}



/*
Console output:

$ gcc -o bit_shift bit_shift.c
$ ./bit_shift
Let's calculate (1U << input) >> 1
1 to 1
2 to 2
3 to 4
4 to 8
5 to 16

手元の実行結果では、1 と 2 は演算結果は変わらない。3 は 4 に変わる

*/
