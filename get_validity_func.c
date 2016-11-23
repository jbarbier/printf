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
	printf("VALID\n");
	valid v[] = {
		{'c', conversion_char},
		{'s', conversion_string},
		{'d', conversion_di},
		{'i', conversion_di},
		{'u', conversion_u},
		{'o', conversion_o},
		{'b', conversion_b}
	};
	int i;

	i = 0;
	while (i < 7)
	{
		if (c == v[i].type)
			return (v[i].conversion_check);
		i++;
	}
	printf("VALID END\n");
	return (NULL);
}
