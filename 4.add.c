#include "monty.h"

/**
 * add - Adds the top two elements of the stack.
 * @stack: Double pointer to the beginning of the stack.
 * @line_number: The current line number in the Monty bytecodes file.
 */
void add(stack_t **stack, unsigned int line_number)
{
    int sum;

    if (*stack == NULL || (*stack)->prev == NULL)
    {
        fprintf(stderr, "L%u: can't add, stack too short\n", line_number);
        exit(EXIT_FAILURE);
    }

    sum = (*stack)->n + (*stack)->prev->n;
    (*stack)->prev->n = sum;
    pop(stack, line_number);
}

