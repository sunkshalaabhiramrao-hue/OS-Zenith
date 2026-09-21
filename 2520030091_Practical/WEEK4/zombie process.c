#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
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
        printf("Parent is sleeping...\n");
        sleep(20);
        printf("Parent process terminating\n");
    }
    return 0;
}
