#include <stdio.h>
#include <stdlib.h>
#include "monty.h"

#define STACK_MAX 1024

typedef struct {
    int data[STACK_MAX];
    int size;
} Stack;

void push(Stack* stack, int value, int line_num) {
    if (stack->size < STACK_MAX) {
        stack->data[stack->size++] = value;
    } else {
        fprintf(stderr, "L%d: Error: stack overflow\n", line_num);
        exit(EXIT_FAILURE);
    }
}

int pop(Stack* stack, int line_num) {
    if (stack->size == 0) {
        fprintf(stderr, "L%d: Error: stack empty\n", line_num);
        exit(EXIT_FAILURE);
    } else {
        return stack->data[--stack->size];
    }
}

void pall(Stack* stack) {
    int i;
    for (i = stack->size - 1; i >= 0; i--) {
        printf("%d\n", stack->data[i]);
    }
}

int main(int argc, char* argv[]) {
    Stack stack = { {0}, 0 };
    FILE* file;
    char* line = NULL;
    size_t len = 0;
    ssize_t read;
    int line_num = 0;

    if (argc != 2) {
        fprintf(stderr, "Usage: %s filename\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    file = fopen(argv[1], "r");
    if (file == NULL) {
        fprintf(stderr, "Error: cannot open file %s\n", argv[1]);
        exit(EXIT_FAILURE);
    }

    while ((read = getline(&line, &len, file)) != -1) {
        line_num++;
        if (strncmp(line, "push ", 5) == 0) {
            int value = atoi(&line[5]);
            push(&stack, value, line_num);
        } else if (strcmp(line, "pall\n") == 0) {
            pall(&stack);
        } else {
            fprintf(stderr, "L%d: Error: invalid instruction\n", line_num);
            exit(EXIT_FAILURE);
        }
    }

    free(line);
    fclose(file);
    exit(EXIT_SUCCESS);
}
