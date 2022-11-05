#include <stdio.h>
#include <dirent.h>

int main(void) {
    DIR *dir;
    struct dirent *ent;
    char ruta[100];
    printf("Write a route to visualize\n");
    scanf("%s", ruta);
    if ((dir = opendir(ruta)) != NULL) {
        while ((ent=readdir(dir)) != NULL) {
            printf("%20s %s\n", ent->d_name, ent->d_type==DT_REG ? "File" : "Directory");
        }
        closedir(dir);
    } else {
        perror("Couldn't open the location: (");
        return 0;
    }
    return 1;
}
