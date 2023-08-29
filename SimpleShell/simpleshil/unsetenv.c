#include"main.h"

int _unsetenv(const char *name)
{
    int i, j, len = 0;

    if (name == NULL)
        return (-1);

    while (environ[i])
    {
        len = _strlen((char *)name);
        if (strncmp(environ[i], name, len) == 0 && environ[i][len] == '=')
        {
            for (j = i; environ[j]; j++)
                environ[j] = environ[j + 1];
            return (0);
        }
        i++;
    }

    return (-1);
}


