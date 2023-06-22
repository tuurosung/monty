#include "monty.h"


void mnty_stack(stack_t **stack_start, unsigned int ln_num)
{
	(void)stack_start;
	(void)ln_num;
	bus.lifi = 0;
}

void mnty_queue(stack_t **stack_start, unsigned int ln_num)
{
	(void)stack_start;
	(void)ln_num;
	bus.lifi = 1;
}

void addqueue(stack_t **stack_start, int n)
{
	stack_t *new_node, *holder;

	holder = *stack_start;
	new_node = malloc(sizeof(stack_t));
	if (new_node == NULL)
	{
		printf("Error\n");
	}
	new_node->n = n;
	new_node->next = NULL;
	if (holder)
	{
		while (holder->next)
			holder = holder->next;
	}
	if (!holder)
	{
		*stack_start = new_node;
		new_node->prev = NULL;
	}
	else
	{
		holder->next = new_node;
		new_node->prev = holder;
	}
}
