#include "binary_trees.h"

/**
 * binary_tree_insert_right - a function that inserts a node as
 *			the right-child of another node
 * @parent: the pointer to the node
 * @value: the value of the node
 * Return: pointer to the node or NULL
 */
binary_tree_t *binary_tree_insert_right(binary_tree_t *parent, int value)
{
	binary_tree_t *node;

	if (!parent)
		return (NULL);

	node = malloc(sizeof(binary_tree_t));
	if (!node)
		return (NULL);

	node->n = value;
	node->left = NULL;
	node->parent = parent;

	if (!parent->right)
	{
		node->right = NULL;
		parent->right = node;
	}
	else
	{
		node->right = parent->right;
		parent->right->parent = node;
		parent->right = node;
	}

	return (node);
}
