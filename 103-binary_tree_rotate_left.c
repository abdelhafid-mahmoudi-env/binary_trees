#include "binary_trees.h"

/**
 * binary_tree_rotate_left - Performs a left-rotation on a binary tree
 * @tree: pointer to the root node of the tree to rotate
 *
 * Return: A pointer to the new root node of the tree once rotated
 */
binary_tree_t *binary_tree_rotate_left(binary_tree_t *tree)
{
	binary_tree_t *new_root;

	if (!tree || !tree->right)
		return (tree);

	new_root = tree->right; /* Step 1 */
	tree->right = new_root->left; /* Prepare for step 3 */

	if (new_root->left) /* Step 3 */
		new_root->left->parent = tree;

	new_root->left = tree; /* Step 2 */
	new_root->parent = tree->parent;
	tree->parent = new_root;

	return (new_root);
}
