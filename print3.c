#include "holberton.h"
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdarg.h>
#include <string.h>

/**
 * error_format - returns error
 * @format: format
 * none
 */

void error_format(const char *format)
{
	if (!format || !*format)
	{
		write(1, "error", 6);
		exit(98);
	}
}

/**
 * _printf - trying to make printf2
 * @format: format of string
 * Return: number of chars printed
 */

int _printf(const char *format, ...)
{
	int i, b_i, l_conv, flag;
	char *buffer, *conv, *format_str;
	va_list alist;

	error_format(format);
	buffer = malloc(BUF_LENGTH * sizeof(char));
	_flush(buffer);
	va_start(alist, format), flag = b_i = 0;
	for (i = 0; format[i] != '\0';)
	{
		if (format[i] != '%')
		{
			fill_buffer(buffer, format + i, b_i, 1);
			i += 1, b_i += 1;
		}
		if (format[i] == '%')
		{
			flag = 1, conv = grab_format(format + i);
			if (format[i + 1] == '%' || conv == NULL)
			{
				flag = (flag == 0) ? 1 : 0;
				fill_buffer(buffer, format + i, b_i, 1);
				i += 2, b_i += 1;
			}
		}
		if (flag == 1)
		{
			flag = 0;
			conv = grab_format(format + i);
			l_conv = _strlen(conv);
			format_str = get_mstring_func(conv[l_conv - 1])(conv, alist);
			free(conv);
			fill_buffer(buffer, format_str, b_i, _strlen(format_str));
			b_i = b_i + _strlen(format_str);
			free(format_str), i += l_conv;
		}
	}
		print_buffer(buffer, b_i);
		free(buffer);
		return (b_i);
}
