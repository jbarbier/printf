#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define BUF_LENGTH 1024

/**
 * _printf - trying to
 * @format: formatting string
 *
 * Return: nb of chars printed
 */
int _printf(const char *format, ...)
{
	int i, j, count_c;
	char *conversion, *buffer;

	if(!format || !*format)
	{
		write(1, "error\n", 6);
		exit(98);
	}

	buffer = malloc(BUF_LENGTH * sizeof(char));
	count_c = 0;
	for(i = 0; *(format + i); ++i)
	{
		for (;*(format + i) != '%' && *(format + i); ++i, ++count_c)
			fill_buffer(buffer, *(format + i));
//check end of string
		if (*(format + i) && *(format + i + 1) == '%')
		{
			++count_c;
			++i;
			fill_buffer(buffer, *(format + i));
		}
		else if (*(format + i))
		{
			j = 0;
			while (no_conversion(*(format + j + i)) && *(format + i + j))
			{
				++j;
			}
			if (no_conversion(*(format + i + j)))
			{
				write(1, "error\n", 6);
				exit(98);
			}
			conversion = malloc(j * sizeof(char));
			if (!check_conversion[] //struct here)
				{
					write(1, "error\n", 6);
					exit(98);
				}
			conversion = strncpy(conversion, (format + i), j);

//call va_arg corresponding to conversion[j - 1]
//formatted = struct[conversion[j - 1]].func(conversion, va... Need a loop through array of structs ?
			formatted = make_string(conversion, va_arg(alist, TYPE));

			l = strlen(formatted);
			count_c += l;
			fill_buffer(buffer, formatted);
			i += j;
		}
	}

	print_buffer(buffer);
	free(buffer);
	return (count_c);
}
