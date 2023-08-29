#include"monty.h"
/**
 *
 *
 *
 */
void push(stackk_t **stack, int value) {
    stackk_t *node = createStackNode(value);
    if (*stack != NULL) {
        node->prev = *stack;
        (*stack)->next = node;
    }
    *stack = node;
}
