#include "monty.h"

glob_t glob = {NULL, NULL};
/**
 * stack_init- initialize all things
 * @head: top of the stack data structure
 */
void stack_init(stack_t **head)
{
	*head = NULL;
	glob.top = head;
}

/**
 * free_all- free all stack after use
 * @stack: double pointer to top of stack
 */
void free_all(void)
{
	stack_t *temp1, *temp2 = NULL;

	temp1 = *(glob.top);
	while (temp1 != NULL)
	{
		temp2 = temp1->next;
		free(temp1);
		temp1 = temp2;
	}
}

/**
 * main- monty bytecode interpreter
 * @argc: number of args on command line
 * @argv: double pointer to array of args on comm line
 *
 * Return: EXIT_SUCCESSFUL or EXIT_FAILURE
 */
int main(int argc, char **argv)
{
	stack_t *head;

	stack_init(&head);
	if (argc != 2)
	{
		printf("USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	process_file(argv[1], &head);
	exit(EXIT_SUCCESS);
}
