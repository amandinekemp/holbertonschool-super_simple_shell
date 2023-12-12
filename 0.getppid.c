#include <stdio.h>
#include <unistd.h>

int main(void)
{
    /* Déclare une structure qui contient le PPID parent */
    pid_t parent_pid;

    /* Attribue varibale ppid parent à la fonction getppid */
    pid_t parent_pid = getppid();
    printf("%u\n", parent_pid);
    return (0);

}
