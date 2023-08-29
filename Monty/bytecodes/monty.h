#ifndef MONTY_H
#define MONTY_H

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
int n;
struct stack_s *prev;
struct stack_s *next;
} stack_t;

/* Structure for stack node */
typedef struct Node
{
int data;
struct Node *next;
} Node;

/* Structure for stack */
typedef struct Stack
{
Node *top;
} Stack;

/* Function prototypes */
void push(Stack *stack, int value);
void pall(Stack *stack);
void pint(stack_t **stack, unsigned int line_number);

#endif /* MONTY_H */
