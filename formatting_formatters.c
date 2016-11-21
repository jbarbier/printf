#include "holberton.h"
#include <stdlib.h>
#include <stdio.h>

/**
 * split_format - counts the number of single %
 * @format: formatting string to check for %
 * Return: returns a malloc array of pointers that will
 * eventually point to the different formats
 */

char *split_format(char *format)
{
	int i, f_count;
	char *array;

	f_count = 0;
	for(i = 0; format[i] != '\0'; ++i)
	{
		if (format[i] == '%' && format[i + 1] != '%')
		{
			f_count++;
		}
	}
	array = malloc(sizeof(char *) * f_count);
	return (array);
}
