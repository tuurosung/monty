#include "monty.h"
/**
 * mnty_swap - swaps the top 2 elements of stack_t stack
 * @stack_start: pointer to the top of the stack
 * @ln_num: current line in input file;
 * Return: returns nothing
 */

void mnty_swap(stack_t **stack_start, unsigned int ln_num)
{
	stack_t *h;
	int len = 0, holder;

	h = *stack_start;
	while (h)
	{
		h = h->next;
		len++;
	}
	if (len < 2)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", ln_num);
		fclose(bus.file);
		free(bus.content);
		free_stack(*stack_start);
		exit(EXIT_FAILURE);
	}
	h = *stack_start;
	holder = h->n;
	h->n = h->next->n;
	h->next->n = holder;
}
