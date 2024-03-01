#include "binary_trees.h"

/**
 * binary_tree_leaves - Counts the leaves in binary tree.
 * @tree: A pointer tree to count the leaves of.
 *
 * Return: The number of leaves in tree.
 */
size_t binary_tree_leaves(const binary_tree_t *tree)
{
	size_t Nleaves = 0;

	if (tree)
	{
		Nleaves += (!tree->left && !tree->right) ? 1 : 0;
		Nleaves += binary_tree_leaves(tree->left);
		Nleaves += binary_tree_leaves(tree->right);
	}
	return (Nleaves);
}
