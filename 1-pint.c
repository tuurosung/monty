#include "monty.h"


void mnty_pint(stack_t **stack_start, unsigned int ln_num)
{
	if (*stack_start == NULL)
	{
		fprintf(stderr, "L%u: can't pint, stack empty\n", ln_num);
		fclose(bus.file);
		free(bus.content);
		free_stack(*stack_start);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", (*stack_start)->n);
}
