#include "monty.h"

/**
 * mnty_pall - prints all values of the stack
 * @stack_start: pointer to the top of the stack
 * @ln_num: current line in input file;
 * Return: returns nothing
 */

void mnty_pall(stack_t **stack_start, unsigned int ln_num)
{
	stack_t *h;
	(void)ln_num;

	h = *stack_start;
	if (h == NULL)
		return;
	while (h)
	{
		printf("%d\n", h->n);
		h = h->next;
	}
}

/**
 * mnty_push - pushes an element to the stack
 * @stack_start: pointer to the top of the stack
 * @ln_num: current line in input file;
 * Return: returns nothing
 */

void mnty_push(stack_t **stack_start, unsigned int ln_num)
{
	int n, j = 0, flag = 0;

	if (bus.arg)
	{
		if (bus.arg[0] == '-')
			j++;
		for (; bus.arg[j] != '\0'; j++)
		{
			if (bus.arg[j] > 57 || bus.arg[j] < 48)
				flag = 1;
		}
		if (flag == 1)
		{
			fprintf(stderr, "L%d: usage: push integer\n", ln_num);
			fclose(bus.file);
			free(bus.content);
			free_stack(*stack_start);
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		fprintf(stderr, "L%d: usage: push integer\n", ln_num);
		fclose(bus.file);
		free(bus.content);
		free_stack(*stack_start);
		exit(EXIT_FAILURE);
	}
	n = atoi(bus.arg);
	if (bus.lifi == 0)
		addnode(stack_start, n);
	else
		addqueue(stack_start, n);
}
