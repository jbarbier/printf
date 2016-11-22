#include "holberton.h"
#include <stdio.h>
#include <string.h>

int main(void)
{
	_printf("This is a test %5cl", 'H');
	puts("______________");
	printf("strnlen = %lu\n", strlen("This is a test %5cl"));

	_printf("TEst %c%c!\n", 'H', 'i');
	puts("______________");

	_printf("Test %ctest%c!!\n", '(', ')');
	return (0);
}
