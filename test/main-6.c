#include "../main.h"
#include <stdio.h>

int main(void)
{
	int x = 42;
	void *ptr = &x;

	_printf("My pointer is: %p\n", ptr);
	printf ("Real printf:  %p\n", ptr);
	return (0);
}
