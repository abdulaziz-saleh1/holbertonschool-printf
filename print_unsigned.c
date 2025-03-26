#include "main.h"

/**
* print_unsigned_base - Prints an unsigned int in a given base
* @n: The number to print
* @base: The base to convert to (e.g. 10, 8, 16)
* @uppercase: 1 if uppercase hex, 0 if lowercase
*
* Return: Number of characters printed
*/
int print_unsigned_base(unsigned int n, int base, int uppercase)
{
char *digits;
char buffer[32];
int i = 0, count = 0;

digits = uppercase ? "0123456789ABCDEF" : "0123456789abcdef";

if (n == 0)
return (write(1, "0", 1));

while (n > 0)
{
buffer[i++] = digits[n % base];
n /= base;
}

while (i--)
{
count += write(1, &buffer[i], 1);
}

return (count);
}
