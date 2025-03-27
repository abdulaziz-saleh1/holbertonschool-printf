#include "main.h"

/**
 * print_string - Writes a string to the buffer
 * @str: string to print
 * @buffer: output buffer
 * @index: buffer index
 * Return: number of characters written
 */
int print_string(const char *str, char *buffer, int *index)
{
int count = 0;
if (!str)
str = "(null)";

while (*str)
{
buffer_char(buffer, *str, index, &count);
str++;
}
return (count);
}
