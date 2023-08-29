#include"main.h"
/**
 * conv_c - prints characters
 * @arg: argument parameters
 * Return: 1
 */
int conv_c(va_list arg)
{
_eputchar(va_arg(arg, int));
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
		_eputchar (str[i]);

	return (i);
}
/**
 *conv_num_d - prints %
 *@arg: argument parameters
 *Return: count
 */

int conv_num_d(va_list arg)
{
unsigned int value, camp, counting, count;
int x;

count = 0;
x = va_arg(arg, int);
if (x < 0)
{
	value = (x * -1);
	count += _eputchar('-');
}
else
value = x;

camp = value;
counting = 1;
while (camp > 9)
{
camp /= 10;
counting *= 10;
}

while (counting >= 1)
{
count += _eputchar(((value / counting) % 10) + '0');
counting /= 10;
}
return (count);
}


