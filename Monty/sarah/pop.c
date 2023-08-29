void pop(stackk_t **stack, int linenumber) {
    if (*stack == NULL) {
        printf("Stack underflow\n");
        return;
    }
    stackk_t *node = *stack;
    *stack = node->prev;
    if (*stack != NULL) {
        (*stack)->next = NULL;
    }
    free(node);
}
