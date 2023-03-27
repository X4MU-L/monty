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
 * add_node_end - add a node to the end on the stack
 * @head: a pointer to the stack
 * @n: int data to add to the stack
 *
 * Return: return a pointer to the new node
 */

stack_t *add_node_end(stack_t **head, int n)
{
	stack_t *new, *temp;

	temp = *head;
	new = malloc(sizeof(stack_t));
	if (new == NULL)
		return (NULL);
	new->n = n;
	new->next = NULL;
	if (!temp)
	{
		new->prev = NULL;
		*head = new;
		return (new);
	}
	while (temp->next)
		temp = temp->next;
	temp->next = new;
	new->prev = temp;
	return (new);
}

/**
 * remove_node_start - delete a node from top of the stack
 * @stack: pointer to the stack
 *
 * Return: return 1 on success and 0 on failure
 */
int remove_node_start(stack_t **stack)
{
	stack_t *temp;

	if (!stack || !*stack)
		return (0);

	temp = *stack;
	*stack = temp->next;
	free(temp);
	return (1);
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
 * Return: always EXIT_SUCCESS
 */

int exit_free(stack_t *head, char *str, FILE *stream)
{
	free_stack(head);
	free(str);
	fclose(stream);

	return (EXIT_SUCCESS);
}
