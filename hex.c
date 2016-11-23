#include "holberton.h"
#include <stdlib.h>
#include <stdio.h>

/**
 * conversion_h - checks validity of hex
 * @s: format string ot check
 * Return: 1 if checks and 0 and exits otherwise
 */
int conversion_h(char *s)
{
	(void) s;
	return (1);
}



/**
 * hex - convert a number to an octal
 * @n: a number
 * Return: a number in octal
 */
char *hex(unsigned int n)
{
	int i;
	char s[16] = "0123456789abcdef";
	char *ns;

	i = 0;
	ns = malloc(sizeof(char) * 100);
	do {
		ns[i++] = (s[n % 16]);
		n = n / 16;
	} while (n > 0);
	reverse_array(ns, i);
	ns[i] = '\0';
	return (ns);
}

/**
 * make_hex - make an octal string
 * @s: a format string
 * @l: a va_list
 * Return: a pointer to the result
 */
char *make_hex(char *s, va_list l)
{
	unsigned int n;
	char *result;
	(void) s;
	n = va_arg(l, unsigned int);
	result = hex(n);
	return (result);
}


/**
 * reverse_array - reverss an array of integers
 * @a: array;
 * @n: number of elements in array
 */

void reverse_array(char *a, int n)
{
	int i;
	int temp;

	i = 0;
	n = n - 1;
	while (i <= n)
	{
		temp = a[i];
		a[i] = a[n];
		a[n] = temp;
		i++;
		n--;
	}
}
