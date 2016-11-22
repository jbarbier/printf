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
	int i, b_i, l_conv, flag;
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
	_flush(buffer);
	va_start(alist, format);
	flag = 0;
	b_i = 0;
	/** Loops through format and fills buffer*/
	for (i = 0; format[i] != '\0';)
	{
//		printf("entering for loop %s\n", format + i);
		if (format[i] != '%')
		{
//			printf("regular char\n");
			fill_buffer(buffer, format + i, b_i, 1);
			i += 1;
			b_i += 1;
		}
		/** % exists */
		if (format[i] == '%')
		{
			flag = 1;
//			printf("INITIALIZED %% see buffer %s flag %i\n", buffer, flag);
			if (format[i + 1] == '%')
			{
				flag = (flag == 0) ? 1 : 0;
				fill_buffer(buffer, format, b_i, 1);
				i += 2;
				b_i += 1;
//				printf("ADDING %% see buffer %s flag %i\n", buffer, flag);
			}
		}
		if (flag == 1)
		{
			flag = 0;
			conv = grab_format(format + i);
			printf("DEB: conv %s\n", conv);
			l_conv = _strlen(conv);
			format_str = get_mstring_func(conv[l_conv - 1])(conv, alist);
			free(conv);
//			printf("DEB: formatted %s\n", format_str);
			fill_buffer(buffer, format_str, b_i,_strlen(format_str));
			//printf("DEB: buffer %s\n", buffer);
			b_i = b_i + _strlen(format_str);
			//printf("DEB: length of buffer = %d\n", b_i);
			free(format_str);
			i += l_conv;

		}
	}
		//printf("DEBUG print for loop i is %d and format is %s\n", i, format + i);
		print_buffer(buffer, b_i);
		free(buffer);
		return (b_i);
}
