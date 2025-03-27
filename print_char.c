#include "main.h"

/**
 * print_char - Writes a character to the buffer
 * @c: Character to print
 * @buffer: Buffer to write the character into
 * @index: Pointer to current buffer index
 *
 * Return: Number of characters written (always 1)
 */
int print_char(char c, char *buffer, int *index)
{
int count = 0;
buffer_char(buffer, c, index, &count);
return (count);
}
