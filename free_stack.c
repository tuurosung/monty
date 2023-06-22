#include "monty.h"



void free_stack(stack_t *stack_start)
{
	stack_t *holder;

	holder = stack_start;
	while (stack_start)
	{
		holder = stack_start->next;
		free(stack_start);
		stack_start = holder;
	}
}
