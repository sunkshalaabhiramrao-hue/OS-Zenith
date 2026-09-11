#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/stat.h>

#define REQUEST_FIFO "server_req_fifo"

typedef struct {
    pid_t client_pid;
    char message[256];
} Message;

int main() {
    pid_t pid = getpid();
    char client_fifo[64];
    snprintf(client_fifo, sizeof(client_fifo), "reply_%d", pid);

    // Create private response FIFO for this client
    mkfifo(client_fifo, 0666);

    Message msg;
    msg.client_pid = pid;
    printf("Enter message to send to server: ");
    if (fgets(msg.message, sizeof(msg.message), stdin) != NULL) {
        msg.message[strcspn(msg.message, "\n")] = 0; // Strip trailing newline
    }

    // Send payload to main request FIFO
    int req_fd = open(REQUEST_FIFO, O_WRONLY);
    if (req_fd < 0) {
        perror("Failed to open server request FIFO");
        unlink(client_fifo);
        exit(1);
    }
    write(req_fd, &msg, sizeof(Message));
    close(req_fd);

    // Wait and read processing result from client-specific pipe
    int resp_fd = open(client_fifo, O_RDONLY);
    char response[256];
    read(resp_fd, response, sizeof(response));
    printf("[Client %d] Processed Response: %s\n", pid, response);

    close(resp_fd);
    unlink(client_fifo); // Clean up private FIFO
    return 0;
}
