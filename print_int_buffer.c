#include "main.h"

/**
* print_int_buffer - Prints an integer to buffer
* @n: The integer to print
* @buffer: The output buffer
* @index: Pointer to current index in buffer
*
* Return: Number of characters added
*/
int print_int_buffer(int n, char *buffer, int *index)
{
int count = 0;
unsigned int num;

if (n < 0)
{
buffer_char(buffer, '-', index, &count);
num = -n;
}
else
{
num = n;
}

if (num / 10)
count += print_int_buffer(num / 10, buffer, index);

buffer_char(buffer, (num % 10) + '0', index, &count);

return (count);
}
