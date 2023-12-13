#include "main.h"

/**
 * main - Prints all the environment variables.
 *
 * Description: The function uses the global variable 'environ' to access
 * the environment variables. It iterates through each environment variable
 * and prints it to the standard output.
 *
 * Return: 0 if successful, non-zero otherwise.
 */


extern char **environ;

int main(void)
{
	char **env = environ;

	while (*env)
	{
		printf("%s\n", *env);
		env++;
	}

	return (0);
}
