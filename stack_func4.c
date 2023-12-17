#include "monty.h"

/**
 * rotl - rotates the stack to the left (to the top)
 *
 * @stack: stack
 * @line_num: the line number
 */
void rotl(stack_t **stack, unsigned int line_num)
{
	stack_t *tail = *stack;

	(void) line_num;
	if (*stack == NULL || (*stack)->next == NULL)
		return;

	while (tail->next != NULL)
		tail = tail->next;

	tail->next = *stack;
	(*stack)->prev = tail;
	*stack = (*stack)->next;
	(*stack)->prev->next = NULL;
	(*stack)->prev = NULL;
}
/**
 * rotr - rotates the stack to the right (to the bottom)
 *
 * @stack: stack
 * @line_num: the line number
 */
void rotr(stack_t **stack, unsigned int line_num)
{
	stack_t *tail = *stack;

	(void) line_num;
	if (*stack == NULL || (*stack)->next == NULL)
		return;

	while (tail->next != NULL)
		tail = tail->next;

	(*stack)->prev = tail;
	tail->next = *stack;
	*stack = tail;
	tail = tail->prev;
	tail->next = NULL;
	(*stack)->prev = NULL;
}
