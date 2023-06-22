#ifndef MONTY_H
#define MONTY_H
#define _GNU_SOURCE

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <ctype.h>



typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;


typedef struct bus_s
{
	char *arg;
	FILE *file;
	char *content;
	int lifi;
}  bus_t;
extern bus_t bus;



typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

char *_realloc(char *ptr, unsigned int old_size, unsigned int new_size);
ssize_t getstdin(char **lineptr, int file);
char  *clean_line(char *content);

/* Mandatory Tasks By Haira Adam */
/* 0-push_pall*/
void mnty_push(stack_t **stack_start, unsigned int number);
void mnty_pall(stack_t **stack_start, unsigned int number);

/* 1-pint*/
void mnty_pint(stack_t **stack_start, unsigned int number);

/* 2-pop*/
void mnty_pop(stack_t **stack_start, unsigned int ln_num);

/* 3-swap*/
void mnty_swap(stack_t **stack_start, unsigned int ln_num);

/* 4-add */
void mnty_add(stack_t **stack_start, unsigned int ln_num);

/* 5-nop */
void mnty_nop(stack_t **stack_start, unsigned int ln_num);

/* Advanced Tasks By Shahabdeen */
/* 6 sub, 7-div, 8-mul, 9-mod, 11-pchar, 12-pstr*/
void mnty_sub(stack_t **stack_start, unsigned int ln_num);
void mnty_div(stack_t **stack_start, unsigned int ln_num);
void mnty_mul(stack_t **stack_start, unsigned int ln_num);
void mnty_mod(stack_t **stack_start, unsigned int ln_num);
void mnty_pchar(stack_t **stack_start, unsigned int ln_num);
void mnty_pstr(stack_t **stack_start, unsigned int ln_num);
void mnty_rotl(stack_t **stack_start, unsigned int ln_num);
void mnty_rotr(stack_t **stack_start, __attribute__((unused)) unsigned int ln_num);

int execute(char *content, stack_t **stack_start, unsigned int ln_num, FILE *file);
void free_stack(stack_t *stack_start);

void addnode(stack_t **stack_start, int n);
void addqueue(stack_t **stack_start, int n);
void mnty_queue(stack_t **stack_start, unsigned int ln_num);
void mnty_stack(stack_t **stack_start, unsigned int ln_num);

#endif
