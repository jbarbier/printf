#include "holberton.h"
#include <stdlib.h>
#include <stdio.h>
/**
 * make_char - make a string from a char
 * @s: string formatting
 * @vl: va_list for argument
 * Return: the string
 */
char *make_char(char *s, va_list vl)
{
	int i, j;
	char *result;

	i = 0;
	while (*s != 'c' && _is_digit(*s))
	{
		i = 10 * i + *s - '0';
		++s;
	}
	if (i == 0)
		i += 1;
	printf("i is %d\n", i);
	result = malloc(i * sizeof(char));

	for (j = 0; j < (i - 1); ++j)
		result[j] = ' ';
	printf("i is %d, j is %d\n", i, j);
	result[j] = va_arg(vl, int);
	return (result);
}

/**
 *
 */

char *make_string(char *s, va_list vl)
{
	return (NULL);
}
