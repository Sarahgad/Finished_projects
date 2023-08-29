int _readfile(char *filename)
{
    instruction_t data;
    stackk_t *head = NULL;
    size_t n = 0;
    ssize_t nreads;
    int count = 0;
    int i ;
    char *lineptr = NULL;
    char **tokens;

    FILE *fp = fopen(filename, "r");
    if (fp == NULL)
        {
                printf("%s", filename);
        fprintf(stderr, "Error: Could not open file '%s': %s\n", filename, strerror(errno));
        exit(EXIT_FAILURE);
        }
        tokens = malloc(sizeof(char *)* 3000);
    while ((nreads = getline(&lineptr, &n, fp)) != -1)
    {
        if (nreads > 1)
        {
            lineptr[nreads - 1] = '\0';
            printf("line number %d : %s", count, lineptr);
                        count++;
        i = 0;   
          while (lineptr[i] != '\0')
            {
                if (strncmp("push", &lineptr[i], strlen("push")) == 0)
                    {
                        ;
                    }
                    else if (strncmp("pall", &lineptr[i], strlen("pull")) == 0)
              
            {
                        printf("oh no\n");
            }
                    
                else if (lineptr[i] >= '0' && lineptr[i] <= '9')
                    {
                        add_dnodeint_end(&head, atoi(&lineptr[i]));                      
                    }
            i++;
            }
        }

        
            else
        {
            perror("Error");
        }

    }
print_dlistint(head);


    free(lineptr);
    free(tokens);
    fclose(fp);
    return 0;
}
