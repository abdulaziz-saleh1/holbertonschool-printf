#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>
#include <unistd.h>

typedef struct flags
{
int plus;
int space;
int hash;
} flags_t;


int _printf(const char *format, ...);


void buffer_char(char *buffer, char c, int *index, int *count);
int flush_buffer(char *buffer, int len);


int print_char(char c);
int print_string(const char *str);
int print_percent(void);
int print_int(int n, flags_t flags, char *buffer, int *index);
int print_binary(unsigned int n);
int print_unsigned(unsigned int n, int base, flags_t flags, char *buffer, int *index);


int print_int_buffer(int n, char *buffer, int *index);
int print_binary_buffer(unsigned int n, char *buffer, int *index);
int print_unsigned_buffer(unsigned long n, int base, int uppercase, char *buffer, int *index);


int handle_specifier(char spec, va_list args, char *buffer, int *index);
int print_S(char *str, char *buffer, int *index);
int print_p(void *ptr, char *buffer, int *index);


#endif
