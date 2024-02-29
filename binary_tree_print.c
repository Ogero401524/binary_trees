#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "binary_trees.h"



/**
 * print_tree_recursive - Stores recursively each level in an array of strings
 *
 * @node: Pointer to the node to print
 * @offset: Offset to print
 * @depth: Depth of the node
 * @buffer: Buffer
 *
 * Return: length of printed tree after process
 */
static int print_tree_recursive(const binary_tree_t *node, int offset, int depth, char **buffer)
{
    char node_str[6];
    int width, left_width, right_width, is_left, i;

    if (!node)
        return 0;
    is_left = (node->parent && node->parent->left == node);
    width = sprintf(node_str, "(%03d)", node->n);
    left_width = print_tree_recursive(node->left, offset, depth + 1, buffer);
    right_width = print_tree_recursive(node->right, offset + left_width + width, depth + 1, buffer);

    for (i = 0; i < width; i++)
        buffer[depth][offset + left_width + i] = node_str[i];

    if (depth && is_left)
    {
        for (i = 0; i < width + right_width; i++)
            buffer[depth - 1][offset + left_width + width / 2 + i] = '-';
        buffer[depth - 1][offset + left_width + width / 2] = '.';
    }
    else if (depth && !is_left)
    {
        for (i = 0; i < left_width + width; i++)
            buffer[depth - 1][offset - width / 2 + i] = '-';
        buffer[depth - 1][offset + left_width + width / 2] = '.';
    }

    return left_width + width + right_width;
}

/**
 * tree_height - Measures the height of a binary tree
 *
 * @node: Pointer to the node to measures the height
 *
 * Return: The height of the tree starting at @node
 */
static size_t tree_height(const binary_tree_t *node)
{
    size_t height_left, height_right;

    height_left = node->left ? 1 + tree_height(node->left) : 0;
    height_right = node->right ? 1 + tree_height(node->right) : 0;
    return (height_left > height_right ? height_left : height_right);
}

/**
 * print_binary_tree - Prints a binary tree
 *
 * @root: Pointer to the root node of the tree to print
 */
void print_binary_tree(const binary_tree_t *root)
{
    char **buffer;
    size_t height, i, j;

    if (!root)
        return;

    height = tree_height(root);
    buffer = malloc(sizeof(*buffer) * (height + 1));

    if (!buffer)
        return;

    for (i = 0; i < height + 1; i++)
    {
        buffer[i] = malloc(sizeof(**buffer) * 255);
	if (!buffer[i])
            return;
        memset(buffer[i], 32, 255);
    }

    print_tree_recursive(root, 0, 0, buffer);

    for (i = 0; i < height + 1; i++)
    {
        for (j = 254; j > 1; --j)
        {
            if (buffer[i][j] != ' ')
                break;
            buffer[i][j] = '\0';
        }

        printf("%s\n", buffer[i]);
        free(buffer[i]);
    }

    free(buffer);
}
