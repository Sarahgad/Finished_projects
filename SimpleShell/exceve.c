#include "main.h"
/**
 *_execve - excute the command
 *@argv: striing of array
*/
void _execve(char **argv)
{
pid_t pid;
int status;
char *path;

pid = fork();
if (pid < 0)
{
perror("fork");
exit(EXIT_FAILURE);
}
if (pid == 0)
{
path = handle_path(argv[0]);

	if (execve(path, argv, NULL) == -1)
{
	free(path);
	exit(EXIT_FAILURE);
	}
}

else
	{
	wait(&status);
	}
}
