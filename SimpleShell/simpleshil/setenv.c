#include"main.h"
int _setenv(const char *name, const char *value, int write)
{
int i, len = 0, len2 = 0;
char *newvar;

if (name == NULL || value == NULL)
{
return (-1);
}

len = _strlen((char *)name);
len2 = _strlen((char *)value);
while (environ[i])
{
if (strncmp(environ[i], name, len) == 0)
{
if (write)
{
newvar = malloc(len + len2 + 2);
                _strcpy(newvar, name);
                _strcat(newvar, "=");
                _strcat(newvar, (char*)value);
                environ[i] = newvar;
                return (0);
            }
        }
        i++;
    }

    newvar = malloc(len + len2 + 2);
    _strcpy(newvar, name);
    _strcat(newvar, "=");
    _strcat(newvar, (char*)value);
    environ[i] = newvar;
    environ[i + 1] = NULL;
    return (0);
}
