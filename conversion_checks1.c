/*file containing all the conversion_check functions
 *it is assumed all functions are called with a valid char * */
#include <unistd.h>
#include <stdlib.h>
#include "holberton.h"

/*for chars*/
/**
 * conversion_char - check if format is right
 * @s: formatting string for chars
 * Return: 1 if it is 0 otherwise, actually exit process
 */
int conversion_char(char *s)
{
	int i;

	i = (*s == '%') ? 1 : 0;
	while (*(s + i) != 'c')
	{
		if (_isdigit(*(s + i)) == 0)
		{
			write(1, "no char\n", 8);
			exit(98);
			return (0);
		}
		++i;
	}
	return (1);
}

/*for strings*/
/**
 * conversion_string - check if format is right
 * @s: formatting string for chars
 * Return: 1 if it is 0 otherwise, actually exit process
 */
int conversion_string(char *s)
{
	int i, dot_flag;

	i = (*s == '%') ? 1 : 0;
	dot_flag = 0;

	while (*(s + i) != 's')
	{
		if ((_isdigit(*(s + i)) == 0 && *(s + i) != '.') ||
		    (*(s + i) == '.' && dot_flag))
		{
			write(1, "no string\n", 10);
			exit(98);
			return (0);
		}
		if (_isdigit(*(s + i)) == 0 && *(s + i) == '.')
			dot_flag = 1;
		++i;
	}
	return (1);
}
