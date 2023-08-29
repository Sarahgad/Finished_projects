#include"main.h"
/**
 *interactive - interactive mode
 */
void interactive(void)
{
char *lineptr = NULL;
size_t n = 0;
ssize_t nreads;

char **argv;
argv = malloc(sizeof(char *) * MAX_ARGS);
if (argv == NULL)
{
perror("malloc");
exit(EXIT_FAILURE);
}


while (1)
{
write(1, "$ ", 2);

nreads = getline(&lineptr, &n, stdin);
if (nreads == -1)
{
perror("getline");
exit(EXIT_FAILURE);
}

lineptr[_strlen(lineptr) - 1] = '\0';
free(argv);
argv = strcut(lineptr);
if (argv == NULL)
{
perror("argv");
exit(EXIT_FAILURE);
}
checkcommand(argv, lineptr);
_execve(argv);
}

free(lineptr);
lineptr = NULL;
free(argv);
argv = NULL;
}

