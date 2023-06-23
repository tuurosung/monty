

#include "monty.h"

void mnty_add(stack_t **stack, unsigned int ln_num);
void mnty_sub(stack_t **stack, unsigned int ln_num);
void mnty_div(stack_t **stack, unsigned int ln_num);
void mnty_mul(stack_t **stack, unsigned int ln_num);
void mnty_mod(stack_t **stack, unsigned int ln_num);




void mnty_add(stack_t **stack, unsigned int ln_num)
{
	if ((*stack)->next == NULL || (*stack)->next->next == NULL)
	{
		config_tkerror(short_stack_error(ln_num, "add"));
		return;
	}

	(*stack)->next->next->n += (*stack)->next->n;
	mnty_pop(stack, ln_num);
}



void mnty_sub(stack_t **stack, unsigned int ln_num)
{
	if ((*stack)->next == NULL || (*stack)->next->next == NULL)
	{
		config_tkerror(short_stack_error(ln_num, "sub"));
		return;
	}

	(*stack)->next->next->n -= (*stack)->next->n;
	mnty_pop(stack, ln_num);
}



void mnty_div(stack_t **stack, unsigned int ln_num)
{
	if ((*stack)->next == NULL || (*stack)->next->next == NULL)
	{
		config_tkerror(short_stack_error(ln_num, "div"));
		return;
	}

	if ((*stack)->next->n == 0)
	{
		config_tkerror(div_error(ln_num));
		return;
	}

	(*stack)->next->next->n /= (*stack)->next->n;
	mnty_pop(stack, ln_num);
}




void mnty_mul(stack_t **stack, unsigned int ln_num)
{
	if ((*stack)->next == NULL || (*stack)->next->next == NULL)
	{
		config_tkerror(short_stack_error(ln_num, "mul"));
		return;
	}

	(*stack)->next->next->n *= (*stack)->next->n;
	mnty_pop(stack, ln_num);
}




void mnty_mod(stack_t **stack, unsigned int ln_num)
{
	if ((*stack)->next == NULL || (*stack)->next->next == NULL)
	{
		config_tkerror(short_stack_error(ln_num, "mod"));
		return;
	}

	if ((*stack)->next->n == 0)
	{
		config_tkerror(div_error(ln_num));
		return;
	}

	(*stack)->next->next->n %= (*stack)->next->n;
	mnty_pop(stack, ln_num);
}
