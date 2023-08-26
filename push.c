#include "monty.h"

/**
 * push - Pushes an element onto the stack.
 * @stack: Pointer to the head of the stack.
 * @line_number: Line number of the instruction.
 */
void push(stack_t **stack, unsigned int line_number)
{
    char *arg = "42"; // Replace this with the actual argument you're using

    if (!arg || (!isdigit(arg[0]) && arg[0] != '-'))
    {
        fprintf(stderr, "L%d: usage: push integer\n", line_number);
        exit(EXIT_FAILURE);
    }

    int value = atoi(arg);
    stack_t *new_node = create_node(value);

    if (!new_node)
    {
        fprintf(stderr, "Error: malloc failed\n");
        free_nodes();
        exit(EXIT_FAILURE);
    }

    new_node->next = *stack;
    if (*stack)
        (*stack)->prev = new_node;
    *stack = new_node;
}

