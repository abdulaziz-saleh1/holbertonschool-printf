#include "main.h"

/**
 * print_percent - Writes a percent sign to buffer
 * @buffer: output buffer
 * @index: buffer index
 * Return: number of characters written
 */
int print_percent(char *buffer, int *index)
{
int count = 0;
buffer_char(buffer, '%', index, &count);
return (count);
}
