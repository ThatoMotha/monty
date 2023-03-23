#include "monty.h"

/**
 * mul - multiplies the second top element of the stack with the top element
 * @stack: double pointer to the beginning of the stack
 * @line_number: current line number in the Monty file being read
 */
void mul(stack_t **stack, unsigned int line_number)
{
    int mul_result;

    if (stack_length(*stack) < 2)
    {
        fprintf(stderr, "L%d: can't mul, stack too short\n", line_number);
        exit(EXIT_FAILURE);
    }

    mul_result = (*stack)->next->n * (*stack)->n;

    pop(stack, line_number);

    (*stack)->n = mul_result;
}
