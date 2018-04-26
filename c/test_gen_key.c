/**
 * How to run
 *   $ gcc -o test_gen_key test_gen_key.c
 *   $ ./test_gen_key
 */

#include <stdio.h>
#include <string.h>
#include <ctype.h>    //isgraph()
#include <stdlib.h>   //srand()
#include <time.h>     //time()
#include <unistd.h>   //sleep()



/**
 * @brief Generate a random string with a given length.
 *
 * @param[out] buf An output buffer.
 * @param[in]  len A length of buf.
 */
void gen_key(char* buf, int len)
{
	srand(time(NULL));
	for (int i = 0; i < len; i++) {
		//printf("%d\n", rand() % 256);
		buf[i] = rand() % 256;
	}
}


void print_char(char *str, int len)
{
	for(int i = 0; i < len; i++) {
		printf("%c", isgraph(str[i]) ? str[i] : '.');
	}
	printf("\n");
}


int main(int argc, char *argv[])
{
	printf("---- Test case 4 ----\n");
	char key4[16] = {0};
	gen_key(key4, sizeof(key4) - 1);
	print_char(key4, sizeof(key4));

    sleep(1);
	gen_key(key4, sizeof(key4) - 1);
	print_char(key4, sizeof(key4));

    sleep(1);
	gen_key(key4, sizeof(key4) - 1);
	print_char(key4, sizeof(key4));

    sleep(1);
	gen_key(key4, sizeof(key4) - 1);
	print_char(key4, sizeof(key4));

	return 0;
}

/*
Console output:

$ gcc -o test_gen_key test_gen_key.c
$ ./test_gen_key
---- Test case 4 ----
.RL....Ef..5/...
......Z...Vu....
C.:.gF...:...\..
p8..B..b.y...!..

*/
