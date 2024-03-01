#include "binary_trees.h"

/**
* height - Measures the height of a binary tree
* @tree: Pointer to the root node of the tree to measure the height.
* Return: The height of the tree.
*/
static int height(const binary_tree_t *tree)
{
	int left_height = 0, right_height = 0;

	if (!tree)
		return (-1);
	if (tree->left)
		left_height = height(tree->left) + 1;
	if (tree->right)
		right_height = height(tree->right) + 1;
	return (left_height > right_height ? left_height : right_height);
}

/**
* binary_tree_balance - Measures the balance factor of a binary tree
* @tree: Pointer to the root node of the tree to measure the balance factor.
* Return: The balance factor.
*/
int binary_tree_balance(const binary_tree_t *tree)
{
	int left_height, right_height;

	if (!tree)
		return (0);
	left_height = tree->left ? height(tree->left) + 1 : 0;
	right_height = tree->right ? height(tree->right) + 1 : 0;
	return (left_height - right_height);
}
