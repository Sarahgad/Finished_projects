#ifndef MONTY_H
#define MONTY_H

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include <sys/types.h>
#define MAX_LINE_LENGTH 100

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

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
        char *opcode;
        void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;
int checkopcode (char* linptr, instruction_t *data, stack_t **head,int len);
int readfile(char *filename, instruction_t *data, stack_t **head);
void pint(stack_t **h, unsigned int linenumber);
void push(stack_t **head, unsigned int linenumber);
stack_t *createStackNode(int value);
void pall(stack_t **head, unsigned int linenumber);
void free_stack_t(stack_t *head);
#endif /*monty.h*/


