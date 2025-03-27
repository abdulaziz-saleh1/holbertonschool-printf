#include "main.h"

int handle_specifier(char spec, va_list args, char *buffer, int *index)
{
int count = 0, i;
char *str;

switch (spec)
{
case 'c':
buffer_char(buffer, va_arg(args, int), index, &count);
break;

case 's':
str = va_arg(args, char *);
if (!str)
str = "(null)";
for (i = 0; str[i]; i++)
buffer_char(buffer, str[i], index, &count);
break;

case 'S':
count += print_S(va_arg(args, char *), buffer, index);
break;

case '%':
buffer_char(buffer, '%', index, &count);
break;

case 'd':
case 'i':
count += print_int_buffer(va_arg(args, int), buffer, index);
break;

case 'b':
count += print_binary_buffer(va_arg(args, unsigned int), buffer, index);
break;

case 'u':
count += print_unsigned_buffer(va_arg(args, unsigned int), 10, 0, buffer, index);
break;

case 'o':
count += print_unsigned_buffer(va_arg(args, unsigned int), 8, 0, buffer, index);
break;

case 'x':
count += print_unsigned_buffer(va_arg(args, unsigned int), 16, 0, buffer, index);
break;

case 'X':
count += print_unsigned_buffer(va_arg(args, unsigned int), 16, 1, buffer, index);
break;

case 'p':
count += print_p(va_arg(args, void *), buffer, index);
break;

default:
buffer_char(buffer, '%', index, &count);
buffer_char(buffer, spec, index, &count);
break;
}
return (count);
}
