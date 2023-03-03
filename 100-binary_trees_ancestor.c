#include "binary_trees.h"

/**
 * binary_trees_ancestor - a function that finds the lowest common ancestor
 *                         of two nodes
 * @first: a pointer to the first node
 * @second: a pointer to the second nmode
 * Return: returns a pointer to the loweset common ancestor node of the two
 *         given nodes or NULL if no common ancestor was found.
 */
binary_tree_t *binary_trees_ancestor(const binary_tree_t *first,
				     const binary_tree_t *second)
{
	binary_tree_t *temp = NULL, *temp2 = NULL;

	if (!first || !second)
		return (NULL);

	if (first->parent)
	{
		temp = binary_trees_ancestor(first->parent, second);
		if (!temp)  /* recurstion returned from last node */
			temp = (binary_tree_t *)first;
	}

	if (second->parent)
	{
		temp2 = binary_trees_ancestor(first, second->parent);
		if (!temp2)
			temp2 = (binary_tree_t *)second;
	}

	if (temp == temp2)
		return (temp);

	return (NULL);
}

