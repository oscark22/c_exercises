#include <stdio.h>
#include <string.h>
#include <dirent.h>

int main(void) {
    DIR *dir;
    FILE *file;
    double max=0;
    struct dirent *ent;
    char ruta[100];
    printf("Write a route to visualize\n");
    scanf("%s", ruta);
    if ((dir = opendir(ruta)) != NULL) {
        while ((ent=readdir(dir)) != NULL) {
            if (strstr(ent->d_name, ".txt")) {
                if ((file=fopen(ent->d_name, "r")) != NULL) {
                    while(!feof(file)) {
                        char c = fgetc(file);
                        printf("%c", c);
                    }
                }
                fclose(file);
            }
        }
        closedir(dir);
    } else {
        perror("Couldn't open the location: (");
        return 0;
    }
    return 1;
}
