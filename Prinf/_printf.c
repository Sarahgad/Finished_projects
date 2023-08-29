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
count += _printchar(format[i]);
}
i++;
}
va_end(arg);
return (count);
}
