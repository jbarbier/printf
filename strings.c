/*string formatters*/
#include <stdarg.h>
#include "holberton.h"
#include <unistd.h>
#include <stdlib.h>
/**
 *
 */

char *make_string(char *s, va_list vl)
{
	(void) s;
	(void) vl;
	return (NULL);
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
