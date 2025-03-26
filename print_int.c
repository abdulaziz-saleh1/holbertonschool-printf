#include "main.h"

/**
* print_int - Prints an integer to stdout
* @n: The integer to print
*
* Return: Number of characters printed
*/
int print_int(int n)
{
int count = 0;
unsigned int num;

if (n < 0)
{
count += write(1, "-", 1);
num = -n;
}
else
{
num = n;
}

if (num / 10)
count += print_int(num / 10);

count += print_char((num % 10) + '0');

return (count);
}
