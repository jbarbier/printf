/*this file contains the function to test if a format is valid for a number*/
/*it assumes that the function will be passed a real char * */

#include <unistd.h>
#include <stdlib.h>
#include "holberton.h"
/*I am including here helper functions that should be moved elsewhere*/
/**
 * _isflag - checks if the format starts with a flag
 * @c: a char
 * Return: 1 if it is, 0 otherwise
 */
int _isdflag(char c)
{
	char *flags = "-+ 0";

	while (*flags)
	{
		if (*flags == c)
			return (1);
		++flags;
	}
	return (0);
}


/**
 * conversion_di - checks conversion format for integer
 * @cs: a string
 * Return: 1 if it is, 0 otherwise, actually exit process
 */
int conversion_di(char *s)
{
	int i, dot_flag;

	i = (*s == '%') ? 1 : 0;
	dot_flag = 0;
	while (*(s + i) != 'd' || *(s + i) != 'c')
	{
		if _isdflag(*(s + i))
				   ++i;

		if ((_isdigit(*(s + i)) == 0 && *(s + i) != '.') ||
		    (*(s + i) == '.' && dot_flag))
		{
			write(1, "no digit\n", 9);
			exit(98);
			return (0);
		}
		if (_isdigit(*(s + i)) == 0 && *(s + i) == '.')
			dot_flag = 1;
		++i;
	}
	return (1);
}
