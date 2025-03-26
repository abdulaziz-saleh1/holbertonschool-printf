#include "../main.h"

int main(void)
{
    _printf("Hello %s!\n", "World");
    _printf("Char: %c\n", 'A');
    _printf("Decimal: %d, Binary: %b\n", 98, 98);
    _printf("Unsigned: %u, Octal: %o, Hex: %x, HEX: %X\n", 255, 255, 255, 255);
    _printf("Percent: %%\n");
    return (0);
}
