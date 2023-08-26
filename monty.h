#ifndef MONTY_H
#define MONTY_H

#define _GNU_SOURCE
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdarg.h>

/**
 * struct stack_s - Structure representing a doubly linked list node
 * @data: Integer data stored in the node
 * @previous: Pointer to the previous node in the list
 * @next: Pointer to the next node in the list
 *
 * Description: This structure defines a node in a doubly linked list,
 * which is used for implementing stack, queue, LIFO, and FIFO data structures.
 */
typedef struct stack_s
{
    int data;
    struct stack_s *previous;
    struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - Contains an opcode and its associated function
 * @opcode: The opcode
 * @f: Pointer to the function that handles the opcode
 *
 * Description: This structure holds an opcode and the corresponding
 * function that performs the associated operation. It is used for various  
 * stack, queue, LIFO, and FIFO operations.
 */
typedef struct instruction_s
{
    char *opcode;
    void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

extern stack_t *head;
typedef void (*op_func)(stack_t **, unsigned int);

/* File operations */
void open_file(char *file_name);
int parse_line(char *buffer, int line_number, int format);
void read_file(FILE *);
int len_chars(FILE *);
void find_func(char *, char *, int, int);

/* Stack operations */
stack_t *create_node(int n);
void free_nodes(void);
void print_stack(stack_t **, unsigned int);
void add_to_stack(stack_t **, unsigned int);
void add_to_queue(stack_t **, unsigned int);

void call_fun(op_func, stack_t **, char *, int, int);

void print_top(stack_t **, unsigned int);
void pop_top(stack_t **, unsigned int);
void nop(stack_t **, unsigned int);
void swap_nodes(stack_t **, unsigned int);
   /* Mathematical operations with nodes */
void add_nodes(stack_t **, unsigned int);
void sub_nodes(stack_t **, unsigned int);
void div_nodes(stack_t **, unsigned int);
void mul_nodes(stack_t **, unsigned int);
void mod_nodes(stack_t **, unsigned int);

/* String operations */
void print_char(stack_t **, unsigned int);
void print_str(stack_t **, unsigned int);
void rotl(stack_t **, unsigned int);

/* Error handling */
void err(int error_code, ...);
void more_err(int error_code, ...);
void string_err(int error_code, ...);
void rotr(stack_t **, unsigned int);

#endif

