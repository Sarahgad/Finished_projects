#include "main.h"
/**
*handle_path - handle the path
*@command: string
*Return: argv always success
*/
char *handle_path(char *command)
{
char *command_path;
char *path;
char *dir;

if (access(command, X_OK) == 0)
{
/*check the command is fullpath*/
return (command);
}
path = _getenv("PATH");
if (path == NULL)
{
/* Split the path */
exit(-1);
}
for (dir = strtok(path, ":"); dir != NULL; dir = strtok(NULL, ":"))
{
/*Build the full path to the command */
command_path = malloc(strlen(path) + strlen(command) + 2);
if (command_path == NULL)
{
perror("malloc");
exit(1);
}
_strcpy(command_path, dir);
_strcat(command_path, "/");
_strcat(command_path, command);
/* Check if command exists */
if (access(command_path, X_OK) == 0)
{
return (command_path);
}
else
{
free(command_path);
/* Free memory if access fails */
}
}
/* Command not found in any directory */
exit(-1);
}
