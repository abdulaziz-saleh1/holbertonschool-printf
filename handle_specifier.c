#include "main.h"
#include <stdarg.h>

/**
 * handle_specifier - Selects the correct function to handle format specifier
 * @spec: format specifier character
 * @args: argument list
 * @buffer: output buffer
 * @index: buffer index
 *
 * Return: number of characters printed
 */
int handle_specifier(char spec, va_list args, char *buffer, int *index)
{
int count = 0;

switch (spec)
{
case 'c':
count += print_char(va_arg(args, int), buffer, index);
break;
case 's':
count += print_string(va_arg(args, char *), buffer, index);
break;
case '%':
count += print_percent(buffer, index);
break;
case 'd':
case 'i':
count += print_int(va_arg(args, int), buffer, index);
break;
case 'b':
count += print_binary(va_arg(args, unsigned int), buffer, index);
break;
case 'u':
count += print_unsigned(va_arg(args, unsigned int), 10, 0, buffer, index);
break;
case 'o':
count += print_unsigned(va_arg(args, unsigned int), 8, 0, buffer, index);
break;
case 'x':
count += print_unsigned(va_arg(args, unsigned int), 16, 0, buffer, index);
break;
case 'X':
count += print_unsigned(va_arg(args, unsigned int), 16, 1, buffer, index);
break;
case 'S':
count += print_S(va_arg(args, char *), buffer, index);
break;
case 'p':
count += print_p(va_arg(args, void *), buffer, index);
break;
default:
count += buffer_char(buffer, '%', index, &count);
count += buffer_char(buffer, spec, index, &count);
break;
}

return (count);
}
