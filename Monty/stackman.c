#include "monty.h"
/**
 *push - implement stack
 *@head: struct
 *@linenumber: integer
 *
 */
void push(stack_t **head, unsigned int  linenumber)
{
stack_t *newNode = createStackNode(num);
(void)linenumber;
if (*head != NULL)
{
newNode->next = *head;
(*head)->prev = newNode;
}
*head = newNode;
}

/**
 *pall - implement stack
 *@head: struct
 *@linenumber: integer
 *
 */
void pall(stack_t **head, unsigned int linenumber)
{
stack_t *current = *head;
(void)linenumber;
while (current != NULL)
{
printf("%d\n", current->n);
current = current->next;
}
}

/**
 *pint - implement stack
 *@head: struct
 *@line_number: integer
 *
 */
void pint(stack_t **head, unsigned int line_number)
{
if (*head == NULL)
{
fprintf(stderr, "L%d: can't pint, stack empty\n", line_number);
exit(EXIT_FAILURE);
}
printf("%d\n", (*head)->n);
}

/**
 *pop - implement stack
 *@head: struct
 *@line_number: integer
 *
 */
void pop(stack_t **head, unsigned int line_number)
{
	stack_t *curr;

	if (*head == NULL)
	{
	fprintf(stderr, "L%d: can't pop an empty stack", line_number);
	exit(EXIT_FAILURE);
	}

	curr = (*head)->next;
	free(*head);
	*head = curr;
}

/**
 *swap - implement stack
 *@head: struct
 *@line_number: integer
 *
 */
void swap(stack_t **head, unsigned int line_number)
{
	int tmp;
	int count = 0;
	stack_t *current, *first, *second;

	current = *head;
	first = *head;
	second = (*head)->next;

	while (current != NULL)
	{
		count++;
		current = current->next;
	}
	if (count < 2)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	tmp = first->n;
	first->n = second->n;
	second->n = tmp;
}

