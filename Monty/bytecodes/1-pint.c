#include <stdio.h>
#include <stdlib.h>
#include "monty.h"

/**
* pint - Prints the value at the top of the stack
* @stack: Pointer to the stack
* @line_number: Line number where the opcode appears
*/

void pint(stack_t **stack, unsigned int line_number)
{
stack_t *current = *stack;
(void)line_number;
if (current == NULL)
{
fprintf(stderr, "L%d: can't pint, stack empty\n", line_number);
exit(EXIT_FAILURE);
}
while (current->next != NULL)
{
current = current->next;
}
printf("%d\n", current->n);
}
