#include "binary_trees.h"

/**
 * binary_tree_nodes - Counts nodes with at least one child inbinary tree
 * @tree: A pointer to the root node of tree to count the number of nodes
 *
 * Return: number of nodes with at least one child. If tree is NULL return 0.
 */
size_t binary_tree_nodes(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);

	if (tree->left == NULL && tree->right == NULL)
		return (0);

	return (1 + binary_tree_nodes(tree->left) + binary_tree_nodes(tree->right));
}
