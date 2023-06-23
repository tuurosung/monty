#include "monty.h"

int usage_error(void);
int malloc_error(void);
int f_open_error(char *filename);
int unknown_op_error(char *opcode, unsigned int ln_num);
int no_int_error(unsigned int ln_num);


int usage_error(void)
{
	fprintf(stderr, "USAGE: monty file\n");
	return (EXIT_FAILURE);
}


int malloc_error(void)
{
	fprintf(stderr, "Error: malloc failed\n");
	return (EXIT_FAILURE);
}


int f_open_error(char *filename)
{
	fprintf(stderr, "Error: Can't open file %s\n", filename);
	return (EXIT_FAILURE);
}




int unknown_op_error(char *opcode, unsigned int ln_num)
{
	fprintf(stderr, "L%u: unknown instruction %s\n",
		ln_num, opcode);
	return (EXIT_FAILURE);
}




int no_int_error(unsigned int ln_num)
{
	fprintf(stderr, "L%u: usage: push integer\n", ln_num);
	return (EXIT_FAILURE);
}
