#include "main.h"

/**
 * Structure for linked list nodes, each containing a directory and a pointer to the next node.
 * (Structure pour les nœuds d'une liste chaînée, chacun contenant un répertoire et un pointeur vers le nœud suivant.)
 * 
 * Return: 0
 */

typedef struct Node
{
	char *directory;

	struct Node *next;
} Node;

/*Function to create a new node with a given directory.*/
Node *create_node(char *directory)
{
	/*Allocate memory for a new node*/
	Node *node = malloc(sizeof(Node));
	/*Copy the directory string*/
	node->directory = strdup(directory);

	/*Set the next pointer to NULL*/
	node->next = NULL;
	return (node);
}

/* Function to create a linked list of directories from the PATH environment variable. */
Node *create_path_list(void)
{
	/* Get the PATH environment variable. */
	char *path = getenv("PATH");

	/* Make a copy of the PATH string. */
	char *path_copy = strdup(path);

	/* Tokenize the string on the ":" character. */
	char *token = strtok(path_copy, ":");

	/* Create a linked list of directories from the tokenized string. */
	Node *head = NULL;
	Node *tail = NULL;

	/*Iterate through the tokens and create nodes for each directory*/
	while (token != NULL)
	{
		/* Create a new node with the current directory*/
		Node *node = create_node(token);

		/* Add the node to the linked list. */
		if (head == NULL)
		{
			head = node;
			tail = node;
		} else
		{
			tail->next = node;
			tail = node;
		}

		/* Get the next token. */
		token = strtok(NULL, ":");
	}

	/* Free the copied string. */
	free(path_copy);
	return (head);
}

int main(void)
{
	/* Create a linked list of directories from the PATH environment variable. */
	Node *path_list = create_path_list();

	/* Print the directories in the list. */
	Node *node = path_list;
	{
		while (node != NULL)
		{
			printf("%s\n", node->directory);
			node = node->next;
		}

		/* Free the list. */
		node = path_list;
		while (node != NULL)
		{
			Node *next = node->next;
			free(node->directory);

			free(node);
			node = next;
		}

		return (0);
	}
	{
		printf("%s\n", node->directory);
		node = node->next;
	}

	/* Free the list. */
	node = path_list;
	while (node != NULL)
	{
		Node *next = node->next;
		free(node->directory);

		free(node);
		node = next;
	}

	return (0);
}
