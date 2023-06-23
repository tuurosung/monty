#include "monty.h"

/**
 * mnty_pop - removes the top element of the stack_t stack
 * @stack_start: pointer to the top of the stack
 * @ln_num: current line in input file;
 * Return: returns nothing
 */

void mnty_pop(stack_t **stack_start, unsigned int ln_num)
{
	stack_t *h;

	if (*stack_start == NULL)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", ln_num);
		fclose(bus.file);
		free(bus.content);
		free_stack(*stack_start);
		exit(EXIT_FAILURE);
	}
	h = *stack_start;
	*stack_start = h->next;
	free(h);
}
