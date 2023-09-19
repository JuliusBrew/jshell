#include "shell_proto.h"


int main(int argc, char *argv[]) {
    if (argc == 1) {
        // Interactive mode
        shell(NULL);
    } 
    if (argc == 3 && strcmp(argv[1], "-c") == 0) {
        // Non-interactive mode with a command
        shell(argv[2]);
    } else {
        // Invalid command-line arguments
        fprintf(stderr, "%s:%s: not found\n", argv[0],argv[2]);
        exit(EXIT_FAILURE);
    }

    return 0;
}
