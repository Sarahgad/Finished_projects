#include "monty.h"
#include <stdio.h>
int num = 0;
int main(int argc, char **argv)
{
    instruction_t data;
    stack_t *head = NULL;
    if (argc == 2)
    {
    readfile(argv[1],&data, &head);
    }
    else
    {
    	 fprintf(stderr,"USAGE: monty file\n");
    	return(EXIT_FAILURE);
}
    free_stack_t(head);
    return 0;
}

int readfile(char *filename, instruction_t *data, stack_t **head)
{
    char lineptr[MAX_LINE_LENGTH];
    int linenumber = 1;
    int x;
    FILE *fp = fopen(filename, "r"); 
    
    if (fp == NULL)
        {
        fprintf(stderr, "Error: Can't open file %s\n", filename);
        exit(EXIT_FAILURE);
        }
       
    while ((fgets(lineptr,sizeof(lineptr), fp)) != NULL)
    {
	   x =  checkopcode (lineptr, data, head, linenumber);
	   if (x != 0)
		   return(EXIT_FAILURE);
   
        linenumber ++;

    }
    
    fclose(fp);
    return (0);
}


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

    return newNode;
}
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


void pint(stack_t **head, unsigned int line_number)
{
    if (*head == NULL)
    {
        fprintf(stderr, "L%d: can't pint, stack empty\n", line_number);
        exit(EXIT_FAILURE);
    }
    printf("%d\n", (*head)->n);
}

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

int checkopcode (char* lineptr, instruction_t *data, stack_t **head, int linenumber)
{
	char *tokens = NULL;
 tokens = strtok(lineptr, " ");
        if (strcmp(tokens,"push") == 0)
        {
        data->opcode = tokens;
        tokens = strtok(NULL, " ");
        if (tokens == NULL && (strcmp(tokens, "0")) != 0)
        {
fprintf(stderr, "L%d: usage: push integer\n", linenumber);
return (EXIT_FAILURE);
        }
        num = atoi(tokens);
        data->f = push;
        data->f(head, linenumber);
        }
        else if (strncmp(tokens,"pall",strlen("pall")) == 0)
        {
                if (strlen("pall") != strlen(tokens))
                {
                        fprintf(stderr,"L%d: unknown instruction %s\n",linenumber ,tokens);
                        return(EXIT_FAILURE);
                }
            data->opcode = "pall";
            data->f = pall;
            data->f(head, linenumber);
        }
        else if (strncmp(tokens,"pint",strlen("pint")) == 0)
        {
                if (strlen("pint") != strlen(tokens))
                {
                        fprintf(stderr,"L%d: unknown instruction %s\n",linenumber ,tokens);
                        return(EXIT_FAILURE);
                }
	data->opcode = "pint";
	data->f = pint;
        pint(head, linenumber);
	}
return (0);
}

