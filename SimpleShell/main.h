#ifndef MAIN_H
#define MAIN_H
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <errno.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <fcntl.h>
#include<stdarg.h>
/*macros function*/
#define DELMITER " \t\r\n\a"
#define del "\n"
#define MAX_ARGS 100
/*global variable*/
extern char **environ;
/*path.c*/
char *handle_path(char *command);
/*getenv.c*/
int _putchar(char c);
void _puts(char *str);
char *_getenv(const char *name);
void _env(void);
/*non_interactive.c*/
void non_interactive(void);
void checkcommand(char **token, char *lineptr);
/*strcut.c*/
char **strcut(char *lineptr);
/*exceve.c*/
void _execve(char **argv);
/*strings.c*/
size_t _strlen(char *s);
char *_strcat(char *dest, char *src);
char *_strcpy(char *dest, const char *src);
int _strcmp(char *s1, char *s2);
/*printf.c*/
int _eputchar(char c);
int _switch(va_list arg, char x);
int _printf(const char *format, ...);
/*conversionSpecifiers.c*/
int conv_c(va_list arg);
int conv_s(va_list arg);
int conv_num_d(va_list arg);
/*interactive*/
void interactive(void);
#endif
