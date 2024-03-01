#include "binary_trees.h"

/**
 * binary_tree_size - Function checking size of a binary tree.
 * @tree: A pointer to the tree to measure the size of.
 *
 * Return: The size of the tree.
 */
size_t binary_tree_size(const binary_tree_t *tree)
{
	size_t Treesize = 0;

	if (tree)
	{
		Treesize += 1;
		Treesize += binary_tree_size(tree->left);
		Treesize += binary_tree_size(tree->right);
	}
	return (Treesize);
}
