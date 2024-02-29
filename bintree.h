#ifndef BINARY_TREES_H
#define BINARY_TREES_H

/* Structure for a binary tree node */
typedef struct binary_tree_s {
    int n; /* Node value */
    struct binary_tree_s *parent; /* Pointer to the parent node */
    struct binary_tree_s *left; /* Pointer to the left child node */
    struct binary_tree_s *right; /* Pointer to the right child node */
} binary_tree_t;

/* Function prototypes */
binary_tree_t *binary_tree_node(binary_tree_t *parent, int value);
void binary_tree_print(const binary_tree_t *tree);

#endif /* BINARY_TREES_H */
