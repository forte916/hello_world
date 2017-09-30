/**
 * @file      add.c
 * @brief     Addition program for C lang.
 *
 * This is the first program for C clang.
 *
 * @author    forte916
 * @version   1.0
 * @copyright Copyright (C) 2017 forte916, all right reserved.
 */

#include <stdio.h>
#include <stdlib.h>		//atoi

//! Requirement: $gcc -std=c99
//#include <stdbool.h>


#ifndef _Bool
#define bool    _Bool
#define true    1
#define false   0
#endif

/**
 * @brief Check if an argument is a number of not.
 * @param[in] s        A string to be checked
 * @retval    true     If s is a number
 * @retval    false    If s is NOT a number
 * @note
 *     C99 has bool type
 * @todo
 *     Implement this func.
 */
bool is_number(char *s)
{
	// TODO: implement here.
	return true; // always true for now.
}


/**
 * @brief  Add given two arguments, then return summary.
 * @param[in]  x    A number
 * @param[in]  y    A number
 * @return     Summary of given arguments.
 */
int add(int x, int y)
{
	return x + y;
}

/**
 * @brief
 * @note
 *   $ gcc -o add add.c
 *   $ ./add
 */
int main(int argc, char *argv[])
{
	printf("Hello, world!\n");
	//printf("argc = %d\n",argc);

	int x = 0;
	int y = 0;

	if (argc >= 3) {
		// read from command line arguments
		x = atoi(argv[1]);
		y = atoi(argv[2]);
		//printf("argv[1] = %s,x = %d\n",argv[1], x);
		//printf("argv[2] = %s,y = %d\n",argv[2], y);
	} else {
		// read from stdin
		//scanf("%d %d", &x, &y);
	}

	int ret = add(x, y);
	printf("%d + %d = %d\n", x, y, ret);
	return 0;
}

