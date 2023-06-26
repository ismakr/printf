#include <unistd.h>
#include <stdarg.h>
/**
 * _strlen - ret the length of str
 * @s: Description of parameter x
(* a blank line
 * Description: Longer description of the function)?
(* section header: Section description)*
 * Return: int i
 */
int _strlen(char *s)
{
	int i;

	i = 0;
	while (s[i] != '\0')
	{
		i++;
	}
	return (i);
}
/**
 * _puts - ret the length of str
 * @str: Description of parameter x
(* a blank line
 * Description: Longer description of the function)?
(* section header: Section description)*
 * Return: void
 */
void _puts(char *str)
{
	while (*str != '\0')
	{
		write(1, str, 1);
		str++;
	}
}
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

	va_start(args, format);
	nbr = 0;
	i = 0;
	while (format[i] != '\0')
	{
		if (format[i] == '%')
		{
			if (format[i + 1] == 'c')
			{
				char c = va_arg(args, int);

				write(1, &c, 1);
				nbr += 1;
				i++;
			}
			else if (format[i + 1] == 's')
			{
				char *s = va_arg(args, char *);

				_puts(s);
				nbr += _strlen(s);
				i++;
			}
			else if (format[i + 1] == '%')
			{
				write(1, "%", 1);
				i++;
				nbr += 1;
			}
		}
		else
		{
			write(1, &format[i], 1);
			nbr += 1;
		}
		i++;
	}
	va_end(args);
	return (nbr);
}
