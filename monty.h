#ifndef MONTY_H
#define MONTY_H

#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

#define OP_INIT {0, 1, NULL}
/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */

typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

/**
 * struct op_s - opcode errors and flags
 * @error: sets error flag
 * @is_stack: sets stack or queue flow
 * @value: argument to opcode instuction if any
 * Description: errors for stack, queues, LIFO, FIFO
 */

typedef struct op_s
{
	int error;
	int is_stack;
	char *value;
} op_t;

extern op_t op;
/* opcode.c */
void push_opcode(stack_t **stack, unsigned int line_num);
void pop_opcode(stack_t **stack, unsigned int line_num);
void print_opcode(stack_t **stack, unsigned int line_num);
void pint_opcode(stack_t **stack, unsigned int line_num);
int run_opcode(stack_t **stack, char *func, unsigned int line_num);

/* opcode2.c */
char *get_opcodes(char *line);
void swap_opcode(stack_t **stack, unsigned int line_num);
void add_opcode(stack_t **stack, unsigned int line_num);
void nop_opcode(stack_t **stack, unsigned int line_num);
void sub_opcode(stack_t **stack, unsigned int line_num);

/* opcode3.c */
void div_opcode(stack_t **stack, unsigned int line_num);
void mul_opcode(stack_t **stack, unsigned int line_num);
void mod_opcode(stack_t **stack, unsigned int line_num);
void pchar_opcode(stack_t **stack, unsigned int line_num);
void pstr_opcode(stack_t **stack, unsigned int line_num);

/* opcode4.c */
void rotl_opcode(stack_t **stack, unsigned int line_num);
void rotr_opcode(stack_t **stack, unsigned int line_num);

/* nodes.c */
stack_t *add_node_start(stack_t **head, int n);
int remove_node_start(stack_t **stack);
void free_stack(stack_t *stack);
int exit_free(stack_t *head, char *str, FILE *stream);

/* string.c */
int _strcmp(char *s1, char *s2);
int _strlen(const char *s);
int is_digit(char c);
int is_delim(const char c);
int is_numbers(char *s);

/* utils.c */
int run_monty(FILE *fd);
void set_op(void);
int is_comment_or_empty(char c);
int is_printable_ascii(int c);

/* errors.c */
int usage_error(void);
int file_open_error(char *file);

#endif /* MONTY_H */
