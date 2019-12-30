/*
** EPITECH PROJECT, 2019
** task1 day13
** File description:
** none
*/

#include "lily.h"

int lily_mov_node(lily_list **first, lily_list *node, int new_index)
{
    int index = lily_get_index_from_node(*first, node);

    if (index == -1)
        return (-1);
    if (index == new_index)
        return (0);
    if (lily_rem_node(first, node))
        return (-1);
    if (lily_add_node(first, node, new_index))
        return (-1);
    return (0);
}