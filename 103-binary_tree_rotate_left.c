#include "binary_trees.h"

/**
 * binary_tree_rotate_left -  a function that performs a
 *				left-rotation on a binary tree
 * @tree:  a pointer to the root node of the tree to rotate
 * Return: return a pointer to the new root node of the tree once rotated
 */
binary_tree_t *binary_tree_rotate_left(binary_tree_t *tree)
{
	binary_tree_t *tmp;

	if (!tree || (tree && !tree->right))
		return (NULL);

	tmp = tree->right;

	tree->right = NULL;
	tree->parent = tmp;

	tmp->parent = NULL;

	if (tmp->left)
	{
		tree->right = tmp->left;
		tmp->left->parent = tree;
	}

	tmp->left = tree;
	return (tmp);
}
