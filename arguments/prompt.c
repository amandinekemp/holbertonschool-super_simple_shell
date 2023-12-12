#include <stdio.h>
#include <stdlib.h>

/**
* main - Continuously prompts the user for input and prints the input received
*
* This function prints a "$ " prompt, waits for the user to enter a command,
* and then prints the entered command on the next line. This process repeats
* until an end-of-file (EOF) condition is encountered, typically when the user
* presses Ctrl+D.
*
* Return: 0 on successful execution
*/
int main(void)
{
	char *line = NULL;

	size_t len = 0;
	ssize_t read;

	while (1)
	{
		printf("$ ");
		read = getline(&line, &len, stdin);

		if (read == -1)
		{
			break;
		}
		printf("%s", line);
		system(line);
	}

	free(line);
	return (0);
}
