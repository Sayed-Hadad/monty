#define _GNU_SOURCE
#include "monty.h"

int data;

/**
 * free_stack - frees stack
 *
 * @head: the head of the doubly linked list
 * Return: void
 */
void free_stack(stack_t *head)
{
	stack_t *current = head, *temp;

	while (current != NULL)
	{
		temp = current;
		current = current->next;
		free(temp);
	}
}
/**
 * main - entry point
 *
 * @argc: number of command line args
 * @argv: list of cmd args
 * Return: int
 */
int main(int argc, char *argv[])
{
	FILE *fp;
	char *line = NULL;
	size_t len = 0;
	ssize_t read;
	stack_t *stack = NULL;
	unsigned int line_num = 0;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	fp = fopen(argv[1], "r");
	if (fp == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	while ((read = getline(&line, &len, fp)) != -1)
	{
		if ((process_line(line, &stack, line_num) == -1))
		{
			free_stack(stack);
			free(line);
			fclose(fp);
			exit(EXIT_FAILURE);
		}
		line_num++;
	}
	free_stack(stack);
	free(line);
	fclose(fp);
	return (0);
}
