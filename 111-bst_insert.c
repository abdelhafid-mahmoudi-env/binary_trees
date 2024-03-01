#include "binary_trees.h"

/**
 * bst_insert - Inserts a value in a Binary Search Tree
 * @tree: Double pointer to the root node of the BST to insert the value
 * @value: The value to store in the node to be inserted
 *
 * Return: A pointer to the created node, or NULL on failure
 */
bst_t *bst_insert(bst_t **tree, int value)
{
    bst_t *node = NULL;
    bst_t *current = NULL;
    bst_t *parent = NULL;

    if (!tree)
        return (NULL);

    /* Create a new node */
    node = binary_tree_node(NULL, value);
    if (!node)
        return (NULL);

    /* If the tree is empty, insert the new node as the root */
    if (!*tree)
    {
        *tree = node;
        return (node);
    }

    /* Find the correct position for the new node */
    current = *tree;
    while (current)
    {
        parent = current;
        if (value < current->n)
        {
            current = current->left;
            if (!current)
            {
                parent->left = node;
                node->parent = parent;
                return (node);
            }
        }
        else if (value > current->n)
        {
            current = current->right;
            if (!current)
            {
                parent->right = node;
                node->parent = parent;
                return (node);
            }
        }
        else /* If the value is already present in the tree, ignore it */
        {
            free(node); /* Clean up the created node */
            return (NULL);
        }
    }

    /* This point should never be reached */
    return (NULL);
}
