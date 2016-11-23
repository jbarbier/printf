#include "holberton.h"
#include <stdlib.h>
#include <stdio.h>

/**
 * conversion_b - checks validity of binaries
 * @s: format string ot check
 * Return: 1 if checks and 0 and exits otherwise
 */
int conversion_b(char *s)
{
	(void) s;
	return (1);
}



/**
 * make_binary - make an octal string
 * @s: a format string
 * @l: a va_list
 * Return: a pointer to the result
 */
char *make_binary(char *s, va_list l)
{
	unsigned int n;
	char *result;
	(void) s;

	n = va_arg(l, unsigned int);
	result = octorbi(n, 2);
	return (result);
}
