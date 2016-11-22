#include "holberton.h"
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdarg.h>
#include <string.h>
/**
 * _printf - trying to make printf2
 * @format: format of string
 * Return: number of chars printed
 */

int _printf(const char *format, ...)
{
	int count_c, i, b_i, j, num_p, k;
	char *buffer, *conv, *format_str;
	va_list alist;

	if (!format || !*format)
	{
		write(1, "error", 6);
		exit(98);
	}
	/** Goes through format and checks validity of formatters*/
	fill_format(format);
	/** */
	buffer = malloc(BUF_LENGTH * sizeof(char));
	va_start(alist, format);
	b_i = 0;
	/** Loops through format and fills buffer*/
	for (i = 0; format[i] != '\0'; i++)
	{
		while (format[i] != '%')
		{
			buffer[b_i] = format[i];
			b_i++;
			i++;
		}
		/** % exists */
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
			while (no_conversion(format[i + j]) && format[i + j])
				++j;
			conv = malloc((j + 1) * sizeof(char));
			conv = _strncpy(conv, format + i, j + 1);
			conv[j + 1] = '\0';
			format_str = get_mstring_func(conv[j])(conv, alist);
			printf("%s\n", format_str);
			fill_buffer(buffer, format_str, b_i, strlen(format_str));
			printf("%s\n", buffer);
			b_i = b_i + strlen(format_str);
			printf("length = %d\n", b_i);
			free(format_str);
			free(conv);

		}
		printf("i is %d and c is %c", i, format[i]);
	}
	print_buffer(buffer, b_i);
	free(buffer);
	write(1, "\n", 1);
	return (b_i);
}
