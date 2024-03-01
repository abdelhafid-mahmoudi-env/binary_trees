#include "binary_trees.h"
#include <stdlib.h>

/**
 * count_nodes - Counts the number of nodes in a binary tree
 * @tree: pointer to the root node of the tree to count the number of nodes
 *
 * Return: number of nodes in the tree
 */
static int count_nodes(const binary_tree_t *tree)
{
	if (!tree)
		return (0);
	return (1 + count_nodes(tree->left) + count_nodes(tree->right));
}

/**
 * is_complete - Recursively checks if a binary tree is complete
 * @tree: pointer to the root node of the tree to check
 * @index: index of the current node
 * @number_nodes: total number of nodes in the tree
 *
 * Return: 1 if complete, 0 otherwise
 */
static int is_complete(const binary_tree_t *tree, int index, int number_nodes)
{
	if (!tree)
		return (1);
	if (index >= number_nodes)
		return (0);
	return (is_complete(tree->left, 2 * index + 1, number_nodes) &&
		is_complete(tree->right, 2 * index + 2, number_nodes));
}

/**
 * binary_tree_is_complete - Checks if a binary tree is complete
 * @tree: pointer to the root node of the tree to check
 *
 * Return: 1 if the tree is complete, 0 otherwise
 */
int binary_tree_is_complete(const binary_tree_t *tree)
{
	int node_count;

	if (!tree)
		return (0);

	node_count = count_nodes(tree);
	return (is_complete(tree, 0, node_count));
}
