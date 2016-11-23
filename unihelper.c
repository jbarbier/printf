/*this file contains basic helpers needed everywhere*/
#include <stdio.h>

/**
 * no_conversion - checks if there is a conversion formatter
 * @c: character to check
 * Return: 1 if not conversion formmater, 0 if it is
 */

int no_conversion(char c)
{
	char array[] = "csdiuoxXpb";
	int i;

	for (i = 0; i < 10; i++)
	{
		if (c == array[i])
			return (0);
	}
	return (1);
}


/**
 * _is_digit - checks if char is a digit
 * @c: a char
 * Return: 1 if it is, 0 otherwise
 */
int _is_digit(char c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

/**
 * _strncpy - copy at most n char from src to the beginning of dest
 * @dest: destination string
 * @src: string to copy
 * @n: number of chars to copy
 *
 * Return: pointer to dest
 */
char *_strncpy(char *dest, const char *src, int n)
{
	int i;

	i = 0;
	while (i < n && *(src + i) != '\0')
	{
		*(dest + i) = *(src + i);
		i++;
	}
	while (i < n) /*happens only if I am pasting a src shorter than n string*/
	{
		printf("UNI here ?, i = %i\n", i);
		*(dest + i++) = '\0';
	}
	return (dest);
}

/**
 * _strlen - length of string
 * @s: a string
 *
 * Return: length of string excluding \0
 */
int _strlen(const char *s)
{
	int i;

	for (i = 0; *(s + i); ++i)
		;
	return (i);
}

/**
 * _isdflag - checks if the format starts with a flag
 * @c: a string, maybe a flag in first place
 * Checks if we have a valid d flag, ie 2 flags can be combined
 * Return: 1 if it is, 0 otherwise
 */
int _isdflag(char *c)
{
	char *flags = "-+ 0";

	while (*flags)
	{
		if (*flags == *c)
			return (1);
		++flags;
	}
	return (0);
}
