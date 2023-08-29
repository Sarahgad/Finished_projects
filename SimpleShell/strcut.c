#include"main.h"
/**
*strcut - cut the input line
*@lineptr: pointer
*Return: argv always success
*/
char **strcut(char *lineptr)
{
char **argv = NULL;
int argc = MAX_ARGS;
int i = 0, j;
char *token;

argv = malloc(sizeof(char *) * argc);
if (argv == NULL)
{
perror("argv");
exit(EXIT_FAILURE);
}
token = strtok(lineptr, DELMITER);
while (token)
{
argv[i] = token;
i++;
if (i >= argc)
{
char **new_argv = realloc(argv, (argc + 64) * sizeof(char *));
if (new_argv == NULL)
{
perror("Allocation Error\n");
for (j = 0; j < i; j++)
{
free(argv[j]);
}
free(argv);
exit(EXIT_FAILURE);
}
argv = new_argv;
argc += 64;
}
token = strtok(NULL, DELMITER);
}
argv[i] = NULL;
return (argv);
}

