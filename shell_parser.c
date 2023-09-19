#include "shell_proto.h"

void execute_command(const char *command) {
    pid_t child_pid;
    int status;

    child_pid = fork();
    if (child_pid == -1) {
        perror("fork");
        return;
    }

    if (child_pid == 0) {
        // Child process
        // Create a non-const copy of the command
        char *command_copy = strdup(command);

        if (command_copy == NULL) {
            perror("strdup");
            exit(EXIT_FAILURE);
        }

        char *args[] = {"./hsh", "-c", command_copy, NULL};

        // Pass the environ variable to execve
        execve(args[0], args, environ);

        // If execve fails, print an error message
        perror("execve");
        free(command_copy); // Free the copy of the command
	fprintf(stderr, "%s: %s: not found\n", args[0], args[2]);
        exit(EXIT_FAILURE);
    } else {
        // Parent process
        waitpid(child_pid, &status, 0);
    }
}

