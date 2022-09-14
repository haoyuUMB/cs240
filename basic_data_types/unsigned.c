/*
 *  A pitfall program about unsigned
 */

#include <stdio.h>

int main(void)
{
	unsigned int a = 1000;
	signed int b = -1;
	if ((signed int) a > b)
		printf("a is more than b");
	else
		printf("a is less or equal than b");
	return 0;
}