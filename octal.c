#include "holberton.h"
#include <stdlib.h>
#include <stdio.h>

/**
 * conversion_o - checks validity of octals
 * @s: format string ot check
 * Return: 1 if checks and 0 and exits otherwise
 */
int conversion_o(char *s)
{
	(void) s;
	return (1);
}



/**
 * octal - convert a number to an octal
 * @n: a number
 * Return: a number in octal
 */
int octal(unsigned int n)
{
	int i;
	unsigned int result;

	i = 0;
	result = 0;
	while (n != 0)
	{
		result += (result % 8) * i;
		n /= 8;
		i *= 10;
	}
	return (result);
}

/**
 * make_octal - make an octal string
 * @s: a format string
 * @l: a va_list
 * Return: a pointer to the result
 */
char *make_octal(char *s, va_list l)
{
	unsigned int n;
	char *result;
	(void) s;
	n = va_arg(l, unsigned int);
	result = _utoa(octal(n));

	return(result);
}
