#include "main.h"

/**
* _printf - Custom printf function (supports %c, %s, %%)
* @format: Format string
* Return: Number of characters printed
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
switch (format[i])
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
default:
count += write(1, "%", 1);
count += write(1, &format[i], 1);
break;
}
}
else
{
count += write(1, &format[i], 1);
}
