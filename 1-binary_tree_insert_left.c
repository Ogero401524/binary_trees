#include "binary_trees.h"

/**
 * binary_tree_insert_left - Inserts a node left-child of in a binary tree.
 * @parent: A pointer to the node to insert the left-child in.
 * @value: The value to store in the node new.
 *
 * Return: If parent is NULL or an error occurs - NULL.
 *         Otherwise - a pointer to the new node.
 *
 */
binary_tree_t *binary_tree_insert_left(binary_tree_t *parent, int value)
{
	binary_tree_t *newn;

	if (parent == NULL)
		return (NULL);

	newn = binary_tree_node(parent, value);
	if (newn == NULL)
		return (NULL);

	if (parent->left != NULL)
	{
		newn->left = parent->left;
		parent->left->parent = newn;
	}
	parent->left = newn;

	return (newn);
}
