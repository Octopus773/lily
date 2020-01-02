/*
** EPITECH PROJECT, 2019
** library lily
** File description:
** lily_destroy_list_and_data
*/

#include "lily.h"

int lily_destroy_list_and_data(lily_list *list, void (*destroy)(void *))
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
        if (node_tmp->data)
            destroy(node_tmp->data);
        free(node_tmp);
    }
    if (start_node->data)
        free(start_node->data);
    free(start_node);
    return (0);
}