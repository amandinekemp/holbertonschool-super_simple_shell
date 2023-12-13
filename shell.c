#include "main.h"
/**
* main - Creates 5 child processes, each executing the command "ls -l /tmp".
* Each child process is created by the same parent process. The parent waits
* for each child to finish before creating the next one.
*
* Return: 0 on success, 1 if fork fails.
*/
int main(void)
{
	for (int i = 0; i < 5; i++)

	{
		pid_t pid = fork();
		/* This block will be run by the child process */
		if (pid == 0)
		{
			char *argv[] = {"/bin/ls", "-l", "/tmp", NULL};

			if (execve(argv[0], argv, NULL) == -1)
			{
				perror("Error:");
			}
			exit(0);
		}
		/* This block will be run by the parent process */
		else if (pid > 0)
		{
			/* Wait for the child to finish */
			wait(NULL);
		}
		/* Fork failed */
		else
		{
			perror("Error:");
			return (1);
		}
	}

	return (0);
}
