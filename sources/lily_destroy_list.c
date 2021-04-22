/*
** EPITECH PROJECT, 2019
** library lily
** File description:
** lily_destroy_list
*/

#include "lily.h"
#include <malloc.h>

int lily_destroy_list(lily_list **list_arg)
{
    lily_list *start_node;
    lily_list *list;
    lily_list *node_tmp;

    if (!list_arg || !*list_arg || !(*list_arg)->next)
        return (-1);
    start_node = *list_arg;
    list = *list_arg;
    list = list->next;
    while (list != start_node) {
        if (!list->next)
            return (-1);
        node_tmp = list;
        list = list->next;
        free(node_tmp);
    }
    free(start_node);
    *list_arg = NULL;
    return (0);
}