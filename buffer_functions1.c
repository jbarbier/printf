/*this file contains functions related to the use of the buffer
 * the buffer length is BUF_LENGTH, defined elswhere now
 * maybe move it to header file
 * The buffer is created, malloc'ed elsewhere
 */


/**
 * flush - fill the buffer with \0
 * The length of the buffer is defned in a macro
 * Return: pointer to buffer
 */
char *flush(char *buffer)
{
	int i;

	for (i = 0; i < BUF_LENGTH; ++i)
		buffer[i] = '\0';
return (buffer);
}




/**
 * fill_buffer - fills the buffer with string s
 * @s: a string to fill buffer with
 * @count_c: number of chars needed to be printed until s
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
	buffer_index = count_c;
	while (i < s_length)
	{
		if (buffer_index == (BUF_LENGTH - 2))
		{
			buffer[BUF_LENGTH - 1] = '\0';
			print_buffer(buffer, BUF_LENGTH);
			buffer = flush(buffer);
			buffer_index = 0;
		}

		buffer[buffer_index] = s[i];
		++i;
		++buffer_index;
	}

	if (i == s_length)
	{
		if (buffer_index < BUF_LENGTH - 2)
			return (buffer);
/*in this case I have added all my string and reached BUF_LENGTH - 1*/
		buffer[BUF_LENGTH - 1] = '\0';
		print_buffer(buffer, BUF_LENGTH);
		buffer = flush(buffer);
		return (buffer);
	}

/**
 * print_buffer - prints the buffer
