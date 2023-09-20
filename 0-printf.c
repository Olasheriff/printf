#include "main.h"
#include <unistd.h>
#include <string.h>

/**
 * _putchar - writes the character c to stdout
 * @c: The character to print
 *
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */

int _putchar(char c)
{
	return (write(1, &c, 1));
}

/**
* _string - handle %s.
* @str: the string given.
* Return: character printed.
*/

int _string(char *str)
{
	int cmptr = 0;

	if (str == NULL)
	{
		str = "(null)";
		write(1, str, 6);
		return (6);
	}
	else
	{
		cmptr = strlen(str);
		write(1, str, cmptr);
		return (cmptr);
	}
}

/**
* _printf - produces output according to a format.
* @format: the format specifier.
* Return: the number of characters printed.
*/

int _printf(const char *format, ...)
{
	va_list arg_list;
	int cmp = 0, i = 0, value = 0;

	va_start(arg_list, format);
	if (format == NULL || !*(format + 0))
		return (-1);
	while (*(format + i) != '\0')
	{
		if (*(format + i) == '%')
		{
			i++;
			if (*(format + i) == 'c' || *(format + i) == '%')
			{
				value = va_arg(arg_list, int);
				if (value == 0)
					write(1, "", 1);
				else
				{
					write(1, &value, 1);
					cmp++;
				}
			}
			else if (*(format + i) == 's')
			{
				char *string = va_arg(arg_list, char *);
				value = _string(string);
				cmp += value;
			}
				else
				{
					_putchar('%');
					if (*(format + i))
						_putchar(*(format + i));
					cmp += 2;
				}
		}
		else
		{
			_putchar(*(format + i));
			cmp++;
		}
		i++;
	}
	return (cmp);
}
