#include <stdio.h>
#include <unistd.h>

/**
 * main - the function return the PID
 * Return: Always 0.
 */
int main(void)
{
    pid_t my_pid;

    my_pid = getpid();
    printf("%u\n", my_pid);
    return (0);
}