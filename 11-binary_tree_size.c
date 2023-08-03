#include "binary_trees.h"
/**
 * binary_tree_size - Calculate the size of a binary tree
 * @tree: The binary tree to measure
 * Return: The size (number of nodes) of the binary tree
 */
size_t binary_tree_size(const binary_tree_t *tree)
{
	size_t size = 0, r = 0, l = 0;

	if (tree == NULL)
	{
		return (0);
	}
	else
	{
		l = binary_tree_size(tree->left);
		r = binary_tree_size(tree->right);
		size = r + l + 1;
	}
	return (size);
}

