#include "monty.h"
/**
 * delegate_op- function thet carry out the needfull ops
 * @stack: double pointer to the stack
 * @op: char pointer to the token from strtok func
 * @line_number: line number in file
 */
void delegate_op(stack_t **stack, char *op, unsigned int line_number)
{
	int i = 0;
	instruction_t all_ops[] = {
		{"push", instruction_push},
		{"pall", instruction_pall},
		{"pint", pint},
		{"pop", pop},
		{"swap", swap},
		{NULL, NULL}
	};

	while (op != NULL && all_ops[i].opcode != NULL)
	{
		if (strcmp(op, all_ops[i].opcode) == 0)
		{
			all_ops[i].f(stack, line_number);
			return;
		}
		i++;
	}
	if (strlen(op) != 0 && op[0] != '#')
	{
		printf("L%u:unknown instruction %s\n", line_number, op);
		exit(EXIT_FAILURE);
	}
}
