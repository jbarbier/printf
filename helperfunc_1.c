#include "holberton.h"

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
