#include "binary_trees.h"

static int path_to_root(const binary_tree_t *root, const binary_tree_t *node)
{
	if (!root)
		return (0);
	if (root == node)
		return (1);
	return (path_to_root(root->parent, node));
}

binary_tree_t *binary_trees_ancestor(const binary_tree_t *first, const binary_tree_t *second)
{
	if (!first || !second)
		return (NULL);

	if (path_to_root(second, first))
		return ((binary_tree_t *)first);

	if (path_to_root(first, second))
		return ((binary_tree_t *)second);

	return (binary_trees_ancestor(first->parent, second));
}
