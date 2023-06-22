#include "monty.h"



void addnode(stack_t **stack_start, int n)
{

	stack_t *new_node, *holder;

	holder = *stack_start;
	new_node = malloc(sizeof(stack_t));
	if (new_node == NULL)
	{ printf("Error\n");
		exit(0); }
	if (holder)
		holder->prev = new_node;
	new_node->n = n;
	new_node->next = *stack_start;
	new_node->prev = NULL;
	*stack_start = new_node;
}
