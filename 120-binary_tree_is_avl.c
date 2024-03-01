#include "binary_trees.h"
#include <limits.h>

/**
 * bst_check - Checks if a binary tree is a valid BST
 * @tree: pointer to the root node of the tree to check
 * @min: minimum value allowed
 * @max: maximum value allowed
 *
 * Return: 1 if tree is a valid BST, 0 otherwise
 */
int bst_check(const binary_tree_t *tree, int min, int max)
{
	if (tree == NULL)
		return (1);
	if (tree->n <= min || tree->n >= max)
		return (0);
	return (bst_check(tree->left, min, tree->n) &&
			bst_check(tree->right, tree->n, max));
}

/**
 * height - Measures the height of a binary tree
 * @tree: pointer to the root node of the tree to measure the height
 *
 * Return: The height of the tree
 */
int height(const binary_tree_t *tree)
{
	int left_height, right_height;

	if (tree == NULL)
		return (0);
	left_height = height(tree->left) + 1;
	right_height = height(tree->right) + 1;
	return ((left_height > right_height) ? left_height : right_height);
}

/**
 * binary_tree_is_avl - Checks if a binary tree is a valid AVL Tree
 * @tree: pointer to the root node of the tree to check
 *
 * Return: 1 if tree is a valid AVL Tree, and 0 otherwise
 */
int binary_tree_is_avl(const binary_tree_t *tree)
{
	int balance;

	if (tree == NULL)
		return (1);

	if (!bst_check(tree, INT_MIN, INT_MAX))
		return (0);

	balance = height(tree->left) - height(tree->right);
	if (abs(balance) > 1)
		return (0);

	if (!binary_tree_is_avl(tree->left) || !binary_tree_is_avl(tree->right))
		return (0);

	return (1);
}
