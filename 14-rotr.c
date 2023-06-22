#include "monty.h"




void mnty_rotr(stack_t **stack_start, __attribute__((unused)) unsigned int ln_num)
{
	stack_t *duplicate;

	duplicate = *stack_start;
	if (*stack_start == NULL || (*stack_start)->next == NULL)
	{
		return;
	}
	while (duplicate->next)
	{
		duplicate = duplicate->next;
	}
	duplicate->next = *stack_start;
	duplicate->prev->next = NULL;
	duplicate->prev = NULL;
	(*stack_start)->prev = duplicate;
	(*stack_start) = duplicate;
}
