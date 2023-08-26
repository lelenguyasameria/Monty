#include "monty.h"

/**
 * add - Adds the top two elements of the stack
 * @stack: Double pointer to the head of the stack
 * @line_number: Line number in the file
 */
void add(stack_t **stack, unsigned int line_number)
{
    if (*stack == NULL || (*stack)->next == NULL)
    {
        fprintf(stderr, "L%d: can't add, stack too short\n", line_number);
        exit(EXIT_FAILURE);
    }

    (*stack)->next->data += (*stack)->data;
    nop(stack, line_number);
}

