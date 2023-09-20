#ifndef MAIN_H
#define MAIN_H
#include <stdlib.h>
#include <stdarg.h>

int _printf(const char *format, ...);
int _putchar(char c);
int _string(char *str);
int print_int(va_list args, char b[], int flags, int width, int precision,
int size);
int _integer(int num);
int numlen(int num);

#endif
