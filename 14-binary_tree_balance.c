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
 * binary_tree_balance - fun that measures the balance factor of a binary tree
 * @tree: params
 * Return: int
 */

int binary_tree_balance(const binary_tree_t *tree)
{
	int leftHeight, rightHeight;

	if (!tree)
		return (0);

	leftHeight =  binary_tree_height(tree->left);
	rightHeight =  binary_tree_height(tree->right);
	return (leftHeight - rightHeight);
}
