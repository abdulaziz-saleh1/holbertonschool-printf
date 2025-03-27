#include "main.h"

/**
 * print_unsigned - prints an unsigned int in given base with hash flag
 * @n: number to print
 * @base: base to use (8, 10, 16)
 * @uppercase: 1 if using uppercase (for %X), 0 for lowercase
 * @flags: struct containing the active flags
 * @buffer: buffer to write to
 * @index: pointer to current index in the buffer
 *
 * Return: number of characters written
 */
int print_unsigned(unsigned int n, int base, int uppercase, flags_t flags, char *buffer, int *index)
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
buffer_char(buffer, (uppercase ? 'X' : 'x'), index, &count);
}
}

count += print_unsigned_buffer(n, base, uppercase, buffer, index);
return (count);
}
