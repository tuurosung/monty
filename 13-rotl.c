#include "monty.h"



void mnty_rotl(stack_t **stack_start,  __attribute__((unused)) unsigned int ln_num)
{
	stack_t *tmp = *stack_start, *holder;

	if (*stack_start == NULL || (*stack_start)->next == NULL)
	{
		return;
	}
	holder = (*stack_start)->next;
	holder->prev = NULL;
	while (tmp->next != NULL)
	{
		tmp = tmp->next;
	}
	tmp->next = *stack_start;
	(*stack_start)->next = NULL;
	(*stack_start)->prev = tmp;
	(*stack_start) = holder;
}
