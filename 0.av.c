#include "main.h"

/**
* main - prints all the arguments the program receives
* @ac: number of arguments
* @av: value of arguments
*
* Return: 0
*/

int main(int ac, char **av)
{
	int index;

	for (index = 0; index < ac; index++)
	{
		printf("%s\n", av[index]);
	}
	return (0);
}
