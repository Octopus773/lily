/*
** EPITECH PROJECT, 2019
** library lily
** File description:
** lily_destroy_list
*/

#include "lily.h"

int lily_destroy_list(lily_list *list)
{
    lily_list *start_node = list;
    lily_list *node_tmp;

    if (!list || !list->next || !list->prev)
        return (-1);
    list = list->next;
    while (list != start_node) {
        if (!list->next)
            return (-1);
        node_tmp = list;
        list = list->next;
        free(node_tmp);
    }
    free(start_node);
    return (0);
}