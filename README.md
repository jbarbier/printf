# _printf 

This is a printf function with the functionalities of printing characters (c), strings (s), % (%), octals(o), hexidecimals (x and X). We also a custom formatter binary (b).

print3.c

This is our file that contains our printf function. Also included is an error function that can return an error when called upon.

Formatter files

We created a file for each formatter. In each file, it should contain a make_formatter function that creates a string to fill in the buffer. Also included in each formatter file is a conversion check to see if we need to account for precision, width, or flag. If necessary, we also included a helper function to convert a number to a string. 

  Foramtter files:
    binary.c
    chars.c
    decimal.c
    hex.c
    heX.c
    octal.c
    strings.c
    unsigned.c
  
Helper files

We created helper files to put universal helper functions such at idigit, no_conversion, reverse_array. These functions are used multiple times throughout the files.

  Helper files:
    unihelper.c
      is_digit
      no_conversion
      strlen
      isdflag
    unihelper2.c
      give_precision.c
      give_width.c
      get_result.c

Example:

int main(void)
{
  _printf("This is a char: [%c]\n", 'c')
  _printf("This is a %s\n", "string.");
  _printf("Unsigned octal:[%o]\n", ui);
  _printf("Unsigned hexadecimal:[%x, %X]\n", ui, ui);
  _printf("Unsigned:[%u]\n", ui);
  _printf("Binary is [%b]\n", 98);
  return (0)
}

This is a char: [c]
This is a string.
Unsigned octal:[20000001777]
Unsigned hexadecimal:[800003ff, 800003FF]
Unsigned:[2147484671]
Binary is [1100010]
