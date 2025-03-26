#include "main.h"

int print_int_buffer(int n, char *buffer, int *index)
{
int count = 0;
unsigned int num;

if (n < 0)
{
buffer_char(buffer, '-', index, &count);
num = -n;
}
else
{
num = n;
}

if (num / 10)
count += print_int_buffer(num / 10, buffer, index);

buffer_char(buffer, (num % 10) + '0', index, &count);

return (count);
}
