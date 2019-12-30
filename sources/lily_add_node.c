/*
** EPITECH PROJECT, 2019
** library lily
** File description:
** lily_add_node
*/

#include "lily.h"

static void set_node(lily_list *node, lily_list *node_tmp, int index)
{
    int size = lily_get_list_length(node_tmp);

    if (index >= 0 && index < size) {
        node->next = node_tmp;
        node->prev = node_tmp->prev;
        node_tmp->prev->next = node;
        node_tmp->prev = node;
    }
    else {
        node->prev = node_tmp;
        node->next = node_tmp->next;
        node_tmp->next->prev = node;
        node_tmp->next = node;
    }
}

int lily_add_node(lily_list **first, lily_list *node, int index)
{
    lily_list *node_tmp;
    int got = lily_get_index_from_node(*first, node);

    if (!node || !first || got != -1)
        return (-1);
    if (!*first) {
        node->prev = node;
        node->next = node;
        *first = node;
        return (0);
    }
    node_tmp = lily_get_node_from_index(*first, index);
    set_node(node, node_tmp, index);
    if (node_tmp == *first && index != -1)
        *first = node;
    return (0);
}