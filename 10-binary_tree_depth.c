#include "binary_trees.h"

/**
 * binary_tree_depth - fun that measures the depth of a node in a binary tree
 * @tree: params
 * Return: size_t
 */

size_t binary_tree_depth(const binary_tree_t *tree)
{
	size_t depth = 0;

	if (!tree)
		return (0);

	while (tree->parent)
	{
		depth += 1;
		tree = tree->parent;
	}
	return (depth);

}
