#include "main.h"

/**
* print_unsigned_buffer - Prints an unsigned int in any base to buffer
* @n: The number
* @base: The base to convert to (8, 10, 16)
* @uppercase: 1 if uppercase hex, 0 otherwise
* @buffer: Output buffer
* @index: Pointer to buffer index
*
* Return: Number of characters printed
*/
int print_unsigned_buffer(unsigned int n, int base, int uppercase,
char *buffer, int *index)
{
char *digits;
char temp[32];
int i = 0, count = 0;

digits = uppercase ? "0123456789ABCDEF" : "0123456789abcdef";

if (n == 0)
{
buffer_char(buffer, '0', index, &count);
return (count);
}

while (n > 0)
{
temp[i++] = digits[n % base];
n /= base;
}

while (i--)
{
buffer_char(buffer, temp[i], index, &count);
}

return (count);
}
