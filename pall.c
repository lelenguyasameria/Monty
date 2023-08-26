#include "monty.h"
/**
 * pall - Prints all the values on the stack.
 * @stack: Pointer to the head of the stack.
 * @line_number: Line number of the instruction.
 */
void pall(stack_element **stack, unsigned int line_number)
{
    (void) line_number;

    stack_t *current = *stack;
    while (current)
    {
        printf("%d\n", current->data);
        current = current->next;
    }
}
