#include "binary_trees.h"

/**
 * all_lesser_than - check if all the values in the tree are lesser
 *			than the value
 * @tree: the tree
 * @val: to check
 * Return: 1 if True else 0
 */
int all_lesser_than(binary_tree_t *tree, int val)
{
	if (!tree)
		return (1);

	if (tree->n < val)
	{
		if (all_lesser_than(tree->left, val) &&
				all_lesser_than(tree->right, val))
			return (1);
	}

	return (0);
}

/**
 * all_greater_than - check if all the values in the tree are greater
 *			than the value
 * @tree: the tree
 * @val: to check
 * Return: 1 if True else 0
 */
int all_greater_than(binary_tree_t *tree, int val)
{
	if (!tree)
		return (1);

	if (tree->n > val)
	{
		if (all_greater_than(tree->left, val) &&
				all_greater_than(tree->right, val))
			return (1);
	}

	return (0);
}
/**
 * binary_tree_is_bst -  a function that checks if a binary tree is
 *			a valid Binary Search Tree.
 * @tree: a pointer to the root node of the tree to check
 * Return: 1 if tree is a valid BST, and 0 otherwise
 */
int binary_tree_is_bst(const binary_tree_t *tree)
{
	if (!tree)
		return (0);

	if (all_lesser_than(tree->left, tree->n) &&
			all_greater_than(tree->right, tree->n))
	{
		return (1);
	}

	return (0);
}
