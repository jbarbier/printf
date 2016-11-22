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
	int i, j, b_i, num_p, k, l_conv;
	char *buffer, *conv, *format_str, *percent;
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
	for (i = 0; format[i] != '\0';)
	{
		printf("entering for loop %s\n", format + i);
		j = 0;
		while (format[i + j] != '%' && format[i + j])
			++j;
		if (j > 0)
		{
			fill_buffer(buffer, format + i, b_i, j);
			i += j;
			b_i += j;
		}
		/** % exists */
		if (!format[i])
			break;
		num_p = k = 0;
		while (format[i + k] == '%')
		{
			num_p++;
			k++;
		}
		i = i + k;
		if (num_p >= 2)
		{
			percent = malloc((num_p / 2) * sizeof(char));
			for (j = 0; j < num_p / 2; ++j)
				percent[j] = '%';
			fill_buffer(buffer, percent, b_i, num_p / 2);
			b_i += num_p / 2;
		}
		if ((num_p % 2) != 0 || num_p == 1)
		{
			conv = grab_format(format + i);
			l_conv = strlen(conv);
			format_str = get_mstring_func(conv[l_conv - 1])(conv, alist);
			free(conv);
			printf("DEB: formatted %s\n", format_str);
			fill_buffer(buffer, format_str, b_i, strlen(format_str));
			printf("DEB: buffer %s\n", buffer);
			b_i = b_i + strlen(format_str);
			printf("DEB: length of buffer = %d\n", b_i);
			free(format_str);
			i += l_conv;

		}
		printf("DEBUG print for loop i is %d and format is %s\n", i, format + i);
	}
	print_buffer(buffer, b_i);
	free(buffer);
	write(1, "\n", 1);
	return (b_i);
}
