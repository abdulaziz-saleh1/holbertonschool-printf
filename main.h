#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>
#include <unistd.h>

int _printf(const char *format, ...);
int print_char(char c);
int print_string(const char *str);
int print_percent(void);
int print_int(int n);
int print_binary(unsigned int n);
int print_unsigned_base(unsigned int n, int base, int uppercase);

#endif
