/*functions handling format parsing*/

#include <stdlib.h>
#include "holberton.h"
#include <stdio.h>
#include <unistd.h>

char *grab_format(const char *format)
{
	int j;
	char *conv;

	j = 0;
	while (no_conversion(format[j]) && format[j])
		++j;
	if (no_conversion(format[j]))
	{
		write(1, "invalid\n", 8);
		exit(98);
	}
	conv = malloc((j + 2) * sizeof(char));
//	printf("GRAB DEBUG see format %s\n", format);
	conv = _strncpy(conv, format, j + 1);
	conv[j + 1] = '\0';
//	printf("GRAB DEBUG see conv %s\n", conv);
	return (conv);
}


/**
 * fill_format - fills in the format_array with all conversion formatters
 * including their flags
 * @format: formatting string containing possible formatters
 * @format_array: array to put the formatting strings in
 * Return: format_array
 */

void fill_format(const char *format)
{
	int i, l_conv, flag;
	char *conv;

	flag = 0;
	for (i = 0; format[i] != '\0'; ++i)
	{
		if (format[i] == '%')
		{
			flag = 1;
			if (format[i + 1] == '%')
			{
				flag = 0;
				i += 1;
			}
		}
		if (flag == 1)
		{
			flag = 0;
//			printf("FILL - format %s\n", format + i);
			conv = grab_format(format + i);
			l_conv = _strlen(conv);
			get_validity_func(conv[l_conv - 1])(conv);
			free(conv);
			i += l_conv - 1;

		}
	}
}
