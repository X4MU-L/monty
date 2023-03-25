#include "monty.h"

/**
 * add_node_start - add a node to the top on the stack
 * @head: a pointer to the stack
 * @n: int data to add to the stack
 *
 * Return: return a pointer to the new node
 */

stack_t *add_node_start(stack_t **head, int n)
{
	stack_t *new, *temp;

	if (!head)
		return (NULL);

	temp = *head;
	new = malloc(sizeof(stack_t));
	if (new == NULL)
		return (NULL);
	new->n = n;
	if (!temp)
	{
		new->prev = NULL;
		new->next = NULL;
		*head = new;
		return (new);
	}
	temp->prev = new;
	new->next = temp;
	*head = new;
	return (new);
}

/**
 * remove_node_start - delete a node from top of the stack
 * @stack: pointer to the stack
 *
 * Return: return 0 on success and -1 on failure
 */
int remove_node_start(stack_t **stack)
{
	stack_t *temp;

	if (!stack || !*stack)
		return (-1);

	temp = *stack;
	*stack = temp->next;
	free(temp);
	return (0);
}

/**
 * free_stack - frees the memory of a stack node
 * @head: pointer to a stack node
 * Return: void
 */
void free_stack(stack_t *head)
{
	stack_t *temp;

	while ((temp = head) != NULL)
	{
		head = head->next;
		free(temp);
	}
}

/**
 * exit_free - frees heaps allocation on exit
 * @head: pointer to stack node
 * @str: pointer to char
 * @stream: FILE descriptor
 * Return: void
 */

int exit_free(stack_t *head, char *str, FILE *stream)
{
	free_stack(head);
	free(str);
	fclose(stream);

	return (0);
}
