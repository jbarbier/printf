#include "holberton.h"
#include <stdlib.h>
#include <stdio.h>

/**
 * conversion_o - checks validity of octals
 * @s: format string ot check
 * Return: 1 if checks and 0 and exits otherwise
 */
int conversion_o(char *s)
{
	(void) s;
	return (1);
}



/**
 * octorbi - convert a number to an octal
 * @n: a number
 * @b: the base, 8 or 2
 * Return: a number in octal or binary in 2 pieces
 */
char *octorbi(unsigned int n, int b)
{

	int i;
	char *s;

	i = 0; /** index for octal string*/
	s = malloc(sizeof(int) * 200);
	do {
		s[i++] = (n % b) + '0';
		n = n / b;
	} while (n > 0);
	reverse_array(s, i);
	s[i] = '\0';

	return (s);
}




/**
 * make_octal - make an octal string
 * @s: a format string
 * @l: a va_list
 * Return: a pointer to the result
 */
char *make_octal(char *s, va_list l)
{
	unsigned int n;
	char *result;
	(void) s;

	n = va_arg(l, unsigned int);
	result = octorbi(n, 8);
	return (result);
}
