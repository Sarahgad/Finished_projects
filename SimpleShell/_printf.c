#include "main.h"
/**
*_printf - function that produces output according to a format.
*@format: the constant string
*Return: count always success
*/
int _printf(const char *format, ...)
{
va_list arg;
int i, count;

count = 0;

if (format == NULL)
return (-1);
va_start(arg, format);
i = 0;
while (format != NULL && format[i] != '\0')
{
if (format[i] == '%')
{
i++;
if (format[i] != '\0')
{
count += _switch(arg, format[i]);
}
else
return (-1);
}
else
{
count += _eputchar(format[i]);
}
i++;
}
va_end(arg);
return (count);
}

/**
 *_switch - convert specifier
 *@arg: input 1
 *@x: input 2
 *Return: count always success
 */
int _switch(va_list arg, char x)
{
int count;

count = 0;

switch (x)
{
case 'c':
{
count += conv_c(arg);
break;
}
case 's':
{
count += conv_s(arg);
break;
}
case 'd':
{
count += conv_num_d(arg);
break;
}
}
return (count);
}


/**
 * _eputchar - writes the character c to stdout
 * @c: The character to print
 *
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */
int _eputchar(char c)
{
	return (write(2, &c, 1));
}
