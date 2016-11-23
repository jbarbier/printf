#include "holberton.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * get_validity_func - selects the correct validity func to perform
 * @c: formatter passed
 * Return: a pointer to function given formatter
 */

int (*get_validity_func(char c))(char *)
{
	valid v[] = {
		{'c', conversion_char},
		{'s', conversion_string},
		{'d', conversion_di},
		{'i', conversion_di},
		{'u', conversion_u},
		{'x', conversion_h},
		{'X', conversion_h},
		{'b', conversion_b},
		{'o', conversion_o}
	};
	int i;

	i = 0;
	while (i < 9)
	{
		if (c == v[i].type)
			return (v[i].conversion_check);
		i++;
	}
	return (NULL);
}
