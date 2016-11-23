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
long octal(unsigned int n)
{
	long int i;
	long result;

	i = 1;
	result = 0;
	while (n != 0)
	{
		result += (n % 8) * i;
		n /= 8;
		i *= 10;
	}
	return (result);
}


/**
 * _ltoa - transforms a number into a string
 * @n: an unsigned int
 * Return: a string
 */
char *_ltoa(long n)
{
	int l, i, min;
	char *number;
	long int tens;

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
	result = _ltoa(octal(n));
	return (result);
}
