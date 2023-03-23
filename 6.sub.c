#include "monty.h"

/**
 * sub - Subtracts the top element of the stack from the second top element.
 * @stack: Double pointer to the beginning of the stack.
 * @line_number: The current line number in the Monty bytecodes file.
 */
void sub(stack_t **stack, unsigned int line_number)
{
    int sub_result;

    if (!*stack || !((*stack)->next))
    {
        fprintf(stderr, "L%u: can't sub, stack too short\n", line_number);
        exit(EXIT_FAILURE);
    }

    sub_result = ((*stack)->next)->n - (*stack)->n;
    pop(stack, line_number);
    (*stack)->n = sub_result;
}
