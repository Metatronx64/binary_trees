#include "binary_trees.h"

/**
 * binary_tree_sibling - Find the sibling node of a given node in a binary tree
 * @node: The node to check
 * Return: The sibling node or NULL if it doesn't exist
 */
binary_tree_t *binary_tree_sibling(binary_tree_t *node)
{
	if (node == NULL || node->parent == NULL)
	{
		return (NULL);
	}

	if (node->parent->left == node)
		return (node->parent->right);

	return (node->parent->left);
}

