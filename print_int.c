#include "main.h"

int print_int(int n, flags_t flags, char *buffer, int *index)
{
int count = 0;
unsigned int num;

if (n >= 0)
{
if (flags.plus)
count += buffer_char(buffer, '+', index);
else if (flags.space)
count += buffer_char(buffer, ' ', index);
num = n;
}
else
{
count += buffer_char(buffer, '-', index);
num = -n;
}

count += print_unsigned_buffer(num, 10, 0, buffer, index);
return (count);
}
