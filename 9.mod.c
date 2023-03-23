#include "monty.h"

/**
 * mod - computes the rest of the division of the second top element
 * of the stack by the top element of the stack.
 * @stack: pointer to the top of stack
 * @line_number: current line number in script
 */
void mod(stack_t **stack, unsigned int line_number)
{
    int mod_result;
    stack_t *temp;

    if (!*stack || !(*stack)->next)
    {
        fprintf(stderr, "L%u: can't mod, stack too short\n", line_number);
        exit(EXIT_FAILURE);
    }

    if ((*stack)->n == 0)
    {
        fprintf(stderr, "L%u: division by zero\n", line_number);
        exit(EXIT_FAILURE);
    }

    temp = *stack;
    mod_result = temp->next->n % temp->n;
    temp->next->n = mod_result;
    *stack = temp->next;
    free(temp);
}
