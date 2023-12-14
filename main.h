#ifndef MAIN_H
#define MAIN_H

/* Libraries */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

/* System call libraries */
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>

/* Function prototypes */
char **split_string(char *str);
extern char **environ;

int _setenv(const char *name, const char *value, int overwrite);
int _unsetenv(const char *name);

void print_path_directories(void);
int _strcmp(char *s1, char *s2);
char *_strcat(char *dest, char *src);
char *_strdup(char *str);
char *_strtok(char *str, char *delim);
int _strlen(char *s);
char *_strcpy(char *dest, char *src);
char *_strchr(char *s, char c);
int _strncmp(char *s1, char *s2, int n);
char *_strchr(char *s, char c);
char *_strpbrk(char *s, char *accept);
char *_strstr(char *haystack, char *needle);
char *_strncat(char *dest, char *src, int n);
char *_memset(char *s, char b, unsigned int n);
char *_memcpy(char *dest, char *src, unsigned int n);
int _atoi(char *s);
int _putchar(char c);


/* Global variables ? */
extern char **environ;

#endif /* MAIN_H */
