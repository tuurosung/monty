/*
 * File: exec_mnty.c
 * Auth: Bennett Dixon
 *       Brennan D Baraban
 */

#include "monty.h"
#include <string.h>

void free_tokens(void);
unsigned int token_arr_len(void);
int is_empty_line(char *line, char *delims);
void (*get_op_func(char *opcode))(stack_t**, unsigned int);
int exec_mnty(FILE *script_fd);

/**
 * free_tokens - Frees the global mnty_tokens array of strings.
 */
void free_tokens(void)
{
	size_t i = 0;

	if (mnty_tokens == NULL)
		return;

	for (i = 0; mnty_tokens[i]; i++)
		free(mnty_tokens[i]);

	free(mnty_tokens);
}

/**
 * token_arr_len - Gets the length of current mnty_tokens.
 *
 * Return: Length of current mnty_tokens (as int).
 */
unsigned int token_arr_len(void)
{
	unsigned int token_len = 0;

	while (mnty_tokens[token_len])
		token_len++;
	return (token_len);
}

/**
 * is_empty_line - Checks if a line read from getline only contains delimiters.
 * @line: A pointer to the line.
 * @delims: A string of delimiter characters.
 *
 * Return: If the line only contains delimiters - 1.
 *         Otherwise - 0.
 */
int is_empty_line(char *line, char *delims)
{
	int i, j;

	for (i = 0; line[i]; i++)
	{
		for (j = 0; delims[j]; j++)
		{
			if (line[i] == delims[j])
				break;
		}
		if (delims[j] == '\0')
			return (0);
	}

	return (1);
}

/**
 * get_op_func - Matches an opcode with its corresponding function.
 * @opcode: The opcode to match.
 *
 * Return: A pointer to the corresponding function.
 */
void (*get_op_func(char *opcode))(stack_t**, unsigned int)
{
	instruction_t op_funcs[] = {
		{"push", mnty_push},
		{"pall", mnty_pall},
		{"pint", mnty_pint},
		{"pop", mnty_pop},
		{"swap", mnty_swap},
		{"add", mnty_add},
		{"nop", mnty_nop},
		{"sub", mnty_sub},
		{"div", mnty_div},
		{"mul", mnty_mul},
		{"mod", mnty_mod},
		{"pchar", mnty_pchar},
		{"pstr", mnty_pstr},
		{"rotl", mnty_rotl},
		{"rotr", mnty_rotr},
		{"stack", mnty_stack},
		{"queue", mnty_queue},
		{NULL, NULL}
	};
	int i;

	for (i = 0; op_funcs[i].opcode; i++)
	{
		if (strcmp(opcode, op_funcs[i].opcode) == 0)
			return (op_funcs[i].f);
	}

	return (NULL);
}


int exec_mnty(FILE *script_fd)
{
	stack_t *stack = NULL;
	char *line = NULL;
	size_t len = 0, exit_status = EXIT_SUCCESS;
	unsigned int ln_num = 0, prev_tok_len = 0;
	void (*op_func)(stack_t**, unsigned int);

	if (init_stack(&stack) == EXIT_FAILURE)
		return (EXIT_FAILURE);

	while (getline(&line, &len, script_fd) != -1)
	{
		ln_num++;
		mnty_tokens = strtow(line, DELIMS);
		if (mnty_tokens == NULL)
		{
			if (is_empty_line(line, DELIMS))
				continue;
			free_stack(&stack);
			return (malloc_error());
		}
		else if (mnty_tokens[0][0] == '#') /* comment line */
		{
			free_tokens();
			continue;
		}
		op_func = get_op_func(mnty_tokens[0]);
		if (op_func == NULL)
		{
			free_stack(&stack);
			exit_status = unknown_op_error(mnty_tokens[0], ln_num);
			free_tokens();
			break;
		}
		prev_tok_len = token_arr_len();
		op_func(&stack, ln_num);
		if (token_arr_len() != prev_tok_len)
		{
			if (mnty_tokens && mnty_tokens[prev_tok_len])
				exit_status = atoi(mnty_tokens[prev_tok_len]);
			else
				exit_status = EXIT_FAILURE;
			free_tokens();
			break;
		}
		free_tokens();
	}
	free_stack(&stack);

	if (line && *line == 0)
	{
		free(line);
		return (malloc_error());
	}

	free(line);
	return (exit_status);
}
