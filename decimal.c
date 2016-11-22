#include "holberton.h"
#include <stdlib.h>
#include <stdarg.h>
#include <stdio.h>

/**
 * conversion_di - checks validity of d and i
 * @s: format string ot check
 * Return: 1 if checks and 0 and exits otherwise
 */

int conversion_di(char *s)
{
	int i, dot_flag;

	i = (*s == '%') ? 1 : 0;
	printf("%c\n", *s);
	dot_flag = 0;
	printf("%c\n", *(s + i));
	if (*(s + i) == 'd' || *(s + i) == 'i')
		return (1);
	while (*(s + i) != 'd' || *(s + i) != 'i')
	{
		if (_isdflag(*(s + i)))
			++i;
		if ((_is_digit(*(s + i)) == 0 && *(s + i) != '.') ||
		    (*(s + i) == '.' && dot_flag))
		{
			write(1, "no digit\n", 9);
			exit(98);
			return (0);
		}
		if (_is_digit(*(s + i)) == 0 && *(s + i) == '.')
			dot_flag = 1;
		++i;
	}
	return (1);
}

/**
 * make_decimal - creates formatted output
 * @s: format string
 * @vl: arguement to format
 * Return: formatted string;
 */

char *make_decimal(char *s, va_list vl)
{
	int i, j, k, l, l2, num;
	char *result, *string;

	num = va_arg(vl, int);
	printf("IM HERE\n");
	string = num_string(num);
	printf("%s\n", string);
/**	for (i = 0, l = 0; s[i] != 's'; i++)
	{
		if (s[i] == '.')
		{
			for (i = i + 1; s[i] != 's'; i++)
				l  = 10 * l + s[i] - '0';
			break;
		}
	}
	num = va_arg(vl,  num);
	for (i = 0; (s[i] != '.' || s[i] != 's') && _is_digit(s[i]); i++)
		l2 = 10 * l2 + s[i] - '0';
	l = (l == 0) ? _strlen(string) + l2 : l;
	result = malloc(sizeof(char) * (l + 1));
	for (j = 0; j < (l2 - 1); ++j)
		result[j] = ' ';
	for (k = k + j, i = 0; k < l && string[i] != '\0'; k++, i++)
	{
		result[k] = string[i];
		} */
	return (result);
}

/**
 * num_string - prints digits
 * @list: digit arguements
 * Return: string of the number
 */

char * num_string(int n)
{
	int i;
	int  sign, exp;
	char *ptr;

	exp = 1000000000;
	sign = 1;
	ptr = malloc(sizeof(char) * 24);
	i = 0;
	/** if n is positive, change to negative */
	if (n > 0)
	{
		n *= -1;
		sign *= -1;
	}
	if  (n != 0)
	{
                /** determine how many places is the number*/
		while ((n / exp) ==  0)
		{
			exp = exp / 10;
		}
		if (sign == 1)
			ptr[i++] = '-';
                /** prints out every char starting from the left */
		while (exp >= 1)
		{
			ptr[i] = (-(n / exp) + '0');
			n = n % exp;
			exp = exp / 10;
			i++;
		}
	}
	else
		ptr[i++] = ('0');
	ptr[i] = '\0';
	return (ptr);
}
