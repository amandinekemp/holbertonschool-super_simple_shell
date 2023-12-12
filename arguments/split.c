#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
* split_string - Splits a string into words
* @str: The string to split
*
* Return: An array of words. Note that the caller is responsible for freeing
* the memory for the array and the words.
*/
char **split_string(char *str)
{
	char **words = malloc(sizeof(char *) * (strlen(str) / 2 + 1));

	char *word = strtok(str, " ");

	int i = 0;

	while (word != NULL)
	{
		words[i] = malloc(strlen(word) + 1);
		strcpy(words[i], word);
		word = strtok(NULL, " ");
		i++;
	}
	words[i] = NULL;  /*Null-terminate the array*/
	return (words);
}
