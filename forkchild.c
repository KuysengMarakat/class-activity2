#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
    pid_t pid;

    // Create child process
    pid = fork();

    if (pid < 0) {
        // Error in fork
        perror("fork failed");
        exit(1);
    }

    if (pid == 0) {
        // Child process
        printf("This is the child process. Running 'ls'...\n");

        // Replace child process with ls
        execl("/bin/ls", "ls", "-l", NULL);

        // If execl fails
        perror("execl failed");
        exit(1);
    } else {
        // Parent process
        printf("This is the parent process. Child PID = %d\n", pid);
    }

    return 0;
}
