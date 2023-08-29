#ifndef MAIN_H
#define MAIN_H
#include<stdarg.h>
#include<stdio.h>
#include<string.h>
#include <unistd.h>
int _printchar(char x);
int _printf(const char *format, ...);
/**
 *struct conv_spec - function' description in 'conv_spec'
 *@spec: member 1
 *@function: member 2
 */
typedef struct conv_spec
{
	char *spec;
	int (*function)(va_list arg);
} conv_t;
int conv_c(va_list arg);
int conv_s(va_list arg);
int conv_p(va_list arg);
#endif/*main.h*/
