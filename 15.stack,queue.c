#include "monty.h"

/**
 * stack - Sets the format of the data to a stack (LIFO)
 * @stack: Double pointer to the head of the stack
 * @line_number: Current line number in the Monty file
 */
void stack(stack_t **stack, unsigned int line_number)
{
    (void) line_number;
    (void) stack;
    /* Do nothing, since stack is already default mode */
}

/**
 * queue - Sets the format of the data to a queue (FIFO)
 * @stack: Double pointer to the head of the stack
 * @line_number: Current line number in the Monty file
 */
void queue(stack_t **stack, unsigned int line_number)
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
    *stack = temp;
}

