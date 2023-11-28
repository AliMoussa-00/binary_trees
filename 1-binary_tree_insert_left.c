#include "binary_trees.h"

/**
 * binary_tree_insert_left - a function that inserts a node as
 *			the left-child of another node
 * @parent: the pointer to the node
 * @value: the value of the node
 * Return: pointer to the node or NULL
 */
binary_tree_t *binary_tree_insert_left(binary_tree_t *parent, int value)
{
	binary_tree_t *node;

	if (!parent)
		return (NULL);

	node = malloc(sizeof(binary_tree_t));
	if (!node)
		return (NULL);

	node->n = value;
	node->right = NULL;
	node->parent = parent;

	if (!parent->left)
	{
		node->left = NULL;
		parent->left = node;
	}
	else
	{
		node->left = parent->left;
		parent->left->parent = node;
		parent->left = node;
	}

	return (node);
}
