#include "binary_trees.h"

/**
 * binary_tree_leaves -  function that counts the leaves in a binary tree
 * @tree: params
 * Return: size_t
 */

size_t binary_tree_leaves(const binary_tree_t *tree)
{
	size_t leaves = 0;

	if (!tree)
		return (0);


	if (!tree->left && !tree->right)
		return (1);
	if (binary_tree_leaves(tree->left) == 1)
		leaves += 1;
	if (binary_tree_leaves(tree->right) == 1)
		leaves += 1;
	return (leaves);

}
