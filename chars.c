/*all char realted functions*/
#include "holberton.h"
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
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
	printf("i is %d\n and string is %s\n", i, s);
	result = malloc((i + 1)* sizeof(char));

	for (j = 0; j < (i - 1); ++j)
		result[j] = ' ';
	printf("i is %d, j is %d\n", i, j);
	result[j] = va_arg(vl, int);
	result[i] = '\0';
	return (result);
}


/**
 * conversion_char - check if format is right
 * @s: formatting string for chars
 * Return: 1 if it is 0 otherwise, actually exit process
 */
int conversion_char(char *s)
{
	int i;

	i = (*s == '%') ? 1 : 0;
	while (*(s + i) != 'c')
	{
		if (_is_digit(*(s + i)) == 0)
		{
			write(1, "no char\n", 8);
			exit(98);
			return (0);
		}
		++i;
	}
	return (1);
}