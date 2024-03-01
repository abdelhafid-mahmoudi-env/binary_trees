#include "binary_trees.h"

/**
 * depth - Helper function to determine the depth of the leftmost node.
 * @tree: pointer to the root node of the tree to measure the depth.
 *
 * Return: The depth of the leftmost node.
 */
static int depth(const binary_tree_t *tree)
{
    int d = 0;
    while (tree)
    {
        d++;
        tree = tree->left;
    }
    return d;
}

/**
 * is_perfect_rec - Helper function to check if binary tree is perfect recursively.
 * @tree: pointer to the root node of the tree to check.
 * @d: depth of the leftmost node.
 * @level: current level in the tree.
 *
 * Return: 1 if the tree is perfect, 0 otherwise.
 */
static int is_perfect_rec(const binary_tree_t *tree, int d, int level)
{
    if (!tree)
        return 1;

    // Check for leaf node
    if (!tree->left && !tree->right)
        return (d == level + 1);

    if (!tree->left || !tree->right)
        return 0;

    return is_perfect_rec(tree->left, d, level + 1) && is_perfect_rec(tree->right, d, level + 1);
}

/**
 * binary_tree_is_perfect - Checks if a binary tree is perfect.
 * @tree: A pointer to the root node of the tree to check.
 *
 * Return: 1 if the tree is perfect, 0 otherwise or if tree is NULL.
 */
int binary_tree_is_perfect(const binary_tree_t *tree)
{
    int d = depth(tree);
    return is_perfect_rec(tree, d, 0);
}
