/*
** EPITECH PROJECT, 2019
** library lily
** File description:
** lily_get_list_length
*/

#include "lily.h"

int lily_get_list_length(lily_list *list)
{
    lily_list *list_start = list;
    int i = 0;

    if (!list || !list->next || !list->prev)
        return (-1);
    list = list->next;
    while (list != list_start) {
        if (!list->next)
            return (-1);
        i++;
        list = list->next;
    }
    i++;
    return (i);
}