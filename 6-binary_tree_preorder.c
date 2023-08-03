#include "binary_trees.h"
/**
 * binary_tree_preorder - Perform pre-order traversal on the binary tree
 * @tree: The binary tree to traverse
 * @func: The function to use for each node's value
 * Return: Nothing
 */
void binary_tree_preorder(const binary_tree_t *tree, void (*func)(int))
{
	if (tree == NULL || func == NULL)
	{
		return;
	}
	else
	{
		func(tree->n);
		binary_tree_preorder(tree->left, func);
		binary_tree_preorder(tree->right, func);
	}
}

