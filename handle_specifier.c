#include "main.h"
#include <stdarg.h>

/**
 * handle_specifier - handles format specifiers and calls appropriate printer
 * @spec: the conversion specifier
 * @args: va_list containing the arguments
 * @buffer: output buffer
 * @index: current index in the buffer
 *
 * Return: number of characters printed
 */
int handle_specifier(char spec, va_list args, char *buffer, int *index)
{
int count = 0;
flags_t flags = {0, 0, 0}; /* default no flags */

/* Check for flags before actual specifier */
while (spec == '+' || spec == ' ' || spec == '#')
{
if (spec == '+')
flags.plus = 1;
else if (spec == ' ')
flags.space = 1;
else if (spec == '#')
flags.hash = 1;

/* Advance to next character for actual specifier */
spec = va_arg(args, int);
}

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
count += print_int(va_arg(args, int), flags, buffer, index);
break;

case 'o':
count += print_unsigned(va_arg(args, unsigned int), 8, 0, flags, buffer, index);
break;

case 'x':
count += print_unsigned(va_arg(args, unsigned int), 16, 0, flags, buffer, index);
break;

case 'X':
count += print_unsigned(va_arg(args, unsigned int), 16, 1, flags, buffer, index);
break;

case 'p':
count += print_p(va_arg(args, void *), buffer, index);
break;

case 'S':
count += print_S(va_arg(args, char *), buffer, index);
break;

case 'b':
count += print_binary(va_arg(args, unsigned int), buffer, index);
break;

default:
buffer_char(buffer, '%', index, &count);
buffer_char(buffer, spec, index, &count);
break;
}

return (count);
}
