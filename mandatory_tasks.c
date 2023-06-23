#include "monty.h"

void mnty_push(stack_t **stack, unsigned int ln_num);
void mnty_pall(stack_t **stack, unsigned int ln_num);
void mnty_pint(stack_t **stack, unsigned int ln_num);
void mnty_pop(stack_t **stack, unsigned int ln_num);
void mnty_swap(stack_t **stack, unsigned int ln_num);




void mnty_push(stack_t **stack, unsigned int ln_num)
{
	stack_t *holder, *new;
	int i;

	new = malloc(sizeof(stack_t));
	if (new == NULL)
	{
		config_tkerror(malloc_error());
		return;
	}

	if (mnty_tokens[1] == NULL)
	{
		config_tkerror(no_int_error(ln_num));
		return;
	}

	for (i = 0; mnty_tokens[1][i]; i++)
	{
		if (mnty_tokens[1][i] == '-' && i == 0)
			continue;
		if (mnty_tokens[1][i] < '0' || mnty_tokens[1][i] > '9')
		{
			config_tkerror(no_int_error(ln_num));
			return;
		}
	}
	new->n = atoi(mnty_tokens[1]);

	if (check_mode(*stack) == STACK) /* STACK mode insert at front */
	{
		holder = (*stack)->next;
		new->prev = *stack;
		new->next = holder;
		if (holder)
			holder->prev = new;
		(*stack)->next = new;
	}
	else /* QUEUE mode insert at end */
	{
		holder = *stack;
		while (holder->next)
			holder = holder->next;
		new->prev = holder;
		new->next = NULL;
		holder->next = new;
	}
}



void mnty_pall(stack_t **stack, unsigned int ln_num)
{
	stack_t *holder = (*stack)->next;

	while (holder)
	{
		printf("%d\n", holder->n);
		holder = holder->next;
	}
	(void)ln_num;
}




void mnty_pint(stack_t **stack, unsigned int ln_num)
{
	if ((*stack)->next == NULL)
	{
		config_tkerror(pint_error(ln_num));
		return;
	}

	printf("%d\n", (*stack)->next->n);
}





void mnty_pop(stack_t **stack, unsigned int ln_num)
{
	stack_t *next = NULL;

	if ((*stack)->next == NULL)
	{
		config_tkerror(pop_error(ln_num));
		return;
	}

	next = (*stack)->next->next;
	free((*stack)->next);
	if (next)
		next->prev = *stack;
	(*stack)->next = next;
}




void mnty_swap(stack_t **stack, unsigned int ln_num)
{
	stack_t *holder;

	if ((*stack)->next == NULL || (*stack)->next->next == NULL)
	{
		config_tkerror(short_stack_error(ln_num, "swap"));
		return;
	}

	holder = (*stack)->next->next;
	(*stack)->next->next = holder->next;
	(*stack)->next->prev = holder;
	if (holder->next)
		holder->next->prev = (*stack)->next;
	holder->next = (*stack)->next;
	holder->prev = *stack;
	(*stack)->next = holder;
}
