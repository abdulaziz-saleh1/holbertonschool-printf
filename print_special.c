#include "main.h"
#include <stdio.h>

int print_S(char *str, char *buffer, int *index)
{
int i, count = 0;
char hex[3];

if (!str)
str = "(null)";

for (i = 0; str[i]; i++)
{
char c = str[i];
if (c < 32 || c >= 127)
{
buffer_char(buffer, '\\', index, &count);
buffer_char(buffer, 'x', index, &count);
sprintf(hex, "%02X", (unsigned char)c);
buffer_char(buffer, hex[0], index, &count);
buffer_char(buffer, hex[1], index, &count);
}
else
{
buffer_char(buffer, c, index, &count);
}
}
return (count);
}

int print_p(void *ptr, char *buffer, int *index)
{
int count = 0, i;
unsigned long addr = (unsigned long)ptr;

if (!ptr)
{
char *null_str = "(nil)";
for (i = 0; null_str[i]; i++)
buffer_char(buffer, null_str[i], index, &count);
}
else
{
buffer_char(buffer, '0', index, &count);
buffer_char(buffer, 'x', index, &count);
count += print_unsigned_buffer(addr, 16, 0, buffer, index);
}
return (count);
}
