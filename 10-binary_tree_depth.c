#include "binary_trees.h"
/**
 * binary_tree_depth - Calculate the depth of a node from the root
 * @tree: The node to check the depth for
 * Return: 0 if it is the root, or the number of depth from the root
 */
size_t binary_tree_depth(const binary_tree_t *tree)
{
	return ((tree && tree->parent) ? 1 + binary_tree_depth(tree->parent) : 0);
}

