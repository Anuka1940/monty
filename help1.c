#include "monty.h"
/**
 * process_file- function that open, read and manipulate the monty bytecode
 * @filename: name of monty bytecode file
 * @stack: double pointer to stack
 */
void process_file(char *filename, stack_t **stack)
{
	size_t len;
	ssize_t read;
	unsigned int line_number = 0;
	char *line = NULL;
	FILE *fp;
	char *op;

	if (!filename)
	{
		printf("Error: Can't open file %s\n", filename);
		exit(EXIT_FAILURE);
	}
	fp = fopen(filename, "r");
	if (fp == NULL)
	{
		printf("Error: Can't open file %s\n", filename);
		exit(EXIT_FAILURE);
	}
	atexit(free_all);
	while ((read = getline(&line, &len, fp)) != -1)
	{
		op = strtok(line, DELIMS);
		line_number++;
		if (op)
			delegate_op(stack, op, line_number);
	}
	free(line);
	fclose(fp);
	exit(EXIT_SUCCESS);
}

