#include "binary_trees.h"

/**
 * max - max of two integer
 * @a: params
 * @b: params
 * Return: int
 */

int max(int a, int b)
{
	return ((a > b) ? a : b);
}

/**
 * binary_tree_height -  function that measures the height of a binary tree
 * @tree: params
 * Return: size_t
 */

size_t binary_tree_height(const binary_tree_t *tree)
{
	int rightHeight, leftHeight;

	if (!tree)
		return (0);

	leftHeight = 1 + binary_tree_height(tree->left);
	rightHeight = 1 + binary_tree_height(tree->right);

	return (max(leftHeight, rightHeight));
}
/**
 * binary_tree_is_perfect -  function that checks if a binary tree is perfect
 * @tree: params
 * Return: int
 */

int binary_tree_is_perfect(const binary_tree_t *tree)
{
	binary_tree_t *l, *r;

	l = tree->left;
	r = tree->right;

	if (!tree)
		return (0);

	if ((!l && r) || (l && !r))
		return (0);
	if (!l && !r)
		return (1);

	if (binary_tree_height(l) == binary_tree_height(r))
	{
		if (binary_tree_is_perfect(l) && binary_tree_is_perfect(r))
			return (1);
	}
	return (0);
}

/**
 * binary_tree_is_complete - function that checks if a binary tree is complete
 * @tree: params
 * Return: int
 */

int binary_tree_is_complete(const binary_tree_t *tree)
{

	binary_tree_t *l, *r;

	l = tree->left;
	r = tree->right;

	if (!tree)
		return (0);

	if (!l && r)
		return (0);

	if ((!l && !r) || (l && !r))
		return (1);

	if (binary_tree_height(l) == binary_tree_height(r))
	{
		if (binary_tree_is_perfect(l) && binary_tree_is_complete(r))
			return (1);
	}
	else if (binary_tree_height(l) == binary_tree_height(r) + 1)
	{
		if (binary_tree_is_complete(l) && binary_tree_is_perfect(r))
			return (1);
	}
	return (0);
}
