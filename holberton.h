#ifndef HEADER
#define HEADER
int no_conversion(char);
char **split_format(char *format);

/*in buffer_functions1.c*/
char *_flush(char *buffer);
char *fill_buffer(char *buffer, char *s, int count_c, int s_length);
void print_buffer(char *buffer, int length);

/*in conversion_checks1.c*/
int conversion_char(char *s);
int conversion_string(char *s);

/* get_validity_func.c */
int (*get_validity_func(char c))(char *s);

/*in conversion_checks2.c*/
int conversion_di(char *s);

/*in unihelper.c*/
int _isdigit(char c);
char *_strncpy(char *dest, char *src, int n);


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








#endif
