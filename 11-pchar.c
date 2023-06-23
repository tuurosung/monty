#include "monty.h"

/**
 * swap - swaps the top 2 elements of stack_t stack
 * @stack: pointer to the top of the stack
 * @ln_number: current line in input file;
 * Return: returns nothing
*/

void mnty_pchar(stack_t **stack_start, unsigned int ln_num)
{
	stack_t *h;

	h = *stack_start;
	if (!h)
	{
		fprintf(stderr, "L%d: can't pchar, stack empty\n", ln_num);
		fclose(bus.file);
		free(bus.content);
		free_stack(*stack_start);
		exit(EXIT_FAILURE);
	}
	if (h->n > 127 || h->n < 0)
	{
		fprintf(stderr, "L%d: can't pchar, value out of range\n", ln_num);
		fclose(bus.file);
		free(bus.content);
		free_stack(*stack_start);
		exit(EXIT_FAILURE);
	}
	printf("%c\n", h->n);
}
