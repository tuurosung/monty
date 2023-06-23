/*
 * File: monty_funcs_3.c
 * Auth: Bennett Dixon
 *       Brennan D Baraban
 */

#include "monty.h"

void mnty_nop(stack_t **stack, unsigned int ln_num);
void mnty_pchar(stack_t **stack, unsigned int ln_num);
void mnty_pstr(stack_t **stack, unsigned int ln_num);

/**
 * mnty_nop - Does absolutely nothing for the Monty opcode 'nop'.
 * @stack: A pointer to the top mode node of a stack_t linked list.
 * @ln_num: The current working line number of a Monty bytecodes file.
 */
void mnty_nop(stack_t **stack, unsigned int ln_num)
{
	(void)stack;
	(void)ln_num;
}

/**
 * mnty_pchar - Prints the character in the top value
 *               node of a stack_t linked list.
 * @stack: A pointer to the top mode node of a stack_t linked list.
 * @ln_num: The current working line number of a Monty bytecodes file.
 */
void mnty_pchar(stack_t **stack, unsigned int ln_num)
{
	if ((*stack)->next == NULL)
	{
		config_tkerror(pchar_error(ln_num, "stack empty"));
		return;
	}
	if ((*stack)->next->n < 0 || (*stack)->next->n > 127)
	{
		config_tkerror(pchar_error(ln_num,
					     "value out of range"));
		return;
	}

	printf("%c\n", (*stack)->next->n);
}

/**
 * mnty_pstr - Prints the string contained in a stack_t linked list.
 * @stack: A pointer to the top mode node of a stack_t linked list.
 * @ln_num: The current working line number of a Monty bytecodes file.
 */
void mnty_pstr(stack_t **stack, unsigned int ln_num)
{
	stack_t *holder = (*stack)->next;

	while (holder && holder->n != 0 && (holder->n > 0 && holder->n <= 127))
	{
		printf("%c", holder->n);
		holder = holder->next;
	}

	printf("\n");

	(void)ln_num;
}
