#include "binary_trees.h"

/**
 * binary_tree_uncle -  function that finds the uncle of a node
 * @node: params
 * Return: binary_tree_t
 */

binary_tree_t *binary_tree_uncle(binary_tree_t *node)
{
	if (!node || (node && !node->parent) ||
			(node && node->parent && !node->parent->parent))
		return (NULL);

	if (node->parent->parent->left == node->parent)
		return (node->parent->parent->right);

	return (node->parent->parent->left);
}
