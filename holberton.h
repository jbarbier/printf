#ifndef HEADER
#define HEADER
int no_conversion(char);
<<<<<<< HEAD
=======
char *split_format(char *format);

/*in buffer_functions1.c*/
char *flush(char *buffer);
char *fill_buffer(char *buffer, char *s, int count_c, int s_length);
void print_buffer(char *buffer, int length);

/*in conversion_checks1.c*/
int conversion_char(char *s);
int conversion_string(char *s);


/*structs*/
/**
 * struct valid - check if formatting is valid
 * @type
 * @conversion_check - function to check if a conversion string is valid
 */
typedef struct valid
{
	char type;
	int (*conversion_check)(char *);
} valid;

/**
 *struct m_string - make strinf from valid format
 * @type: type of format
 * @m_string - make the string
 */
typedef struct m_string
{
	char type;
	char *(*make_s)(char *);
} m_string;







>>>>>>> 8b9dfdb4140eb01630a74264b1538d00fc33b317
#endif
