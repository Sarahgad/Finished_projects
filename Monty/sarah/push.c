#include "monty.h"

int main(int argc, char **argv)
{
    int x;
    instruction_t data;
    stackk_t *head;

    data.opcode = NULL;
    data.f = NULL;
    head = NULL;
    if (argc == 2)
    {
    x = readfile(argv[1],data, &head);
    }
    else if (argc != 2)
    {
    fprintf(stderr, "USAGE: monty file\n");
    return (EXIT_FAILURE);
    }
    return 0;
}

int readfile(char *filename, instruction_t data, stackk_t **head)
{
    size_t n = 0;
    ssize_t nreads;
    int value;
    int linenumber = 1;
    int i;
    char *lineptr = NULL;
    char **tokens = NULL;
    FILE *fp = fopen(filename, "r");

    if (fp == NULL)
        {
        fprintf(stderr, "Error: Can't open file %s\n", filename);
        exit(EXIT_FAILURE);
        }
        tokens = malloc(sizeof(char *)* 3000);

    while ((nreads = getline(&lineptr, &n, fp)) != -1)
    {
        i = 0;
        tokens[i] = strtok(lineptr, " \n");
        if (strcmp(tokens[i],"push") == 0)
        {
        data.opcode = tokens[i];
        i++;
        tokens[i]= strtok(NULL, " \n");
        if (tokens[i] == NULL)
        {
            fprintf(stderr, "L%d: usage: push integer\n", linenumber);
            return (EXIT_FAILURE);
        }
        value = atoi(tokens[i]);
        data.f = push;
        data.f(head, linenumber);
        }
        else if (strcmp(tokens[i],"pall") == 0)
        {
            data.opcode = "pall";
            data.f = pall;
            data.f(head, linenumber);
        }
        else if (strcmp(tokens[i],"pint") == 0)
        {
        data.opcode = "pint";
        data.f = pint;
        data.f(head, linenumber);
        }
        linenumber ++;
    }


    free(lineptr);
    free(tokens);
    fclose(fp);
    return 0;
}

