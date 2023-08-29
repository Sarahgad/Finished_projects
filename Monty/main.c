#include "monty.h"
#include <stdio.h>
/**
 *main - Entry Point
 *@argc: int
 *@argv: string
 *Return: 0 Always success
 */
int main(int argc, char **argv)
{
instruction_t data;
stack_t *head = NULL;
if (argc == 2)
{
readfile(argv[1], &data, &head);
}
else
{
fprintf(stderr, "USAGE: monty file\n");
return (EXIT_FAILURE);
}
free_stack_t(head);
return (0);
}

/**
 *readfile - check opcode
 *@filename: string
 *@data: struct
 *@head: struct
 *Return: 0 always success
 */
int readfile(char *filename, instruction_t *data, stack_t **head)
{
char lineptr[MAX_LINE_LENGTH];
int linenumber = 1;
FILE *fp = fopen(filename, "r");

if (fp == NULL)
{
fprintf(stderr, "Error: Can't open file %s\n", filename);
exit(EXIT_FAILURE);
}

while ((fgets(lineptr, sizeof(lineptr), fp)) != NULL)
{
if (checkpush(lineptr, data, head, linenumber) != 0)
break;
if (checkdisplay(lineptr, data, head, linenumber) != 0)
break;
if (checkmunp(lineptr, data, head, linenumber) != 0)
break;
if (checkop(lineptr, data, head, linenumber) != 0)
break;
if (checkopp(lineptr, data, head, linenumber) != 0)
break;
linenumber++;
}
fclose(fp);
return (0);
}

