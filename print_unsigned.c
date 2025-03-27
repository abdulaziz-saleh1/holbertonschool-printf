#include "main.h"

int print_unsigned(unsigned int n, int base, flags_t flags, char *buffer, int *index)
{
int count = 0;

if (flags.hash && n != 0)
{
if (base == 8)
{
buffer_char(buffer, '0', index, &count);
}
else if (base == 16)
{
buffer_char(buffer, '0', index, &count);
buffer_char(buffer, (flags.uppercase ? 'X' : 'x'), index, &count);
}
}

count += print_unsigned_buffer(n, base, flags.uppercase, buffer, index);
return (count);
}
