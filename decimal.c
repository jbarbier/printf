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
	int i, dot_flag;

	i = (*s == '%') ? 1 : 0;
	printf("%s\n", s);
	dot_flag = 0;
	if (*(s + i) == 'd' || *(s + i) == 'i')
		return (1);
	if (*(s + i) == '0' && *(s + i + 1) == '0')
	{
		write(1, "no digit\n", 9);
		exit(98);
		return (0);
	}
	while (*(s + i) != 'd' && *(s + i) != 'i')
	{
		printf("LO0KING at %c\n",*(s + i));
		if (_isdflag(*(s + i)))
		{
			;
		}
		else if ((!_is_digit(*(s + i)) && *(s + i) != '.') ||
		    (*(s + i) == '.' && dot_flag))
		{
			write(1, "no digit\n", 9);
			exit(98);
			return (0);
		}
		else if (_is_digit(*(s + i)) == 0 && *(s + i) == '.')
		{
			dot_flag = 1;
		}
		++i;
	}
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
 * make_decimal - creates formatted output
 * @s: format string
 * @vl: arguement to format
 * Return: formatted string;
 */

char *make_decimal(char *s, va_list vl)
{
	int width, precision, ln, l, i;
	char *number, *result;

	width = getwidth(s);
	precision = getprecision(s);

	number = _itoa(va_arg(vl, int));
	ln = _strlen(number);

	l = max(ln, max(width, precision));

	result = malloc((l + 1) * sizeof(char));

	i = (*s = '%') ? 1 : 0;
	if (_isdflag(*(s + i)))
	{
		switch *(s + i)
		{
		case '-':

			break;
case '


}











int main(void)
{

	conversion_di("%9.0d");
	conversion_di("%00.9i");
	conversion_di("%5d");

	return (0);
}
