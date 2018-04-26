/**
 * How to run
 *   $ gcc -o test_sscanf_OOB_write test_sscanf_OOB_write.c
 *   $ ./test_sscanf_OOB_write
 */

#include <stdio.h>
#include <string.h>

void test_sscanf_OOB_write()
{
    char param[50], value[50];
    char length49[128] = "1234567890123456789012345678901234567890123456789 aaaaa";
    char length50[128] = "12345678901234567890123456789012345678901234567890 aaaaa";
    char length51[128] = "123456789012345678901234567890123456789012345678901 aaaaa";
    int tokens;

    //case1
    tokens = sscanf(length49, "%50s %50s", param, value);
    printf("len:%d, param:[%s]\n", strlen(param), param);
    printf("len:%d, value:[%s]\n", strlen(value), value);

    //case2
    tokens = sscanf(length50, "%50s %50s", param, value);
    printf("len:%d, param:[%s]\n", strlen(param), param);
    printf("len:%d, value:[%s]\n", strlen(value), value);

    //case3
    tokens = sscanf(length51, "%50s %50s", param, value);
    printf("len:%d, param:[%s]\n", strlen(param), param);
    printf("len:%d, value:[%s]\n", strlen(value), value);

    printf("\n");

    //case4
    tokens = sscanf(length51, "%51s %51s", param, value);
    printf("len:%d, param:[%s]\n", strlen(param), param);
    printf("len:%d, value:[%s]\n", strlen(value), value);

    printf("\n");

    //case5
    tokens = sscanf(length49, "%49s %49s", param, value);
    printf("len:%d, param:[%s]\n", strlen(param), param);
    printf("len:%d, value:[%s]\n", strlen(value), value);

    //case6
    tokens = sscanf(length50, "%49s %49s", param, value);
    printf("len:%d, param:[%s]\n", strlen(param), param);
    printf("len:%d, value:[%s]\n", strlen(value), value);

    //case7
    tokens = sscanf(length51, "%49s %49s", param, value);
    printf("len:%d, param:[%s]\n", strlen(param), param);
    printf("len:%d, value:[%s]\n", strlen(value), value);
}



int main(int argc, char *argv[])
{
	printf("Hello, world!\n");
	test_sscanf_OOB_write();
	return 0;
}



/*
手元の実行結果では、case2 や case3 では
恐らく pram[50] = NUL, value[50] = NUL が自動的に代入され、OOB write となっていた可能性がある
このテストプログラムでは crash は発生しない

Console output:

$ ./test_sscanf_OOB_write
Hello, world!
len:49, param:[1234567890123456789012345678901234567890123456789]
len:49, value:[aaaaa]
len:50, param:[12345678901234567890123456789012345678901234567890]
len:50, value:[aaaaa]
len:50, param:[12345678901234567890123456789012345678901234567890]  ★恐らくOOB write
len:50, value:[1]

len:51, param:[123456789012345678901234567890123456789012345678901] ★OOB write
len:51, value:[aaaaa]

len:49, param:[1234567890123456789012345678901234567890123456789]
len:49, value:[aaaaa]
len:49, param:[1234567890123456789012345678901234567890123456789]
len:49, value:[0]
len:49, param:[1234567890123456789012345678901234567890123456789]
len:49, value:[01]

*/
