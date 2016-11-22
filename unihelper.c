/*this file contains basic helpers needed everywhere*/




/**
 * _isdigit - checks if char is a digit
 * @c: a char
 * Return: 1 if it is, 0 otherwise
 */
int _isdigit(char c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

/**
 * _strncpy - copy at mots n char from src to the beginning of dest
 * @dest: destination string
 * @src: string to copy
 * @n: number of chars to copy
 *
 * Return: pointer to dest
 */
char *_strncpy(char *dest, char *src, int n)
{
	int i;

	i = 0;

	while (i < n && *(src + i) != '\0')
	{
		*(dest + i) = *(src + i);
		i++;
	}
	while (i < n) /*happens only if I am pasting a src shorter than n string*/
		*(dest + i++) = '\0';

	return (dest);
}
