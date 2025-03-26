#include "main.h"

int flush_buffer(char *buffer, int len)
{
return (write(1, buffer, len));
}

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
