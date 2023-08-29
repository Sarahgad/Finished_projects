#include "main.h"

int process_unsetenv_command()
{
char *name = "MY_VAR";
char *value = "my_value";
char *env_value;

/*Declare env_value at the beginning of the function */

/* Set the environment variable*/
if (_setenv(name, value, 1) != 0)
{
printf("Failed to set environment variable\n");
return (1);
}

/* Get the value of the environment variable */
env_value = getenv(name);
if (env_value == NULL)
{
printf("Environment variable not found\n");
return (1);
}
printf("%s=%s\n", name, env_value);

/* Unset the environment variable*/
if (_unsetenv(name) != 0)
{
printf("Failed to unset environment variable\n");
return (1);
}

/* Check that the environment variable is unset */
env_value = getenv(name);
if (env_value != NULL)
{
printf("Environment variable still set\n");
return (1);
}
printf("%s unset\n", name);

return (0);
}
