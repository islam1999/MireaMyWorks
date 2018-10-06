#include <stdio.h>
#include <string.h>
#include <malloc.h>

int BMsearch(char* str, const char* word) {
    int N = strlen(str);
    int M = strlen(word) -1;

    int d[256];
    int i;
    for (i = 0; i < 256; i++)
        d[i] = M;

    for (i = 0; i < M - 1; i++)
        d[(unsigned char) word[i]] = M - i - 1;

    int result = -1;
    for (i = M; i <= N; i += d[(unsigned char) str[i - 1]]) {
        int j, k;
        for (j = M - 1, k = i - 1; j >= 0 && str[k] == word[j]; k--, j--);
        if (j < 0) {
            result = i - M;
            break;
        }
        if (i == N) {
            result = -1;
            break;
        }
    }
    return result;
}

int FileStringSearcher(int argc, char *argv[]) {

    FILE *file = NULL;
    size_t size = sizeof(char) * 2048;
    char *filename = NULL;

    if (argc < 2 || (file = fopen(argv[1], "r") ) == NULL) {
        while (!file) {
            printf("Write filename:\n");
            getline(&filename, &size, stdin);

            filename[strlen(filename)-1]= '\0';
            file = fopen(filename, "r");

            if (file == NULL) {
                printf("Error: the file not found!\n");
            }
        }
        free(filename);
    }
    printf("Success: File opened!\n");

    int row = 0;
    int column = -1;
    char *line = malloc(size);
    char *input = NULL;

    if (argc > 2) {
        input = argv[2];
    } else {
        printf("Write string for search:\n");
        getline(&input, &size, stdin);
    }

    printf("Success: Start searching...\n");

    while (fgets(line, size, file) != NULL) {
        row++;
        column = BMsearch(line, input);

        if (column != -1)
            break;
    }

    if (column == -1) {
        printf("Not found\n");
    } else {
        printf("File string:%sYour string:%s\n", line, input);
        printf("Row: %d\n""Column: %d\n", row, ++column);
    }
    free(line);
    free(input);
    fclose(file);
    return 0;
}