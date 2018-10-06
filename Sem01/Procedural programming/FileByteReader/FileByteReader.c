#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {

    if(argc != 2)
        return -1;

    FILE *file = NULL;
    file = fopen(argv[1], "rb");

    char *filename = NULL;

    while (!file) {
        printf("Write filename:\n");
        getline(&filename, 0, stdin);

        file = fopen(filename, "rb");
        if (file == NULL) {
            printf("Error: this file doesn't exist!\n");
        }
    }
    printf("Success: File opened!\n");

    unsigned long file_size = 0;
    int x,y,i;
    while(!feof(file)) {
        int buffer[1024];
        size_t rd_bt = fread(buffer, sizeof(char), 1023, file);
        buffer[rd_bt] = '\0';
        file_size += rd_bt;

        for (i = 0, x = 0, y = 0; i < rd_bt; i++, x++, y++) {
            if (y == 36) {
                printf("\n");
                y = 0;
            }
            if (x == 4) {
                printf("\t");
                x = 0;
            }
            printf("%d", buffer[i]);
        }

    }
    printf("\nSize in byte: %lu\n", file_size);

    free(filename);
    fclose(file);
    return 0;
}