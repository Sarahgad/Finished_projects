#include "monty.h"
/**
*add - operation
*@head: struct
*@line_number: integer
*/
void add(stack_t **head, unsigned int line_number)
{
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
	fprintf(stderr, "L%d: can't add, stack too short\n", line_number);
	exit(EXIT_FAILURE);
	}
	second->n = second->n + first->n;
	pop(&first, line_number);
	*head = second;

}

/**
*sub - operation
*@head: struct
*@line_number: integer
*/
void sub(stack_t **head, unsigned int line_number)
{
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
	fprintf(stderr, "L%d: can't sub, stack too short\n", line_number);
	exit(EXIT_FAILURE);
	}
	second->n = second->n - first->n;
	pop(&first, line_number);
	*head = second;

}

/**
*_div - operation
*@head: struct
*@line_number: integer
*/
void _div(stack_t **head, unsigned int line_number)
{
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
	fprintf(stderr, "L%d: can't div, stack too short\n", line_number);
	exit(EXIT_FAILURE);
	}
	if (first->n == 0)
	{
	fprintf(stderr, "L%d: division by zero", line_number);
	exit(EXIT_FAILURE);
	}
	second->n = second->n / first->n;
	pop(&first, line_number);
	*head = second;
}

/**
*mul - operation
*@head: struct
*@line_number: integer
*/
void mul(stack_t **head, unsigned int line_number)
{
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
		fprintf(stderr, "L%d: can't mul, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	second->n = second->n * first->n;
	pop(&first, line_number);
	*head = second;
}
/**
*mod - operation
*@head: struct
*@line_number: integer
*/
void mod(stack_t **head, unsigned int line_number)
{
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
		fprintf(stderr, "L%d: can't mod, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	if (first->n == 0)
	{
		fprintf(stderr, "L%d: division by zero", line_number);
		exit(EXIT_FAILURE);
	}
	second->n = second->n % first->n;
	pop(&first, line_number);
	*head = second;
}
