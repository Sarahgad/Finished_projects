#include "main.h"

/**
*_printf - function that produces output according to a format.
*@format: the constant string
*Return: count always success
*/
int _printf(const char *format, ...)
{
va_list arg;
int i, j, count;
conv_t array[] = {
{"c", conv_c},
{"s", conv_s},
{"%", conv_p},
{NULL, NULL},
};

if (format == NULL)
return (-1);
va_start(arg, format);
i = 0;
while (format != NULL && format[i] != '\0')
{
if (format[i] == '%')
{
i++;
if (format[i] == '\0')
{
return (-1);
}
j = 0;
while (array[j].spec != NULL)
if (*(array[j].spec) == format[i])
count += array[j].function(arg);
j++;
}
i++;
}
va_end(arg);
return (count);
}
