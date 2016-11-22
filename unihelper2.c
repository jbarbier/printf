#include <stdio.h>
#include "holberton.h"
#include <stdlib.h>

/**
 * give_precision - returns the appropriate precision
 * @s: format string;
 * Return: precision number of -1 if it doesnt exist
 */

int give_precision(char *s, char formatter)
{
	int p, i, l;

	p = 0;
	for (i = 0; s[i] != formatter; i++)
	{
		if (s[i] == '.')
		{
			i++;
			while (s[i] != formatter)
			{
				p = 10 * p + s[i] - '0';
				i++;
			}
			if (p == 0)
				return (-1);
			break;
		}
	}
	return (p);
}

/**
 * give_width - returns the appropriate width
 * @s: format string;
 * @formatter: formatter to check
 * Return: width or -1 if width doesnt exist
 */

int give_width(char *s, char formatter)
{
	int w, i;

	i = 1;
	w = 0;
	while ((s[i] != '.' || s[i] != formatter) && _is_digit(s[i]))
	{
		w = 10 * w + s[i] - '0';
		i++;
	}
	return (w);
}

/**
 * get_result: gives a pointer back to results
 * @result: array
 * @p: precision
 * @w: width
 * @slen: str len
 * @flen: format len
 * @mlen: malloc len
 * Return: result pointer
 */

char *get_result(char * result, char *string, int p,
		 int w, int slen, int flen, int mlen)
{
	int j, k, i;

	j = k = i = 0;
	if (p > 0 && w > 0)
	{
		for (j = 0; j < (slen - p); j++)
			result[j] = '.';
		for (k = 0; k < p; k++, j++)
			result[j] = string[k];
		result[j] = '\0';
	}
	else if (p == 0 && w == 0 && flen == 2)
	{
		for (j = 0; string[j] != '\0'; j++)
			result[j] = string[j];
		printf("HELLO\n");
		result[j] = '\0';
	}
	else if (p == -1)
	{
		result[j] = '\0';
	}
	else
	{
		for (j = 0; j < (w - slen); j++)
			result[j] = '.';
		for (k = k + j, i = 0; k < mlen && string[i] != '\0'; k++, i++)
			result[k] = string[i];
		result[k] = '\0';
        }
	return (result);

}
