#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
    char cmd[100];
    printf("Enter a Linux command (e.g., ls): ");
    scanf("%s", cmd);

    pid_t pid = fork();

    if (pid == 0) { // Child process
        printf("Child PID: %d\n", getpid());
        execlp(cmd, cmd, NULL);
        perror("Exec failed"); 
        exit(1);
    } else if (pid > 0) { // Parent process
        printf("Parent PID: %d\n", getpid());
        wait(NULL); // Wait for child
        printf("Child process finished.\n");
    } else {
        printf("Fork failed!\n");
    }
    return 0;
}


