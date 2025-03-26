#include "main.h"

/**
* _printf - Custom printf function using 1024-char local buffer
* @format: Format string
*
* Return: Number of characters printed, or -1 on error
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
