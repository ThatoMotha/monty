#include "monty.h"

/**
 * rotr - Rotates the stack to the bottom
 * @stack: Double pointer to the head of the stack
 * @line_number: Current line number in the Monty file
 */
void rotr(stack_t **stack, unsigned int line_number)
{
    stack_t *tail = NULL, *temp = NULL;

    (void) line_number;

    if (*stack == NULL || (*stack)->next == NULL)
        return;

    tail = *stack;
    while (tail->next != NULL)
        tail = tail->next;

    temp = tail->prev;
    temp->next = NULL;
    tail->prev = NULL;
    tail->next = *stack;
    (*stack)->prev = tail;
    *stack = tail;
}
