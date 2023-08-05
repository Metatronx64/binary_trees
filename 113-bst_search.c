#include "binary_trees.h"

/**
 * bst_search - Searches for a specific value in a binary search tree (BST)
 * and returns the node containing the value.
 *
 * @tree: Pointer to the root node of the binary search tree.
 * @value: The value to search for.
 *
 * Return: Pointer to the node containing the value or NULL if the value is not in the tree.
 */
bst_t *bst_search(const bst_t *tree, int value)
{
	bst_t *found;

	if (tree == NULL)
		return (NULL);

	if (value < tree->n)
	{
		found = bst_search(tree->left, value);
	}
	else if (value > tree->n)
	{
		found = bst_search(tree->right, value);
	}
	else if (value == tree->n)
		return ((bst_t *)tree);
	else
		return (NULL);

	return (found);
}

