#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdlib.h>

int main() {
    pid_t child1, child2, child3;

    // Create first child
    child1 = fork();

    if (child1 == 0) {
        printf("Child 1: PID = %d\n", getpid());
        sleep(2);
        printf("Child 1 finished.\n");
        exit(10);
    }

    // Create second child
    child2 = fork();

    if (child2 == 0) {
        printf("Child 2: PID = %d\n", getpid());
        sleep(4);
        printf("Child 2 finished.\n");
        exit(20);
    }

    // Create third child
    child3 = fork();

    if (child3 == 0) {
        printf("Child 3: PID = %d\n", getpid());
        sleep(1);
        printf("Child 3 finished.\n");
        exit(30);
    }

    // Parent waits for a specific child
    waitpid(child2, NULL, 0);
    printf("Parent: Child 2 completed using waitpid().\n");

    // Parent waits for remaining children
    wait(NULL);
    wait(NULL);

    printf("All child processes completed.\n");

    return 0;
}
