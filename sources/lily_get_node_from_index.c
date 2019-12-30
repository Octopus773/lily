/*
** EPITECH PROJECT, 2019
** library lily
** File description:
** lily_get_node_from_index
*/

#include "lily.h"

static lily_list *get_node_ind(int ind, lily_list *first, lily_list *first_tmp)
{
    while (ind) {
        if (!first->prev)
            return (NULL);
        first = first->prev;
        if (first == first_tmp)
            return (first_tmp);
        ind++;
    }
    return (first);
}

lily_list *lily_get_node_from_index(lily_list *first, int index)
{
    lily_list *first_tmp = first;

    if (!first || !first->next || !first->prev)
        return (NULL);
    if (index < 0)
        return (get_node_ind(index, first, first_tmp));
    while (index) {
        if (!first->next)
            return (NULL);
        first = first->next;
        if (first == first_tmp)
            return (first_tmp->prev);
        index--;
    }
    return (first);
}