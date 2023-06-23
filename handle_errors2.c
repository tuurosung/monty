#include "monty.h"

int short_stack_error(unsigned int ln_num, char *op);
int div_error(unsigned int ln_num);
int pop_error(unsigned int ln_num);
int div_error(unsigned int ln_num);
int pchar_error(unsigned int ln_num, char *message);



int pop_error(unsigned int ln_num)
{
	fprintf(stderr, "L%u: can't pop an empty stack\n", ln_num);
	return (EXIT_FAILURE);
}




int pint_error(unsigned int ln_num)
{
	fprintf(stderr, "L%d: can't pint, stack empty\n", ln_num);
	return (EXIT_FAILURE);
}




int short_stack_error(unsigned int ln_num, char *op)
{
	fprintf(stderr, "L%u: can't %s, stack too short\n", ln_num, op);
	return (EXIT_FAILURE);
}




int div_error(unsigned int ln_num)
{
	fprintf(stderr, "L%u: division by zero\n", ln_num);
	return (EXIT_FAILURE);
}




int pchar_error(unsigned int ln_num, char *message)
{
	fprintf(stderr, "L%u: can't pchar, %s\n", ln_num, message);
	return (EXIT_FAILURE);
}
