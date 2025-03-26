#include "main.h"

/**
* handle_specifier - Handles format specifiers for _printf
* @spec: The format specifier
* @args: List of arguments
*
* Return: Number of characters printed
*/
int handle_specifier(char spec, va_list args)
{
int count = 0;

switch (spec)
{
case 'c':
count += print_char(va_arg(args, int));
break;
case 's':
count += print_string(va_arg(args, char *));
break;
case '%':
count += print_percent();
break;
case 'd':
case 'i':
count += print_int(va_arg(args, int));
break;
case 'b':
count += print_binary(va_arg(args, unsigned int));
break;
case 'u':
count += print_unsigned_base(va_arg(args, unsigned int), 10, 0);
break;
case 'o':
count += print_unsigned_base(va_arg(args, unsigned int), 8, 0);
break;
case 'x':
count += print_unsigned_base(va_arg(args, unsigned int), 16, 0);
break;
case 'X':
count += print_unsigned_base(va_arg(args, unsigned int), 16, 1);
break;
default:
count += write(1, "%", 1);
count += write(1, &spec, 1);
break;
}

return (count);
}

/**
* _printf - Custom printf function
* @format: Format string
*
* Return: Number of characters printed, or -1 on error
*/
int _printf(const char *format, ...)
{
int i = 0, count = 0;
va_list args;

if (format == NULL)
return (-1);

va_start(args, format);

while (format[i])
{
if (format[i] == '%')
{
if (format[i + 1] == '\0')
{
va_end(args);
return (-1);
}
i++;
count += handle_specifier(format[i], args);
}
else
{
count += write(1, &format[i], 1);
}
i++;
}

va_end(args);
return (count);
}
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
* handle_specifier - Processes format specifiers
* @spec: Format specifier
* @args: Arguments list
* @buffer: The character buffer
* @index: Pointer to current buffer index
*
* Return: Number of characters printed
*/
int handle_specifier(char spec, va_list args, char *buffer, int *index)
{
int count = 0;
char *str;
char temp[32];
int i, len;

switch (spec)
{
case 'c':
buffer_char(buffer, va_arg(args, int), index, &count);
break;
case 's':
str = va_arg(args, char *);
if (!str) str = "(null)";
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
* _printf - Custom printf function with 1024 buffer
* @format: Format string
*
* Return: Total number of characters printed
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
