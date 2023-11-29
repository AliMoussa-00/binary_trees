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
/**
 * binary_trees_ancestor - fun finds the lowest common ancestor of two nodes
 * @first: params
 * @second: params
 * Return: binary_tree_t
 */

binary_tree_t *binary_trees_ancestor(const binary_tree_t *first,
	const binary_tree_t *second)
{
	size_t n, m;

	if (!first || !second)
		return (NULL);

	n = binary_tree_depth(first);
	m = binary_tree_depth(second);

	while (n > m)
	{
		first = first->parent;
		n--;
	}
	while (n < m)
	{
		second = second->parent;
		m--;
	}
	while (first && second)
	{
		if (first == second)
			return ((binary_tree_t *)first);
		first = first->parent;
		second = second->parent;
	}

	return ((binary_tree_t *)first);
}
