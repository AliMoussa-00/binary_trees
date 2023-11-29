#include "binary_trees.h"

/**
 * binary_tree_height - a function that measures the height of a binary tree.
 * @tree: a pointer to the root node of the tree to measure the height.
 * Return: the height of the tree.
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
	int left_height, right_height, max;

	if (!tree || (tree && !tree->left && !tree->right))
		return (0);

	left_height = 1 + binary_tree_height(tree->left);
	right_height = 1 + binary_tree_height(tree->right);

	max = left_height > right_height ? left_height : right_height;
	return (max);

}
/**
 * traverse - traverse through the binary tree and print the number
 *		at the wanted level
 * @tree: pointer to the binary tree
 * @level: the level of the node
 * @func: the printing function
 * Return: void
 */
void traverse(const binary_tree_t *tree, size_t level, void (*func)(int))
{
	if (!tree || level == 0)
		return;

	/**
	 * the pointer tree goes down the tree and the level decerases
	 * when level reaches 1 then we are at the right level left and right
	 */
	if (level == 1)
		func(tree->n);
	else
	{
		traverse(tree->left, level - 1, func);
		traverse(tree->right, level - 1, func);
	}
}

/**
 * binary_tree_levelorder - a function that goes through a binary tree
 *			using level-order traversal
 * @tree: a pointer to the root node of the tree to traverse.
 * @func: a pointer to a function to call for each node.
 * Return: void
 */
void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int))
{
	size_t i, height;

	if (!tree)
		return;


	height = binary_tree_height(tree);

	if (height > 0)
	{
		for (i = 1; i <= height + 1; i++)
			traverse(tree, i, func);
	}
}
