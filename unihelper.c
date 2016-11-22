/*this file contains basic helpers needed everywhere*/
#include <stdio.h>

/**
 * no_conversion - checks if there is a conversion formatter
 * @char: character to check
 * Return: 1 if not conversion formmater, 0 if it is
 */

int no_conversion(char c)
{
	char array[9] = "csdiuoxXp";
	int i;

	for (i = 0; i < 9; i++)
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
//	printf("Inside copy, i = %i, src = %s\n", n, src);
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
//	printf("STRLEN here");
	for (i = 0; *(s + i); ++i)
//		printf("STRLEN %i\n", i);
		;
	return (i);
}

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
