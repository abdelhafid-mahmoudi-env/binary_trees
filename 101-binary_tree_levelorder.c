#include "binary_trees.h"
#include <stdlib.h>

/**
 * binary_tree_t struct
 */
typedef struct queue_s
{
	const binary_tree_t *node;
	struct queue_s *next;
} queue_t;

/**
 * enqueue - Adds an item to the queue
 * @head: Double pointer to the head of the queue
 * @node: Pointer to the binary tree node to add to the queue
 */
void enqueue(queue_t **head, const binary_tree_t *node)
{
	queue_t *new_node = malloc(sizeof(queue_t));
	queue_t *temp = *head;

	if (!new_node)
		return;

	new_node->node = node;
	new_node->next = NULL;

	if (!*head)
	{
		*head = new_node;
		return;
	}

	while (temp->next)
		temp = temp->next;

	temp->next = new_node;
}

/**
 * dequeue - Removes an item from the queue
 * @head: Double pointer to the head of the queue
 *
 * Return: The node that was removed
 */
const binary_tree_t *dequeue(queue_t **head)
{
	queue_t *temp;
	const binary_tree_t *ret_node;

	if (!head || !*head)
		return (NULL);

	temp = *head;
	ret_node = temp->node;
	*head = temp->next;
	free(temp);

	return (ret_node);
}

/**
 * binary_tree_levelorder - Goes through a binary tree using level-order traversal
 * @tree: Pointer to the root node of the tree to traverse
 * @func: Pointer to a function to call for each node.
 *        The value in the node must be passed as a parameter to this function.
 */
void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int))
{
	queue_t *queue = NULL;
	const binary_tree_t *temp_node;

	if (!tree || !func)
		return;

	enqueue(&queue, tree);
	while ((temp_node = dequeue(&queue)) != NULL)
	{
		func(temp_node->n);
		if (temp_node->left)
			enqueue(&queue, temp_node->left);
		if (temp_node->right)
			enqueue(&queue, temp_node->right);
	}
}

