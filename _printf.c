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
