#include "binary_trees.h"
/**
 * binary_tree_add_right - append a node to the right of the parent
 * If a parent exists, traverse down one level and append the new node first
 * @parent: parent node of the specified node
 * @value: value to be assigned to the new node
 * Return: NULL if the addition fails, or the new node
 */

binary_tree_t *binary_tree_add_right(binary_tree_t *parent, int value)
{
    binary_tree_t *new_node;

    if (parent == NULL)
    {
        return (NULL);
    }

    new_node = binary_tree_node(parent, value);
    if (new_node == NULL)
    {
        return (NULL);
    }
    if (parent->right != NULL)
    {
        new_node->right = parent->right;
        parent->right->parent = new_node;
    }
    parent->right = new_node;
    return (new_node);
}

