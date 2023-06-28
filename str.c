#include <unistd.h>
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
int _puts(char *str)
{
	int i;

	if (str == NULL)
	{
		write(1, "(null)", 6);
		return (6);
	}
	i = _strlen(str);
	while (*str != '\0')
	{
		write(1, str, 1);
		str++;
	}
	return (i);
}
