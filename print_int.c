#include "main.h"

/**
 * print_int - prints a signed integer with flags (+ and space)
 * @n: the integer to print
 * @flags: struct containing the active flags
 * @buffer: buffer to write characters to
 * @index: pointer to current index in the buffer
 *
 * Return: number of characters written
 */
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
