#include "main.h"

int print_binary(unsigned int n, char *buffer, int *index)
{
int count = 0;
int binary[32];
int i = 0, started = 0;

if (n == 0)
return (print_char('0', buffer, index));

while (n > 0)
{
binary[i++] = n % 2;
n /= 2;
}

while (--i >= 0)
{
if (binary[i] == 1)
started = 1;

if (started)
count += print_char(binary[i] + '0', buffer, index);
}

return (count);
}
