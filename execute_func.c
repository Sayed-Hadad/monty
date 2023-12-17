#include "monty.h"

/**
 * execute - executes the commands
 *
 * @cmd: the command
 * @stack: the stack
 * @line_number: the line_number
 * @flag: 0 if no int data, 1 otherwise
 * Return: 1 or -1
 */
int execute(char *cmd, stack_t **stack, unsigned int line_number, int flag)
{
	instruction_t instructions[] = {
		{"push", push}, {"pall", pall}, {"pint", pint},
		{"pop", pop}, {"swap", swap}, {"add", add}, {"nop", nop},
		{"sub", sub}, {"mul", mul}, {"div", divide}, {"mod", mod},
		{"pchar", pchar}, {"pstr", pstr}, {"rotl", rotl}, {"rotr", rotr},
		{NULL, NULL}
	};
	int cmd_err = 1, i;

	for (i = 0; instructions[i].opcode; i++)
	{
		if (strcmp(cmd, instructions[i].opcode) == 0)
		{
			if (i == 0 && flag == 0)
			{
				fprintf(stderr,  "L%d: usage: push integer\n", line_number + 1);
				return (-1);
			}
			instructions[i].f(stack, line_number);
			cmd_err = 0;
			break;
		}
	}
	if (cmd_err)
	{
		fprintf(stderr, "L%d: unknown instruction %s\n", line_number + 1, cmd);
		return (-1);
	}
	return (1);
}
