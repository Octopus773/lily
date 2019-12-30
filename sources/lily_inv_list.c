/*
** EPITECH PROJECT, 2019
** task1 day13
** File description:
** none
*/

#include "lily.h"

int lily_inv_list(lily_list **first)
{
    lily_list *start_node;
    lily_list *tmp = NULL;
    lily_list *node;

    if (!first || !*first)
        return (-1);
    start_node = *first;
    if (!start_node->next || !start_node->prev)
        return (-1);
    node = start_node;
    while (node != start_node || !tmp) {
        if (!node->next || !node->prev)
            return (-1);
        tmp = node->next;
        node->next = node->prev;
        node->prev = tmp;
        node = tmp;
    }
    *first = node->next;
    return (0);
}