#include "binary_trees.h"

/**
 * binary_tree_insert_right - Insert node right-child in a binary tree.
 * @parent: A pointer to the node.
 * @value: The value to store in new node.
 *
 * Return: If parent is NULL or an error occurs - NULL.
 *         Otherwise - a pointer new node.
 *
 */
binary_tree_t *binary_tree_insert_right(binary_tree_t *parent, int value)
{
	binary_tree_t *newNR;

	if (parent == NULL)
		return (NULL);

	newNR = binary_tree_node(parent, value);
	if (new == NULL)
		return (NULL);

	if (parent->right != NULL)
	{
		newNR->right = parent->right;
		parent->right->parent = newNR;
	}
	parent->right = newNR;

	return (newNR);
}
