#include "binary_trees.h"

/**
 * check_bst - Helper function to check if binary tree is a BST
 * @tree: pointer to the root node of the tree to check
 * @min: pointer to the node that contains the minimum value allowed
 * @max: pointer to the node that contains the maximum value allowed
 *
 * Return: 1 if tree is a valid BST, and 0 otherwise
 */
int check_bst(const binary_tree_t *tree, const binary_tree_t *min, const binary_tree_t *max)
{
	if (tree == NULL)
		return (1);

	if (min != NULL && tree->n <= min->n)
		return (0);
	if (max != NULL && tree->n >= max->n)
		return (0);

	return (check_bst(tree->left, min, tree) && check_bst(tree->right, tree, max));
}

/**
 * binary_tree_is_bst - Checks if a binary tree is a valid Binary Search Tree
 * @tree: pointer to the root node of the tree to check
 *
 * Return: 1 if tree is a valid BST, and 0 otherwise
 */
int binary_tree_is_bst(const binary_tree_t *tree)
{
	return (check_bst(tree, NULL, NULL));
}
