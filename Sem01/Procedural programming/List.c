#include <stdio.h>
#include <string.h>
#include <dirent.h>

#define NAME_MAX 256

int List(int argc, char **argv)
{
    DIR *directory;
    struct dirent *dir;
    char file_name[NAME_MAX];
    if ( argc < 2 ){
        strcpy(file_name, ".");
    }
    else{
        strcpy(file_name, argv[1]);
    }
    printf("%s\n\n", file_name);
    directory=opendir(file_name);
    while( (dir=readdir(directory)) != NULL ){
        printf("%s\n", dir->d_name);
    }
    closedir(directory);
    return 0;
}
