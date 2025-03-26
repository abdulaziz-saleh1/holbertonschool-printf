#include "main.h"

/**
 * print_unsigned_buffer - Prints unsigned int in given base using buffer
 * @n: Number
 * @base: Base (8 for octal, 10 for decimal, 16 for hex)
 * @uppercase: 1 for A-F, 0 for a-f
 * @buffer: Output buffer
 * @index: Pointer to buffer index
 * Return: Characters printed
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
