#include "binary_trees.h"
/**
 * binary_tree_destroy - recursively free an entire tree
 * It frees the node when the node's left and right pointers are NULL.
 * @tree: tree to be freed
 * Return: Nothing
 */
void binary_tree_destroy(binary_tree_t *tree)
{
    if (tree == NULL)
    {
        return;
    }
    else
    {
        if (tree != NULL)
        {
            binary_tree_destroy(tree->left);
            binary_tree_destroy(tree->right);
        }
        free(tree);
    }
}

