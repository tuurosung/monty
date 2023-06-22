#include "monty.h"


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
