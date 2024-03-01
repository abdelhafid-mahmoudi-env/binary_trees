#include "binary_trees.h"

/**
 * bst_search - Searches for a value in a Binary Search Tree
 * @tree: Pointer to the root node of the BST to search
 * @value: The value to search in the tree
 *
 * Return: Pointer to the node containing a value equals to value
 *         If tree is NULL or if nothing is found, return NULL
 */
bst_t *bst_search(const bst_t *tree, int value)
{
	while (tree != NULL)
	{
		if (value < tree->n)
			tree = tree->left;
		else if (value > tree->n)
			tree = tree->right;
		else
			return ((bst_t *)tree);
	}
	return (NULL);
}
