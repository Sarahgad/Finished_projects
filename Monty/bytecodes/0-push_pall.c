#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "monty.h"

void push(Stack *stack, int value);
void pall(Stack *stack);

/**
 * main - Entry point of the program
 * @argc: The number of command-line arguments
 * @argv: An array of strings containing the arguments
 * Return: EXIT_SUCCESS on success, EXIT_FAILURE on failure
 */
int main(int argc, char *argv[])
{
Stack stack;
char line[100];
char *opcode;
char *arg;
int line_number = 1;
int value;
FILE *file = fopen(argv[1], "r");

if (argc != 2)
{
fprintf(stderr, "USAGE: monty file\n");
return (EXIT_FAILURE);
}

if (file == NULL)
{
fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
return (EXIT_FAILURE);
}

while (fgets(line, sizeof(line), file) != NULL)
{
opcode = strtok(line, " \n");
if (strcmp(opcode, "push") == 0)
{
arg = strtok(NULL, " \n");
if (arg == NULL)
{
fprintf(stderr, "L%d: usage: push integer\n", line_number);
return (EXIT_FAILURE);
}
value = atoi(arg);
if (value == 0 && strcmp(arg, "0") != 0)
{
fprintf(stderr, "L%d: usage: push integer\n", line_number);
return (EXIT_FAILURE);
}
push(&stack, value);
}
else if (strcmp(opcode, "pall") == 0)
{
pall(&stack);
}

line_number++;
}

fclose(file);

return (EXIT_SUCCESS);
}
/**
 * push - Pushes an element onto the stack
 * @stack: Pointer to the stack
 * @value: Value to be pushed onto the stack
 */
void push(Stack *stack, int value)
{
Node *newNode = malloc(sizeof(Node));
if (newNode == NULL)
{
fprintf(stderr, "Error: malloc failed\n");
exit(EXIT_FAILURE);
}
newNode->data = value;
newNode->next = stack->top;
stack->top = newNode;
}
/**
 * pall - Prints all the elements in the stack
 * @stack: Pointer to the stack
 */
void pall(Stack *stack)
{
Node *current = stack->top;
while (current != NULL)
{
printf("%d\n", current->data);
current = current->next;
}
}
