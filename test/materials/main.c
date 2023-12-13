#include "shell.h"

/*@a: display prompt
 *@b: read the instruct or command line
 *@c: execute the instruct
 */

int main(void) {
    char instruct[130];

    while (true) {
        display_prompt();
        read_instruct(instruct, sizeof(instruct));
        execute_instruct(instruct);
    }


    return 0;
}
