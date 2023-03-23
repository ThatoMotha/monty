#include "monty.h"

/**
 * div_op - divides the second top element of the stack by the top element of
 * the stack.
 * @stack: double pointer to the beginning of the stack
 * @line_number: current line number in the Monty file
 */
void div_op(stack_t **stack, unsigned int line_number)
{
    int div_result;

    if (*stack == NULL || (*stack)->next == NULL)
    {
        fprintf(stderr, "L%d: can't div, stack too short\n", line_number);
        free_all(stack);
        exit(EXIT_FAILURE);
    }

    if ((*stack)->n == 0)
    {
        fprintf(stderr, "L%d: division by zero\n", line_number);
        free_all(stack);
        exit(EXIT_FAILURE);
    }

    div_result = (*stack)->next->n / (*stack)->n;
    (*stack)->next->n = div_result;
    pop_op(stack, line_number);
}

