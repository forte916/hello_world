/**
 * How to run
 *   $ gcc -o trim trim.c
 *   $ ./trim
 */

#include <stdio.h>
#include <string.h>

void trim(char* str)
{
	printf("before trimmed: [%s] \n", str);
	int i = 0;
	int len = strlen(str);
	char* first = str;
	char* last = str + len;

	//Trim left
	for (i = 0; i<len; i++) {
		if (first[i] != ' ') break;
	}
	//printf("left_blanks: %d \n", i);
	int left_blanks = i;

	//Trim right
	for (i = len; i>0; i--) {
		//printf("i: %d, str[i-1]: [%c] \n", i, str[i-1]);
		if (str[i-1] != ' ') break;
	}
	//printf("right_blanks: %d \n", i);
	str[i] = '\0';

	//Refill
	for (i=0; i<strlen(str); i++) {
		//printf("i: %d, i - left_blanks: %d,  str[i]: [%c] \n", i, i - left_blanks, str[i]);
		if (i < left_blanks) continue;
		str[i - left_blanks] = str[i];
	}
	str[i - left_blanks] = '\0';
	//printf("trimmed: [%s] \n", str);
}


int main(int argc, char *argv[])
{
	printf("Hello, world!\n");

	char test1[] = "  AB C ";
	trim(test1);
	printf("test1: [%s] \n", test1);

	return 0;
}

/*
Console output:

$ gcc -o trim trim.c
$ ./trim.exe
Hello, world!
before trimmed: [  AB C ]
test1: [AB C]

*/

