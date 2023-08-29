#include"main.h"
/**
*non_interactive -non interactive function
*/
void non_interactive(void)
{
char *lineptr = NULL;
size_t n = 0;
ssize_t nreads;
char **token;
n = (lineptr == NULL || n == 0) ? 120 : n;
lineptr = malloc(n);
	if (lineptr == NULL)
	{
		perror("lineptr");
		exit(-1);
	}
while ((nreads = getline(&lineptr, &n, stdin)) != -1)
{
if (nreads == -1)
{
perror("nreads");
exit(EXIT_FAILURE);
}
if (nreads == 1)
continue;
if (lineptr[_strlen(lineptr) - 1] == '\n')
lineptr[_strlen(lineptr) - 1] = '\0';
token = strcut(lineptr);
if (token == NULL)
{
perror("token");
exit(EXIT_FAILURE);
}
checkcommand(token, lineptr);
_execve(token);
free(token);
free(lineptr);
n = 0;
lineptr = NULL;
}
free(lineptr);
}
/**
 *checkcommand - checkthe command if it's exist
 *@token: string
 *@lineptr: pointer
 */
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
}
