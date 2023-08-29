#include"main.h"
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
case '%':
{
count += conv_p(arg);
	break;
}
case 's':
{
count += conv_s(arg);
break;
}
case 'i':
{
count += conv_num_i(arg);
break;
}
case 'd':
{
count += conv_num_d(arg);
break;
}
default:
{
count += _printchar('%');
count += _printchar(x);
break;
}
}
return (count);
}
