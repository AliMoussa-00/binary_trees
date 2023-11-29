#include "binary_trees.h"

/**
 * binary_tree_rotate_right - a function that performs a
 *			right-rotation on a binary tree
 * @tree: a pointer to the root node of the tree to rotate
 * Return: return a pointer to the new root node of the tree once rotated
 */
binary_tree_t *binary_tree_rotate_right(binary_tree_t *tree)
{
	binary_tree_t *tmp;

	if (!tree || (tree && !tree->left))
		return (NULL);

	tmp = tree->left;

	tree->left = NULL;
	tree->parent = tmp;

	tmp->parent = NULL;

	if (tmp->right)
	{
		tree->left = tmp->right;
		tmp->right->parent = tree;
	}

	tmp->right = tree;
	return (tmp);
}
