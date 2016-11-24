# _printf 
<br />
This is a printf function with the functionalities of printing characters (c), strings (s), % (%), octals(o), hexidecimals (x and X). We also a custom formatter binary (b).
<br />
print3.c
<br />
This is our file that contains our printf function. Also included is an error function that can return an error when called upon.
<br />
Formatter files<br />
<br />
We created a file for each formatter. In each file, it should contain a make_formatter function that creates a string to fill in the buffer. Also included in each formatter file is a conversion check to see if we need to account for precision, width, or flag. If necessary, we also included a helper function to convert a number to a string. 
<br />
  Foramtter files:<br />
    binary.c <br />
    chars.c <br />
    decimal.c <br />
    hex.c <br />
    heX.c <br />
    octal.c <br />
    strings.c <br />
    unsigned.c <br />
 <br /> 
Helper files
<br />
We created helper files to put universal helper functions such at idigit, no_conversion, reverse_array. These functions are used multiple times throughout the files.
<br />
  Helper files:<br />
    unihelper.c<br />
      is_digit<br />
      no_conversion<br />
      strlen<br />
      isdflag<br />
    unihelper2.c<br />
      give_precision.c<br />
      give_width.c<br />
      get_result.c<br />
<br />
Example:
<br />
int main(void)<br />
{<br />
  _printf("This is a char: [%c]\n", 'c')<br />
  _printf("This is a %s\n", "string.");<br />
  _printf("Unsigned octal:[%o]\n", ui);<br />
  _printf("Unsigned hexadecimal:[%x, %X]\n", ui, ui);<br />
  _printf("Unsigned:[%u]\n", ui);<br />
  _printf("Binary is [%b]\n", 98);<br />
  return (0)<br />
}<br />

This is a char: [c]<br />
This is a string.<br />
Unsigned octal:[20000001777]<br />
Unsigned hexadecimal:[800003ff, 800003FF]<br />
Unsigned:[2147484671]<br />
Binary is [1100010]<br />
