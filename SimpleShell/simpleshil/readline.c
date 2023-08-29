#include "main.h"
/**
 *_readline - readline the input
 *@c: character
 *Return: input always success
*/
char *_readline(char c)
{
	int i;
	char *input;

	input = malloc(sizeof(char) * MAXINPUT);
	if (input == NULL)
	{
		return (NULL);
	}
	i = 0;
while (read(0, &c, 1) == 1)
{
if (c == '\n')
{
input[i] = '\0';
break;
}
input[i++] = c;
}
if (input[0] == 'e' && input[1] == 'n' && input[2] == 'v')
{
	_env();
}
if (input[0] == 'e' && input[1] == 'x' && input[2] == 'i' && input [3] == 't')
{
free(input);
exit(0);
}
return (input);
}
