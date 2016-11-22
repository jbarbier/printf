/*string formatters*/
#include <stdarg.h>
#include "holberton.h"
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

/**
 * make_string - creates formatted string
 * @s: format
 * @vl: argument
 * Return: formatted string
 */

char *make_string(char *s, va_list vl)
{
	int i, j, k, l, l2, c_l, j2;
	char *result, *string;

	k = 0;
	for (i = 0, l = 0; s[i] != 's'; i++)
	{
		if (s[i] == '.')
		{
			i++;
			while (s[i] != 's')
			{
				l  = 10 * l + s[i] - '0';
				i++;
			}
			break;
		}
	}
	c_l = l;
	string = va_arg(vl, char *);
	i = 1;
	while ((s[i] != '.' || s[i] != 's') && _is_digit(s[i]))
	{
		l2 = 10 * l2 + s[i] - '0';
		i++;
	}
	l = (l == 0) ? _strlen(string) + l2 : l + l2;
	result = malloc(sizeof(char) * (l + 1));
	if (c_l != 0 && l2 != 0)
	{
		for (j = 0; j < l2 - 1; j++)
			result[j] = ' ';
		for (j2 = 0; j2 < c_l; j2++)
			result[j] = string[j2];
	}
	else
	{
		for (j = 0; j < (l2 - _strlen(string)); ++j)
			result[j] = ' ';
		for (k = k + j, i = 0; k < l && string[i] != '\0'; k++, i++)
			result[k] = string[i];
	}
	return (result);
}


/*for strings*/
/**
 * conversion_string - check if format is right
 * @s: formatting string for chars
 * Return: 1 if it is 0 otherwise, actually exit process
 */
int conversion_string(char *s)
{
	int i, dot_flag;

	i = (*s == '%') ? 1 : 0;
	dot_flag = 0;

	while (*(s + i) != 's')
	{
		if ((_is_digit(*(s + i)) == 0 && *(s + i) != '.') ||
		    (*(s + i) == '.' && dot_flag))
		{
			write(1, "no string\n", 10);
			exit(98);
			return (0);
		}
		if (_is_digit(*(s + i)) == 0 && *(s + i) == '.')
			dot_flag = 1;
		++i;
	}
	return (1);
}
