#include "monty.h"

/**
 * swap - swaps the first 2 elements in the stack
 *
 * @stack: stack
 * @line_num: the line number
 */
void swap(stack_t **stack, unsigned int line_num)
{
	stack_t *current = *stack;

	if (current == NULL || current->next == NULL)
	{
		fprintf(stderr,  "L%d: can't swap, stack too short\n", line_num + 1);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}
	current = current->next;
	(*stack)->next = current->next;
	(*stack)->prev = current;
	current->next = (*stack);
	current->prev = NULL;
	(*stack) = current;
}

/**
 * add - adds the first 2 elements in the stack
 *
 * @stack: stack
 * @line_num: the line number
 */
void add(stack_t **stack, unsigned int line_num)
{
	stack_t *current = *stack;

	if (current == NULL || current->next == NULL)
	{
		fprintf(stderr,  "L%d: can't add, stack too short\n", line_num + 1);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}
	(*stack) = current->next;
	(*stack)->n += current->n;
	(*stack)->prev = NULL;
	free(current);
}
/**
 * nop - an opcode that doesn't do anything
 *
 * @stack: stack
 * @line_num: the line number
 */
void nop(stack_t **stack, unsigned int line_num)
{
	(void) stack;
	(void) line_num;
}
/**
 * sub - subs the first 2 elements in the stack
 *
 * @stack: stack
 * @line_num: the line number
 */
void sub(stack_t **stack, unsigned int line_num)
{
	stack_t *current = *stack;

	if (current == NULL || current->next == NULL)
	{
		fprintf(stderr,  "L%d: can't sub, stack too short\n", line_num + 1);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}
	(*stack) = current->next;
	(*stack)->n -= current->n;
	(*stack)->prev = NULL;
	free(current);
}
/**
 * mul - mul the first 2 elements in the stack
 *
 * @stack: stack
 * @line_num: the line number
 */
void mul(stack_t **stack, unsigned int line_num)
{
	stack_t *current = *stack;

	if (current == NULL || current->next == NULL)
	{
		fprintf(stderr,  "L%d: can't mul, stack too short\n", line_num + 1);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}
	(*stack) = current->next;
	(*stack)->n *= current->n;
	(*stack)->prev = NULL;
	free(current);
}
