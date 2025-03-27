#include "main.h"

int print_int(int n, flags_t flags, char *buffer, int *index)
{
int count = 0;

if (n >= 0)
{
if (flags.plus)
buffer_char(buffer, '+', index, &count);
else if (flags.space)
buffer_char(buffer, ' ', index, &count);
}

count += print_int_buffer(n, buffer, index);
return (count);
}
