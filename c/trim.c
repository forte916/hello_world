/**
 * How to run
 *   $ gcc -o trim trim.c
 *   $ ./trim
 */

#include <stdio.h>
#include <string.h>

void trim2(char* str)
{
	printf("trim2: [%s] \n", str);
	int i = 0;
	int len = strlen(str);
	char* first = str;
	char* last = str + len - 1; //Cares array index bound

	//Trim left
	for (i = 0; i<len; i++, first++) {
		//printf("i: %d, *first: [%c] \n", i, *first);
		if (*first != ' ') break;
	}
	//printf("left_pos: %d \n", i);

	//Trim right
	for (i = len; i>0; i--, last--) {
		//printf("i: %d, *last: [%c] \n", i, *last);
		if (*last != ' ') break;
	}
	//printf("right_pos: %d \n", i);
	*(last + 1) = '\0';

	//Refill
	len = strlen(first) + 1; //Includes NULL
	for (i=0; i<len; i++) {
		//printf("i: %d, *str: [%c],  *first: [%c] \n", i, *str, *first);
		*str++ = *first++;
	}
	//printf("trimmed: [%s] \n", str);
}


void trim(char* str)
{
	printf("trim1: [%s] \n", str);
	int i = 0;
	int len = strlen(str);

	//Trim left
	for (i = 0; i<len; i++) {
		if (str[i] != ' ') break;
	}
	//printf("left_pos: %d \n", i);
	int left_pos = i;

	//Trim right
	for (i = len; i>0; i--) {
		//printf("i: %d, str[i-1]: [%c] \n", i, str[i-1]);
		if (str[i-1] != ' ') break;
	}
	//printf("right_pos: %d \n", i);
	str[i] = '\0';

	//Refill
	for (i=0; i<strlen(str); i++) {
		//printf("i: %d, i - left_pos: %d,  str[i]: [%c] \n", i, i - left_pos, str[i]);
		if (i < left_pos) continue;
		str[i - left_pos] = str[i];
	}
	str[i - left_pos] = '\0';
	//printf("trimmed: [%s] \n", str);
}


int main(int argc, char *argv[])
{
	printf("Hello, world!\n");

	char test1[] = "  AB C ";
	trim(test1);
	printf("test1: [%s] \n", test1);

	char test2[] = "  AB C ";
	trim2(test2);
	printf("test2: [%s] \n", test2);

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

