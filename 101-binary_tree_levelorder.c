#include "binary_trees.h"

/**
 * binary_tree_height - Measures the height of a binary tree.
 * @tree: Pointer to the root of the tree.
 * Return: The height of the tree.
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
	size_t left_height = 0;
	size_t right_height = 0;

	if (tree == NULL)
	{
		return (0);
	}
	else
	{
		if (tree)
		{
			left_height = tree->left ? 1 + binary_tree_height(tree->left) : 0;
			right_height = tree->right ? 1 + binary_tree_height(tree->right) : 0;
		}
		return ((left_height > right_height) ? left_height : right_height);
	}
}

/**
 * binary_tree_depth - Calculates the depth of a specified node from the root.
 * @tree: Pointer to the node to check the depth for.
 * Return: 0 if it is the root, or the number of levels from the root to the node.
 */
size_t binary_tree_depth(const binary_tree_t *tree)
{
	return ((tree && tree->parent) ? 1 + binary_tree_depth(tree->parent) : 0);
}

/**
 * linked_node - Creates a linked list node to store a tree node along with its depth level.
 * @head: Pointer to the head of the linked list.
 * @tree: Pointer to the node to store in the linked list.
 * @level: Depth level of the node to store.
 * Return: Nothing.
 */
void linked_node(link_t **head, const binary_tree_t *tree, size_t level)
{
	link_t *new, *aux;

	new = malloc(sizeof(link_t));
	if (new == NULL)
	{
		return;
	}

	new->n = level;
	new->node = tree;

	if (*head == NULL)
	{
		new->next = NULL;
		*head = new;
	}
	else
	{
		aux = *head;
		while (aux->next != NULL)
		{
			aux = aux->next;
		}
		new->next = NULL;
		aux->next = new;
	}
}

/**
 * recursion - Traverses the complete tree and stores each node in a linked list using linked_node.
 * @head: Pointer to the head of the linked list.
 * @tree: Pointer to the current node to check.
 * Return: Nothing; it affects the linked list through the pointer.
 */
void recursion(link_t **head, const binary_tree_t *tree)
{
	size_t level = 0;

	if (tree != NULL)
	{
		level = binary_tree_depth(tree);
		linked_node(head, tree, level);
		recursion(head, tree->left);
		recursion(head, tree->right);
	}
}

/**
 * binary_tree_levelorder - Prints the elements of the binary tree in level-order.
 * @tree: Pointer to the root node of the binary tree.
 * @func: Function to use for printing the node elements.
 * Return: Nothing.
 */
void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int))
{
	link_t *head, *aux;
	size_t height = 0, count = 0;

	if (!tree || !func)
	{
		return;
	}
	else
	{
		height = binary_tree_height(tree);
		head = NULL;
		recursion(&head, tree);

		while (count <= height)
		{
			aux = head;
			while (aux != NULL)
			{
				if (count == aux->n)
				{
					func(aux->node->n);
				}
				aux = aux->next;
			}
			count++;
		}

		while (head != NULL)
		{
			aux = head;
			head = head->next;
			free(aux);
		}
	}
}

