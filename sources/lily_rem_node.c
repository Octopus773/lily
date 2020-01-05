/*
** EPITECH PROJECT, 2019
** library lily
** File description:
** lily_rem_node
*/

#include "lily.h"

int lily_rem_node(lily_list **first, lily_list *node)
{
    int index;

    if (!first)
        return (-1);
    index = lily_get_index_from_node(*first, node);
    if (index == -1)
        return (-1);
    node->prev->next = node->next;
    node->next->prev = node->prev;
    if (node == *first)
        *first = node->next;
    node->next = NULL;
    node->prev = NULL;
    return (0);
}