
#include <stdio.h>
#include <stdlib.h>

int main() {
    char buffer[128];
    FILE *fp = popen("ls -1 --color=auto", "r");

    if (fp == NULL) {
        perror("popen failed");
        return 1;
    }

    while (fgets(buffer, sizeof(buffer), fp) != NULL) {
        printf("%s", buffer);
    }

    pclose(fp);
    return 0;
}
