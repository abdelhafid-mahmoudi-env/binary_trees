#include "binary_trees.h"

/**
 * binary_tree_sibling - Finds the sibling of a node in a binary tree.
 * @node: A pointer to the node to find the sibling of.
 *
 * Return: A pointer to the sibling node. If node is NULL, the parent is NULL,
 *         or the node has no sibling, return NULL.
 */
binary_tree_t *binary_tree_sibling(binary_tree_t *node)
{
    if (node == NULL || node->parent == NULL)
        return (NULL);

    // Si le nœud est le fils gauche, retourne le fils droit et vice versa.
    if (node->parent->left == node)
        return (node->parent->right);
    else
        return (node->parent->left);
}
