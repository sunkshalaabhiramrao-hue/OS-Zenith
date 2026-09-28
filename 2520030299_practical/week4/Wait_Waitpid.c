#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
int main()
{
    pid_t p1, p2;
    int status;
    p1 = fork();
    if(p1 == 0)
    {
        printf("Child 1: PID = %d\n", getpid());
        sleep(2);
        printf("Child 1 terminated\n");
        exit(10);
    }
    p2 = fork();
    if(p2 == 0)
    {
        printf("Child 2: PID = %d\n", getpid());
        sleep(4);
        printf("Child 2 terminated\n");
        exit(20);
    }
    printf("Parent: PID = %d\n", getpid());
    wait(&status);
    printf("Parent collected one child using wait()\n");
    waitpid(p2, &status, 0);
    printf("Parent collected Child 2 using waitpid()\n");
    printf("All child processes completed\n");
    return 0;
}
