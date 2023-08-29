void pint(stackk_t **stack) {
    if (*stack == NULL) {
        printf("Stack underflow\n");
        return;
        }
    printf("The top element of the stack is: %d\n", (*stack)->n);
}
