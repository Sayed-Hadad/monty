#include "monty.h"

/**
 * get_first_string - Get the first string object
 *
 * @input: the input
 * @first_string: pointer to the string
 * Return: void
 */
void get_first_string(char *input, char **first_string)
{
	size_t len = strlen(input);
	size_t i = 0, j = 0;

	*first_string = malloc((len + 1) * sizeof(char));
	if (*first_string == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}

	/* Skip any leading spaces */
	while (i < len && isspace(input[i]))
		i++;

	/* Find the start of the first string */
	while (i < len && !isspace(input[i]))
	{
		(*first_string)[j] = input[i];
		i++;
		j++;
	}
	(*first_string)[j] = 0;
}
/**
 * get_first_integer - Get the first integer object
 * @input: the input
 * @flag: if there's no int argument flag will be 0
 * Return: int
*/
int get_first_integer(char *input, int *flag)
{
	int first_integer = 0;
	size_t len = strlen(input);
	size_t i = 0;
	int sign = 1;

	*flag = 0;
	/* Skip any leading spaces */
	while (i < len && !isdigit(input[i]) && input[i] != '-')
		i++;

	/* Check for sign */
	if (i < len && input[i] == '-')
	{
		sign = -1;
		i++;
	}
	/* Find the start of the integer */
	while (i < len && isdigit(input[i]))
	{
		first_integer = first_integer * 10 + (input[i] - '0');
		i++;
		*flag = 1;
	}
	if (input[i] && !isspace(input[i]))
	{
		*flag = 0;
	}
	return (first_integer * sign);
}

/**
 * process_line - process each line in the input
 *
 * @input: the input
 * @stack: the stack
 * @line_num: the line number
 * Return: execute func;
 */
int process_line(char *input, stack_t **stack, unsigned int line_num)
{
	char *cmd = NULL;
	int flag = 0, to_return;

	get_first_string(input, &cmd);
	if (!cmd[0] || cmd[0] == '\n' || cmd[0] == '#')
	{
		free(cmd);
		return (1);
	}
	data = get_first_integer(input, &flag);
	to_return = execute(cmd, stack, line_num, flag);
	free(cmd);
	return (to_return);
}
