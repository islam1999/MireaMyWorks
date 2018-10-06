#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>
#include <mem.h>
#include <stdarg.h>


/*******************************************************************************************************************/
const int LIMIT_SIZE = 4;
const int LIMIT_VALUE = 10;

typedef struct matrix {
    int row;
    int column;
    double **array;
} Matrix;

void mt_Reverse(Matrix *mt);

void mt_Print(Matrix *mt);

void mt_DeleteMinimum(Matrix *mt);

int mt_ReInput(Matrix *mt);

Matrix mt_Create_with_input();

int asprintf(char **str, const char *fmt, ...);

int vasprintf(char **str, const char *fmt, va_list args);

Matrix mt_Multiply(Matrix *mt01, Matrix *mt02);

/*******************************************************************************************************************/
int matrix() {
    srand((unsigned int) time(NULL));

    Matrix mt01;
    mt01.row = 5 + rand() % LIMIT_SIZE;
    mt01.column = 4 + rand() % LIMIT_SIZE;
    mt01.array = (double **) malloc(sizeof(double *) * mt01.row);

    int i, j;
    for (i = 0; i < mt01.row; i++) {
        mt01.array[i] = (double *) malloc(sizeof(double) * mt01.column);
        for (j = 0; j < mt01.column; j++) {
            mt01.array[i][j] = rand() % LIMIT_VALUE;
        }
    }

    mt_Print(&mt01);

    mt_Reverse(&mt01);
    mt_Print(&mt01);

    mt_DeleteMinimum(&mt01);
    mt_Print(&mt01);

    Matrix mt02 = mt_Create_with_input();
    mt_Print(&mt02);

    mt01 = mt_Multiply(&mt01, &mt02);
    mt_Print(&mt01);
    return 0;
}

/*******************************************************************************************************************/
void mt_Reverse(Matrix *mt) {
    int j;
    for (j = 0; j < mt->column; j++) {
        double tmp = mt->array[0][j];
        mt->array[0][j] = mt->array[mt->row - 1][mt->column - 1 - j];
        mt->array[mt->row - 1][mt->column - 1 - j] = tmp;
    }
}

void mt_Print(Matrix *mt) {
    int i, j;
    if (mt->array) {
        for (i = 0; i < mt->row; i++) {
            for (j = 0; j < mt->column; j++) {
                printf("%5.2lf  ", mt->array[i][j]);
            }
            printf("\n");
        }
        printf("\n");
    } else printf("Error: no matrix\n");
}

void mt_DeleteMinimum(Matrix *mt) {
    double min = mt->array[0][0];
    int miny = 0;
    int minx = 0;
    int i, j;

    for (i = 0; i < mt->row; i++) {
        for (j = 0; j < mt->column; j++) {
            if (mt->array[i][j] < min) {
                min = mt->array[i][j];
                minx = i;
                miny = j;
            }
        }
    }

    Matrix mt_tmp;
    mt_tmp.column = mt->column - 1;
    mt_tmp.row = mt->row - 1;

    mt_tmp.array = (double **) malloc(sizeof(double *) * mt_tmp.row);
    for (i = 0; i < mt_tmp.row; i++) {
        mt_tmp.array[i] = (double *) malloc(sizeof(double) * mt_tmp.column);
    }

    int n, m;
    for (i = 0, n = 0; i < mt->column; i++, n++) {
        if (i == miny) {
            n--;
            continue;
        }
        for (j = 0, m = 0; j < mt->row; j++, m++) {
            if (j == minx) {
                m--;
                continue;
            }
            mt_tmp.array[m][n] = mt->array[j][i];
        }
    }

    for (i = 0; i < mt->row; i++) {
        free(mt->array[i]);
    }
    free(mt->array);

    mt->row--;
    mt->column--;

    mt->array = mt_tmp.array;
}

Matrix mt_Multiply(Matrix *mt01, Matrix *mt02) {
    Matrix mt;
    if (mt01->column != mt02->row)
        return mt;

    mt.row = mt02->row;
    mt.column = mt02->column;

    mt.array = (double **) malloc(sizeof(double *) * mt.row);
    int i, j;
    for (i = 0; i < mt.row; i++) {
        mt.array[i] = (double *) malloc(sizeof(double) * mt.column);
        for (j = 0; j < mt.column; j++) {
            mt.array[i][j] = 0;
        }
    }

    int m = 0;
    for (i = 0; i < mt.row; ++i) {
        for (j = 0; j < mt.column; ++j) {
            for (m = 0; m < mt01->row; ++m) {
                mt.array[i][j] += mt01->array[i][m] * mt02->array[m][j];
            }
        }
    }
    return mt;
}


int mt_ReInput(Matrix *mt) {
    char *input = malloc(sizeof(char));
    char buf;
    int size_elem = 0;
    int i = 0;
    int j = 0;
    do {
        if (i > mt->column || j > mt->row) {
            printf("ERROR: i(j) >= row(column)\n");
            return 1;
        }
        buf = (char) getchar();
        if (isdigit(buf)) {
            *(input + size_elem) = buf;
            size_elem++;
        } else if (buf == ' ' || buf == '.') {
            if (size_elem > 0) {
                mt->array[i][j++] = strtod(input, NULL);
                input += size_elem;
                size_elem = 0;
            }
        } else if (buf == ',') {
            j = 0;
            i++;
        }

    } while (buf != '.');
    return 0;
} /* изменение готовой матрицы */

Matrix mt_Create_with_input() {
    char *input = NULL;
    char *line = "";
    char *temp = NULL;
    unsigned int row = 1;
    unsigned int column = 0;
    unsigned int max_col = 1;
    unsigned int i;
    unsigned int len;
    unsigned int end = 1;
    size_t size = sizeof(char) * 128;

    do {
        getline(&input, &size, stdin);
        len = strlen(input);
        for (i = 0; i < len; i++) {
            if (isdigit(input[i])) {
                double t = strtod(input + i, &temp);
                column++;
                i += (int) (temp - (input + i));
                if (*(temp - 1) == '.') {
                    end = 0;
                    break;
                } else if (*(temp) == ',') {
                    row++;
                    column = 0;
                }
            } else if (input[i] == ',') {
                row++;
                column = 0;
            } else if (input[i] == '.') {
                end = 0;
                break;
            }
        }
        if (column > max_col)
            max_col = column;
        if (input[len - 2] == '.') {
            end = 0;
            input[len - 2] = ' ';
            input[len - 1] = '.';
        } else input[len - 1] = ' ';
        asprintf(&line, "%s %s", line, input);
    } while (end == 1);
    free(input);

    column = max_col;

    Matrix mt;
    mt.row = row;
    mt.column = column;

    printf("Current row: %d \nCurrent column: %d\n", row, column);

    mt.array = (double **) malloc(sizeof(double *) * mt.row);
    for (i = 0; i < mt.row; i++) {
        mt.array[i] = (double *) malloc(sizeof(double) * mt.column);
        int j;
        for (j = 0; j < mt.column; j++) {
            mt.array[i][j] = 0;
        }
    }

    for (row = 0, column = 0, i = 0; i < strlen(line); ++i) {
        if (isdigit(line[i])) {
            mt.array[row][column++] = strtod(line + i, &temp);
            i += (int) (temp - (line + i));
            if (*(temp) == ',') {
                row++;
                column = 0;
            }
        } else if (line[i] == ',') {
            row++;
            column = 0;
        }
    }
    return mt;
}

/* функции для сложения строк */
int asprintf(char **str, const char *fmt, ...) {
    int size = 0;
    va_list args;

    va_start(args, fmt);

    size = vasprintf(str, fmt, args);

    va_end(args);

    return size;
}

int vasprintf(char **str, const char *fmt, va_list args) {
    int size = 0;
    va_list tmpa;

    va_copy(tmpa, args);

    size = vsnprintf(NULL, size, fmt, tmpa);

    va_end(tmpa);

    if (size < 0) { return -1; }

    *str = (char *) malloc((size + 1));

    if (NULL == *str) { return -1; }

    size = vsprintf(*str, fmt, args);
    return size;
}