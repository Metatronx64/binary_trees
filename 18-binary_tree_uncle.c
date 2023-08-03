#include "binary_trees.h"

/**
 * binary_tree_uncle - Find the uncle node of a given node in a binary tree
 * @node: The node to check
 * Return: The uncle node or NULL if it doesn't exist
 */
binary_tree_t *binary_tree_uncle(binary_tree_t *node)
{
	if (node == NULL || node->parent == NULL || node->parent->parent == NULL)
	{
		return (NULL);
	}

	if (node->parent->parent->left == node->parent)
		return (node->parent->parent->right);

	return (node->parent->parent->left);
}

