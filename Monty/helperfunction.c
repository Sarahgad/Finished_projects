#include"monty.h"
/**
 * is_valid_number - Checks if a string is a valid number
 * @str: The string to be checked
 *
 * Return: 1 if the string is a valid number, 0 otherwise
 */
int is_valid_number(char *str)
{
int i = 0;
if (str == NULL || *str == '\0')
{
return (0);
}

if (str[i] == '-' || str[i] == '+')
{
i++;
}
while (str[i] != '\0')
{
if (!isdigit(str[i]))
{
return (0);
}
i++;
}
return (1);
}
/**
 * free_stack_t - Frees a stack_t linked list
 * @head: The head of the linked list
 */
void free_stack_t(stack_t *head)
{
stack_t *curr = head;
while (head)
{
curr = head->next;
free(head);
head = curr;
}
}
/**
 * createStackNode - Creates a new stack node
 * @y: The value for the new node
 *
 * Return: A pointer to the newly created node
 */
stack_t *createStackNode(int y)
{
stack_t *newNode = malloc(sizeof(stack_t));
if (newNode == NULL)
{
fprintf(stderr, "Error: Memory allocation failed\n");
exit(EXIT_FAILURE);
}

newNode->n = y;
newNode->prev = NULL;
newNode->next = NULL;

return (newNode);
}
/**
 * nop - Does nothing
 * @head: The stack's head
 * @line_number: The line number in the Monty file
 */
void nop(stack_t **head, unsigned int line_number)
{
(void)head;
(void)line_number;
return;
}

/**
 * parse_push_argument - Parses the argument for the push opcode
 * @line: The line containing the push opcode and argument
 *
 * Return: The parsed integer argument
 */
int parse_push_argument(char *line)
{
int i = 0;
int sign = 1;
int result = 0;

/* Skip whitespace characters */
while (line[i] == ' ' || line[i] == '\t')
i++;

/* Check if there is a sign (+/-) */
if (line[i] == '-' || line[i] == '+')
{
if (line[i] == '-')
sign = -1;
i++;
}

/* Parse the integer argument */
while (line[i] >= '0' && line[i] <= '9')
{
result = result * 10 + (line[i] - '0');
i++;
}

/* Check if there are any non-digit characters after the number */
while (line[i] == ' ' || line[i] == '\t')
i++;
if (line[i] != '\0' && line[i] != '\n')
return (INT_MIN);
return (result *sign);
}
