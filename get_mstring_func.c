#include "holberton.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * get_mstring_func - selects the correct validity func to perform
 * @c: formatter passed
 * Return: a pointer to function given formatter
 */

char *(*get_mstring_func(char c))(char *, va_list)
{
	m_string v[] = {
		{'c', make_char},
		{'s', make_string}
/**		{'d', make_decimal} */
	};
	int i;

	i = 0;
	while (i < 3)
	{
		if (c == v[i].type)
			return (v[i].make_s);
		i++;
	}
	return (NULL);
}
