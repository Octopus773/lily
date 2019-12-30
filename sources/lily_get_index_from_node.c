/*
** EPITECH PROJECT, 2019
** task1 day13
** File description:
** none
*/

#include "lily.h"

int lily_get_index_from_node(lily_list *first, lily_list *node)
{
    lily_list *first_tmp = first;
    int index = 0;

    if (!first || !node || !first->next)
        return (-1);
    if (first == node)
        return (index);
    first = first->next;
    while (first != first_tmp || !index) {
        index++;
        if (!first->next)
            return (-1);
        if (first == node)
            return (index);
        first = first->next;
    }
    return (-1);
}