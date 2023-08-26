#include "monty.h"

/**
 * pop - Removes the top element of the stack
 * @stack: Double pointer to the head of the stack
 * @line_number: Line number in the file
 */
void pop(stack_t **stack, unsigned int line_number)
{
    if (*stack == NULL)
    {
        fprintf(stderr, "L%d: can't pop an empty stack\n", line_number);
        exit(EXIT_FAILURE);
    }

    stack_t *temp = *stack;

    if (temp->next)
        temp->next->previous = NULL;

    *stack = temp->next;
    free(temp);
}

