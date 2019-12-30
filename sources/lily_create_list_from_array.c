/*
** EPITECH PROJECT, 2019
** task1 day13
** File description:
** none
*/

#include "lily.h"

lily_list *lily_create_list_from_array(void **array)
{
    lily_list *node;
    lily_list *first = NULL;

    if (!array || !*array)
        return (NULL);
    for (int i = 0; array[i]; i++) {
        node = lily_create_node(array[i]);
        if (!node) {
            lily_destroy_list(first);
            return (NULL);
        }
        lily_add_node(&first, node, -1);
    }
    return (first);
}