#include "binary_trees.h"

/**
 * binary_tree_height - Measures the height of a binary tree.
 * @tree: A pointer to the root node of the tree whose height is to be measured.
 * 
 * Description: This function recursively calculates the height of the left and right subtrees,
 *              then returns the greater of the two values, increased by one.
 * Return: The height of the tree if the tree is not NULL, otherwise 0.
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
    size_t right, left;

    // Returns 0 if the tree is NULL or if it is a leaf.
    if (tree == NULL || (tree->left == NULL && tree->right == NULL))
        return (0);

    // Calculates the height of the left and right subtrees, respectively.
    left = binary_tree_height(tree->left) + 1;
    right = binary_tree_height(tree->right) + 1;

    // Returns the greater height of the two.
    if (left > right)
        return (left);
    return (right);
}

/**
 * binary_tree_balance - Measures the balance factor of a binary tree.
 * @tree: A pointer to the root node of the tree whose balance factor is to be measured.
 * 
 * Description: The function calculates the difference between the heights of the left and right subtrees.
 *              A positive balance factor indicates the left subtree is taller,
 *              while a negative factor indicates the right subtree is taller.
 * Return: The balance factor of the tree. If the tree is NULL, returns 0.
 */
int binary_tree_balance(const binary_tree_t *tree)
{
    size_t left = 0, right = 0;

    // Directly returns 0 if the tree is NULL.
    if (tree == NULL)
        return (0);

    // Calculates the heights of the left and right subtrees.
    left = binary_tree_height(tree->left);
    right = binary_tree_height(tree->right);

    // Returns the difference between the heights of the left and right subtrees.
    return (left - right);
}

