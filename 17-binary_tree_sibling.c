#include "binary_trees.h"

/**
 * binary_tree_sibling - function that finds the sibling of a node
 * @node: params
 * Return: binary_tree_t
 */

binary_tree_t *binary_tree_sibling(binary_tree_t *node)
{
	if (!node || (node && !node->parent))
		return (NULL);

	if (node->parent->left == node)
		return (node->parent->right);

	return (node->parent->left);


}
