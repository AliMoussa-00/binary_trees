#include "binary_trees.h"

/**
 * binary_tree_height - a function that checks the height
 *			of a binary tree if the same.
 * @tree: a pointer to the root node of the tree to measure the height.
 * Return: the height of the tree.
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
	int left_height, right_height, max;

	if (!tree)
		return (0);

	left_height = 1 + binary_tree_height(tree->left);
	right_height = 1 + binary_tree_height(tree->right);

	max = left_height == right_height ? left_height : 0;
	return (max);

}

/**
 * binary_tree_is_perfect - a function that checks if a binary tree is perfect<
 * @tree:  a pointer to the root node of the tree to check
 * Return: 1 if true else 0
 */
int binary_tree_is_perfect(const binary_tree_t *tree)
{
	if (!tree)
		return (0);

	if ((!tree->left && tree->right) || (tree->left && !tree->right))
		return (0);

	if (!tree->left && !tree->right)
		return (1);

	if (binary_tree_height(tree->left) == binary_tree_height(tree->right))
	{
		if (binary_tree_is_perfect(tree->left) &&
				binary_tree_is_perfect(tree->right))
			return (1);
	}

	return (0);
}
