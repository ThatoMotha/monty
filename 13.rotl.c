#include "monty.h"

/**
 * rotl - rotates the stack to the top
 * @stack: double pointer to the beginning of the stack
 * @line_number: current line number of the opcode
 *
 * Return: void
 */
void rotl(stack_t **stack, unsigned int line_number)
{
        stack_t *temp, *last;
        (void)line_number;

        if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
                return;

        temp = *stack;
        last = *stack;
        while (last->next != NULL)
                last = last->next;

        *stack = temp->next;
        (*stack)->prev = NULL;

        temp->next = NULL;
        temp->prev = last;
        last->next = temp;
}
