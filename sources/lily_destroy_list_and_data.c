/*
** EPITECH PROJECT, 2019
** library lily
** File description:
** lily_destroy_list_and_data
*/

#include "lily.h"
#include <malloc.h>

static int destroy_list(lily_list **l_a, lily_list *s_n, void destroy(void *))
{
    lily_list *list = *l_a;
    lily_list *node_tmp;

    list = list->next;
    while (list != s_n) {
        if (!list->next)
            return (-1);
        node_tmp = list;
        list = list->next;
        if (node_tmp->data)
            (*destroy)(node_tmp->data);
        free(node_tmp);
    }
    return (0);
}

int lily_destroy_list_and_data(lily_list **list_arg, void destroy(void *))
{
    lily_list *start_node;

    if (!list_arg || !*list_arg || !(*list_arg)->next|| !destroy)
        return (-1);
    start_node = *list_arg;
    if (destroy_list(list_arg, *list_arg, destroy))
        return (-1);
    if (start_node->data)
        (*destroy)(start_node->data);
    free(start_node);
    *list_arg = NULL;
    return (0);
}