#include "binary_trees.h"

/**
 * bst_insert - a function that inserts a value in a Binary Search Tree
 * @tree: a double pointer to the root node of the BST to insert the value
 * @value: the value to store in the node to be inserted
 * Return:  return a pointer to the created node, or NULL on failure
 */
bst_t *bst_insert(bst_t **tree, int value)
{
	bst_t *node, *current, *parent;
	int is_left = 0;

	node = (bst_t *) binary_tree_node(NULL, value);
	if (!node)
		return (NULL);

	if (!*tree)
	{
		*tree = node;
		return (*tree);
	}

	current = *tree;

	while (current)
	{
		parent = current;

		if (current->n > value)
		{
			current = current->left;
			is_left = 1;
		}
		else if (current->n < value)
		{
			current = current->right;
			is_left = 0;
		}
		else
			return (NULL);
	}

	node->parent = parent;
	if (is_left)
		parent->left = node;
	else
		parent->right = node;

	return (node);
}
