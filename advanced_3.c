/*
 * File: monty_funcs_4.c
 * Auth: Bennett Dixon
 *       Brennan D Baraban
 */

#include "monty.h"

void mnty_rotl(stack_t **stack, unsigned int ln_num);
void mnty_rotr(stack_t **stack, unsigned int ln_num);
void mnty_stack(stack_t **stack, unsigned int ln_num);
void mnty_queue(stack_t **stack, unsigned int ln_num);

/**
 * mnty_rotl - Rotates the top value of a stack_t linked list to the bottom.
 * @stack: A pointer to the top mode node of a stack_t linked list.
 * @ln_num: The current working line number of a Monty bytecodes file.
 */
void mnty_rotl(stack_t **stack, unsigned int ln_num)
{
	stack_t *top, *bottom;

	if ((*stack)->next == NULL || (*stack)->next->next == NULL)
		return;

	top = (*stack)->next;
	bottom = (*stack)->next;
	while (bottom->next != NULL)
		bottom = bottom->next;

	top->next->prev = *stack;
	(*stack)->next = top->next;
	bottom->next = top;
	top->next = NULL;
	top->prev = bottom;

	(void)ln_num;
}

/**
 * mnty_rotr - Rotates the bottom value of a stack_t linked list to the top.
 * @stack: A pointer to the top mode node of a stack_t linked list.
 * @ln_num: The current working line number of a Monty bytecodes file.
 */
void mnty_rotr(stack_t **stack, unsigned int ln_num)
{
	stack_t *top, *bottom;

	if ((*stack)->next == NULL || (*stack)->next->next == NULL)
		return;

	top = (*stack)->next;
	bottom = (*stack)->next;
	while (bottom->next != NULL)
		bottom = bottom->next;

	bottom->prev->next = NULL;
	(*stack)->next = bottom;
	bottom->prev = *stack;
	bottom->next = top;
	top->prev = bottom;

	(void)ln_num;
}

/**
 * mnty_stack - Converts a queue to a stack.
 * @stack: A pointer to the top mode node of a stack_t linked list.
 * @ln_num: The current working line number of a Monty bytecodes file.
 */
void mnty_stack(stack_t **stack, unsigned int ln_num)
{
	(*stack)->n = STACK;
	(void)ln_num;
}

/**
 * mnty_queue - Converts a stack to a queue.
 * @stack: A pointer to the top mode node of a stack_t linked list.
 * @ln_num: The current working line number of a Monty bytecodes file.
 */
void mnty_queue(stack_t **stack, unsigned int ln_num)
{
	(*stack)->n = QUEUE;
	(void)ln_num;
}
