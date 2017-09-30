/**
 * @file      add.cpp
 * @brief     Addition program for C lang.
 *
 * This is the first program for C++.
 *
 * @author    forte916
 * @version   1.0
 * @copyright Copyright (C) 2017 forte916, all right reserved.
 */

#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>		//atoi


/**
 * @brief Check if an argument is a number of not.
 * @param[in] s        A string to be checked
 * @retval    true     If s is a number
 * @retval    false    If s is NOT a number
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
 *   $ gcc -o add add.cpp
 *   $ ./add
 */
int main(int argc, char *argv[])
{
	std::cout << "Hello, world!\n";
	std::cout << "argc = " << argc << std::endl;

	int x = 0;
	int y = 0;
	std::vector<std::string> all_args;

	if (argc >= 3) {
		// read from command line arguments
    	all_args.assign(argv + 1, argv + argc);
		x = atoi(all_args[0].c_str());
		y = atoi(all_args[1].c_str());
	} else {
		// read from stdin
		//std::cin >> x >> y;
	}

	int ret = add(x, y);
	std::cout << x << " + " << y << " = " << ret << std::endl;
	return 0;
}

