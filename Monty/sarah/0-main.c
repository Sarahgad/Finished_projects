
#include "monty.h"
extern int value;
    int value = 0;

int main(int argc, char **argv)
{
    if (argc == 2)
    {
   readfile(argv[1]);
    }
    else
	    perror("Error: argv");
    return 0;
}

void readfile(char *filename)
{
    int linenumber = 1;
    char lineptr[MAX_LINE_LENGTH];
    char *tokens = NULL;
    FILE *fp = fopen(filename, "r"); 
     stackk_t *head; 
    instruction_t data;
    data.f = NULL;
    data.opcode = NULL;
     head = malloc(sizeof(stackk_t));
     if (head == NULL)
     {
            fprintf(stderr, "Error: malloc failed");
            exit(EXIT_FAILURE);
     }
    
    if (fp == NULL)
        {
        fprintf(stderr, "Error: Can't open file %s\n", filename);
        exit(EXIT_FAILURE);
        }
       
    while ((fgets(lineptr,sizeof(lineptr), fp)) != NULL)
    {
        tokens = strtok(lineptr, " ");
        if (strcmp(tokens,"push") == 0)
        {
        data.opcode = tokens;
        tokens = strtok(NULL, " ");
        value = atoi(tokens);
          if (tokens == NULL && (strcmp(tokens, "0")) != 0)
        {       
fprintf(stderr, "L%d: usage: push integer\n", linenumber);
exit (EXIT_FAILURE);
        }
        data.f = push;
        data.f(&head, linenumber);
        }
        else if (strncmp(tokens,"pall",strlen("pall")) == 0)
        {
            data.opcode = "pall";
            data.f = pall;
            data.f(&head, linenumber);
        }
        else if (strncmp(tokens,"pint",strlen("pint")) == 0)
        {
        data.opcode = "pint";
        data.f = pint;
        data.f(&head, linenumber);
        }
        linenumber ++;

    }
    free_stack_t(head);
    fclose(fp);
}
void free_stack_t(stackk_t *head)
{
	if (head != NULL)
	{
        stackk_t *curr = head;
        stackk_t *tmp;
        while (curr != NULL)
        {
        tmp = curr;
        curr = curr->next;
        free(tmp);
        }
	}
}
void push (stackk_t **head, unsigned int  linenumber)
{
	(void)linenumber;
    if (*head == NULL)
    {
        (*head)->n = value;
    }
    else
    {
stackk_t *top = malloc(sizeof(stackk_t));
top->n = value;
top->next = *head;
(*head)->prev = top;
*head = top;
}
}


void pall(stackk_t **head, unsigned int __attribute__((unused)) line_number)
{

    stackk_t *current;
    if (head == NULL)
	    return;
    current = *head;
    while (current->next != NULL)
    {
        printf("%d\n", current->n);
        current = current->next;
    }
}

void pint(stackk_t **head, unsigned int line_number)
{
    if (*head == NULL)
    {
        fprintf(stderr, "L%d: can't pint, stack empty\n", line_number);
        exit(EXIT_FAILURE);
    }
    printf("%d\n", (*head)->n);
}

