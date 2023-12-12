#include <stdio.h>
#include <stdlib.h>

/**
* main - Prompts the user for input and prints the input received
*
* This function prints a "$ " prompt, waits for the user to enter a command,
* then prints the entered command on the next line. This process is done once,
* the program exits after printing the user's input or if an end-of-file (EOF)
* condition is encountered, typically when the user presses Ctrl+D.
*
* Return: 0 on successful execution
*/
int main(void)
{
	char *line = NULL;

	size_t len = 0;
	ssize_t read;

	printf("$ ");
	read = getline(&line, &len, stdin);

	if (read != -1)
		printf("%s", line);

	free(line);
	return (0);
}
