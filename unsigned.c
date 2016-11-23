#include "holberton.h"
#include <stdlib.h>
#include <stdio.h>

/**
 * conversion_u - checks validity of u
 * @s: format string ot check
 * Return: 1 if checks and 0 and exits otherwise
 */
int conversion_u(char *s)
{
	(void) s;
	return (1);
}



/**
 * _utoa - transforms a number into a string
 * @n: an unsigned int
 * Return: a string
 */
char *_utoa(unsigned int n)
{
	int l, i;
	char *number;
	unsigned int tens;

	l = 1;
	tens = n;
	while (tens > 9)
	{
		tens /= 10;
		l = l + 1;
	}

	number = malloc((l + 1) * sizeof(char));
	i = l - 1;
	number[l] = '\0';
	do {
		number[i] = (n % 10) + '0';
		n /= 10;
		--i;
	} while (i >= 0 && n > 0);
	return (number);
}



/**
 * make_unsigned - make an unsigned int
 * @s: a format string
 * @l: a va_list
 * Return: a pointer to the result
 */
char *make_unsigned(char *s, va_list l)
{
	unsigned int n;
	char *result;
	(void) s;
	n = va_arg(l, unsigned int);
	result = _utoa(n);
	return (result);

}
