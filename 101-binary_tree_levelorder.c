#include "binary_trees.h"

/**
 * apply_func_at_level - Applies a function to nodes at a specific level
 * @tree: Pointer to the root node of the tree
 * @func: Pointer to a function to call for each node's value
 * @level: Target level to apply the function
 */
static void apply_func_at_level(const binary_tree_t *tree, void (*func)(int), int level)
{
	if (!tree)
		return;
	if (level == 0)
		func(tree->n);
	else
	{
		apply_func_at_level(tree->left, func, level - 1);
		apply_func_at_level(tree->right, func, level - 1);
	}
}

/**
 * tree_height - Calculates the height of a binary tree
 * @tree: Pointer to the root node of the tree
 *
 * Return: The height of the tree
 */
static int tree_height(const binary_tree_t *tree)
{
	if (!tree)
		return -1;
	int left_height = tree_height(tree->left);
	int right_height = tree_height(tree->right);

	return (left_height > right_height ? left_height : right_height) + 1;
}

/**
 * binary_tree_levelorder - Goes through a binary tree using level-order traversal
 * @tree: Pointer to the root node of the tree to traverse
 * @func: Pointer to a function to call for each node's value
 */
void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int))
{
	if (!tree || !func)
		return;

	int height = tree_height(tree);
	for (int level = 0; level <= height; level++)
		apply_func_at_level(tree, func, level);
}

