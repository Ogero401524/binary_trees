#include "binary_trees.h"

/**
 * binary_tree_height - Measures the height tree.
 * @tree: A pointer to the root nodetree.
 * Return: If tree is NULL return 0, else return height.
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
	if (tree)
	{
		size_t a = 0, b = 0;

		a = tree->left ? a + binary_tree_height(tree->left) : 0;
		b = tree->right ? a + binary_tree_height(tree->right) : 0;
		return ((a > b) ? a : b);
	}
	return (0);
}
