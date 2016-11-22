#include "holberton.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

/**
 * split_format - counts the number of single %
 * @format: formatting string to check for %
 * Return: returns a malloc array of pointers that will
 * eventually point to the different formats
 */

char **split_format(char *format)
{
	int i, f_count, j, num_p;
	char **array;

	f_count = 0;
	for(i = 0; format[i] != '\0'; ++i)
	{
		j = num_p = 0;
		if (format[i] == '%')
		{
			while (format[i + j] == '%')
			{
				num_p++;
				j++;
			}
			if ((num_p % 2) != 0)
				f_count++;
			i = i + j;
		}

	}
	printf("f_count is %d\n", f_count);
	array = malloc(sizeof(char *) * f_count);
	return (array);
}

/**
 * fill_format - fills in the format_array with all conversion formatters
 * including their flags
 * @format: formatting string containing possible formatters
 * @format_array: array to put the formatting strings in
 * Return: format_array
 */

void *fill_format(const char *format)
{
	int f_index, i, j, k, num_p;
	char *conv;

	f_index = 0;
	for (i = 0; format[i] != '\0'; ++i)
	{
		if (format[i] == '%')
		{
			num_p = k = 0;
			while (format[i + k] == '%')
			{
				num_p++;
				k++;
			}
			i = i + k;
			if ((num_p % 2) != 0 || num_p == 1)
			{
				j = 0;
				while (no_conversion(format[i + j]) &&
				       format[i + j])
					++j;
				conv = malloc((j + 2) * sizeof(char));
				conv = strncpy(conv, format + i, j + 1);
				conv[j + 1]= '\0';
				get_validity_func(conv[j])(conv);
				free(conv);
			}

		}
	}
}
