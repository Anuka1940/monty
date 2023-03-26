#include "monty.h"
/**
 * instruction_push- push a new data to stack
 * @stack: double pointer to top of stack
 * @line_number: file line number
 */
void instruction_push(stack_t **stack, unsigned int line_number)
{
	stack_t *new = malloc(sizeof(stack_t));
	int num, base = 10;
	char *op, *endptr;

	if (new == NULL)
	{
		printf("Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	op = strtok(NULL, DELIMS);
	if (op == NULL || stack == NULL)
	{
		printf("L%u: usage: push integer", line_number);
		exit(EXIT_FAILURE);
	}
	num = strtol(op, &endptr, base);
	new->n = num;
	new->prev = NULL;
	new->next = *stack;
	if (new->next != NULL)
		(new->next)->prev = new;
	*stack = new;
}
/**
 * instruction_pall- display the contents of stack following  LIFO
 * @stack: double pointer to stack
 * @line_number: void file line number
 */
void instruction_pall(stack_t **stack, unsigned int line_number)
{
	stack_t *temp = NULL;

	(void)(line_number);
	temp = *stack;
	while (temp != NULL)
	{
		printf("%d\n", temp->n);
		temp = temp->next;
	}
}
/**
 * pint- print the first element on the stack
 * @stack: double pointer to stack
 * @line_number: void file line number
 */
void pint(stack_t **stack, unsigned int line_number)
{
	if (stack == NULL || *stack == NULL)
	{
		printf("L%u: can't pint, stack empty", line_number);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", (*stack)->n);
}

/**
 * pop- delete element on top of the stack
 * @stack: double pointer to stack
 * @line_number: void file line number
 */
void pop(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;

	if (stack == NULL || *stack == NULL)
	{
		printf("L%u: can't pint, stack empty", line_number);
		exit(EXIT_FAILURE);
	}
	temp = *stack;
	(*stack) = (*stack)->next;
	free(temp);
}
