#include "binary_trees.h"

/**
 * binary_tree_is_root - Determine if a node is a root of the tree
 * @node: Node to check
 * Return: 1 if it is a root, or 0 if it is not
 */
int binary_tree_is_root(const binary_tree_t *node)
{
    if (node == NULL || node->parent != NULL)
        return (0);
    return (1);
}

