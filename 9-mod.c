#include "monty.h"

/**
 * mnty_mod - computes the rest of the division of the second
 * top element of the stack by the top element of the stack.
 * @stack_start: pointer to the top of the stack
 * @ln_numb: current line in input file;
 * Return: returns nothing
 */
void mnty_mod(stack_t **stack_start, unsigned int ln_num)
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
		fprintf(stderr, "L%d: can't mod, stack too short\n", ln_num);
		fclose(bus.file);
		free(bus.content);
		free_stack(*stack_start);
		exit(EXIT_FAILURE);
	}
	h = *stack_start;
	if (h->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", ln_num);
		fclose(bus.file);
		free(bus.content);
		free_stack(*stack_start);
		exit(EXIT_FAILURE);
	}
	holder = h->next->n % h->n;
	h->next->n = holder;
	*stack_start = h->next;
	free(h);
}
