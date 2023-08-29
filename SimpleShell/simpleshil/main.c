#include "main.h"
/**
 *main - Entry point
 *Description: simple shell
 *Return: 0 always success
 */
int main(void)
{
if (!isatty(STDIN_FILENO))
{
non_interactive();
}
else
{
int i, j;
char *input;
char **args;
char c;
c = '\0';
i = 0;
while (1)
{
if (c == '\n' || c == EOF)
{
break;
}
write(1, "$ ", 2);
i++;
input = _readline(c);
args = strcut(input);
_execve(args, i);
}

free(input);
j = 0;
while(args[j])
{
	free(args[j]);
	args[j] = NULL;
	j++;
}

}
return (0);

}
