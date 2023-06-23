<<<<<<< HEAD
#ifndef MONTY_H
#define MONTY_H

#define _GNU_SOURCE
=======
#ifndef __MONTY_H__
#define __MONTY_H__
#define  _GNU_SOURCE
>>>>>>> 23e28b37e2f49d58fdbd785f18586d0a6f67beb6

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define STACK 0
#define QUEUE 1
#define DELIMS " \n\t\a\b"


extern char **mnty_tokens;


typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;


typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int ln_num);
} instruction_t;




void free_stack(stack_t **stack);
int init_stack(stack_t **stack);
int check_mode(stack_t *stack);
void free_tokens(void);
unsigned int token_arr_len(void);
int exec_mnty(FILE *script_fd);
void config_tkerror(int error_code);

/* Mandatory Tasks */
void mnty_push(stack_t **stack, unsigned int ln_num);
void mnty_pall(stack_t **stack, unsigned int ln_num);
void mnty_pint(stack_t **stack, unsigned int ln_num);
void mnty_pop(stack_t **stack, unsigned int ln_num);
void mnty_swap(stack_t **stack, unsigned int ln_num);

/* Advanced Tasks */
void mnty_add(stack_t **stack, unsigned int ln_num);
void mnty_nop(stack_t **stack, unsigned int ln_num);
void mnty_sub(stack_t **stack, unsigned int ln_num);
void mnty_div(stack_t **stack, unsigned int ln_num);
void mnty_mul(stack_t **stack, unsigned int ln_num);
void mnty_mod(stack_t **stack, unsigned int ln_num);
void mnty_pchar(stack_t **stack, unsigned int ln_num);
void mnty_pstr(stack_t **stack, unsigned int ln_num);
void mnty_rotl(stack_t **stack, unsigned int ln_num);
void mnty_rotr(stack_t **stack, unsigned int ln_num);
void mnty_stack(stack_t **stack, unsigned int ln_num);
void mnty_queue(stack_t **stack, unsigned int ln_num);



char **strtow(char *str, char *delims);
char *get_int(int n);




int usage_error(void);
int malloc_error(void);
int f_open_error(char *filename);
int unknown_op_error(char *opcode, unsigned int ln_num);
int no_int_error(unsigned int ln_num);
int pop_error(unsigned int ln_num);
int pint_error(unsigned int ln_num);
int short_stack_error(unsigned int ln_num, char *op);
int div_error(unsigned int ln_num);
int pchar_error(unsigned int ln_num, char *message);

#endif
