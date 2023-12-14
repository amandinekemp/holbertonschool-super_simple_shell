#include "main.h"

/**
 * This program modifies environment variables using a custom _setenv function.
 * Ce programme modifie les variables d'environnement à l'aide d'une fonction _setenv personnalisée.
 * 
 * Return: Always 0.
 */

/* Declare the environ variable which is a pointer to an array of environment variables. */
extern char **environ;

/* Define the _setenv function which sets the value of an environment variable. */
int _setenv(const char *name, const char *value, int overwrite)
{

	char **ep;

	size_t namelen;

	/* Get the length of the name. */
	namelen = strlen(name);
	/* Loop through the environment variables. */
	for (ep = environ; *ep != NULL; ++ep)
	{
		/* If the current environment variable is the one we're looking for... */
		if (!strncmp(*ep, name, namelen) && (*ep)[namelen] == '=')
		{
			/*If overwrite is non-zero, change the value of the environment variable.*/
			if (overwrite)
			{
				char *new_value = malloc(namelen + strlen(value) + 2);

				if (new_value == NULL)
				{
					return (-1);
				}
				strcpy(new_value, name);
				strcat(new_value, "=");
				strcat(new_value, value);
				*ep = new_value;
			}
			return (0);
		}
	}

	/* If the environment variable doesn't exist, add a new one. */
	char **new_environ = malloc((ep - environ + 2) * sizeof(char *));

	if (new_environ == NULL)
	{
		return (-1);
	}
	memcpy(new_environ, environ, (ep - environ) * sizeof(char *));
	new_environ[ep - environ] = malloc(namelen + strlen(value) + 2);
	if (new_environ[ep - environ] == NULL)
	{
		free(new_environ);
		return (-1);
	}
	strcpy(new_environ[ep - environ], name);
	strcat(new_environ[ep - environ], "=");
	strcat(new_environ[ep - environ], value);
	new_environ[ep - environ + 1] = NULL;
	environ = new_environ;

	return (0);
}
