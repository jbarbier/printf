#include "holberton.h"
#include <stdlib.h>
#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>

/**
 * conversion_di - checks validity of d and i
 * @s: format string ot check
 * Return: 1 if checks and 0 and exits otherwise
 */
int conversion_di(char *s)
{
	return (1);
}


/**
 * _max - get the max of 2 numbers
 * @a: int
 * @b: int
 * Return: the largest
 */
int _max(int a, int b)
{
	return ((a > b) ? a : b);
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
	l = 1;
	min = 0;
	if (n < 0)
	{
		++l;
		min = 1;
		n = -n;
	}
	tens = 10;
	while ((n / tens) > 0)
	{
		tens *= tens;
		++l;
	}
	number = malloc((l + 1) * sizeof(char));
	i = l - 1;
	number[l] = '\0';
	do
	{
		number[i] = n % 10 + '0';
		n /= 10;
		--i;
	} while (i >= 0 && n > 0);

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

	number = _itoa(va_arg(vl, int));

	return (number);
}


