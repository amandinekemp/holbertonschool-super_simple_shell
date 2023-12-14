#include "main.h"

/**
 * _unsetenv - removes an environment variable
 *
 * This program removes an environment variable
 * using a custom _unsetenv function.
 * Ce programme supprime une variable d'environnement
 * à l'aide d'une fonction _unsetenv personnalisée
 *
 * _unsetenv - removes an environment variable
 *
 * Return: 0 successful, -1 error
 */

extern char **environ;

int _unsetenv(const char *name)
{
	char **ep;

	size_t namelen;

	namelen = strlen(name);
	for (ep = environ; *ep != NULL; ++ep)
	{
		if (!strncmp(*ep, name, namelen) && (*ep)[namelen] == '=')
		{
			/* Shift all following variables up by one to overwrite the current one. */
			for (char **dp = ep; *dp != NULL; ++dp)

			{
				*dp = *(dp + 1);
			}
			return (0);
		}
	}

	/* If the environment variable was not found, return -1. */
	return (-1);
}
