#include "binary_trees.h"
/**
 * binary_tree_inorder - Perform in-order traversal on the binary tree
 * @tree: The binary tree to traverse
 * @func: The function to use for each node's value
 * Return: Nothing
 */
void binary_tree_inorder(const binary_tree_t *tree, void (*func)(int))
{
	if (tree == NULL || func == NULL)
	{
		return;
	}
	else
	{
		binary_tree_inorder(tree->left, func);
		func(tree->n);
		binary_tree_inorder(tree->right, func);
	}
}

