#ifndef S_H
#define S_H
#include<stdarg.h>
#include<stdio.h>
#include<string.h>
#include <unistd.h>
int _printchar(char x);
int conv_c(va_list arg);
int conv_s(va_list arg);
int conv_p(va_list arg);
int conv_num_i(va_list arg);
int conv_num_d(va_list arg);
int _switch(va_list arg, char x);
int _printf(const char *format, ...);
#endif/*s.h*/
