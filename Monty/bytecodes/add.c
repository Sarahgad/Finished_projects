#include "monty.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void add(stack_t **head, unsigned int line_number)
{
if (*head == NULL || (*head)->top == NULL || (*head)->top->next == NULL)
{
fprintf(stderr, "L%d: can't add, stack too short\n", line_number);
exit(EXIT_FAILURE);
}
int a = pop(*head);
int b = pop(*head);
push(*head, a + b);
}
int main(int argc, char *argv[])
{
if (argc != 2)
{
fprintf(stderr, "USAGE: monty file\n");
return (EXIT_FAILURE);
}
FILE *file = fopen(argv[1], "r");
if (file == NULL)
{
fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
return (EXIT_FAILURE);
}
stack_t *stack = malloc(sizeof(stack_t));
if (stack == NULL)
{
fprintf(stderr, "Error: malloc failed\n");
fclose(file);
return (EXIT_FAILURE);
}
stack->top = NULL;
stack->size = 0;
/*Read and process the file line by line*/
char line[1024];
unsigned int line_number = 0;
while (fgets(line, sizeof(line), file))
{
line_number++;
/*Parse the opcode and arguments from the line*/
char opcode[64];
int arg;
if (sscanf(line, "%63s %d", opcode, &arg) == 2)
{
/*Process the opcode*/
if (strcmp(opcode, "add") == 0)
{
add(&stack, line_number);
}
/*Implement other opcodes here*/
else
{
fprintf(stderr, "L%d: unknown instruction %s\n", line_number, opcode);
free_stack(stack);
fclose(file);
return (EXIT_FAILURE);
}
}
}
/*Cleanup and exit*/
free_stack(stack);
fclose(file);
return (EXIT_SUCCESS);
}
