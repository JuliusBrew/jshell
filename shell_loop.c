#include "shell_proto.h"


void shell(const char *command) {
    // Determine whether the shell is in interactive mode
    int interactive = isatty(STDIN_FILENO);

    char *input_buffer = NULL;
    size_t buffer_size = 0;

    while (1) {
        if (interactive) {
            // Display the prompt in interactive mode
            printf("$ ");
            fflush(stdout);
        }

        if (command == NULL) {
            // Read user input and dynamically allocate memory as needed
            ssize_t input_length = getline(&input_buffer, &buffer_size, stdin);

            if (input_length == -1) {
                // Handle EOF (Ctrl+D) in interactive mode
                if (interactive) {
                    printf("\n");
                }
                break;
            }

            // Remove the newline character from the input
            input_buffer[strcspn(input_buffer, "\n")] = '\0';

            // Check if the user entered "exit" to exit the shell
            if (strcmp(input_buffer, "exit") == 0) {
                if (interactive) {
                    printf("\n");
                }
                printf("Exiting the shell...\n");
                free(input_buffer); // Free dynamically allocated memory
                exit(0);
            }

            // Execute the command
            execute_command(input_buffer);
        } else {
            // Execute the provided command in non-interactive mode
            execute_command(command);
            break; // Exit the loop after executing the command
        }

        if (!interactive) {
            break; // Exit the loop in non-interactive mode after executing the command
        }

        // Free the input buffer
        free(input_buffer);
        input_buffer = NULL;
    }

    // Free dynamically allocated memory for the last command
    free(input_buffer);
}
