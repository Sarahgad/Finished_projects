#include"main.h"
    char *lineptr = NULL;
        char **argv;
void interact()
{

    size_t n = 0;
    ssize_t nreads;
    int status;
    pid_t pid;

    argv = malloc(sizeof(char*) * MAX_ARGS);
    if (argv == NULL) {
        perror("malloc");
        exit(EXIT_FAILURE);
    }

   signal(SIGINT, sigint_handler);

    while (1) {
        write(1, "$ ", 2);

        nreads = getline(&lineptr, &n, stdin);
        if (nreads == -1) {
            perror("getline");
            exit(EXIT_FAILURE);
        }

        lineptr[_strlen(lineptr) - 1] = '\0';
	    argv = strcut(lineptr);
        if (argv == NULL)
        {
            perror("argv");
            exit(EXIT_FAILURE);
        }
        checkcommand(argv, lineptr);
        _execve(argv);
        free(argv);
    }

        free(lineptr);
        lineptr = NULL;
        argv[0] = NULL;
    free(argv);
}

void sigint_handler(int signum) 
{

	if (signum == SIGINT) {

        free(lineptr);
        lineptr = NULL;
        free(argv);
        exit(EXIT_SUCCESS);
	}
}

