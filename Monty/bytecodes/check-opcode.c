#include "monty.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int readfile(char *filename, instruction_t *data, stack_t **head);
stack_t *createStackNode(int y);
int checkopcode(char *lineptr, instruction_t *data, stack_t **head, int linenumber);
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
int readfile(char *filename, instruction_t *data, stack_t **head)
{
char lineptr[MAX_LINE_LENGTH];
int linenumber = 1;
int x;
FILE *fp = fopen(filename, "r");
if (fp == NULL)
{
fprintf(stderr, "Error: Can't open file %s\n", filename);
return (EXIT_FAILURE);
}
while (fgets(lineptr, sizeof(lineptr), fp) != NULL)
{
x = checkopcode(lineptr, data, head, linenumber);
if (x != 0)
break;
linenumber++;
}
fclose(fp);
return (0);
}
stack_t *createStackNode(int y)
{
stack_t *newNode = malloc(sizeof(stack_t));
if (newNode == NULL)
{
fprintf(stderr, "Error: Memory allocation failed\n");
exit(EXIT_FAILURE);
}
newNode->n = y;
newNode->prev = NULL;
newNode->next = NULL;
return (newNode);
}
void push(stack_t **head, unsigned int line_number)
{
stack_t *newNode = createStackNode(num);
(void)line_number;
if (*head != NULL)
{
newNode->next = *head;
(*head)->prev = newNode;
}
*head = newNode;
}
void pall(stack_t **head, unsigned int line_number)
{
stack_t *current = *head;
(void)line_number;
while (current != NULL)
{
printf("%d\n", current->n);
current = current->next;
}
}
void pint(stack_t **head, unsigned int line_number)
{
if (*head == NULL)
{
fprintf(stderr, "L%d: can't pint, stack empty\n", line_number);
exit(EXIT_FAILURE);
}
printf("%d\n", (*head)->n);
}
void free_stack_t(stack_t *head)
{
stack_t *curr = head;
while (head)
{
curr = head->next;
free(head);
head = curr;
}
}
int checkopcode(char *lineptr, instruction_t *data, stack_t **head, int linenumber)
{
char *tokens = NULL;
int num = 0;
tokens = strtok(lineptr, " \n");
if (tokens == NULL)
{
return (0);
}
if (strcmp(tokens, "push") == 0)
{
tokens = strtok(NULL, " \n");
if (tokens == NULL || !is_valid_number(tokens))
{
fprintf(stderr, "L%d: usage: push integer\n", linenumber);
return (1);
}
num = atoi(tokens);
data->opcode = "pushinteger";
data->f = push;
data->f(head, linenumber);
}
else if (strcmp(tokens, "pall") == 0)
{
data->opcode = "pall";
data->f = pall;
data->f(head, linenumber);
}
else if (strcmp(tokens, "pint") == 0)
{
data->opcode = "pint";
data->f = pint;
data->f(head, linenumber);
}
else
{
fprintf(stderr, "L%d: unknown instruction %s\n", linenumber, tokens);
return (EXIT_FAILURE);
}
return (0);
}
int is_valid_number(char *str)
{
int i = 0;
if (str == NULL || *str == '\0')
{
return (0);
}
if (str[i] == '-' || str[i] == '+')
{
i++;
}
while (str[i] != '\0')
{
if (!isdigit(str[i]))
{
return (0);
}
i++;
}
return (1);
}
