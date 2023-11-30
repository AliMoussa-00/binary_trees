#include "binary_trees.h"

/**
 * binary_tree_height - a function that measures the height of a binary tree.
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

	max = left_height > right_height ? left_height : right_height;
	return (max);

}

/**
 * check_all - check if all the values in the tree are all
 *			greater or lesser than the value
 * @tree: the tree
 * @val: to check
 * @lesser: if 1 then we need to check if all 'lesser' else  'greater'
 * Return: 1 if True else 0
 */
int check_all(binary_tree_t *tree, int lesser, int val)
{
	if (!tree)
		return (1);

	if (lesser != 1) /*check if all left is greater than root*/
	{
		if (tree->n > val)
		{
			if (check_all(tree->left, lesser, val) &&
					check_all(tree->right, lesser, val))
				return (1);
		}
	}
	else /*check if all left is lesser than root*/
	{
		if (tree->n < val)
		{
			if (check_all(tree->left, lesser, val) &&
					check_all(tree->right, lesser, val))
				return (1);
		}
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

	if (check_all(tree->left, 1, tree->n) &&
			check_all(tree->right, 0, tree->n))
	{
		return (1);
	}

	return (0);
}


/**
 * helper - helper function for AVL
 * @tree: pointer
 * Return: 1 if success else 0
 */
int helper(const binary_tree_t *tree)
{
	int lh, rh, diff;

	if (!tree)
		return (1);

	if (binary_tree_is_bst(tree))
	{
		lh = binary_tree_height(tree->left);
		rh = binary_tree_height(tree->right);

		diff = abs(lh - rh);
		if (diff > 1)
			return (0);
	}
	else
		return (0);

	return (helper(tree->left) && helper(tree->right));
}

/**
 * binary_tree_is_avl - checks if a binary tree is a valid AVL Tree
 * @tree: a pointer to the root node of the tree to check
 * Return: return 1 if tree is a valid AVL Tree, and 0 otherwise
 */
int binary_tree_is_avl(const binary_tree_t *tree)
{
	if (!tree)
		return (0);

	return (helper(tree));
}
