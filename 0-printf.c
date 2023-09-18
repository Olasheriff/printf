#include "main.h"
#include <unistd.h>
#include <string.h>

/**
* _printf - produces output according to a format.
* @format: the format specifier.
* Return: the number of characters printed.
*/

int _printf(const char *format, ...)
{
	va_list arg_list;
	int cmp = 0, i = 0, value = 0;
	char *string = NULL;


	va_start(arg_list, format);
	if (format == NULL)
		return (0);
	while (*(format + i) != '\0')
	{
		if (*(format + i) == 'c' || *(format + i) == '%')
		{
			value = va_arg(arg_list, int);
			write(1, &value, 1);
			cmp++;
		}
		else if (*(format + i) == 's')
		{
			string = va_arg(arg_list, char *);
			if (string == NULL)
			{
				string = "";
				write(1, string, 1);
			}
			else
			{
				value = strlen(string);
				write(1, string, value);
				cmp += value;
			}
		}
		i++;
	}
	return (cmp);
}
