#include <stdio.h>
#include <unistd.h>

int main(void) {
    FILE *fp;
    fp = fopen("ostest01.log","a");
    
    while(1) {
        fprintf(fp,"Hello\n");
        sleep(5);
    }
    fclose(fp);
}
