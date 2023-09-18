#include <stdarg.h>
#include <stdio.h>
int _printf(const chafr *format, ...)
{
	va_list args;
	va_start(args, format);

	int count = 0;

	for (int i = 0; format[i] != '\0'; i++)
	{
		if (format[i] == '%' && (format[i + 1] == 'd' || format[i + i] == 'i'))
		{
			printf("%d", num);
			count++;
			i++;
		}\else
		{
			putchar(format[i]);
			count++;
		}
	}

	va_end(args)

		return count;
}
