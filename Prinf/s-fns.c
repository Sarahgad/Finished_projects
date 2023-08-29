#include "main.h"
/**
 *conv_num_i - prints %
 *@arg: argument parameters
 *Return: 1
 */

int conv_num_i(va_list arg)
{
unsigned int value, camp, counting, count;
int x;

count = 0;
x = va_arg(arg, int);
if (x < 0)
{
	value = (x * -1);
	count += _printchar('-');
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
count += _printchar(((value / counting) % 10) + '0');
counting /= 10;
}
return (count);
}

/**
 *conv_num_d - prints %
 *@arg: argument parameters
 *Return: 1
 */
int conv_num_d(va_list arg)
{
	return (conv_num_i(arg));
}
