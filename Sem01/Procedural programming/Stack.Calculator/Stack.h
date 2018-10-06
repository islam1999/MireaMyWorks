#ifndef STACK_CALCULATOR_STACK_H
#define STACK_CALCULATOR_STACK_H

typedef struct stack_s {
    void *array;
    size_t element_size;
    unsigned int current_number;
} stack;

stack *create_stack(size_t elemtent_size);
void free_stack(stack *st);
int push(stack *st, void *element);
int pop(stack *st, void *element);
#endif
