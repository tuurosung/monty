#include "monty.h"


void config_tkerror(int error_code)
{
	int token_len = 0, i = 0;
	char *exit_str = NULL;
	char **gen_token = NULL;

	token_len = token_arr_len();
	gen_token = malloc(sizeof(char *) * (token_len + 2));
	if (!mnty_tokens)
	{
		malloc_error();
		return;
	}
	while (i < token_len)
	{
		gen_token[i] = mnty_tokens[i];
		i++;
	}
	exit_str = get_int(error_code);
	if (!exit_str)
	{
		free(gen_token);
		malloc_error();
		return;
	}
	gen_token[i++] = exit_str;
	gen_token[i] = NULL;
	free(mnty_tokens);
	mnty_tokens = gen_token;
}
