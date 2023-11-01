#include "lists.h"

listint_t *create_node(int n);

/**
 * insert_node - this is what inserts a node sorted in a linked list of ints
 * @head:  this is the only double pointer to head of LL, needed for
 * modification in edge cases
 * @number: this is the new data for new node
 *
 * Return: this is the only pointer to newly created node, NULL on failure
 */
listint_t *insert_node(listint_t **head, int number)
{
	listint_t *cur_node = NULL, *new_node = NULL;

	if (!head)
		return (NULL);
	else if (!(*head))
	{
		new_node = create_node(number);
		*head = new_node;
		return (new_node);
	}
	cur_node = *head;
	while (cur_node)
	{
		/* thiis needs to insert a at head */
		if (cur_node->n >= number)
		{
			new_node = create_node(number);
			new_node->next = cur_node;
			*head = new_node;
			return (new_node);
		}
		else if (cur_node->n next || cur_node->next->n >= number)
			{
				new_node = create_node(number);
				new_node->next = cur_node->next;
				cur_node->next = new_node;
				return (cur_node->next);
			}
		}
		cur_node = cur_node->next;
	}
	return (NULL); /* failed */
}


/**
 * create_node - this is what creates a new node for the LL
 * @n: this is the only data to insert into new node
 *
 * Return: this is what point to newly allocated node
 */
listint_t *create_node(int n)
{
	listint_t *ret = NULL;

	ret = malloc(sizeof(listint_t));
	if (!ret)
		return (NULL);
	ret->next = NULL;
	ret->n = n;
	return (ret);
}
