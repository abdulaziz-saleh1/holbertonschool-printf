#include "main.h"

/**
* flush_buffer - Writes the buffer to stdout
* @buffer: The character buffer
* @len: Length of buffer to write
*
* Return: Number of bytes written
*/
int flush_buffer(char *buffer, int len)
{
return (write(1, buffer, len));
}

/**
* buffer_char - Adds a character to buffer, flushes if full
* @buffer: The character buffer
* @c: Character to add
* @index: Pointer to current buffer index
* @count: Pointer to total characters printed
*/
void buffer_char(char *buffer, char c, int *index, int *count)
{
buffer[*index] = c;
(*index)++;
(*count)++;

if (*index == 1024)
{
flush_buffer(buffer, *index);
*index = 0;
}
}
