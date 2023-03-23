#include "monty.h"

/**
 * pchar - prints the char at the top of the stack
 * @stack: double pointer to the beginning of the stack
 * @line_number: line number of the opcode in the file being read
 */
void pchar(stack_t **stack, unsigned int line_number)
{
	int char_code;

	if (*stack == NULL)
	{
		fprintf(stderr, "L%d: can't pchar, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}

	char_code = (*stack)->n;

	if (char_code < 0 || char_code > 127)
	{
		fprintf(stderr, "L%d: can't pchar, value out of range\n", line_number);
		exit(EXIT_FAILURE);
	}

	putchar(char_code);
	putchar('\n');
}
