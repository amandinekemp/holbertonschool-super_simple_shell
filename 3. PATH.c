#include "main.h"

/**
 * print_path_directories - prints all the directories in the PATH
 * 
 * Return: void
 */

void print_path_directories(void)
{
    char *path = getenv("PATH");
    char *path_copy = strdup(path);
    char *token = strtok(path_copy, ":");

    while (token != NULL) {
        printf("%s\n", token);
        token = strtok(NULL, ":");
    }

    free(path_copy);
}

/**
 * main - calls the print_path_directories function
 * 
 * Return: 0 if successful
 */

int main(void)
{
    print_path_directories();
    return 0;
}
