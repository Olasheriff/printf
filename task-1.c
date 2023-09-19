#include <stdarg.h>
#include <stdio.h>
#include "main.h"

/*print_int - prints integers
 *@counts - counts characters
 *@args - list of arguments
 *@b - buffer array to handle
 *@flags- calculates active flags
 *@width- gets width
 *@precision- precision specification
 *@size- size specifier
 *Return: numbers of characters printed
 */
int print_int(va_list args, char b[], int flags, int width, int precision, int size)

{
	int BUFF_SIZE
	int x = BUFF_SIZE - 2;
	int is_neg = 0;
	long int y = va_arg(args, long int);
	unsigned long int num;
	
	y = convert_size_number(y, size);

	if (y == 0)
		b[x--] = '\0';
	
	b[BUFF_SIZE - 1] = '\0';
	num = (unsigned long int y); 

	if (y < 0)
	{
		num = (unsigned long int)((-1) * y);
		is_neg = 1;
	}
	while (num > 0)
	{
		b[x--] = (num % 10) + '0';
		num /= 10;
	}

	x++;

	return (write_number(is_neg, x, b, flags, width, precision, size));
}
