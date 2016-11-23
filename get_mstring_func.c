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
//	printf("MSTRING\n");
	m_string v[] = {
		{'c', make_char},
		{'s', make_string},
		{'d', make_decimal},
		{'i', make_decimal},
		{'u', make_unsigned},
		{'o', make_octal},
		{'b', make_binary}
	};
	int i;
//	printf("MShere\n");
//	char *(*p)(char *, va_list) = make_unsigned;
//	printf("%p", p);

	i = 0;
	while (i < 7)
	{
		if (c == v[i].type)
			return (v[i].make_s);
		i++;
	}
	return (NULL);
}
