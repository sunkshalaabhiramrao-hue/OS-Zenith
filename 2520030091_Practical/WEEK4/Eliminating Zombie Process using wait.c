#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
int main()
{
    pid_t pid;
    pid = fork();
    if(pid == 0)
    {
        printf("Child process: PID = %d\n", getpid());
        printf("Child process terminating\n");
        exit(0);
    }
    else
    {
        printf("Parent process: PID = %d\n", getpid());
        printf("Child PID = %d\n", pid);
        wait(NULL);
        printf("Parent collected child using wait()\n");
        printf("Zombie process eliminated\n");
    }
    return 0;
}
