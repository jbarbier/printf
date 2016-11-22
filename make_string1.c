#include "holberton.h"


/**
 * make_char - make a string from a char
 * @s: string formatting
 * @vl: va_list for argument
 * Return: the string
 */
char *make_char(char *s, va_list vl);
{
	int i, j;
	char *result;

	i = 0;
	while (*s != 'c' && _isdigit(*s))
	{
		i = 10 * i + *s - '0';
		++s;
	}
	result = malloc((1 + i) * sizeof(char));

	for (j = 0; j < i; ++j)
		result[j] = ' ';
	result[i] = va_arg(vl, int);
	return (result);
}

