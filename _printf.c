#include "main.h"
#include <stdarg.h>
#include <unistd.h>

int _printf(const char *format, ...)
{
char buffer[1024];
int index = 0, i = 0, count = 0;
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
break;
count += handle_specifier(format[i], args, buffer, &index);
}
else
{
buffer[index++] = format[i];
if (index == 1024)
{
count += flush_buffer(buffer, index);
index = 0;
}
}
i++;
}

if (index > 0)
count += flush_buffer(buffer, index);

va_end(args);
return (count);
}
