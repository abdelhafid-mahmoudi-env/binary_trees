#include "binary_trees.h"

/**
 * depth - Helper function to determine the depth of the leftmost node.
 * @tree: pointer to the root node of the tree to measure the depth.
 *
 * Return: The depth of the leftmost node.
 */
static int binary_tree_is_perfect(const binary_tree_t *tree)
{
	int left = 0, right = 0;

	if(tree->left && tree->right)
	{
		right = 1 + tree_is_perfect(tree->left);
		left = 1 + tree_is_perfect(tree->right);
		if(left == right && right != 0 && left != 0)
			return (right);
		return (0);
	}
	else if(!tree->right && !tree->left)
	{
		return (1);
	}
	return (0);
}

/**
 * binary_tree_is_perfect - Checks if a binary tree is perfect.
 * @tree: A pointer to the root node of the tree to check.
 *
 * Return: 1 if the tree is perfect, 0 otherwise or if tree is NULL.
 */
int binary_tree_is_perfect(const binary_tree_t *tree)
{
	int isperfect = 0;

	if (tree == NULL)
	{
		return (0);
	}
	else
	{
		isperfect = tree_is_perfect(tree);
		if(isperfect != 0)
		{
			return (1);
		}
		return (0);
	}
}
