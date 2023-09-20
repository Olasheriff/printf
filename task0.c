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
* numlen - calculates the lentgh of a number.
* @num: the number given.
* Return: the length.
*/

int numlen(int num)
{
	int length = 0;

	while (num != 0) 
	{
		num /= 10;
		length++;
	}
	return (length);
}

/**
* _integer - handling with %d and %i.
* @num: the giving integer.
* Return: the number printed.
*/

int _integer(int num)
{
	char *str;
	int len = 0, i;
	if (num == 0)
	{
		_putchar('0');
		return(1);
	}

	if (num < 0)
	{
		_putchar('-');
		num = -num;
	}
	len = numlen(num);
	str = (char *)malloc(sizeof(char) * (len + 1));
	if (str == NULL)
		return (-1);

	for (i = len - 1; i >= 0; i--)
	{
		str[i] = '0' + (num % 10);
		num /= 10;
	}
	str[len] = '\0';
	write(1, str, len);
	free(str);
	return (len);
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
	char *string;

	va_start(arg_list, format);
	if (format == NULL)
		return (-1);
	while (*(format + i) != '\0')
	{
		if (*(format + i) == '%')
		{
			i++;
			if (*(format + i) == 'c' || *(format + i) == '%')
			{
				value = va_arg(arg_list, int);
				write(1, &value, 1);
				cmp++;
			}
			else if (*(format + i) == 's')
			{
				string = va_arg(arg_list, char *);
				value = _string(string);
				cmp += value;
			}
				else if (*(format + i) == 'd' || *(format + i) == 'i')
				{
					value = va_arg(arg_list, int);
					cmp += _integer(value);
				}
				else
				{
					_putchar('%');
					if (*(format + i))
					{
						_putchar(*(format + i));
						cmp += 2;
					}
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
