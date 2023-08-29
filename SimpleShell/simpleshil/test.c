#include"main.h"
/**
 *non_interactive - non interactive function
*/
void non_interactive(void)
{
    char *lineptr = NULL;
    size_t n = 0;
    ssize_t nreads;
    char **token;

    while ((nreads = getline(&lineptr, &n, stdin)) != -1)
    {
        if (nreads == -1)
        {
            perror("nreads");
            exit(EXIT_FAILURE);
        }
        if (nreads == 1) {
            continue;
        }
        if (lineptr[_strlen(lineptr) - 1] == '\n')
        {
            lineptr[_strlen(lineptr) - 1] = '\0';
        }
        token = strcut(lineptr);
        if (token == NULL)
        {
            perror("token");
            exit(EXIT_FAILURE);
        }
        checkcommand(token, lineptr);
        _execve(token);
        free(token);
        n = 0;
        free(lineptr);
        lineptr = NULL;
    }
    free(lineptr);
}

void checkcommand(char **token, char *lineptr)
{
           if (strcmp(token[0], "env") == 0)
        {
            _env();
        }
        if (strcmp(token[0], "exit") == 0)
        {
                free(lineptr);
                free(token);
            exit(0);
        }
	if (strcmp(token[0], "setenv") == 0)
        {
           process_setenv_command(token);
        }
        else if (strcmp(token[0], "unsetenv") == 0)
        {
           process_unsetenv_command(token);
        }
}
