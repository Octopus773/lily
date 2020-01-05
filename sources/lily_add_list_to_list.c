/*
** EPITECH PROJECT, 2019
** library lily
** File description:
** lily_add_list_to_list
*/

#include "lily.h"

int lily_add_list_to_list(lily_list **first_dest, lily_list *first_src, int ind)
{
    int size = lily_get_list_length(first_src);
    int size_dest;
    lily_list *node;

    if (!first_dest || !*first_dest || !first_src)
        return (-1);
    size_dest = lily_get_list_length(*first_dest);
    if (ind >= 0 && ind <= size_dest)
        lily_inv_list(&first_src);
    for (int i = 0; i < size; i++) {
        node = first_src;
        if (lily_rem_node(&first_src, node))
            return (-1);
        if (lily_add_node(first_dest, node, ind))
            return (-1);
    }
    return (0);
}