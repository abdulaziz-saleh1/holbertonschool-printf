#include "main.h"

/**
* flush_buffer - Writes the buffer content to stdout
* @buffer: The character buffer
* @len: The number of characters in the buffer
*
* Return: Number of characters written
*/
int flush_buffer(char *buffer, int len)
{
return (write(1, buffer, len));
}

/**
* buffer_char - Adds a character to the buffer, and flushes if full
* @buffer: The character buffer
* @c: The character to add
* @index: Pointer to the current index in buffer
* @count: Pointer to total character count
*/
void buffer_char(char *buffer, char c, int *index, int *count)
{
buffer[*index] = c;
(*index)++;
(*count)++;

if (*index == 1024)
{
flush_buffer(buffer, *index);
*index = 0;
}
}

/**
* handle_specifier - Handles format specifiers for _printf
* @spec: Format specifier
* @args: Arguments list
* @buffer: Output buffer
* @index: Current buffer index
*
* Return: Number of characters printed
*/
int handle_specifier(char spec, va_list args, char *buffer, int *index)
{
int count = 0;
char *str;
int i;

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
default:
buffer_char(buffer, '%', index, &count);
buffer_char(buffer, spec, index, &count);
break;
}
return (count);
}

/**
* _printf - Custom printf function using 1024 char buffer
* @format: Format string
*
* Return: Number of characters printed
*/
int _printf(const char *format, ...)
{
char buffer[1024];
int i = 0, index = 0, count = 0;
va_list args;

if (!format)
return (-1);

va_start(args, format);

while (format[i])
{
if (format[i] == '%')
{
i++;
if (!format[i])
{
va_end(args);
return (-1);
}
count += handle_specifier(format[i], args, buffer, &index);
}
else
{
buffer_char(buffer, format[i], &index, &count);
}
i++;
}

va_end(args);

if (index > 0)
flush_buffer(buffer, index);

return (count);
}
