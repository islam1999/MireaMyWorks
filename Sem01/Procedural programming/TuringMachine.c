#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define DEFAUlT_SIZE 10
#define RESIZING_COEFFICIENT 1.5


typedef struct turing_tape_s {
    unsigned char *array_plus;
    unsigned char *array_minus;
    unsigned long int size_plus;
    unsigned long int size_minus;
    int sign_of_array;
    unsigned long int current_element;
} turing_tape;

char *Cmovl = "movl";
char *Cmovr = "movr";
char *Cinc = "inc";
char *Cdec = "dec";
char *Cprint = "print";
char *Cget = "get";
char *Cprintc = "printc";
char *Cbegin = "begin";
char *Cend = "end";
int i;

void init_turing_tape(turing_tape *tape) {
    tape->array_plus = (unsigned char *) calloc(DEFAUlT_SIZE, sizeof(unsigned char));
    tape->array_minus = (unsigned char *) calloc(DEFAUlT_SIZE, sizeof(unsigned char));
    tape->sign_of_array = 1;
    tape->size_plus = DEFAUlT_SIZE;
    tape->size_minus = DEFAUlT_SIZE;
    tape->current_element = 0;
}
turing_tape *create_turing_tape() {
    turing_tape *tape = (turing_tape *) malloc(sizeof(turing_tape));
    init_turing_tape(tape);
    return tape;
}
void free_turing_tape(turing_tape *tape) {
    if(tape->array_plus)
        free(tape->array_plus);
    if(tape->array_minus)
        free(tape->array_minus);
    if(tape)
        free(tape);
}
void resize_turing_tape(turing_tape *tape, int tape_type) {
    if(tape_type == 1) {
        unsigned char *tmp_array = (unsigned char *) calloc(tape->size_plus*RESIZING_COEFFICIENT, sizeof(unsigned char));
        memcpy(tmp_array, tape->array_plus, tape->size_plus);
        free(tape->array_plus); tape->array_plus = tmp_array;
        tape->size_plus = tape->size_plus*RESIZING_COEFFICIENT;
    } else if(tape_type == -1) {
        unsigned char *tmp_array = (unsigned char *) calloc(tape->size_minus*RESIZING_COEFFICIENT, sizeof(unsigned char));
        memcpy(tmp_array, tape->array_minus, tape->size_minus);
        free(tape->array_minus); tape->array_minus = tmp_array;
        tape->size_minus = tape->size_minus*RESIZING_COEFFICIENT;
    }
}
void print_turing_tape(turing_tape *tape) {
    unsigned long int i;
    for(i = tape->size_minus; i > 0; i--) {
        printf("%3ld: %d\t", -i, tape->array_minus[i-1]);
    }
    printf("\n");
    for(i = 0; i < tape->size_plus; i++) {
        printf("%3ld: %d\t", i, tape->array_plus[i]);
    }
    printf("\n\n");
}
void movl(turing_tape *tape) {
    if(tape->sign_of_array == 1) {
        if(tape->current_element == 0) {
            tape->sign_of_array = -1;
        } else {
            tape->current_element--;
        }
    } else if(tape->sign_of_array == -1) {
        if(tape->current_element == tape->size_minus-1) {
            resize_turing_tape(tape, tape->sign_of_array);
            tape->current_element++;
        } else {
            tape->current_element++;
        }
    }
}
void movr(turing_tape *tape) {
    if(tape->sign_of_array == 1) {
        if(tape->current_element == tape->size_plus-1) {
            resize_turing_tape(tape, tape->sign_of_array);
            tape->current_element++;
        } else {
            tape->current_element++;
        }
    } else if(tape->sign_of_array == -1) {
        if(tape->current_element == 0) {
            tape->sign_of_array = 1;
        } else {
            tape->current_element--;
        }
    }
}
void inc(turing_tape *tape) {
    if(tape->sign_of_array == 1) {
        tape->array_plus[tape->current_element]++;
    } else if(tape->sign_of_array == -1) {
        tape->array_minus[tape->current_element]++;
    }
}
void dec(turing_tape *tape) {
    if(tape->sign_of_array == 1) {
        tape->array_plus[tape->current_element]--;
    } else if(tape->sign_of_array == -1) {
        tape->array_minus[tape->current_element]--;
    }
}
void print(turing_tape *tape) {
    if(tape->sign_of_array == 1) {
        printf("%u\n", tape->array_plus[tape->current_element]);
    } else if(tape->sign_of_array == -1) {
        printf("%u\n",tape->array_minus[tape->current_element]);
    }
}
void get(turing_tape *tape) {
    if(tape->sign_of_array == 1) {
        tape->array_plus[tape->current_element] = getchar();
    } else if(tape->sign_of_array == -1) {
        tape->array_minus[tape->current_element] = getchar();
    }
}
char cur(turing_tape *tape) {
    if(tape->sign_of_array == 1) {
        return tape->array_plus[tape->current_element];
    } else if(tape->sign_of_array == -1) {
        return tape->array_minus[tape->current_element];
    }
    return 0;
}
void printc(turing_tape *tape) {
    if(tape->sign_of_array == 1) {
        printf("%c\n", tape->array_plus[tape->current_element]);
    } else if(tape->sign_of_array == -1) {
        printf("%c\n",tape->array_minus[tape->current_element]);
    }
}

int string_array_length(char **string_array) {
    if(!string_array)
        return 0;

    int length = 0;
    while(*string_array++) {
        length++;
    }
    return length;
}
char **read_all_commands(const char *filename) {
    FILE *file = fopen(filename, "r");
    if(file == NULL) {
        return NULL;
    }
    const double mult = 1.5;
    int index = 0;
    int array_size = 10;
    char **array = (char **) calloc(array_size, sizeof(char *));
    char *line;
    size_t size;
    while(!feof(file)) {
        line = NULL;
        size = 0;
        getline(&line, &size, file);
        array[index++] = line;
        if(index == array_size) {
            array_size = (int) (array_size*mult);
            array = (char **) realloc(array, sizeof(char *)*array_size);
        }
    }
    array[index] = NULL;
    return array;
}
void check(char** t, turing_tape *pointer, int start, int end){
    int cycle;
    for(i = cycle = start; i< end; i++) {
        if (strstr(t[i], Cmovl)){
            movl(pointer);
        }
        if (strstr(t[i], Cmovr)){
            movr(pointer);
        }
        if (strstr(t[i], Cinc)){
            inc(pointer);
        }
        if (strstr(t[i], Cdec)){
            dec(pointer);
        }
        if (strstr(t[i], Cprint)){
            print(pointer);

        }
        if (strstr(t[i], Cget)){
            get(pointer);
        }
        if (strstr(t[i], Cprintc)){
            printc(pointer);
        }
        if (strstr(t[i], Cbegin)){
            cycle = i+1;

        }
        if (strstr(t[i], Cend)){
            while(cur(pointer)){
                check(t, pointer, cycle, i);
            }
        }
    }
}

int TuringMachine(int argc, char *argv[]) {
    char **t = read_all_commands(argv[1]);
    turing_tape tape;
    turing_tape *point = &tape;
    tape = *create_turing_tape();
    check(t, point, 0,string_array_length(t));
    return 0;
}