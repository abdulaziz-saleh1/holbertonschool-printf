#include "main.h"

/**
* print_binary - Converts unsigned int to binary and prints it
* @n: The unsigned int to convert
*
* Return: Number of characters printed
*/
int print_binary(unsigned int n)
{
int i, count = 0;
unsigned int mask = 1 << 31;
int started = 0;

if (n == 0)
return (write(1, "0", 1));

for (i = 0; i < 32; i++)
{
if (n & (mask >> i))
{
started = 1;
count += print_char('1');
}
else if (started)
{
count += print_char('0');
}
}

return (count);
}
