#include "monty.h"

/**
 * mnty_sub - subtracts the top element of the stack from
 * the second top element of the stack
 * @stack_start: pointer to the top of the stack
 * @ln_num: current line in input file;
 * Return: returns nothing
 */



void mnty_sub(stack_t **stack_start, unsigned int ln_num)
{
	stack_t *holder;
	int sus, nodes;

	holder = *stack_start;
	for (nodes = 0; holder != NULL; nodes++)
		holder = holder->next;

	if (nodes < 2)
	{
		fprintf(stderr, "L%d: can't sub, stack too short\n", ln_num);
		fclose(bus.file);
		free(bus.content);
		free_stack(*stack_start);
		exit(EXIT_FAILURE);
	}
	holder = *stack_start;
	sus = holder->next->n - holder->n;
	holder->next->n = sus;
	*stack_start = holder->next;
	free(holder);
}
