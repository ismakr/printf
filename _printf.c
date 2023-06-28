#include <unistd.h>
#include <stdarg.h>
#include "main.h"
/**
 * _printf - produces output according to a format.
 * @format: character string. The format string is composed
 * of zero or more directives.
 * Return: the number of characters printed
 */
int _printf(const char *format, ...)
{
	int i, nbr;
	va_list args;

	if (format == NULL || (format[0] == '%' && format[1] == '\0'))
		return (-1);
	va_start(args, format);
	nbr = 0;
	i = 0;
	while (format[i] != '\0')
	{
		if (format[i] == '%')
		{
			if (format[i + 1] == 'c')
			{
				nbr += f_char(va_arg(args, int));
				i++;
			}
			else if (format[i + 1] == 's')
			{
				nbr += _puts(va_arg(args, char *));
				i++;
			}
			else if (format[i + 1] == '%')
			{
				nbr += write(1, "%", 1);
				i++;
			}
			else
			{
				nbr += write(1, &format[i], 1);
			}
		}
		else
		{
			nbr += write(1, &format[i], 1);
		}
		i++;
	}
	va_end(args);
	return (nbr);
}
