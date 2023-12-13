#include "main.h"

/**
 * _getenv - gets the value of an environment variable
 * @name: name of the environment variable
 *
 * Return: pointer to the value of the environment variable
 * or NULL if there is no match
 */

extern char **environ;

char *_getenv(const char *name)
{
    int i = 0;
    int len = strlen(name);

    while (environ[i])
    {
        if (strncmp(environ[i], name, len) == 0 && environ[i][len] == '=')
        {
            return &environ[i][len + 1];
        }
        i++;
    }
    return NULL;
}
