#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <stdlib.h>
int main()
{
    pid_t pid;
    printf("Before fork: PID = %d, PPID = %d\n", getpid(), getppid());
    pid = fork();
    if(pid == 0)
    {
        printf("Child Process\n");
        printf("Child PID = %d\n", getpid());
        printf("Child PPID = %d\n", getppid());
        printf("Child is running\n");
        sleep(5);
        printf("Child is terminating\n");
        exit(0);
    }
    else
    {
        printf("Parent Process\n");
        printf("Parent PID = %d\n", getpid());
        printf("Parent PPID = %d\n", getppid());
        printf("Parent is waiting\n");
        sleep(10);
        printf("Parent is terminating\n");
    }
    return 0;
}
