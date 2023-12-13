#include "main.h"

/**
* main - program that prints the address of env and environ
*
* Return: Always 0.
*/

extern char **environ;

int main(int argc, char *argv[], char *env[])
{

	printf("Address of env: %p\n", env);
	printf("Address of environ: %p\n", environ);

	return (0);
}
