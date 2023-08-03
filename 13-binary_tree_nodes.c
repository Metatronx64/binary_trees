#include "binary_trees.h"
/**
 * binary_tree_nodes - Calculate the number of nodes in the binary tree with children
 * @tree: The binary tree to check
 * Return: The number of nodes in the binary tree that have children
 */
size_t binary_tree_nodes(const binary_tree_t *tree)
{
	size_t node = 0;

	if (tree == NULL)
	{
		return (0);
	}
	else
	{
		node += ((tree->left || tree->right) ? 1 : 0);
		node += binary_tree_nodes(tree->left);
		node += binary_tree_nodes(tree->right);
		return (node);
	}
}

