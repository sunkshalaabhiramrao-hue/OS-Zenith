#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main() {
    pid_t pid;

    printf("--- Stage 1: Before Fork ---\n");
    printf("Parent Initial PID: %d ,PPID: %d\n\n", getpid(), getppid());

    pid = fork();

    if (pid < 0) {
        perror("Fork failed");
        return 1;
    }
    else if (pid == 0) {
        printf("--- Stage 2: Child Running ---\n");
        printf("Child  PID: %d  PPID: %d\n", getpid(), getppid());
        sleep(5);
        printf("Child Waking up and terminating execution.\n");
        exit(0);
    }
    else {
       
        printf("--- Stage 2: Parent Execution ---\n");
        printf("Parent PID: %d , Spawned Child PID: %d\n", getpid(), pid);
        printf("Parent Waiting for child to terminate...\n\n");

        wait(NULL);

        printf("--- Stage 3: Post-Termination ---\n");
        printf("Parent Child finished. Parent resuming and exiting.\n");
    }

    return 0;
}
