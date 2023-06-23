

#include "monty.h"
#include <string.h>
#include <stdlib.h>

void free_stack(stack_t **stack);
int init_stack(stack_t **stack);
int check_mode(stack_t *stack);


void free_stack(stack_t **stack)
{
	stack_t *holder = *stack;

	while (*stack)
	{
		holder = (*stack)->next;
		free(*stack);
		*stack = holder;
	}
}


int init_stack(stack_t **stack)
{
	stack_t *s;

	s = malloc(sizeof(stack_t));
	if (s == NULL)
		return (malloc_error());

	s->n = STACK;
	s->prev = NULL;
	s->next = NULL;

	*stack = s;

	return (EXIT_SUCCESS);
}


int check_mode(stack_t *stack)
{
	if (stack->n == STACK)
		return (STACK);
	else if (stack->n == QUEUE)
		return (QUEUE);
	return (2);
}
