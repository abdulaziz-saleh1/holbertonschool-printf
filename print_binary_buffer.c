#include "main.h"

/**
 * print_binary_buffer - Prints unsigned int in binary using buffer
 * @n: number to convert
 * @buffer: buffer to write to
 * @index: pointer to current buffer index
 * Return: number of characters printed
 */
int print_binary_buffer(unsigned int n, char *buffer, int *index)
{
	int i, count = 0, started = 0;
	unsigned int mask = 1 << 31;

	if (n == 0)
	{
		buffer_char(buffer, '0', index, &count);
		return (count);
	}

	for (i = 0; i < 32; i++)
	{
		if (n & (mask >> i))
		{
			started = 1;
			buffer_char(buffer, '1', index, &count);
		}
		else if (started)
		{
			buffer_char(buffer, '0', index, &count);
		}
	}

	return (count);
}
