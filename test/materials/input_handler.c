#include "shell.h"

/*@a:reads input from the user
*b:prints a new line if end of file 
*@c: exits script if no input
*/

void read_instruct(char *instruct, size_t size) {
    if (fgets(instruct, size, stdin) == NULL) {
        if (feof(stdin)) {
            shell_print_f("\n");
            exit(EXIT_SUCCESS);
        } else {
            shell_print_f("Error while reading input.\n");
            exit(EXIT_FAILURE);
        }
    }
    instruct[strcspn(instruct, "\n")] = '\0'; // Remove newline
}
