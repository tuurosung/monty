#include "monty.h"


void mnty_pstr(stack_t **stack_start, unsigned int ln_num)
{
	stack_t *h;
	(void)ln_num;

	h = *stack_start;
	while (h)
	{
		if (h->n > 127 || h->n <= 0)
		{
			break;
		}
		printf("%c", h->n);
		h = h->next;
	}
	printf("\n");
}
