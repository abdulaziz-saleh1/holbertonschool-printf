#include "main.h"

/**
* print_char - Prints a single character to stdout
* @c: The character to be printed
*
* Return: Number of characters printed (always 1)
*/

int print_char(char c)
{
return (write(1, &c, 1));
}
