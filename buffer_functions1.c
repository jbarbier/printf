/*this file contains functions related to the use of the buffer
 * the buffer length is BUF_LENGTH, defined elswhere now
 * maybe move it to header file
 * The buffer is created, malloc'ed elsewhere
 */
#include <unistd.h>
#include "holberton.h"
#include <stdio.h>
/**
 * _flush - fill the buffer with \0
 * The length of the buffer is defned in a macro
 * Return: pointer to buffer
 */
char *_flush(char *buffer)
{
	int i;

	for (i = 0; i < BUF_LENGTH; ++i)
		buffer[i] = '\0';
return (buffer);
}




/**
 * _fill_buffer - fills the buffer with string s
 * @s: a string to fill buffer with
 * @count_c: number of chars put in buffer before s
 * IMPORTANT: update count_c in printf only after filling the buffer, I need to
 * know here at which index I can start to append to the buffer
 * @s_length: length of string, not required, but if I have it rigth away
 * in printf I might just pass it instead of calling strlen here
 * Fills the buffer starting at index count_c with string s of length s_length
 * Return: pointer to buffer
 */
char *fill_buffer(char *buffer, char *s, int count_c, int s_length)
{
	int i, buffer_index;

	i = 0;
	buffer_index = (count_c > BUF_LENGTH) ? count_c % BUF_LENGTH : count_c;
	printf("BUFFER index at entry %d s_length is %d\n", buffer_index, s_length);
	while (i < s_length)
	{
		if (buffer_index == BUF_LENGTH)
		{
			//printf("FLUSH FILLED BUFFER\n");
			print_buffer(buffer, BUF_LENGTH);
			buffer = _flush(buffer);
			buffer_index = 0;
		}
		buffer[buffer_index] = s[i];
		printf("COPY WORKS: [index: %i]%c %c\n", buffer_index, buffer[buffer_index], s[i]);
		++i;
		++buffer_index;
	}
/*all my string is in the buffer*/
	printf("DONE WITH STRING\n");
	if (buffer_index == BUF_LENGTH)
	{
		//printf("FLUSH AGAIN\n");
		print_buffer(buffer, BUF_LENGTH);
		buffer = _flush(buffer);
	}
	return (buffer);
}

/**
 * print_buffer - prints the buffer
 * @buffer: a buffer, char array
 * @length: number of characters I need to print
 *
 * Return: void
 */
void print_buffer(char *buffer, int length)
{
	printf("PRINT Length entry: %d\n", length);
/*if I call the function with count_c,
 *the number of characters already bufferized*/
	if (length > BUF_LENGTH)
		length = length % BUF_LENGTH;
	printf("PRINT Length after if: %d\n", length);
	write(1, buffer, length);
}

/*do not forget to add a new line in printf*/
