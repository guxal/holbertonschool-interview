#include "binary_trees.h"

/**
 * 
 */
binary_tree_t *binary_tree_node(binary_tree_t *parent, int value)
{
    binary_tree_t *_new = malloc(sizeof(binary_tree_t));

    if (_new == NULL)
        return (NULL);
    memset(_new, 0x0, sizeof(*_new));
    _new->parent = parent, _new->n = value;
    return (_new);
}