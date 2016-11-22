#include "holberton.h"
#include <stdio.h>
#include <string.h>
int main(void)
{
	_printf("This is a test %5cl", 'H');
	printf("strnlen = %lu", strlen("This is a test %5cl"));
	return (0);
}
