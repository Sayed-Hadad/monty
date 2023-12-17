#include "monty.h"

/**
 * divide - div the first 2 elements in the stack
 *
 * @stack: stack
 * @line_num: the line number
 */
void divide(stack_t **stack, unsigned int line_num)
{
	stack_t *current = *stack;

	if (current == NULL || current->next == NULL)
	{
		fprintf(stderr,  "L%d: can't div, stack too short\n", line_num + 1);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}
	if (current->n == 0)
	{
		fprintf(stderr,  "L%d: division by zero\n", line_num + 1);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}
	(*stack) = current->next;
	(*stack)->n = (*stack)->n / current->n;
	(*stack)->prev = NULL;
	free(current);
}
/**
 * mod - mod the first 2 elements in the stack
 *
 * @stack: stack
 * @line_num: the line number
 */
void mod(stack_t **stack, unsigned int line_num)
{
	stack_t *current = *stack;

	if (current == NULL || current->next == NULL)
	{
		fprintf(stderr,  "L%d: can't mod, stack too short\n", line_num + 1);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}
	if (current->n == 0)
	{
		fprintf(stderr,  "L%d: division by zero\n", line_num + 1);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}
	(*stack) = current->next;
	(*stack)->n = (*stack)->n % current->n;
	(*stack)->prev = NULL;
	free(current);
}
/**
 * pchar - prints the ascii char of the top element in the stack
 *
 * @stack: stack
 * @line_num: the line number
 */
void pchar(stack_t **stack, unsigned int line_num)
{
	if ((*stack) == NULL)
	{
		fprintf(stderr,  "L%d: can't pchar, stack empty\n", line_num + 1);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}
	if ((*stack)->n > 127 || (*stack)->n < 0)
	{
		fprintf(stderr,  "L%d: can't pchar, value out of range\n", line_num + 1);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}
	printf("%c\n", (*stack)->n);
}
/**
 * pstr - prints the ascii char of all elements in the stack forming a string
 *
 * @stack: stack
 * @line_num: the line number
 */
void pstr(stack_t **stack, unsigned int line_num)
{
	stack_t *current = *stack;

	(void) line_num;
	while (current != NULL && current->n > 0 && current->n <= 127)
	{
		printf("%c", current->n);
		current = current->next;
	}
	printf("\n");
}
