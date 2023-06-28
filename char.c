#include <unistd.h>
/**
 * f_char - prints char
 * @c: chqr to be printed
 * Return: nbr of char (1)
 */
int f_char(char c)
{
	write(1, &c, 1);
	return (1);
}
