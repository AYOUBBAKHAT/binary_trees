#include "binary_trees.h"

unsigned char is_terminal(const binary_tree_t *node);
size_t measure_depth(const binary_tree_t *tree);
const binary_tree_t *fetch_terminal(const binary_tree_t *tree);
int is_perfect_recursive(const binary_tree_t *tree,
		size_t terminal_depth, size_t level);
int check_perfection(const binary_tree_t *tree);

/**
 * is_terminal - Determines if a node is a terminal node in a binary tree.
 * @node: A pointer to the node to be checked.
 *
 * Return: 1 if the node is a terminal node, 0 otherwise.
 */
unsigned char is_terminal(const binary_tree_t *node)
{
	return ((node->left == NULL && node->right == NULL) ? 1 : 0);
}

/**
 * easure_depth - Calculates the depth of a specified node in a binary tree.
 * @tree: A pointer to the node whose depth is to be calculated.
 *
 * Return: The depth of the specified node.
 */
size_t measure_depth(const binary_tree_t *tree)
{
	return (tree->parent != NULL ? 1 + measure_depth(tree->parent) : 0);
}

/**
 * fetch_terminal - Retrieves a terminal node from a binary tree.
 * @tree: A pointer to the root node of the binary tree.
 *
 * Return: A pointer to the first terminal node encountered.
 */
const binary_tree_t *fetch_terminal(const binary_tree_t *tree)
{
	if (is_terminal(tree) == 1)
		return (tree);
	return (tree->left ? fetch_terminal(tree->left) : fetch_terminal(tree->right));
}

/**
 * is_perfect_recursive - Determines if a binary tree is perfect recursively.
 * @tree: A pointer to the root node of the binary tree.
 * @terminal_depth: The depth of a terminal node in the binary tree.
 * @level: The level of the current node.
 *
 * Return: 1 if the binary tree is perfect, 0 otherwise.
 */
int is_perfect_recursive(const binary_tree_t *tree,
	size_t terminal_depth, size_t level)
{
	if (is_terminal(tree))
		return (level == terminal_depth ? 1 : 0);
	if (tree->left == NULL || tree->right == NULL)
		return (0);
	return (is_perfect_recursive(tree->left, terminal_depth, level + 1) &&
			is_perfect_recursive(tree->right, terminal_depth, level + 1));
}

/**
 * binary_tree_is_perfect - Determines if a binary tree is perfect.
 * @tree: A pointer to the root node of the binary tree.
 *
 * Return: 0 if the binary tree is NULL or not perfect, 1 otherwise.
 */
int check_perfection(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);
	return (is_perfect_recursive(tree, measure_depth(fetch_terminal(tree)), 0));
}
