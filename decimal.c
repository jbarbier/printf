#include "holberton.h"
#include <stdlib.h>
#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>
#include <limits.h>

/**
 * conversion_di - checks validity of d and i
 * @s: format string ot check
 * Return: 1 if checks and 0 and exits otherwise
 */
int conversion_di(char *s)
{
	(void) s;
	return (1);
}

/**
 * _itoa - transforms a number into a string
 * @n: an int
 * Return: a string
 */
char *_itoa(int n)
{
	int l, tens, i, min;
	char *number;

	l = 2;
	min = 1;
	if (n >= 0)
	{
		l = l - 1;
		min = 0;
		n = -n;
	}
	tens = n;
	while (tens < -9)
	{
		tens /= 10;
		l = l + 1;
	}
	number = malloc((l + 1) * sizeof(char));
	i = l - 1;
	number[l] = '\0';
	do {
		number[i] = -(n % 10) + '0';
		n /= 10;
		--i;
	} while (i >= 0 && n < 0);

	if (i == 0 && min)
		number[0] = '-';

	return (number);
}

/**
 * make_decimal - creates formatted output
 * @s: format string
 * @vl: arguement to format
 * Return: formatted string;
 */

char *make_decimal(char *s, va_list vl)
{
	char *number;
	int n;
	(void) s;

	n = va_arg(vl, int);
	number = _itoa(n);
	return (number);
}
