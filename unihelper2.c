#include <stdio.h>
#include "holberton.h"
#include <stdlib.h>

/**
 * give_precision - returns the appropriate precision
 * @s: format string;
 * @formatter: formatter
 * Return: precision number of -1 if it doesnt exist
 */

int give_precision(char *s, char formatter)
{
	int p, i;

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
 * get_result- gives a pointer back to results
 * @r: array
 * @s: string
 * @p: precision
 * @w: width
 * @slen: str len
 * @flen: format len
 * @mlen: malloc len
 * Return: result pointer
 */

char *get_result(char *r, char *s, int p, int w, int slen, int flen, int mlen)
{
	int j, k, i;

	j = k = i = 0;
	/* handles those with both precision and width*/
	if (p > 0 && w > 0)
	{
		for (j = 0; j < (slen - p); j++)
			r[j] = ' ';
		for (k = 0; k < p; k++, j++)
			r[j] = s[k];
		r[j] = '\0';
	}
	/* Regular simple string case %s*/
	else if (p == 0 && w == 0 && flen == 2)
	{
		for (j = 0; s[j] != '\0'; j++)
			r[j] = s[j];
		r[j] = '\0';
	}
	/* case for when there is . or .0 */
	else if (p == -1)
	{
		r[j] = '\0';
	}
	else
	{
		for (j = 0; j < (w - slen); j++)
			r[j] = ' ';
		for (k = k + j, i = 0; k < mlen && s[i] != '\0'; k++, i++)
			r[k] = s[i];
		r[k] = '\0';
	}
	return (r);

}
