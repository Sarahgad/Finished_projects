#include "main.h"
/**
 * conv_c - prints characters
 * @arg: argument parameters
 * Return: 1
 */
int conv_c(va_list arg)
{
_printchar(va_arg(arg, int));
return (1);
}

/**
 * conv_s - prints strings
 * @arg: argument parameters
 * Return: i
 */

int conv_s(va_list arg)
{
char *str;
	int i;

	str = (va_arg(arg, char*));
	if (str == NULL)
		str = "(null)";
	for (i = 0; str[i]; i++)
		_printchar (str[i]);

	return (i);
}
/**
 * conv_p - prints %
 * @arg: argument parameters
 * Return: 1
 */
int conv_p(va_list arg)
{
	(void)arg;
	_printchar('%');
	return (1);
}
