#include <stdio.h>
#include <unistd.h>

int main() {
    int p_id;
    int status;
    int return_code = 0;

    p_id = fork();
    printf("process %d created\n",p_id);
    if (p_id == 0 ) {
        printf("process %d nothing to do\n",p_id);
    }
    else {
        if (p_id != -1) {
            printf("process %d sleep\n",p_id);
            sleep(60);
            return_code = 1;
        }
    }
    printf("process %d end\n",p_id);
    return return_code;
}