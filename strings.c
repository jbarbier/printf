/*string formatters*/
#include <stdarg.h>
#include "holberton.h"
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

/**
 * make_string - creates formatted string
 * @s: format
 * @vl: argument
 * Return: formatted string
 */

char *make_string(char *s, va_list vl)
{
	int p, w, slen, mlen, flen, i, j, k;
	char *result, *string;

	slen = mlen = j = k = 0;
	string = va_arg(vl, char *);
	if (string == NULL)
		exit(98);
	p = give_precision(s, 's');
	w = give_width(s, 's');
	slen = _strlen(string);
	flen = _strlen(s);
	/* determine malloc len */
	if (w > p && w != 0 && p != -1)
		mlen = w;
	else if (p > w && p != 0)
		mlen = p;
	else if (p == 0)
		mlen = p;
	else
		mlen = slen;
	result = malloc(sizeof(char) * (mlen + 1));
	printf("mlen is %d\n", mlen);
	printf("w is %d and p is %d\n", w, p);
	result = get_result(result, string, p, w, slen, flen, mlen);
/**	if (p > 0 && w > 0)
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
		}*/
	return (result);
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
		if ((_is_digit(*(s + i)) == 0 && *(s + i) != '.') ||
		    (*(s + i) == '.' && dot_flag))
		{
			write(1, "no string\n", 10);
			exit(98);
			return (0);
		}
		if (_is_digit(*(s + i)) == 0 && *(s + i) == '.')
			dot_flag = 1;
		++i;
	}
	return (1);
}
