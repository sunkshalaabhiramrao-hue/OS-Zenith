#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdlib.h>

int main() {
    pid_t pid;

    printf("Before fork()\n");

    pid = fork();

    if (pid < 0) {
        perror("Fork failed");
        return 1;
    }

    if (pid == 0) {
        // Child process
        printf("\n--- Child Process ---\n");
        printf("PID  : %d\n", getpid());
        printf("PPID : %d\n", getppid());

        printf("Child is running...\n");
        sleep(3);

        printf("Child process terminating.\n");
        exit(0);
    } 
    else {
        // Parent process
        printf("\n--- Parent Process ---\n");
        printf("PID  : %d\n", getpid());
        printf("Child PID : %d\n", pid);

        printf("Parent is waiting for child...\n");

        wait(NULL);

        printf("Child has terminated.\n");
        printf("Parent process terminating.\n");
    }

    return 0;
}
