#include "binary_trees.h"

/**
* bst_find_min - Finds the node with the minimum value in a BST.
* @root: The root of the BST.
*
* Return: The node with the minimum value.
*/
bst_t *bst_find_min(bst_t *root)
{
	while (root->left != NULL)
		root = root->left;
	return (root);
}

/**
* bst_remove - Removes a node from a Binary Search Tree.
* @root: A pointer to the root node of the tree where you will remove a node.
* @value: The value to remove in the tree.
*
* Return: A pointer to the new root node of the tree after removing the desired value.
*/
bst_t *bst_remove(bst_t *root, int value)
{
	if (root == NULL)
		return (NULL);

	if (value < root->n)
		root->left = bst_remove(root->left, value);
	else if (value > root->n)
		root->right = bst_remove(root->right, value);
	else
	{
		if (root->left == NULL)
		{
			bst_t *temp = root->right;
			free(root);
			return (temp);
		}
		else if (root->right == NULL)
		{
			bst_t *temp = root->left;
			free(root);
			return (temp);
		}

		bst_t *temp = bst_find_min(root->right);
		root->n = temp->n;
		root->right = bst_remove(root->right, temp->n);
	}
	return (root);
}
